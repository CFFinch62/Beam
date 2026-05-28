# BEAM Language Reference

**Version 1.0 | Fragillidae Software**

---

## Table of Contents

1. [Overview](#1-overview)
2. [Program Structure](#2-program-structure)
3. [Data Types & Variables](#3-data-types--variables)
4. [Operators](#4-operators)
5. [Control Flow](#5-control-flow)
6. [Subroutines & Functions](#6-subroutines--functions)
7. [Built-in yabasic Functions](#7-built-in-yabasic-functions)
8. [BEAM GUI Commands — Window Management](#8-beam-gui-commands--window-management)
9. [BEAM GUI Commands — Widgets](#9-beam-gui-commands--widgets)
10. [BEAM GUI Commands — Layout](#10-beam-gui-commands--layout)
11. [BEAM GUI Commands — Dialogs & System](#11-beam-gui-commands--dialogs--system)
12. [The Frame Loop Pattern](#12-the-frame-loop-pattern)
13. [File I/O](#13-file-io)
14. [Error Handling Notes](#14-error-handling-notes)
15. [Command Quick Reference](#15-command-quick-reference)

---

## 1. Overview

BEAM (Basic Easy App Maker) is a BASIC programming environment for building
native GUI applications on Linux, Windows, and macOS. It extends the
[yabasic](http://www.yabasic.de) interpreter with GUI commands built on
SDL2 and Nuklear.

- Any plain-text editor can be used to write `.bas` source files.
- Run a program: `beam myscript.bas`
- All existing yabasic programs continue to run unmodified under BEAM.
- GUI commands are purely additive — a program with no `beam_*` calls is a
  normal terminal yabasic program.

---

## 2. Program Structure

```basic
' This is a comment (single quote)
rem This is also a comment (rem keyword)

' Variable assignment
x = 42
name$ = "Alice"

' Subroutine definition
sub greet(who$)
  print "Hello, " + who$
end sub

' Main code
greet(name$)
```

- Statements are separated by newlines (one statement per line).
- There is no mandatory `MAIN` block — execution starts at the first line.
- Line numbers are optional and ignored by the interpreter.
- String variables always end with `$`. All other variables are numeric.

---

## 3. Data Types & Variables

BEAM (via yabasic) has two data types: **numeric** and **string**.

| Type | Example | Notes |
|---|---|---|
| Numeric | `x = 3.14` | Double-precision floating point |
| String | `s$ = "hello"` | Must end with `$` |

### Arrays

```basic
dim scores(10)          ' numeric array, indices 0-9
dim names$(20)          ' string array, indices 0-19
scores(0) = 100
names$(0) = "Alice"
```

Arrays are zero-indexed. Declare with `dim` before use.

### Constants

yabasic has no `const` keyword. Use plain variables by convention:

```basic
MAX_ITEMS = 50
```

---

## 4. Operators

### Arithmetic

| Operator | Meaning |
|---|---|
| `+` | Addition (also string concatenation) |
| `-` | Subtraction |
| `*` | Multiplication |
| `/` | Division |
| `^` | Exponentiation |
| `mod` | Modulo (integer remainder) |

### Comparison

| Operator | Meaning |
|---|---|
| `=` | Equal |
| `<>` | Not equal |
| `<` | Less than |
| `>` | Greater than |
| `<=` | Less than or equal |
| `>=` | Greater than or equal |

### Logical

| Operator | Meaning |
|---|---|
| `and` | Logical AND |
| `or` | Logical OR |
| `not` | Logical NOT |

### String Concatenation

```basic
full$ = first$ + " " + last$
```

---

## 5. Control Flow

### if / elseif / else / end if

```basic
if x > 0 then
  print "positive"
elseif x < 0 then
  print "negative"
else
  print "zero"
end if
```

> **Important:** Inside a multi-line `if`/`end if` block, do not write
> `if condition then action` on a single line — always use the multi-line form.
> Single-line `if` is only safe at the top level.

### while / wend

```basic
i = 0
while i < 10
  print i
  i = i + 1
wend
```

### for / to / step / next

```basic
for i = 1 to 10
  print i
next i

for i = 10 to 1 step -1
  print i
next i
```

### goto / gosub / return

```basic
goto my_label

label my_label
print "jumped here"

gosub my_subroutine
end

label my_subroutine
print "in subroutine"
return
```

> Prefer `sub`/`end sub` over `gosub` for new code.

### switch / case (yabasic extension)

```basic
switch x
  case 1
    print "one"
  case 2
    print "two"
  default
    print "other"
end switch
```

---

## 6. Subroutines & Functions

### sub (no return value)

```basic
sub print_line(text$)
  print text$
end sub

print_line("Hello")
```

### sub (with return value via function name)

```basic
sub square(n)
  square = n * n
end sub

result = square(5)   ' result = 25
```

To return a string, assign to the sub name with `$`:

```basic
sub shout$(text$)
  shout$ = upper$(text$) + "!"
end sub
```

### Local variables

Variables in yabasic are global by default. To create a local variable
inside a sub, declare it with `local`:

```basic
sub add(a, b)
  local result
  result = a + b
  add = result
end sub
```

### Recursive calls

yabasic supports recursion. Each call gets its own `local` variable stack.

---

## 7. Built-in yabasic Functions

### String Functions

| Function | Description |
|---|---|
| `len(s$)` | Length of string |
| `left$(s$, n)` | First n characters |
| `right$(s$, n)` | Last n characters |
| `mid$(s$, start, len)` | Substring (1-based) |
| `upper$(s$)` | Convert to uppercase |
| `lower$(s$)` | Convert to lowercase |
| `ltrim$(s$)` | Remove leading whitespace |
| `rtrim$(s$)` | Remove trailing whitespace |
| `trim$(s$)` | Remove leading and trailing whitespace |
| `instr(s$, find$)` | Position of find$ in s$ (0 if not found) |
| `str$(n)` | Convert number to string |
| `val(s$)` | Convert string to number |
| `chr$(n)` | Character from ASCII code |
| `asc(s$)` | ASCII code of first character |

### Math Functions

| Function | Description |
|---|---|
| `abs(x)` | Absolute value |
| `int(x)` | Truncate to integer |
| `sqrt(x)` | Square root |
| `sin(x)` | Sine (radians) |
| `cos(x)` | Cosine (radians) |
| `tan(x)` | Tangent (radians) |
| `log(x)` | Natural logarithm |
| `exp(x)` | e^x |
| `mod(a, b)` | Integer modulo |
| `max(a, b)` | Larger of two values |
| `min(a, b)` | Smaller of two values |
| `ran(n)` | Random integer 0 to n-1 |

### I/O

| Statement | Description |
|---|---|
| `print expr` | Print to stdout |
| `print expr;` | Print without newline |
| `input var` | Read from stdin |
| `input "prompt: ", var` | Read with prompt |

---

## 8. BEAM GUI Commands — Window Management

All GUI programs must call `beam_open` before any widget or layout command.
The returned handle is passed to `beam_begin` and `beam_end` each frame.

| Command | Returns | Description |
|---|---|---|
| `win = beam_open(w, h, title$)` | handle | Open a window of size w×h with the given title. |
| `beam_close(win)` | — | Close the window and free resources. |
| `beam_title(win, title$)` | — | Update the window title at runtime. |
| `beam_size(win, w, h)` | — | Resize the window programmatically. |
| `running = beam_running(win)` | 0 or 1 | Returns 1 while the window is open; 0 after it is closed or the user clicks the OS close button. Use as the main loop condition. |
| `beam_begin(win)` | — | Begin a new Nuklear frame. **Must** be called once per loop iteration before any widget calls. |
| `beam_end(win)` | — | End the frame and render it to screen. **Must** be called once per loop iteration after all widget calls. |

### Multiple Windows

Up to 8 windows may be open simultaneously. Each call to `beam_open` returns
a unique handle. Test each handle independently with `beam_running`:

```basic
while beam_running(win1) or beam_running(win2)
  if beam_running(win1) then
    beam_begin(win1)
      ' ... widgets for win1 ...
    beam_end(win1)
  end if
  if beam_running(win2) then
    beam_begin(win2)
      ' ... widgets for win2 ...
    beam_end(win2)
  end if
wend
```

---

## 9. BEAM GUI Commands — Widgets

Widget commands must be placed **between** `beam_begin` and `beam_end`.

| Command | Returns | Description |
|---|---|---|
| `clicked = beam_button(label$, w, h)` | 0 or 1 | Render a button. Returns 1 on the frame it is clicked. |
| `beam_label(text$)` | — | Render a single-line static text label. |
| `beam_text(text$, w, h)` | — | Render multi-line text with word-wrap inside w×h pixels. |
| `changed = beam_input(buf$, maxlen, w)` | 0 or 1 | Single-line text input field of width w. `buf$` is read and written. Returns 1 if the content changed this frame. |
| `checked = beam_checkbox(label$, val)` | 0 or 1 | Checkbox. `val` is the current state (0=off, 1=on). Returns the new state. |
| `idx = beam_combo(items$, count, sel, w, h)` | integer | Dropdown list. `items$` is newline-delimited (`\n`). `count` is the number of items. `sel` is the current selection index. Returns the selected index. |
| `val = beam_slider(val, min, max, step, w)` | number | Horizontal slider. Returns the current value. |
| `beam_progress(val, max, w, h)` | — | Progress bar. No return value. |
| `beam_separator()` | — | Draw a horizontal dividing line. |
| `beam_spacing(px)` | — | Insert vertical blank space of px pixels. |
| `beam_image(path$, w, h)` | — | Display an image from a file path at w×h pixels. |

### Widget notes

**beam_button**: The `##` suffix idiom allows multiple buttons with the same
visible label but different internal IDs (Nuklear requires unique widget IDs):

```basic
if beam_button("Delete##" + str$(i), 70, 24) then
  remove_item(i)
end if
```

**beam_input**: Always assign the return value back to the same variable and
also capture whether the content changed:

```basic
if beam_input(name$, 64, 300) then
  ' name$ was modified this frame
end if
```

**beam_checkbox**: The returned value must be assigned back to the variable
used as the current state:

```basic
dark_mode = beam_checkbox("Dark Mode", dark_mode)
```

**beam_combo**: Items are separated by `\n` in the string:

```basic
items$ = "Red\nGreen\nBlue"
sel = beam_combo(items$, 3, sel, 160, 26)
```

---

## 10. BEAM GUI Commands — Layout

Layout commands control how widgets are arranged within a window.

| Command | Description |
|---|---|
| `beam_row(h, cols)` | Begin a horizontal row of `cols` equal-width columns, each `h` pixels tall. Subsequent widgets fill columns left-to-right. |
| `beam_row_end()` | End the current row and return to single-column vertical flow. |
| `beam_group_begin(title$)` | Begin a labelled group box. All widgets until `beam_group_end` are rendered inside it. Height is auto-sized to fill remaining window space. |
| `beam_group_begin(title$, h)` | Same, but allocates exactly `h` pixels of vertical space for the group. Use this when two or more groups are stacked vertically so each gets the correct height. |
| `beam_group_end()` | End the current group box. |
| `beam_panel_begin(title$, w, h)` | Begin a scrollable panel of w×h pixels. |
| `beam_panel_end()` | End the current panel. |

### Layout example — side-by-side groups (inside beam_row)

```basic
beam_row(200, 2)
  beam_group_begin("Left")
    beam_label("Left column content")
  beam_group_end()
  beam_group_begin("Right")
    beam_label("Right column content")
  beam_group_end()
beam_row_end()
```

### Layout example — stacked groups (explicit heights)

When two or more groups are stacked vertically (not inside a `beam_row`), every
group except the last should be given an explicit height.  Without it each group
auto-sizes to fill all remaining space, pushing later groups off screen.

```basic
// Top group: fixed height so the second group is not pushed off screen.
beam_group_begin("Options", 90)
  beam_label("Pick an option:")
  r = beam_checkbox("Enable feature", r)
beam_group_end()

beam_spacing(6)

// Last group: auto-height fills whatever space remains.
beam_group_begin("Results")
  beam_label("Output appears here.")
beam_group_end()
```

### Scrollable panel example

```basic
beam_panel_begin("Items", 440, 300)
  i = 0
  while i < count
    beam_label(items$(i))
    i = i + 1
  wend
beam_panel_end()
```

---

## 11. BEAM GUI Commands — Dialogs & System

| Command | Returns | Description |
|---|---|---|
| `r = beam_msgbox(title$, msg$)` | 1 | Modal message box. Returns 1 when the user dismisses it. |
| `r = beam_confirm(title$, msg$)` | 0 or 1 | Yes/No dialog. Returns 1 for Yes, 0 for No. |
| `f$ = beam_open_file(filter$)` | string | File open dialog. Returns the selected path, or `""` if cancelled. |
| `f$ = beam_save_file(filter$)` | string | File save dialog. Returns the selected path, or `""` if cancelled. |
| `beam_set_color(r, g, b)` | — | Override the Nuklear accent color (0–255 per channel). |
| `beam_set_style(name$)` | — | Apply a named theme: `"dark"`, `"white"`, or `"amber"`. |
| `t = beam_time()` | number | Elapsed milliseconds since the program started. |
| `beam_sleep(ms)` | — | Pause execution for `ms` milliseconds. |

### File filter syntax

Filter strings are pipe-delimited: `"*.bas|*.txt|BEAM source files"`.
Multiple extension groups can be combined. An empty filter shows all files.

### beam_set_style themes

| Name | Description |
|---|---|
| `"dark"` | Dark grey background with light text (default) |
| `"white"` | Light background with dark text |
| `"amber"` | Dark background with Fragillidae amber (#D97706) accents |

---

## 12. The Frame Loop Pattern

Nuklear is an **immediate-mode** GUI toolkit. This means the entire UI is
rebuilt from scratch on every frame. The mandatory structure is:

```basic
win = beam_open(w, h, title$)

while beam_running(win)
  beam_begin(win)        ' start frame — REQUIRED
    ' all widget and layout calls go here
  beam_end(win)          ' render frame — REQUIRED
wend
```

**Rules:**
- `beam_begin` and `beam_end` must each be called exactly once per loop iteration.
- Never call widget commands outside of a `beam_begin`/`beam_end` pair.
- State that changes the UI (variables, array contents) can be updated anywhere
  in the loop — before `beam_begin`, between widgets, or after `beam_end`.
- For time-sensitive updates (animations, timers), update state after
  `beam_end` to avoid blocking the render cycle.

### Animation pattern

```basic
win  = beam_open(400, 200, "Timer")
last = beam_time()
val  = 0

while beam_running(win)
  beam_begin(win)
    beam_progress(val, 100, 360, 24)
  beam_end(win)

  ' update after render — doesn't block the frame
  now = beam_time()
  if now - last >= 16 then
    val  = val + 1
    last = now
  end if
wend
```

---

## 13. File I/O

BEAM inherits yabasic's file I/O. Files are identified by integer channel
numbers (e.g., `#1`).

### Reading a text file

```basic
open "data.txt" for reading as #1
while not eof(#1)
  line input #1, row$
  print row$
wend
close #1
```

### Writing a text file

```basic
open "output.txt" for writing as #2
print #2, "line one"
print #2, "line two"
close #2
```

### Appending to a file

```basic
open "log.txt" for appending as #3
print #3, "new entry"
close #3
```

### Checking if a file exists

```basic
if open("test.txt") then
  close
  print "file exists"
end if
```

---

## 14. Error Handling Notes

yabasic does not have structured exception handling (`try`/`catch`). Keep
these points in mind:

- **Division by zero** produces 0 (with a runtime warning). Guard with an
  explicit check: `if divisor <> 0 then result = a / divisor end if`
- **File not found** on `open … for reading` halts the program. Use a guard
  or test for existence first.
- **Array out of bounds** halts the program. Always track the item count and
  check before indexing.
- **beam_open_file / beam_save_file** return `""` when cancelled — always
  check before using the result: `if path$ <> "" then … end if`

---

## 15. Command Quick Reference

### Window Management

```
win = beam_open(w, h, title$)     open window, returns handle
beam_close(win)                   close window
beam_title(win, title$)           set window title
beam_size(win, w, h)              resize window
running = beam_running(win)       1 if open, 0 if closed
beam_begin(win)                   start frame (required)
beam_end(win)                     render frame (required)
```

### Widgets

```
clicked = beam_button(label$, w, h)
beam_label(text$)
beam_text(text$, w, h)
changed = beam_input(buf$, maxlen, w)
checked = beam_checkbox(label$, val)
idx     = beam_combo(items$, count, sel, w, h)
val     = beam_slider(val, min, max, step, w)
beam_progress(val, max, w, h)
beam_separator()
beam_spacing(px)
beam_image(path$, w, h)
```

### Layout

```
beam_row(h, cols)
beam_row_end()
beam_group_begin(title$)          // auto height (fills remaining space)
beam_group_begin(title$, h)       // explicit height in pixels
beam_group_end()
beam_panel_begin(title$, w, h)
beam_panel_end()
```

### Dialogs & System

```
r  = beam_msgbox(title$, msg$)
r  = beam_confirm(title$, msg$)
f$ = beam_open_file(filter$)
f$ = beam_save_file(filter$)
beam_set_color(r, g, b)
beam_set_style(name$)           "dark" | "white" | "amber"
t  = beam_time()                milliseconds since start
beam_sleep(ms)
```

---

*BEAM Language Reference v1.0 | Fragillidae Software*
