# BEAM — Basic Easy App Maker

## Implementation Specification & AI Agent Prompt Guide

**Version 1.1 | Fragillidae Software**

---

## Table of Contents

1. [Project Overview](#1-project-overview)
2. [Architecture](#2-architecture)
3. [BEAM GUI Command Vocabulary](#3-beam-gui-command-vocabulary)
4. [Example BEAM Programs](#4-example-beam-programs)
5. [Implementation Phases](#5-implementation-phases)
6. [AI Agent Prompts](#6-ai-agent-prompts)
7. [Dependencies & Licensing](#7-dependencies--licensing)
8. [Quick Reference](#8-quick-reference)

---

## 1. Project Overview

BEAM (Basic Easy App Maker) is a cross-platform BASIC programming environment
that allows developers to create native GUI applications for Linux, Windows,
and macOS using a clean, readable BASIC dialect. BEAM extends the yabasic
interpreter with a GUI command layer built on SDL2 and Nuklear, delivering
immediate-mode windowed applications without requiring a visual designer or
specialized IDE.

### 1.1 Design Philosophy

- Code-first, no visual designer required — any text editor works
- Edit in your editor, run from the command line or a run-button plugin
- Cross-platform from day one: Linux, Windows, macOS (Intel)
- Minimal dependencies — SDL2 + Nuklear are vendored or easily installed
- BASIC syntax stays familiar — yabasic core is unchanged
- GUI commands are additive — all existing yabasic programs still run

### 1.2 Key Components

| Component | Description |
|---|---|
| **BEAM Interpreter** | Extended yabasic binary with GUI built-ins compiled in |
| **SDL2** | Cross-platform window and event management |
| **Nuklear** | Single-header immediate-mode GUI toolkit (vendored in repo) |
| **beam_gui.h/c** | Abstraction layer between BASIC commands and Nuklear/SDL2 |
| **beam_commands.c** | BASIC built-in command handlers |
| **MyCode Plugin** | Syntax highlighting + run/stop for MyCode editor |

### 1.3 What BEAM Is NOT

- Not a fork of yabasic — it is a new product using yabasic source as its foundation
- Not a visual GUI designer — layout is defined in BASIC code
- Not tied to any specific IDE — works with any editor including MyCode

---

## 2. Architecture

### 2.1 System Diagram

```
  myscript.bas  (plain text, any editor)
       |
    beam  (extended yabasic binary)
    |          |
  BASIC     beam_gui.c  (GUI abstraction)
  runtime        |
            SDL2 + Nuklear
                 |
    Linux / Windows / macOS (native window)
```

### 2.2 Real Tarball Structure — Ground Truth

> **IMPORTANT:** The tarball structure is completely flat. There is NO `unix/`
> subdirectory. All C sources live directly in the root of the extracted
> directory. Previous documentation referring to `unix/lang/` was wrong and
> should be ignored entirely.

After extracting `yabasic-2.91.4.tar.gz`, the directory contains many files of which you will be mostyl be workig with the following:

```
yabasic-2.91.4/
├── main.c            <- interpreter entry point
├── function.c        <- built-in functions  ← YOU WILL EDIT THIS
├── flow.c            <- control flow
├── io.c              <- input/output
├── graphic.c         <- existing graphics commands
├── symbol.c          <- symbol table
├── foreign.c         <- foreign function interface
├── flex.c            <- lexer (PRE-GENERATED — do not regenerate)
├── bison.c           <- parser (PRE-GENERATED — do not regenerate)
├── bison.h           <- parser header
├── yabasic.h         <- main header
├── yabasic.flex      <- original flex source (reference only)
├── yabasic.bison     <- original bison source (reference only)
├── Makefile.am       <- build definition  ← YOU WILL EDIT THIS
├── Makefile.in       <- generated from Makefile.am
├── configure         <- ALREADY PRESENT — just run it
├── configure.ac      <- autoconf source  ← YOU WILL EDIT THIS
├── demo.yab          <- example yabasic program
└── tests/            <- yabasic test suite
```

### 2.3 Key Insight: flex.c and bison.c

The tarball ships **pre-generated** C files from the flex and bison sources.
This means:

- `flex.c` is the generated lexer — already valid C, ready to compile
- `bison.c` is the generated parser — already valid C, ready to compile
- `yabasic.flex` and `yabasic.bison` are the human-readable sources

**For BEAM you edit `flex.c` and `bison.c` directly** to add new keywords and
grammar rules. You do NOT need to install flex or bison, and you do NOT need
to regenerate these files. The `yabasic.flex` and `yabasic.bison` files are
reference material so you can understand the patterns — but your edits go
into the `.c` files.

### 2.4 BEAM Project Structure

This is what your BEAM project looks like after setup — the yabasic files
remain in place and you add your new `beam/` directory alongside them:

```
BEAM/                       <- renamed from yabasic-2.91.4/
├── main.c
├── function.c              <- add BEAM function registrations here
├── flow.c
├── io.c
├── graphic.c
├── symbol.c
├── foreign.c
├── flex.c                  <- add BEAM keyword tokens here
├── bison.c                 <- add BEAM grammar rules here
├── bison.h
├── yabasic.h
├── yabasic.flex            <- reference only
├── yabasic.bison           <- reference only
├── Makefile.am             <- update to add beam/ sources + SDL2
├── configure.ac            <- update to detect SDL2
├── configure               <- already present, re-run after edits
├── beam/                   <- CREATE THIS — all your new code
│   ├── nuklear.h           <- vendored single-header, unmodified
│   ├── beam_gui.h          <- GUI abstraction header
│   ├── beam_gui.c          <- SDL2 + Nuklear implementation
│   └── beam_commands.c     <- BASIC command handlers
├── examples/               <- CREATE THIS — .bas sample programs
└── docs/                   <- CREATE THIS — language reference
```

### 2.5 Build System

The tarball already contains a working `configure` script — no need for
`autoconf`, `automake`, or `autoreconf`. The normal build is simply:

```bash
./configure && make
```

You will need to edit `Makefile.am` and `configure.ac` to add SDL2 support
and your new source files, then re-run `./configure && make`.

> **NOTE:** `configure` is pre-built and present in the tarball. This is
> different from the GitHub repo which does NOT ship `configure`. Always
> start from the tarball, not a GitHub clone.

---

## 3. BEAM GUI Command Vocabulary

All commands follow yabasic naming conventions. GUI state is managed through
integer handles returned by creation functions.

### 3.1 Window Management

| Command | Description |
|---|---|
| `win = beam_open(w, h, title$)` | Open a window, returns handle. Must be called before any widgets. |
| `beam_close(win)` | Close window and free resources. |
| `beam_title(win, title$)` | Update window title at runtime. |
| `beam_size(win, w, h)` | Resize window programmatically. |
| `running = beam_running(win)` | Returns 1 if window is open, 0 if closed. Use in main loop. |
| `beam_begin(win)` | Begin a new frame. Call once per loop before widgets. |
| `beam_end(win)` | End frame and render. Call once per loop after all widgets. |

### 3.2 Widget Commands

| Command | Description / Returns |
|---|---|
| `clicked = beam_button(label$, w, h)` | Render a button. Returns 1 if clicked this frame. |
| `beam_label(text$)` | Render a static text label. |
| `beam_text(text$, w, h)` | Render a multi-line text block with wrap. |
| `changed = beam_input(buf$, maxlen, w)` | Single-line text input. Returns 1 if changed. |
| `beam_checkbox(label$, checked)` | Checkbox. Returns 1 if checked. |
| `idx = beam_combo(items$, count, sel, w, h)` | Dropdown. `items$` is newline-delimited. Returns selected index. |
| `beam_slider(val, min, max, step, w)` | Horizontal slider. Returns current value. |
| `beam_progress(val, max, w, h)` | Progress bar. No return value. |
| `beam_separator()` | Horizontal dividing line. |
| `beam_spacing(px)` | Add vertical space in pixels. |
| `beam_image(path$, w, h)` | Display image from file path. |

### 3.3 Layout Commands

| Command | Description |
|---|---|
| `beam_row(h, cols)` | Begin a row layout: h=height in px, cols=number of columns. |
| `beam_row_end()` | End current row layout, return to vertical flow. |
| `beam_group_begin(title$)` | Begin a named group box. |
| `beam_group_end()` | End current group box. |
| `beam_panel_begin(title$, w, h)` | Scrollable panel. |
| `beam_panel_end()` | End current panel. |

### 3.4 Dialogs & System

| Command | Description / Returns |
|---|---|
| `r = beam_msgbox(title$, msg$)` | Modal message box. Returns 1 when dismissed. |
| `r = beam_confirm(title$, msg$)` | Yes/No dialog. Returns 1=Yes, 0=No. |
| `f$ = beam_open_file(filter$)` | File open dialog. Returns path or empty string. |
| `f$ = beam_save_file(filter$)` | File save dialog. Returns path or empty string. |
| `beam_set_color(r, g, b)` | Set foreground color (0-255 each). |
| `beam_set_style(name$)` | Set Nuklear theme: `"dark"`, `"white"`, `"amber"`. |
| `t = beam_time()` | Returns elapsed milliseconds since start. |
| `beam_sleep(ms)` | Pause execution for ms milliseconds. |

---

## 4. Example BEAM Programs

### 4.1 Hello World Window

```basic
' BEAM Hello World
win = beam_open(400, 200, "Hello BEAM")

while beam_running(win)
  beam_begin(win)
    beam_label("Hello, World!")
    beam_spacing(10)
    if beam_button("Close", 80, 30) then
      beam_close(win)
    end if
  beam_end(win)
wend
```

### 4.2 Simple Form with Input

```basic
' BEAM Input Form Example
win = beam_open(500, 300, "User Info")
name$ = ""
result$ = ""

while beam_running(win)
  beam_begin(win)
    beam_group_begin("Enter Details")
      beam_label("Your name:")
      beam_row(30, 1)
        if beam_input(name$, 64, 300) then
          result$ = "Hello, " + name$ + "!"
        end if
      beam_row_end()
      beam_spacing(8)
      if beam_button("Submit", 100, 30) then
        r = beam_msgbox("Result", result$)
      end if
    beam_group_end()
  beam_end(win)
wend
```

### 4.3 Multi-Column Layout

```basic
' BEAM Two-Column Layout
win = beam_open(600, 400, "Settings")
vol = 50
dark_mode = 0

while beam_running(win)
  beam_begin(win)
    beam_row(200, 2)
      beam_group_begin("Audio")
        beam_label("Volume")
        vol = beam_slider(vol, 0, 100, 1, 180)
        beam_label("Level: " + str$(vol))
      beam_group_end()
      beam_group_begin("Display")
        dark_mode = beam_checkbox("Dark Mode", dark_mode)
        if beam_button("Apply", 80, 28) then
          if dark_mode then
            beam_set_style("dark")
          else
            beam_set_style("white")
          end if
        end if
      beam_group_end()
    beam_row_end()
  beam_end(win)
wend
```

---

## 5. Implementation Phases

### Phase 1 — Project Setup & Baseline Build

1. Download `yabasic-2.91.4.tar.gz` from www.yabasic.de
2. Extract: `tar -xzf yabasic-2.91.4.tar.gz`
3. Rename: `mv yabasic-2.91.4 BEAM`
4. `cd BEAM`
5. Build the baseline: `./configure && make`
6. Verify: `./yabasic --version`
7. Install SDL2: `sudo apt install libsdl2-dev libsdl2-ttf-dev`
8. Create project directories: `mkdir beam examples docs`
9. Get nuklear.h (see Section 8.3) and place at `beam/nuklear.h`
10. Create stub files: `beam/beam_gui.h`, `beam/beam_gui.c`, `beam/beam_commands.c`
11. Initialize git: `git init && git add . && git commit -m "v0.0-yabasic-baseline"`
12. Push to private GitHub repo: `git remote add origin https://github.com/CFFinch62/BEAM.git && git push -u origin master`
13. Create dev branch: `git checkout -b dev`

**Done when:** `./yabasic --version` works and all files are committed to the
private GitHub repo on the `dev` branch.

---

### Phase 2 — Keyword Pipeline Proof of Concept

1. Open `flex.c` — find where existing keywords like `"print"` are defined
   and add a `"beam_open"` entry following the same pattern
2. Open `bison.c` — find where `%token` declarations appear and add
   `BEAM_OPEN`; add a stub grammar rule
3. Create `beam/beam_commands.c` stub that prints `"BEAM STUB: beam_open"`
4. Edit `Makefile.am` — add `beam/beam_gui.c beam/beam_commands.c` to
   `yabasic_SOURCES`
5. Edit `configure.ac` — add SDL2 detection via `PKG_CHECK_MODULES`
6. Re-run: `./configure && make`
7. Test: run a `.bas` file containing `beam_open` — confirm stub message prints
8. Change the output binary name from `yabasic` to `beam` in `Makefile.am`

**Done when:** Running `beam test.bas` with `beam_open` prints the stub
message without errors.

---

### Phase 3 — Core GUI Implementation

1. Implement `beam/beam_gui.c`: SDL2 init, Nuklear init, window creation,
   frame loop
2. Implement window management commands: `beam_open`, `beam_close`,
   `beam_running`, `beam_begin`, `beam_end`
3. Wire all Widget commands (Section 3.2) through to Nuklear
4. Wire all Layout commands (Section 3.3) through to Nuklear
5. Connect `beam/beam_commands.c` handlers to real `beam_gui` functions
6. Test each command against the example programs in Section 4

**Done when:** All three example programs in Section 4 run correctly on Linux.

---

### Phase 4 — Dialogs, Polish & Cross-Platform

1. Implement Dialog commands (Section 3.4)
2. Implement `beam_set_style` themes: dark / white / amber
3. Test and fix on Windows
4. Test and fix on macOS Intel (2014 iMac)
5. Create install/packaging scripts for each platform
6. Write `beam_test_suite.bas` covering all commands

**Done when:** `beam_test_suite.bas` passes on Linux, Windows, and macOS Intel.

---

### Phase 5 — MyCode Plugin & Documentation

1. Write `BEAM.lang` syntax definition for MyCode
2. Implement Run plugin: shell out to `beam %file%`
3. Implement Stop plugin: kill beam process
4. Write BEAM Language Reference in `docs/`
5. Write 10+ example programs in `examples/`
6. Tag `v1.0.0` and make repo public

**Done when:** A `.bas` file can be edited in MyCode, syntax-highlighted,
and run with a single button press.

---

## 6. AI Agent Prompts

Each prompt is self-contained. Attach the listed files when submitting.

---

### Phase 1 Prompts

#### P1-A: Create Stub Files

```
I am building BEAM (Basic Easy App Maker), a cross-platform BASIC interpreter
with GUI support built on SDL2 and Nuklear. It is based on yabasic 2.91.4.

IMPORTANT structural facts about this codebase:
- All source files are FLAT in the project root — there is no unix/ subdirectory
- The lexer is flex.c (pre-generated C — edit directly, do not regenerate)
- The parser is bison.c (pre-generated C — edit directly, do not regenerate)
- yabasic.flex and yabasic.bison are reference sources only
- My new BEAM-specific files go in a beam/ subdirectory

Task: Create three stub files in the beam/ directory:
  1. beam/beam_gui.h       - declares all beam_gui_* C functions (stubs only)
  2. beam/beam_gui.c       - stub implementations that printf their name and return 0
  3. beam/beam_commands.c  - stub BASIC command handlers that printf their name

Use the complete BEAM GUI vocabulary from the specification. No real
functionality yet — stubs only that prove the pipeline.

[ATTACH: yabasic.h, function.c, BEAM specification]
```

---

### Phase 2 Prompts

#### P2-A: Lexer Keyword Registration

```
I am building BEAM (Basic Easy App Maker), extending yabasic 2.91.4.

CRITICAL: The lexer file is flex.c — a pre-generated C file that I edit
directly. There is no lex.l file. The original flex source is yabasic.flex
and is provided for pattern reference only.

Attached are:
  - flex.c         (the pre-generated lexer I will edit)
  - yabasic.flex   (reference: original flex source showing patterns)
  - bison.h        (token definitions)

Task: Show me exactly where and how to add the beam_* keyword tokens to
flex.c. Find where existing keywords like "print" or "if" are registered
and add ALL beam_* commands from the specification following the exact
same pattern. Provide the specific lines to add and where to insert them.

[ATTACH: flex.c, yabasic.flex, bison.h, BEAM specification]
```

#### P2-B: Parser Grammar Rules

```
I am building BEAM (Basic Easy App Maker), extending yabasic 2.91.4.

CRITICAL: The parser file is bison.c — a pre-generated C file that I edit
directly. There is no yabasic.y file. The original bison source is
yabasic.bison and is provided for pattern reference only.

Attached are:
  - bison.c        (the pre-generated parser I will edit)
  - yabasic.bison  (reference: original bison source showing patterns)
  - bison.h        (current token definitions — I will add BEAM tokens here)

Task:
  1. Show me where to add BEAM_* token declarations in bison.h
  2. Show me where and how to add grammar rules for all beam_* commands
     in bison.c, following the exact patterns used for existing commands
  3. Each grammar rule should call the corresponding stub handler in
     beam/beam_commands.c

[ATTACH: bison.c, yabasic.bison, bison.h, beam/beam_commands.c, BEAM specification]
```

#### P2-C: Makefile & Configure Updates

```
I am building BEAM (Basic Easy App Maker), extending yabasic 2.91.4.

All source files are flat in the project root. My new files are in beam/.
The build system uses autoconf/automake. configure is already present
in the tarball — I do NOT need to run autoreconf.

Attached are:
  - Makefile.am
  - configure.ac

Task:
  1. Add SDL2 detection to configure.ac using PKG_CHECK_MODULES
  2. Add SDL2_ttf detection similarly
  3. Add beam/beam_gui.c and beam/beam_commands.c to yabasic_SOURCES
     in Makefile.am
  4. Link SDL2 and SDL2_ttf into the final binary via LDADD
  5. Rename the output binary from yabasic to beam in Makefile.am
     (change bin_PROGRAMS = yabasic to bin_PROGRAMS = beam)
  6. Add -DBEAM_VERSION=\"1.0.0\" to AM_CPPFLAGS

Show the complete modified Makefile.am and the modified sections of
configure.ac.

[ATTACH: Makefile.am, configure.ac]
```

---

### Phase 3 Prompts

#### P3-A: Core GUI Layer — Window Management

```
I am building BEAM (Basic Easy App Maker). Stub commands are registered
and the project builds. Now I need the real GUI implementation.

Project structure facts:
  - All yabasic sources are flat in the project root
  - My GUI code lives in beam/beam_gui.h and beam/beam_gui.c
  - Nuklear is at beam/nuklear.h

Task: Implement Window Management in beam/beam_gui.c:
  - beam_gui_init()
  - beam_gui_open(w, h, title)   -> returns int handle
  - beam_gui_close(handle)
  - beam_gui_running(handle)     -> returns 1 if open, 0 if closed
  - beam_gui_begin(handle)
  - beam_gui_end(handle)

Use SDL2 + Nuklear. Define all NK_INCLUDE_* and NK_IMPLEMENTATION
macros in beam_gui.c before including nuklear.h (never in the header).
Support up to 8 simultaneous windows via a static array of structs.

[ATTACH: beam/beam_gui.h, beam/beam_gui.c, beam/nuklear.h]
```

#### P3-B: Widget Implementation

```
I am building BEAM (Basic Easy App Maker). Window management works.

Task: Implement all widget functions in beam/beam_gui.c:
  beam_gui_button(handle, label, w, h)         -> int (1 if clicked)
  beam_gui_label(handle, text)                 -> void
  beam_gui_text(handle, text, w, h)            -> void
  beam_gui_input(handle, buf, maxlen, w)       -> int (1 if changed)
  beam_gui_checkbox(handle, label, *val)       -> int (checked state)
  beam_gui_combo(handle, items, count, *sel, w, h) -> int (selected index)
  beam_gui_slider(handle, *val, min, max, step, w) -> double (current val)
  beam_gui_progress(handle, val, max, w, h)    -> void
  beam_gui_separator(handle)                   -> void
  beam_gui_spacing(handle, px)                 -> void

Map each to its corresponding nk_* Nuklear call.

[ATTACH: beam/beam_gui.h, beam/beam_gui.c]
```

#### P3-C: Layout Implementation

```
I am building BEAM (Basic Easy App Maker). Widgets work.

Task: Implement layout functions in beam/beam_gui.c:
  beam_gui_row(handle, h, cols)        -> nk_layout_row_dynamic
  beam_gui_row_end(handle)             -> reset to single-column flow
  beam_gui_group_begin(handle, title)  -> nk_group_begin
  beam_gui_group_end(handle)           -> nk_group_end
  beam_gui_panel_begin(handle, title, w, h)  -> nk_window_begin (child)
  beam_gui_panel_end(handle)           -> nk_window_end

beam_gui_row_end should reset to nk_layout_row_dynamic with 1 column
at 30px default height. Track the reset state in the window struct.

[ATTACH: beam/beam_gui.h, beam/beam_gui.c]
```

#### P3-D: Connect Commands to GUI Layer

```
I am building BEAM (Basic Easy App Maker). beam_gui.c is complete.
Now I need to wire the BASIC command handlers to the real C functions.

IMPORTANT: Study how existing yabasic commands pop arguments from the
stack in function.c and flow.c — BEAM command handlers must follow
the exact same stack argument pattern.

Task: Replace all stubs in beam/beam_commands.c with real implementations:
  1. Pop arguments from the yabasic stack in correct order and type
  2. Call the corresponding beam_gui_* function
  3. Push return value back onto the stack where applicable

[ATTACH: beam/beam_commands.c, beam/beam_gui.h, function.c, flow.c]
```

---

### Phase 4 Prompts

#### P4-A: Dialog Commands

```
I am building BEAM (Basic Easy App Maker). Core widgets and layout work.

Task: Implement in beam/beam_gui.c:
  beam_gui_msgbox(handle, title, msg)      -> int (1 on dismiss)
  beam_gui_confirm(handle, title, msg)     -> int (1=Yes, 0=No)
  beam_gui_open_file(handle, filter)       -> char* (path or "")
  beam_gui_save_file(handle, filter)       -> char* (path or "")
  beam_gui_set_style(handle, name)         -> void ("dark","white","amber")
  beam_gui_set_color(handle, r, g, b)      -> void
  beam_gui_time()                          -> double (milliseconds)
  beam_gui_sleep(ms)                       -> void

For file dialogs use tinyfiledialogs (vendor beam/tinyfiledialogs.h and
beam/tinyfiledialogs.c from https://sourceforge.net/projects/tinyfiledialogs).
For amber theme use Fragillidae brand color #D97706.

[ATTACH: beam/beam_gui.h, beam/beam_gui.c]
```

#### P4-B: Cross-Platform Windows Build

```
I am building BEAM (Basic Easy App Maker) based on yabasic 2.91.4.
I need to build on Windows.

Project facts:
  - All sources are flat in the project root
  - My additions are in beam/ subdirectory
  - New source files: beam/beam_gui.c, beam/beam_commands.c
  - Binary should be named beam.exe
  - Requires SDL2 linking

The yabasic README says Windows builds use Visual Studio 2019.

Task:
  1. What changes are needed to support BEAM's new files on Windows?
  2. How do I obtain SDL2 dev libraries for Windows (VC version)?
  3. What project file or build script changes are needed?
  4. Are there any beam_gui.c code changes needed for Windows
     (e.g. SDL2 main() handling, path separators)?

[ATTACH: Makefile.am, configure.ac, beam/beam_gui.h]
```

---

### Phase 5 Prompts

#### P5-A: MyCode Syntax Plugin

```
I am building a syntax highlighting plugin for BEAM in the MyCode editor
(https://github.com/CFFinch62/MyCode).

BEAM is a BASIC dialect with these token types:
  Keywords:     if, then, else, end if, while, wend, for, to, step, next,
                goto, gosub, return, sub, end sub, print, input, let, dim,
                and, or, not, rem, data, read, restore, end, import, export
  BEAM commands: all beam_* functions (full list in specification)
  Strings:      double-quoted, e.g. "hello"
  Comments:     rem keyword OR single quote (') to end of line
  Numbers:      integer and float literals
  Variables:    identifiers; string variables end with $ e.g. name$
  Line numbers: optional integer at start of line (legacy BASIC style)
  Operators:    + - * / ^ = < > <= >= <> ( )

Task: Review the MyCode repo structure and existing language plugin files
to determine the exact format required, then produce all necessary plugin
files for BEAM syntax highlighting.

[ATTACH: BEAM specification, examples from MyCode repo showing plugin format]
```

#### P5-B: MyCode Run/Stop Plugin

```
I am building a Run/Stop plugin for BEAM in the MyCode editor.

Behavior required:
  Run:  1. Save current file if modified
        2. Execute: beam <current_file_path>
        3. Show stdout/stderr in output panel
        4. Track the process PID for Stop

  Stop: 1. Send SIGTERM on Linux/macOS or TerminateProcess on Windows
        2. Update output panel status

The beam binary will be on PATH after installation.

Task: Review the MyCode repo plugin API and produce the Run/Stop plugin
files for BEAM.

[ATTACH: MyCode run plugin examples from repo]
```

#### P5-C: Example Programs Suite

```
I am building BEAM (Basic Easy App Maker). Write 10 complete example programs:

  1.  hello.bas         - hello world window with close button
  2.  calculator.bas    - 4-function calculator
  3.  form.bas          - contact form with name, email, message, submit
  4.  settings.bas      - checkboxes, sliders, combo box
  5.  file_viewer.bas   - open file dialog, display text file in panel
  6.  progress.bas      - animated progress bar with start/stop
  7.  color_picker.bas  - RGB sliders with color preview label
  8.  todo.bas          - add/remove list items with an array
  9.  two_windows.bas   - two simultaneous windows
  10. style_demo.bas    - switch between dark/white/amber themes

Each program must be complete, runnable, well-commented, and use only
commands from the official BEAM vocabulary (Section 3 of spec).

[ATTACH: BEAM specification Section 3]
```

---

## 7. Dependencies & Licensing

| Component | License | Notes |
|---|---|---|
| yabasic 2.91.4 | MIT | Retain original copyright in LICENSE file |
| SDL2 | zlib | Dynamic link preferred |
| SDL2_ttf | zlib | Only if custom font rendering added |
| Nuklear | MIT or Public Domain | Single header — vendor unmodified |
| tinyfiledialogs | zlib | For file dialogs — vendor both .h and .c |
| BEAM itself | MIT | Fragillidae Software, Chuck Finch |

> Add a `CREDITS.md` acknowledging Marc-Oliver Ihm as the original yabasic
> author. The MIT license requires the original copyright notice be preserved.

---

## 8. Quick Reference

### 8.1 Build Commands (Linux)

```bash
# Install dependencies
sudo apt install build-essential libsdl2-dev libsdl2-ttf-dev

# Extract and set up
tar -xzf yabasic-2.91.4.tar.gz
mv yabasic-2.91.4 BEAM
cd BEAM

# Baseline build (verify before making any changes)
./configure && make
./yabasic --version

# After editing Makefile.am and configure.ac
./configure && make
./beam --version
```

### 8.2 Running a BEAM Program

```bash
./beam myscript.bas
./beam examples/hello.bas
```

### 8.3 Getting nuklear.h

Nuklear is a single-file header. Download it from:

```
https://github.com/Immediate-Mode-UI/Nuklear/blob/master/nuklear.h
```

Click **Raw**, then save the file as `beam/nuklear.h`. Do not modify it.

### 8.4 Key Files to Edit When Adding a New Command

| File | What to add |
|---|---|
| `flex.c` | Keyword token rule (find existing keywords for pattern) |
| `bison.h` | `%token BEAM_NEWCOMMAND` declaration |
| `bison.c` | Grammar rule that calls the handler |
| `beam/beam_commands.c` | Command handler (pop args, call beam_gui, push result) |
| `beam/beam_gui.h` | C function declaration |
| `beam/beam_gui.c` | C function implementation using Nuklear/SDL2 |

### 8.5 Nuklear Mandatory Frame Pattern

Every BEAM program **must** follow this structure. Nuklear requires a
begin/end pair on every render cycle — widget calls outside this pair
will crash:

```basic
win = beam_open(w, h, title$)
while beam_running(win)     ' polls SDL events, returns 0 when closed
  beam_begin(win)           ' REQUIRED: start Nuklear frame
    ' all widget calls go here
  beam_end(win)             ' REQUIRED: render and present frame
wend
```

### 8.6 Git Branch Strategy

```bash
master   <- stable tagged releases only
dev      <- all active development

git checkout -b dev    # do all work here
git push origin dev
```

Merge to `master` only when a phase is complete and tested.

---

*BEAM — Basic Easy App Maker | Fragillidae Software*
