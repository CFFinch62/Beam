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

/* Shared input buffer for beam_input().
 * Exposed via beam_fn_input_get_buf() so function.c can propagate the
 * current text back into a named BASIC string variable each frame.      */
static char g_beam_input_buf[1024];

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

void beam_cmd_vbar(void) {
    int    h   = (int)POP_NUM();
    int    w   = (int)POP_NUM();
    double mx  = POP_NUM();
    double val = POP_NUM();
    beam_gui_vbar(g_active_win, val, mx, w, h);
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
    beam_gui_group_begin(g_active_win, title, 0);
}

void beam_cmd_group_begin_h(void) {
    int   height = (int)POP_NUM();
    char *title  = POP_STR();
    beam_gui_group_begin(g_active_win, title, height);
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

/* Set to 1 by function.c to request a one-shot clear of the edit buffer.
 * This avoids using the BASIC variable value (which is always "") as the
 * clear signal, which would wipe the buffer on every single frame.      */
int g_beam_input_clear_request = 0;

double beam_fn_input(const char *buf, int maxlen, int w) {
    /* buf arrives as a read-only copy of the BASIC string variable.
     * We edit g_beam_input_buf in-place via Nuklear.
     * Rules:
     *   - If a clear was requested by function.c (one-shot flag), reset.
     *   - If buffer is currently empty and BASIC variable has a value,
     *     seed the buffer from the BASIC variable (initial value/pre-fill).
     *   - Otherwise keep whatever the user has typed (don't overwrite
     *     on every frame).
     * beam_fn_input_get_buf() exposes the buffer so function.c can push
     * its content into a named BASIC global each frame.                 */
    int limit = maxlen < (int)sizeof(g_beam_input_buf) - 1
                ? maxlen
                : (int)sizeof(g_beam_input_buf) - 1;
    if (g_beam_input_clear_request) {
        g_beam_input_buf[0] = '\0';
        g_beam_input_clear_request = 0;
    } else if (g_beam_input_buf[0] == '\0' && buf && buf[0] != '\0') {
        /* Buffer empty and BASIC variable has an initial value: seed it */
        strncpy(g_beam_input_buf, buf, limit);
        g_beam_input_buf[limit] = '\0';
    }
    int changed = beam_gui_input(g_active_win, g_beam_input_buf, limit, w);
    /* Return 1 if Enter was pressed (committed), 0 otherwise.          */
    return (double)changed;
}

const char *beam_fn_input_get_buf(void) {
    return g_beam_input_buf;
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

/* ------------------------------------------------------------------ */
/* NMEA 0183 serial I/O handlers                                        */
/* ------------------------------------------------------------------ */

void beam_cmd_nmea_close(void) {
    int handle = (int)POP_NUM();
    beam_nmea_close(handle);
}

double beam_fn_nmea_open(const char *port, int baud) {
    return (double)beam_nmea_open(port, baud);
}

char *beam_fn_nmea_read(int handle) {
    return strdup(beam_nmea_read(handle));
}

char *beam_fn_nmea_field(const char *sentence, int n) {
    return strdup(beam_nmea_field(sentence, n));
}
