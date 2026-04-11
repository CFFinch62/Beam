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

/* Active window: updated by beam_begin(), used by all widget/layout commands.
 * Defaults to 0 so single-window programs continue to work without change.  */
static int g_active_win = 0;

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
    g_active_win = win;          /* track which window is being rendered */
    beam_gui_begin(win);
}

void beam_cmd_end(void) {
    int win = (int)POP_NUM();
    beam_gui_end(win);
}

void beam_cmd_label(void) {
    char *text = POP_STR();
    beam_gui_label(g_active_win, text);
}

void beam_cmd_text(void) {
    int   h    = (int)POP_NUM();
    int   w    = (int)POP_NUM();
    char *text = POP_STR();
    beam_gui_text(g_active_win, text, w, h);
}

void beam_cmd_image(void) {
    int   h    = (int)POP_NUM();
    int   w    = (int)POP_NUM();
    char *path = POP_STR();
    beam_gui_image(g_active_win, path, w, h);
}

void beam_cmd_progress(void) {
    int    h   = (int)POP_NUM();
    int    w   = (int)POP_NUM();
    double mx  = POP_NUM();
    double val = POP_NUM();
    beam_gui_progress(g_active_win, val, mx, w, h);
}

void beam_cmd_separator(void) {
    beam_gui_separator(g_active_win);
}

void beam_cmd_spacing(void) {
    int px = (int)POP_NUM();
    beam_gui_spacing(g_active_win, px);
}

void beam_cmd_row(void) {
    int cols = (int)POP_NUM();
    int h    = (int)POP_NUM();
    beam_gui_row(g_active_win, h, cols);
}

void beam_cmd_row_end(void) {
    beam_gui_row_end(g_active_win);
}

void beam_cmd_group_begin(void) {
    char *title = POP_STR();
    beam_gui_group_begin(g_active_win, title);
}

void beam_cmd_group_end(void) {
    beam_gui_group_end(g_active_win);
}

void beam_cmd_panel_begin(void) {
    int   h     = (int)POP_NUM();
    int   w     = (int)POP_NUM();
    char *title = POP_STR();
    beam_gui_panel_begin(g_active_win, title, w, h);
}

void beam_cmd_panel_end(void) {
    beam_gui_panel_end(g_active_win);
}

void beam_cmd_set_color(void) {
    int b = (int)POP_NUM();
    int g = (int)POP_NUM();
    int r = (int)POP_NUM();
    beam_gui_set_color(g_active_win, r, g, b);
}

void beam_cmd_set_style(void) {
    char *name = POP_STR();
    beam_gui_set_style(g_active_win, name);
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
    return (double)beam_gui_button(g_active_win, label, w, h);
}

double beam_fn_input(const char *buf, int maxlen, int w) {
    /* buf arrives as a read-only copy of the BASIC string variable.
     * We copy it into a static buffer so Nuklear can edit it in-place.
     * The updated text is held in edit_buf; the BASIC variable is NOT
     * modified (yabasic passes strings by value).  Use beam_input_get$()
     * to retrieve the current content after editing.                    */
    static char edit_buf[1024];
    int limit = maxlen < (int)sizeof(edit_buf) ? maxlen : (int)sizeof(edit_buf) - 1;
    /* Only seed the buffer the first frame (when it is empty or buf differs
     * from what the user has typed so far).  A simple heuristic: if the
     * BASIC variable still matches the initial seed, keep the buffer as-is
     * so Nuklear retains the user's keystrokes across frames.            */
    if (edit_buf[0] == '\0' && buf && buf[0] != '\0') {
        strncpy(edit_buf, buf, limit);
        edit_buf[limit] = '\0';
    }
    int changed = beam_gui_input(g_active_win, edit_buf, limit, w);
    /* Return 1 if Enter was pressed (committed), 0 otherwise.          */
    return (double)changed;
}

double beam_fn_checkbox(const char *label, int checked) {
    return (double)beam_gui_checkbox(g_active_win, label, &checked);
}

double beam_fn_combo(const char *items, int count, int sel, int w, int h) {
    return (double)beam_gui_combo(g_active_win, items, count, &sel, w, h);
}

double beam_fn_slider(double val, double mn, double mx, double step, int w) {
    return beam_gui_slider(g_active_win, &val, mn, mx, step, w);
}

double beam_fn_time(void) {
    return beam_gui_time();
}

double beam_fn_msgbox(const char *title, const char *msg) {
    return (double)beam_gui_msgbox(g_active_win, title, msg);
}

double beam_fn_confirm(const char *title, const char *msg) {
    return (double)beam_gui_confirm(g_active_win, title, msg);
}

/* ------------------------------------------------------------------ */
/* String function handlers                                             */
/* ------------------------------------------------------------------ */

char *beam_fn_open_file(const char *filter) {
    return beam_gui_open_file(g_active_win, filter);
}

char *beam_fn_save_file(const char *filter) {
    return beam_gui_save_file(g_active_win, filter);
}
