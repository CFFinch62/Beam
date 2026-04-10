/*
 * beam_commands.c - BEAM GUI command and function handlers
 * Phase 3: Real implementations — pop yabasic stack args, call beam_gui_*.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef YABASIC_INCLUDED
#include "../yabasic.h"
#endif

#include "beam_commands.h"
#include "beam_gui.h"

/* Convenience macros matching yabasic's pop() convention */
#define POP_NUM()  (pop(stNUMBER)->value)
#define POP_STR()  (pop(stSTRING)->pointer)

/* ------------------------------------------------------------------ */
/* Void command handlers                                                */
/* Args are on the yabasic stack; pop in reverse-push order (LIFO).   */
/* ------------------------------------------------------------------ */

void beam_cmd_close(void) {
    int win = (int)POP_NUM();
    beam_gui_close(win);
}

void beam_cmd_title(void) {
    char *title = POP_STR();
    int   win   = (int)POP_NUM();
    beam_gui_title(win, title);
}

void beam_cmd_size(void) {
    int h   = (int)POP_NUM();
    int w   = (int)POP_NUM();
    int win = (int)POP_NUM();
    beam_gui_size(win, w, h);
}

void beam_cmd_begin(void) {
    int win = (int)POP_NUM();
    beam_gui_begin(win);
}

void beam_cmd_end(void) {
    int win = (int)POP_NUM();
    beam_gui_end(win);
}

void beam_cmd_label(void) {
    char *text = POP_STR();
    /* beam_label has no window handle in the grammar — uses "current" window.
     * For Phase 3 we use handle 0 as the implicit active window.
     * A future phase can pass the handle explicitly if needed.        */
    beam_gui_label(0, text);
}

void beam_cmd_text(void) {
    int   h    = (int)POP_NUM();
    int   w    = (int)POP_NUM();
    char *text = POP_STR();
    beam_gui_text(0, text, w, h);
}

void beam_cmd_image(void) {
    int   h    = (int)POP_NUM();
    int   w    = (int)POP_NUM();
    char *path = POP_STR();
    beam_gui_image(0, path, w, h);
}

void beam_cmd_progress(void) {
    int    h   = (int)POP_NUM();
    int    w   = (int)POP_NUM();
    double mx  = POP_NUM();
    double val = POP_NUM();
    beam_gui_progress(0, val, mx, w, h);
}

void beam_cmd_separator(void) {
    beam_gui_separator(0);
}

void beam_cmd_spacing(void) {
    int px = (int)POP_NUM();
    beam_gui_spacing(0, px);
}

void beam_cmd_row(void) {
    int cols = (int)POP_NUM();
    int h    = (int)POP_NUM();
    beam_gui_row(0, h, cols);
}

void beam_cmd_row_end(void) {
    beam_gui_row_end(0);
}

void beam_cmd_group_begin(void) {
    char *title = POP_STR();
    beam_gui_group_begin(0, title);
}

void beam_cmd_group_end(void) {
    beam_gui_group_end(0);
}

void beam_cmd_panel_begin(void) {
    int   h     = (int)POP_NUM();
    int   w     = (int)POP_NUM();
    char *title = POP_STR();
    beam_gui_panel_begin(0, title, w, h);
}

void beam_cmd_panel_end(void) {
    beam_gui_panel_end(0);
}

void beam_cmd_set_color(void) {
    int b = (int)POP_NUM();
    int g = (int)POP_NUM();
    int r = (int)POP_NUM();
    beam_gui_set_color(0, r, g, b);
}

void beam_cmd_set_style(void) {
    char *name = POP_STR();
    beam_gui_set_style(0, name);
}

void beam_cmd_sleep(void) {
    int ms = (int)POP_NUM();
    beam_gui_sleep(ms);
}

/* ------------------------------------------------------------------ */
/* Numeric function handlers                                            */
/* Args are pre-popped by function.c and passed directly.             */
/* ------------------------------------------------------------------ */

double beam_fn_open(int w, int h, const char *title) {
    beam_gui_init();
    return (double)beam_gui_open(w, h, title);
}

double beam_fn_running(int win) {
    return (double)beam_gui_running(win);
}

double beam_fn_button(const char *label, int w, int h) {
    return (double)beam_gui_button(0, label, w, h);
}

double beam_fn_input(const char *buf, int maxlen, int w) {
    /* The BASIC variable is passed by value (string copy).
     * We can only return changed=0/1; the caller must use
     * an assignment to capture the new value from the variable.
     * Phase 3 limitation: buf is read-only here; input editing
     * works only when the variable is passed by reference via
     * the grammar rule. See bison grammar for beam_input.       */
    (void)maxlen; (void)w;
    (void)buf;
    return 0.0;
}

double beam_fn_checkbox(const char *label, int checked) {
    return (double)beam_gui_checkbox(0, label, &checked);
}

double beam_fn_combo(const char *items, int count, int sel, int w, int h) {
    return (double)beam_gui_combo(0, items, count, &sel, w, h);
}

double beam_fn_slider(double val, double mn, double mx, double step, int w) {
    return beam_gui_slider(0, &val, mn, mx, step, w);
}

double beam_fn_time(void) {
    return beam_gui_time();
}

double beam_fn_msgbox(const char *title, const char *msg) {
    return (double)beam_gui_msgbox(0, title, msg);
}

double beam_fn_confirm(const char *title, const char *msg) {
    return (double)beam_gui_confirm(0, title, msg);
}

/* ------------------------------------------------------------------ */
/* String function handlers                                             */
/* ------------------------------------------------------------------ */

char *beam_fn_open_file(const char *filter) {
    return beam_gui_open_file(0, filter);
}

char *beam_fn_save_file(const char *filter) {
    return beam_gui_save_file(0, filter);
}
