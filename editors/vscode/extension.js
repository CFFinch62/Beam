// BEAM Language extension — run/check/bind commands for .yab files.
//
// Syntax highlighting, editor behaviours and snippets are entirely
// declarative (package.json + the grammar + language-configuration.json);
// none of them need this file. Everything here exists only to drive the
// `beam` binary and turn its diagnostics into entries in the Problems panel.

const vscode = require('vscode');
const cp = require('child_process');
const path = require('path');

/** BEAM prints a diagnostic as two lines (main.c:2073):
 *
 *      ---Error in /path/prog.yab, line 12:
 *      ---Error: String not terminated
 *         print "unterminated
 *               ^~~~~~~~~~~~~
 *
 *  The location header is only emitted when the file or line CHANGES, so a
 *  second diagnostic on the same line arrives as a bare message that belongs
 *  to the header above it. These two regexes are paired by the parser below,
 *  which keeps the last location as it goes. */
const LOCATION_RE = /^---(Error|Warning|Note|Fatal|Info) in (.*), line (\d+):$/;
const MESSAGE_RE = /^---(Error|Warning|Note|Fatal|Info):\s?(.*)$/;

/** Trailing summaries emitted after the real diagnostics (main.c:299, 2006).
 *  They carry no location of their own, so attaching them to whatever line
 *  came last would pin a second, meaningless squiggle there. */
const SUMMARY_MESSAGES = [
  "Couldn't parse program",
  'Program stopped due to an error',
];

let diagnostics = null;
let output = null;

function config() {
  return vscode.workspace.getConfiguration('beam');
}

function interpreter() {
  return config().get('interpreterPath', 'beam') || 'beam';
}

