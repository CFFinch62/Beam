/**
 * BEAM Language Support Plugin for MyCode
 *
 * Provides:
 *   - Syntax highlighting for .bas / .yab files (Monaco Monarch tokenizer)
 *   - Hover documentation for all beam_* commands
 *   - Run command: saves file, spawns `beam <path>` in a PTY terminal,
 *     streams output to a bottom panel
 *   - Stop command: kills the running beam process
 *   - Status bar Run / Stop buttons
 *   - Tools menu items for Run and Stop
 *
 * Fragillidae Software — BEAM v2.0.0
 */

(function () {

    // -----------------------------------------------------------------------
    // BEAM command hover documentation (Section 3 of spec)
    // -----------------------------------------------------------------------
    const BEAM_DOCS = {
        'beam_open':        'beam_open(w, h, title$) → num\nOpen a window. Returns an integer handle.\nMust be called before any widget commands.',
        'beam_close':       'beam_close(win)\nClose window and free all resources.',
        'beam_title':       'beam_title(win, title$)\nUpdate the window title bar text at runtime.',
        'beam_size':        'beam_size(win, w, h)\nResize the window programmatically.',
        'beam_running':     'beam_running(win) → num\nReturns 1 if window is open, 0 if closed.\nUse as the condition of the main while loop.',
        'beam_begin':       'beam_begin(win)\nBegin a new GUI frame. Call once per loop iteration\nbefore any widget or layout commands.',
        'beam_end':         'beam_end(win)\nEnd the frame, render all widgets, and present.\nCall once per loop iteration after all widgets.',
        'beam_button':      'beam_button(label$, w, h) → num\nRender a button. Returns 1 if clicked this frame.',
        'beam_label':       'beam_label(text$)\nRender a static text label.',
        'beam_text':        'beam_text(text$, w, h)\nRender a multi-line word-wrapped text block.',
        'beam_input':       'beam_input(buf$, maxlen, w) → num\nSingle-line text input field.\nReturns 1 if the content changed this frame.',
        'beam_checkbox':    'beam_checkbox(label$, checked) → num\nRender a checkbox. Returns 1 if checked, 0 if not.',
        'beam_combo':       'beam_combo(items$, count, sel, w, h) → num\nDropdown combo box. items$ is newline-delimited.\nReturns the selected index.',
        'beam_slider':      'beam_slider(val, min, max, step, w) → num\nHorizontal slider. Returns the current value.',
        'beam_progress':    'beam_progress(val, max, w, h)\nRender a progress bar. No return value.',
        'beam_separator':   'beam_separator()\nDraw a horizontal dividing line.',
        'beam_spacing':     'beam_spacing(px)\nAdd vertical whitespace of px pixels.',
        'beam_image':       'beam_image(path$, w, h)\nDisplay a BMP image from file path.',
        'beam_row':         'beam_row(h, cols)\nBegin a row layout: h = height in pixels,\ncols = number of columns side by side.',
        'beam_row_end':     'beam_row_end()\nEnd the current row layout, return to vertical flow.',
        'beam_group_begin': 'beam_group_begin(title$)\nBegin a named group box (bordered panel with title).',
        'beam_group_end':   'beam_group_end()\nEnd the current group box.',
        'beam_panel_begin': 'beam_panel_begin(title$, w, h)\nBegin a scrollable panel.',
        'beam_panel_end':   'beam_panel_end()\nEnd the current scrollable panel.',
        'beam_msgbox':      'beam_msgbox(title$, msg$) → num\nShow a modal message box. Returns 1 when dismissed.',
        'beam_confirm':     'beam_confirm(title$, msg$) → num\nShow a Yes/No dialog. Returns 1 = Yes, 0 = No.',
        'beam_open_file':   'beam_open_file(filter$) → str\nShow a file-open dialog. Returns selected path or "".',
        'beam_save_file':   'beam_save_file(filter$) → str\nShow a file-save dialog. Returns chosen path or "".',
        'beam_set_color':   'beam_set_color(r, g, b)\nSet foreground accent colour (0–255 each channel).',
        'beam_set_style':   'beam_set_style(name$)\nSwitch Nuklear theme. name$ = "dark" | "white" | "amber".',
        'beam_time':        'beam_time() → num\nReturns elapsed milliseconds since program start.',
        'beam_sleep':       'beam_sleep(ms)\nPause execution for ms milliseconds.',
    };

    // -----------------------------------------------------------------------
    // Runtime state
    // -----------------------------------------------------------------------
    let runStatusItem   = null;
    let stopStatusItem  = null;
    let outputPanel     = null;
    let outputEl        = null;   // <pre> inside the panel
    let terminalId      = null;   // active PTY terminal id
    let capturingOutput = false;  // gate: ignore fish startup noise
    let beamExePath     = null;   // resolved path to beam binary

    // -----------------------------------------------------------------------
    // Helpers
    // -----------------------------------------------------------------------

    // Strip all common terminal escape sequences (CSI, OSC, DEC private, etc.)
    function stripAnsi(text) {
        return text
            // OSC sequences: ESC ] ... ST  or  ESC ] ... BEL
            .replace(/\x1b\][^\x07\x1b]*(\x07|\x1b\\)/g, '')
            // CSI sequences: ESC [ ... final-byte
            .replace(/\x1b\[[\x30-\x3f]*[\x20-\x2f]*[\x40-\x7e]/g, '')
            // DEC private / other two-char ESC sequences
            .replace(/\x1b[\x20-\x2f\/]?[\x40-\x7e]/g, '')
            // Remaining bare ESC
            .replace(/\x1b/g, '')
            // Backspace sequences
            .replace(/.\x08/g, '');
    }

    function appendOutput(text) {
        if (!outputEl) return;
        const clean = stripAnsi(text);
        if (!clean) return;
        outputEl.textContent += clean;
        outputEl.scrollTop = outputEl.scrollHeight;
    }

    // Locate the beam binary by checking known installation paths.
    // Returns the path string, or null if not found anywhere.
    async function findBeamExecutable() {
        if (!window.mycode || !window.mycode.file) return null;
        const candidates = [
            '/usr/local/bin/beam',
            '/usr/bin/beam',
            '/opt/local/bin/beam',
        ];
        for (const p of candidates) {
            try {
                if (await window.mycode.file.exists(p)) return p;
            } catch (e) { /* keep trying */ }
        }
        return null;
    }

    function clearOutput() {
        if (outputEl) outputEl.textContent = '';
    }

    function setRunning(yes) {
        if (runStatusItem)  runStatusItem.update({ text: yes ? '⏸ BEAM running...' : '▶ Run BEAM' });
        if (stopStatusItem) {
            if (yes) stopStatusItem.show(); else stopStatusItem.hide();
        }
    }

    // -----------------------------------------------------------------------
    // Main plugin module
    // -----------------------------------------------------------------------
    const pluginModule = {

        async activate(api) {
            console.log('[BEAM] Plugin activating...');

            // Resolve the beam executable path once at startup.
            beamExePath = await findBeamExecutable();
            if (!beamExePath) {
                console.warn('[BEAM] beam binary not found in known locations. ' +
                    'Run `sudo make install` in the Beam source directory.');
            } else {
                console.log('[BEAM] Found beam at:', beamExePath);
            }

            const monaco = window.monaco;
            if (!monaco) {
                console.error('[BEAM] Monaco not available');
                return;
            }

            // -----------------------------------------------------------
            // 1. Register language
            // -----------------------------------------------------------
            monaco.languages.register({
                id: 'beam',
                extensions: ['.bas', '.yab'],
                aliases: ['BEAM', 'Beam', 'yabasic'],
            });

            // -----------------------------------------------------------
            // 2. Monarch tokenizer
            // -----------------------------------------------------------
            monaco.languages.setMonarchTokensProvider('beam', {

                // BASIC core keywords
                basicKeywords: [
                    'if', 'then', 'else', 'endif', 'end',
                    'while', 'wend',
                    'for', 'to', 'step', 'next',
                    'do', 'loop', 'until',
                    'goto', 'gosub', 'return',
                    'sub', 'endsub',
                    'print', 'input',
                    'let', 'dim',
                    'data', 'read', 'restore',
                    'import', 'export',
                    'local', 'global',
                    'break', 'continue',
                    'switch', 'case', 'default',
                    'on', 'error',
                    'open', 'close', 'write',
                ],

                // BEAM GUI commands — all from Section 3
                beamCommands: [
                    'beam_open', 'beam_close', 'beam_title', 'beam_size',
                    'beam_running', 'beam_begin', 'beam_end',
                    'beam_button', 'beam_label', 'beam_text', 'beam_input',
                    'beam_checkbox', 'beam_combo', 'beam_slider',
                    'beam_progress', 'beam_separator', 'beam_spacing', 'beam_image',
                    'beam_row', 'beam_row_end',
                    'beam_group_begin', 'beam_group_end',
                    'beam_panel_begin', 'beam_panel_end',
                    'beam_msgbox', 'beam_confirm',
                    'beam_open_file', 'beam_save_file',
                    'beam_set_color', 'beam_set_style',
                    'beam_time', 'beam_sleep',
                ],

                // Built-in BASIC/yabasic functions
                builtins: [
                    'str', 'val', 'chr', 'asc', 'len', 'mid', 'left', 'right',
                    'instr', 'upper', 'lower', 'trim', 'ltrim', 'rtrim',
                    'space', 'string', 'abs', 'int', 'sqr', 'sin', 'cos',
                    'tan', 'atn', 'exp', 'log', 'rnd', 'max', 'min',
                    'peek', 'poke', 'system',
                ],

                tokenizer: {
                    root: [
                        // Single-quote comment to end of line
                        [/'[^\n]*/, 'comment'],

                        // rem comment
                        [/\brem\b[^\n]*/, 'comment'],

                        // BEAM commands (must come before plain identifier rule)
                        [/\bbeam_[a-z_]+\b/, {
                            cases: {
                                '@beamCommands': 'keyword.beam',
                                '@default':      'identifier'
                            }
                        }],

                        // BASIC keywords (multi-word handled via two passes)
                        [/\bend\s+if\b/i,  'keyword.control'],
                        [/\bend\s+sub\b/i, 'keyword'],
                        [/\b(if|then|else|end|while|wend|for|to|step|next|do|loop|until|goto|gosub|return|sub|print|input|let|dim|data|read|restore|import|export|local|global|break|continue|switch|case|default|on|error|open|close|write)\b/i, 'keyword.control'],

                        // Logical operators as keywords
                        [/\b(and|or|not)\b/i, 'keyword.operator'],

                        // Built-in functions (with optional $ suffix)
                        [/\b(str|val|chr|asc|len|mid|left|right|instr|upper|lower|trim|ltrim|rtrim|space|string|abs|int|sqr|sin|cos|tan|atn|exp|log|rnd|max|min|peek|poke|system)\$?\b/,
                            'support.function'],

                        // Strings
                        [/"([^"\\]|\\.)*"/, 'string'],
                        [/"[^"]*$/,         'string.invalid'],

                        // Numbers: float before integer
                        [/\d+\.\d+([eE][+-]?\d+)?/, 'number.float'],
                        [/\d+([eE][+-]?\d+)?/,       'number'],

                        // Hex literals
                        [/0x[0-9a-fA-F]+/, 'number.hex'],

                        // String variable names (identifier ending with $)
                        [/[a-zA-Z_][a-zA-Z0-9_]*\$/, 'variable.string'],

                        // Regular identifiers
                        [/[a-zA-Z_][a-zA-Z0-9_]*/, 'identifier'],

                        // Operators
                        [/[<>]=?|<>|[+\-*\/^=]/, 'operator'],

                        // Brackets and delimiters
                        [/[()[\]]/, '@brackets'],
                        [/[,;]/, 'delimiter'],

                        // Whitespace
                        [/\s+/, 'white'],
                    ]
                }
            });

            // -----------------------------------------------------------
            // 3. Language configuration
            // -----------------------------------------------------------
            monaco.languages.setLanguageConfiguration('beam', {
                comments: {
                    lineComment: "'",
                },
                brackets: [
                    ['(', ')'],
                    ['[', ']'],
                ],
                autoClosingPairs: [
                    { open: '(', close: ')' },
                    { open: '[', close: ']' },
                    { open: '"', close: '"', notIn: ['string'] },
                ],
                surroundingPairs: [
                    { open: '(', close: ')' },
                    { open: '[', close: ']' },
                    { open: '"', close: '"' },
                ],
                indentationRules: {
                    // Increase indent after if/then, while, for, sub, do
                    increaseIndentPattern: /^\s*(if\b.*then\s*$|while\b|for\b|do\b|sub\b)/i,
                    // Decrease indent on else/end if/wend/next/loop/end sub
                    decreaseIndentPattern: /^\s*(else\b|end\s*if\b|wend\b|next\b|loop\b|end\s*sub\b)/i,
                },
            });

            // -----------------------------------------------------------
            // 4. Hover documentation for beam_* commands
            // -----------------------------------------------------------
            monaco.languages.registerHoverProvider('beam', {
                provideHover(model, position) {
                    const word = model.getWordAtPosition(position);
                    if (!word) return null;

                    // Also grab the character before the word to check for beam_
                    const lineContent = model.getLineContent(position.lineNumber);
                    const start = word.startColumn - 1;
                    // Extract full beam_xxx token (word boundary may split at _)
                    const tokenMatch = lineContent.slice(Math.max(0, start - 10))
                        .match(/beam_[a-z_]+/);
                    const token = tokenMatch
                        ? tokenMatch[0]
                        : word.word;

                    const doc = BEAM_DOCS[token];
                    if (!doc) return null;

                    const lines = doc.split('\n');
                    const sig   = lines[0];
                    const rest  = lines.slice(1).join('\n');

                    return {
                        contents: [
                            { value: '```beam\n' + sig + '\n```' },
                            rest ? { value: rest } : null,
                        ].filter(Boolean),
                    };
                }
            });

            // -----------------------------------------------------------
            // 5. Output bottom panel
            // -----------------------------------------------------------
            outputPanel = api.ui.registerBottomPanel({
                id: 'beam-output',
                title: 'BEAM Output',
                icon: '▶',
            });

            outputEl = document.createElement('pre');
            outputEl.style.cssText = [
                'margin:0', 'padding:8px 12px',
                'font-family:monospace', 'font-size:13px',
                'background:#1a1a1a', 'color:#d0d0d0',
                'height:100%', 'overflow-y:auto',
                'white-space:pre-wrap', 'word-break:break-all',
            ].join(';');

            if (outputPanel.element) {
                outputPanel.element.style.cssText = 'height:100%;overflow:hidden;';
                outputPanel.element.appendChild(outputEl);
            }

            // -----------------------------------------------------------
            // 6. Terminal data listener (set up once at activate time)
            // -----------------------------------------------------------
            if (window.mycode && window.mycode.terminal) {
                window.mycode.terminal.onData((id, data) => {
                    // Only capture after the exec command has been sent;
                    // this skips all fish shell startup noise.
                    if (id === terminalId && capturingOutput) appendOutput(data);
                });

                window.mycode.terminal.onExit((id, exitCode) => {
                    if (id === terminalId) {
                        capturingOutput = false;
                        appendOutput('\n[BEAM] Process exited (code ' + exitCode + ')\n');
                        terminalId = null;
                        setRunning(false);
                    }
                });
            }

            // -----------------------------------------------------------
            // 7. Run command
            // -----------------------------------------------------------
            api.commands.register('beam.run', async () => {
                const filePath = api.workspace.getActiveFilePath();
                if (!filePath) {
                    api.ui.showNotification('BEAM: No file open', 'error', 3000);
                    return;
                }
                if (!filePath.endsWith('.bas') && !filePath.endsWith('.yab')) {
                    api.ui.showNotification(
                        'BEAM: Active file is not a .bas or .yab file', 'warning', 3000);
                    return;
                }

                // Re-check for beam in case it was installed since activation
                if (!beamExePath) {
                    beamExePath = await findBeamExecutable();
                }
                if (!beamExePath) {
                    api.ui.showNotification(
                        'BEAM: beam not found. Run `sudo make install` in the Beam source directory.',
                        'error', 6000);
                    return;
                }

                // Stop any existing run first (non-blocking)
                if (terminalId && window.mycode && window.mycode.terminal) {
                    capturingOutput = false;
                    const oldId = terminalId;
                    terminalId = null;
                    window.mycode.terminal.destroy(oldId).catch(() => {});
                }

                // Save the file before running
                try {
                    const content = api.editor.getContent();
                    await api.workspace.writeFile(filePath, content);
                } catch (e) {
                    api.ui.showNotification('BEAM: Could not save file: ' + e.message, 'error', 4000);
                    return;
                }

                // Determine working directory
                const dir = filePath.replace(/[/\\][^/\\]*$/, '') || '.';

                clearOutput();
                appendOutput('[BEAM] Running: ' + beamExePath + ' ' + filePath + '\n\n');
                outputPanel.show();
                setRunning(true);
                capturingOutput = false;

                if (!window.mycode || !window.mycode.terminal) {
                    api.ui.showNotification('BEAM: Terminal API not available', 'error', 4000);
                    setRunning(false);
                    return;
                }

                try {
                    terminalId = await window.mycode.terminal.create(dir, 120, 30);

                    // Wait for the shell to finish its startup sequence, then use
                    // `exec` to replace the shell process with beam directly.
                    // This means: no shell prompt noise, and when beam exits the
                    // PTY exits cleanly (triggering onExit above).
                    setTimeout(() => {
                        if (!terminalId) return;
                        // Shell-quote the path (single-quotes, escape any embedded single-quotes)
                        const qPath = "'" + beamExePath.replace(/'/g, "'\\''") + "'";
                        const qFile = "'" + filePath.replace(/'/g, "'\\''") + "'";
                        window.mycode.terminal.write(terminalId,
                            'exec ' + qPath + ' ' + qFile + '\n');
                        // Begin capturing beam's own output a moment after sending
                        setTimeout(() => { capturingOutput = true; }, 150);
                    }, 500);
                } catch (e) {
                    appendOutput('[BEAM] Error starting terminal: ' + e.message + '\n');
                    setRunning(false);
                }
            });

            // -----------------------------------------------------------
            // 8. Stop command
            // -----------------------------------------------------------
            api.commands.register('beam.stop', () => {
                if (!terminalId) {
                    api.ui.showNotification('BEAM: No program running', 'info', 2000);
                    return;
                }
                if (!window.mycode || !window.mycode.terminal) return;

                capturingOutput = false;
                appendOutput('\n[BEAM] Stopped.\n');

                // Send Ctrl+C in case beam is reading from stdin, then destroy.
                // Do NOT await destroy — that blocks the renderer and freezes the UI.
                const idToKill = terminalId;
                terminalId = null;
                setRunning(false);

                window.mycode.terminal.write(idToKill, '\x03');
                setTimeout(() => {
                    window.mycode.terminal.destroy(idToKill).catch(() => {});
                }, 200);

                api.ui.showNotification('BEAM: Program stopped', 'info', 2000);
            });

            // -----------------------------------------------------------
            // 9. Status bar items
            // -----------------------------------------------------------
            runStatusItem = api.ui.createStatusBarItem({
                id:       'beam-run',
                text:     '▶ Run BEAM',
                tooltip:  'Run the current BEAM program (beam.run)',
                command:  'beam.run',
                alignment: 'left',
                priority: 50,
            });
            runStatusItem.show();

            stopStatusItem = api.ui.createStatusBarItem({
                id:       'beam-stop',
                text:     '■ Stop',
                tooltip:  'Stop the running BEAM program (beam.stop)',
                command:  'beam.stop',
                alignment: 'left',
                priority: 49,
            });
            // Hidden until a run is active

            // -----------------------------------------------------------
            // 10. Tools menu items
            // -----------------------------------------------------------
            api.menus.registerMenuItem({
                id:      'beam.menu.run',
                label:   'Run BEAM Program',
                command: 'beam.run',
                group:   'tools',
            });
            api.menus.registerMenuItem({
                id:      'beam.menu.stop',
                label:   'Stop BEAM Program',
                command: 'beam.stop',
                group:   'tools',
            });

            // -----------------------------------------------------------
            // 11. Auto-run on save when the file is a .bas file
            //     (disabled by default — uncomment to enable)
            // -----------------------------------------------------------
            // api.hooks.onAfterSave((ctx) => {
            //     if (ctx.language === 'beam') api.commands.execute('beam.run');
            // });

            console.log('[BEAM] Plugin activated — syntax highlighting and Run/Stop ready');
            api.ui.showNotification('BEAM language support activated', 'success', 3000);
        },

        deactivate() {
            console.log('[BEAM] Plugin deactivated');
            capturingOutput = false;
            if (terminalId && window.mycode && window.mycode.terminal) {
                window.mycode.terminal.destroy(terminalId).catch(() => {});
                terminalId = null;
            }
            if (runStatusItem)  { runStatusItem.dispose();  runStatusItem  = null; }
            if (stopStatusItem) { stopStatusItem.dispose(); stopStatusItem = null; }
            if (outputPanel)    { outputPanel.dispose();    outputPanel    = null; }
            outputEl = null;
        }
    };

    // -----------------------------------------------------------------------
    // Register with MyCode plugin loader
    // -----------------------------------------------------------------------
    window.__MYCODE_PLUGINS__ = window.__MYCODE_PLUGINS__ || {};
    window.__MYCODE_PLUGINS__['mycode-beam-language'] = pluginModule;

    const callbackName = '__plugin_mycode_beam_language__';
    if (window[callbackName]) {
        window[callbackName](pluginModule);
    }

})();
