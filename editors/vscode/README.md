# BEAM Language — VS Code extension

Syntax highlighting, editor behaviours, snippets and one-key running for
[BEAM](https://github.com/CFFinch62/BEAM) (`.yab` files).

## Getting BEAM

This extension highlights and runs `.yab` files — it does not bundle the
interpreter. Get it from GitHub:

**<https://github.com/CFFinch62/BEAM>**

BEAM is free and open source, as is this extension.

```sh
git clone https://github.com/CFFinch62/BEAM.git
cd BEAM
autoreconf --install
./configure
make
```

That produces the `beam` binary. Put it on your `PATH`, or point
`beam.interpreterPath` (below) at it with an absolute path.

## What it does

**Syntax highlighting** for all 237 keyword forms, generated from
`yabasic.flex` and split by role, so a program reads by structure rather than
as one colour: control flow, storage, word operators (`and`, `mod`, `eor`,
`shl`), graphics, file I/O, maths, the `$`-suffixed string functions, and the
foreign-function family each get their own scope.

**BEAM's own additions get their own colour.** The 37 `beam_*` commands —
the GUI widgets, dialogs and NMEA serial calls that BEAM adds on top of
Yabasic — are scoped separately from the Yabasic core, so it is obvious at a
glance which half of the language a line is using.

It also handles the details:

- Matching is **case-insensitive** — `print`, `PRINT` and `PrInT` are the same
  token, as the interpreter treats them.
- Multi-word block enders are matched as one keyword, in every spelling BEAM
  accepts: `end if`, `end-if`, `endif`, `fi`, `end while`, `end-while`,
  `end sub`, `end switch$`.
- Comments are `//` and `REM` — Yabasic has no `'` comment.
- `left$` is a string function, while `name$` is a string variable.
- `sub` and `label` definitions are scoped as definitions, so a jump target
  stands out from a call.

**Editor behaviours** — `//` comment toggling, bracket matching, auto-closing
pairs, and indentation that follows the block keywords. `if … then` only
indents when `then` ends the line: Yabasic's short if (`if a then print "x"`)
is a complete statement and correctly stays put. `beam_begin`, `beam_row` and
the other paired GUI calls indent and dedent with their partners. Folding is
marker-based, since BEAM blocks are delimited by keywords rather than
indentation.

**Snippets** for a complete BEAM app skeleton with its event loop, every
widget and container, the dialogs, an NMEA serial read, and all the Yabasic
block forms.

**Commands** — each also available from the Command Palette:

| Command | Default key | What it runs |
|---|---|---|
| BEAM: Run File | `Ctrl+F5` | `beam <file>` |
| BEAM: Check for Errors | `Ctrl+Shift+F5` | `beam --check <file>` |
| BEAM: Bind Standalone Executable | — | `beam --bind <out> <file>` |

**Problems panel** — errors become squiggles in the editor. **Check for
Errors** parses and reports without executing, so a GUI program opens no
window. A file's errors are cleared as soon as you edit it.

## Settings

| Setting | Default | Purpose |
|---|---|---|
| `beam.interpreterPath` | `beam` | Path to the `beam` binary |
| `beam.saveBeforeRun` | `true` | Save before running, checking or binding |
| `beam.runInTerminal` | `true` | Run in a terminal so `input` and GUI windows work |
| `beam.checkOnSave` | `false` | Run `--check` on every save |
| `beam.librarypath` | *(none)* | Passed as `--librarypath` |
| `beam.infolevel` | *(BEAM's default)* | Passed as `--infolevel`; lower it to see notes and warnings |

## How the diagnostics are read

BEAM prints a diagnostic as two lines:

```text
---Error in prog.yab, line 12:
---Error: String not terminated
   print "unterminated
         ^~~~~~~~~~~~~
```

so the bundled `$beam` problem matcher uses one pattern for the location and
another for the message.

There is a wrinkle a plain matcher cannot handle: BEAM only reprints the
location header when the file or line *changes*, so a second diagnostic on the
same line arrives as a bare message. The extension keeps the last header and
attaches those correctly. It also drops the trailing run summaries
(`Couldn't parse program`, `Program stopped due to an error`), which carry no
location of their own and would otherwise pin a meaningless second squiggle to
whatever line came last.

## About `.yab`

BEAM claims `.yab`, and FragBASIC claims `.bas` — matching how the MyCode
editor resolves the same overlap. BEAM runs `.bas` files perfectly well; if you
have some, either rename them or pick the language from the status bar.

## Installing from source

```sh
cd editors/vscode
npx @vscode/vsce package
code --install-extension beam-language-0.1.0.vsix
```

## Without the extension

`tasks.example.json` in this directory sets up the same check and run tasks
using only VS Code's built-in task runner and its two-pattern problem matcher —
no extension required. Copy it to your project's `.vscode/tasks.json`.

## License

See [LICENSE](LICENSE).