/** Quote a path for a shell command line (the terminal path). */
function shellQuote(p) {
  if (process.platform === 'win32') return `"${p}"`;
  return `'${String(p).replace(/'/g, `'\\''`)}'`;
}

/** Options that apply to every invocation. */
function commonFlags() {
  const cfg = config();
  const flags = [];
  const lib = (cfg.get('librarypath', '') || '').trim();
  if (lib) flags.push('--librarypath', lib);
  const info = (cfg.get('infolevel', '') || '').trim();
  if (info) flags.push('--infolevel', info);
  return flags;
}

async function activeBeamDocument() {
  const editor = vscode.window.activeTextEditor;
  if (!editor || editor.document.languageId !== 'beam') {
    vscode.window.showErrorMessage('BEAM: no .yab file is active.');
    return null;
  }
  if (config().get('saveBeforeRun', true) && editor.document.isDirty) {
    await editor.document.save();
  }
  return editor.document;
}

/** Run in the integrated terminal — output appears live, `input` works, and a
 *  GUI program gets a real controlling process. One reused terminal. */
function runInTerminal(doc, args) {
  let term = vscode.window.terminals.find((t) => t.name === 'BEAM');
  if (!term) {
    term = vscode.window.createTerminal({
      name: 'BEAM',
      cwd: path.dirname(doc.fileName),
    });
  }
  term.show(true);
  const isFlag = (a) => /^--[a-z-]+$/.test(a) || /^-[a-zA-Z]+$/.test(a);
  const parts = [
    shellQuote(interpreter()),
    ...args.map((a) => (isFlag(a) ? a : shellQuote(a))),
  ];
  term.sendText(parts.join(' '));
}

/** Run as a child process — output goes to an Output channel and diagnostics
 *  become squiggles in the editor via the Problems panel. */
function runInOutputChannel(doc, args, label) {
  if (!output) output = vscode.window.createOutputChannel('BEAM');
  output.clear();
  output.show(true);

  const exe = interpreter();
  output.appendLine(`> ${exe} ${args.join(' ')}`);
  output.appendLine('');

  const started = Date.now();
  const child = cp.spawn(exe, args, { cwd: path.dirname(doc.fileName) });

  let stderr = '';
  child.stdout.on('data', (d) => output.append(d.toString()));
  child.stderr.on('data', (d) => {
    const text = d.toString();
    stderr += text;
    output.append(text);
  });

  child.on('error', (err) => reportSpawnError(err, exe));

  child.on('close', (code) => {
    publishDiagnostics(doc, stderr);
    output.appendLine('');
    output.appendLine(
      `[${label} exit ${code} in ${((Date.now() - started) / 1000).toFixed(2)}s]`
    );
  });

  // A program that reads `input` would otherwise wait forever on a pipe with
  // nothing behind it. Closing stdin makes it fail fast instead.
  child.stdin.end();
}

function reportSpawnError(err, exe) {
  if (err.code === 'ENOENT') {
    vscode.window
      .showErrorMessage(
        `BEAM: '${exe}' not found. Run './configure && make' in the Beam repo, or set beam.interpreterPath.`,
        'Open Settings'
      )
      .then((choice) => {
        if (choice === 'Open Settings') {
          vscode.commands.executeCommand(
            'workbench.action.openSettings',
            'beam.interpreterPath'
          );
        }
      });
  } else {
    vscode.window.showErrorMessage(`BEAM: ${err.message}`);
  }
}

function severityOf(word) {
  switch (word) {
    case 'Warning':
      return vscode.DiagnosticSeverity.Warning;
    case 'Note':
    case 'Info':
      return vscode.DiagnosticSeverity.Information;
    default:
      return vscode.DiagnosticSeverity.Error;
  }
}

/** Pair BEAM's two-line diagnostics into editor squiggles.
 *
 *  Walks the output keeping the most recent `--- X in FILE, line N:` header,
 *  and attaches every following `--- X: message` to it. That is what makes a
 *  second diagnostic on the same line — which BEAM prints without repeating
 *  the header — land in the right place. Messages seen before any header, and
 *  the trailing run summaries, are left for the Output channel. */
function publishDiagnostics(doc, stderr) {
  const byFile = new Map();
  let current = null;

  for (const raw of stderr.split('\n')) {
    const line = raw.replace(/\r$/, '');

    const loc = LOCATION_RE.exec(line);
    if (loc) {
      current = { file: loc[2], line: parseInt(loc[3], 10) };
      continue;
    }

    const msg = MESSAGE_RE.exec(line);
    if (!msg) continue;

    const text = msg[2].trim();
    if (!current || SUMMARY_MESSAGES.includes(text)) continue;

    const lineNo = Math.max(0, current.line - 1);
    const uri = vscode.Uri.file(
      path.resolve(path.dirname(doc.fileName), current.file)
    );
    // BEAM reports a line but no usable column here (the caret is drawn on a
    // separate echo line), so underline the whole line.
    const diag = new vscode.Diagnostic(
      new vscode.Range(lineNo, 0, lineNo, Number.MAX_SAFE_INTEGER),
      text,
      severityOf(msg[1])
    );
    diag.source = 'beam';

    const key = uri.toString();
    if (!byFile.has(key)) byFile.set(key, { uri, items: [] });
    byFile.get(key).items.push(diag);
  }

  diagnostics.clear();
  for (const { uri, items } of byFile.values()) {
    diagnostics.set(uri, items);
  }
}

/** `beam --check` in the background, for checkOnSave. */
function checkQuietly(doc) {
  const child = cp.spawn(
    interpreter(),
    ['--check', ...commonFlags(), doc.fileName],
    { cwd: path.dirname(doc.fileName) }
  );

  let stderr = '';
  child.stderr.on('data', (d) => (stderr += d.toString()));
  // A missing binary would fire on every save -- stay silent and let the
  // explicit commands be the ones that complain.
  child.on('error', () => {});
  child.on('close', () => publishDiagnostics(doc, stderr));
  child.stdin.end();
}

async function run() {
  const doc = await activeBeamDocument();
  if (!doc) return;
  const args = [...commonFlags(), doc.fileName];
  if (config().get('runInTerminal', true)) runInTerminal(doc, args);
  else runInOutputChannel(doc, args, 'run');
}

/** `--check` parses and reports without executing — BEAM prints
 *  "Program will not be executed" and stops, so a GUI program opens no window
 *  and an `input` never blocks. */
async function checkFile() {
  const doc = await activeBeamDocument();
  if (!doc) return;
  runInOutputChannel(doc, ['--check', ...commonFlags(), doc.fileName], 'check');
}

/** `--bind` packs the interpreter and the program into one executable. */
async function bindFile() {
  const doc = await activeBeamDocument();
  if (!doc) return;
  const out = doc.fileName.replace(/\.yab$/i, '');
  runInOutputChannel(
    doc,
    ['--bind', out, ...commonFlags(), doc.fileName],
    'bind'
  );
}

function activate(context) {
  diagnostics = vscode.languages.createDiagnosticCollection('beam');

  context.subscriptions.push(
    diagnostics,
    vscode.commands.registerCommand('beam.runFile', run),
    vscode.commands.registerCommand('beam.checkFile', checkFile),
    vscode.commands.registerCommand('beam.bindFile', bindFile),

    // A file's errors are stale the moment it is edited.
    vscode.workspace.onDidChangeTextDocument((e) => {
      if (e.document.languageId === 'beam') diagnostics.delete(e.document.uri);
    }),

    vscode.workspace.onDidSaveTextDocument((doc) => {
      if (doc.languageId === 'beam' && config().get('checkOnSave', false)) {
        checkQuietly(doc);
      }
    })
  );
}

function deactivate() {
  if (output) output.dispose();
}

module.exports = { activate, deactivate };
