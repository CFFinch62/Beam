/*
 * beam_commands.c - BEAM GUI command and function stubs
 *
 * Phase 2: All handlers print "BEAM STUB: <name>" and return safe defaults.
 * Phase 3 will replace these with real SDL2/Nuklear implementations.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef YABASIC_INCLUDED
#include "../yabasic.h"
#endif

#include "beam_commands.h"

/* Convenience macro for popping typed values */
#define POP_NUM()  (pop(stNUMBER)->value)
#define POP_STR()  (pop(stSTRING)->pointer)
#define POP_ANY()  (pop(stSTRING_OR_NUMBER))

/* ------------------------------------------------------------------ */
/* Void command stubs                                                   */
/* Each pops the arguments the grammar pushed, in reverse order.       */
/* ------------------------------------------------------------------ */

void beam_cmd_close(void) {
    double win = POP_NUM();
    printf("BEAM STUB: beam_close(win=%g)\n", win);
}

void beam_cmd_title(void) {
    char *title = POP_STR();
    double win  = POP_NUM();
    printf("BEAM STUB: beam_title(win=%g, title=\"%s\")\n", win, title);
}

void beam_cmd_size(void) {
    double h  = POP_NUM();
    double w  = POP_NUM();
    double win = POP_NUM();
    printf("BEAM STUB: beam_size(win=%g, w=%g, h=%g)\n", win, w, h);
}

void beam_cmd_begin(void) {
    double win = POP_NUM();
    printf("BEAM STUB: beam_begin(win=%g)\n", win);
}

void beam_cmd_end(void) {
    double win = POP_NUM();
    printf("BEAM STUB: beam_end(win=%g)\n", win);
}

void beam_cmd_label(void) {
    char *text = POP_STR();
    printf("BEAM STUB: beam_label(\"%s\")\n", text);
}

void beam_cmd_text(void) {
    double h    = POP_NUM();
    double w    = POP_NUM();
    char *text  = POP_STR();
    printf("BEAM STUB: beam_text(\"%s\", w=%g, h=%g)\n", text, w, h);
}

void beam_cmd_image(void) {
    double h     = POP_NUM();
    double w     = POP_NUM();
    char *path   = POP_STR();
    printf("BEAM STUB: beam_image(\"%s\", w=%g, h=%g)\n", path, w, h);
}

void beam_cmd_progress(void) {
    double h   = POP_NUM();
    double w   = POP_NUM();
    double mx  = POP_NUM();
    double val = POP_NUM();
    printf("BEAM STUB: beam_progress(val=%g, max=%g, w=%g, h=%g)\n", val, mx, w, h);
}

void beam_cmd_separator(void) {
    printf("BEAM STUB: beam_separator()\n");
}

void beam_cmd_spacing(void) {
    double px = POP_NUM();
    printf("BEAM STUB: beam_spacing(px=%g)\n", px);
}

void beam_cmd_row(void) {
    double cols = POP_NUM();
    double h    = POP_NUM();
    printf("BEAM STUB: beam_row(h=%g, cols=%g)\n", h, cols);
}

void beam_cmd_row_end(void) {
    printf("BEAM STUB: beam_row_end()\n");
}

void beam_cmd_group_begin(void) {
    char *title = POP_STR();
    printf("BEAM STUB: beam_group_begin(\"%s\")\n", title);
}

void beam_cmd_group_end(void) {
    printf("BEAM STUB: beam_group_end()\n");
}

void beam_cmd_panel_begin(void) {
    double h     = POP_NUM();
    double w     = POP_NUM();
    char *title  = POP_STR();
    printf("BEAM STUB: beam_panel_begin(\"%s\", w=%g, h=%g)\n", title, w, h);
}

void beam_cmd_panel_end(void) {
    printf("BEAM STUB: beam_panel_end()\n");
}

void beam_cmd_set_color(void) {
    double b = POP_NUM();
    double g = POP_NUM();
    double r = POP_NUM();
    printf("BEAM STUB: beam_set_color(r=%g, g=%g, b=%g)\n", r, g, b);
}

void beam_cmd_set_style(void) {
    char *name = POP_STR();
    printf("BEAM STUB: beam_set_style(\"%s\")\n", name);
}

void beam_cmd_sleep(void) {
    double ms = POP_NUM();
    printf("BEAM STUB: beam_sleep(ms=%g)\n", ms);
}

/* ------------------------------------------------------------------ */
/* Numeric function stubs                                               */
/* ------------------------------------------------------------------ */

double beam_fn_open(int w, int h, const char *title) {
    printf("BEAM STUB: beam_open(w=%d, h=%d, title=\"%s\") -> 1\n", w, h, title);
    return 1.0;
}

double beam_fn_running(int win) {
    printf("BEAM STUB: beam_running(win=%d) -> 0\n", win);
    return 0.0;
}

double beam_fn_button(const char *label, int w, int h) {
    printf("BEAM STUB: beam_button(\"%s\", w=%d, h=%d) -> 0\n", label, w, h);
    return 0.0;
}

double beam_fn_input(const char *buf, int maxlen, int w) {
    printf("BEAM STUB: beam_input(buf=\"%s\", maxlen=%d, w=%d) -> 0\n", buf, maxlen, w);
    return 0.0;
}

double beam_fn_checkbox(const char *label, int checked) {
    printf("BEAM STUB: beam_checkbox(\"%s\", checked=%d) -> %d\n", label, checked, checked);
    return (double)checked;
}

double beam_fn_combo(const char *items, int count, int sel, int w, int h) {
    printf("BEAM STUB: beam_combo(items=\"%s\", count=%d, sel=%d, w=%d, h=%d) -> %d\n",
           items, count, sel, w, h, sel);
    return (double)sel;
}

double beam_fn_slider(double val, double mn, double mx, double step, int w) {
    printf("BEAM STUB: beam_slider(val=%g, min=%g, max=%g, step=%g, w=%d) -> %g\n",
           val, mn, mx, step, w, val);
    return val;
}

double beam_fn_time(void) {
    printf("BEAM STUB: beam_time() -> 0\n");
    return 0.0;
}

double beam_fn_msgbox(const char *title, const char *msg) {
    printf("BEAM STUB: beam_msgbox(title=\"%s\", msg=\"%s\") -> 1\n", title, msg);
    return 1.0;
}

double beam_fn_confirm(const char *title, const char *msg) {
    printf("BEAM STUB: beam_confirm(title=\"%s\", msg=\"%s\") -> 0\n", title, msg);
    return 0.0;
}

/* ------------------------------------------------------------------ */
/* String function stubs                                                */
/* ------------------------------------------------------------------ */

char *beam_fn_open_file(const char *filter) {
    printf("BEAM STUB: beam_open_file(filter=\"%s\") -> \"\"\n", filter);
    return strdup("");
}

char *beam_fn_save_file(const char *filter) {
    printf("BEAM STUB: beam_save_file(filter=\"%s\") -> \"\"\n", filter);
    return strdup("");
}
