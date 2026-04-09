/*
 * beam_gui.c - BEAM GUI abstraction layer
 *
 * Phase 2: stub implementations only.
 * Phase 3: replace with real SDL2 + Nuklear implementation.
 *
 * To implement Phase 3:
 *   #define NK_INCLUDE_FIXED_TYPES
 *   #define NK_INCLUDE_STANDARD_IO
 *   #define NK_INCLUDE_DEFAULT_ALLOCATOR
 *   #define NK_INCLUDE_VERTEX_BUFFER_OUTPUT
 *   #define NK_INCLUDE_FONT_BAKING
 *   #define NK_INCLUDE_DEFAULT_FONT
 *   #define NK_IMPLEMENTATION
 *   #define NK_SDL_RENDERER_IMPLEMENTATION
 *   #include "nuklear.h"
 *   ... then implement each function with SDL2/Nuklear calls.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "beam_gui.h"

int beam_gui_init(void) { return 1; }

int beam_gui_open(int w, int h, const char *title) {
    printf("beam_gui_open(%d, %d, \"%s\")\n", w, h, title);
    return 1;
}

void beam_gui_close(int handle)          { (void)handle; }
int  beam_gui_running(int handle)        { (void)handle; return 0; }
void beam_gui_begin(int handle)          { (void)handle; }
void beam_gui_end(int handle)            { (void)handle; }
void beam_gui_title(int handle, const char *t)  { (void)handle; (void)t; }
void beam_gui_size(int handle, int w, int h)    { (void)handle; (void)w; (void)h; }

int    beam_gui_button(int h, const char *l, int w, int ht) { (void)h;(void)l;(void)w;(void)ht; return 0; }
void   beam_gui_label(int h, const char *t)                  { (void)h;(void)t; }
void   beam_gui_text(int h, const char *t, int w, int ht)   { (void)h;(void)t;(void)w;(void)ht; }
int    beam_gui_input(int h, char *buf, int ml, int w)       { (void)h;(void)buf;(void)ml;(void)w; return 0; }
int    beam_gui_checkbox(int h, const char *l, int *v)       { (void)h;(void)l; return *v; }
int    beam_gui_combo(int h, const char *it, int cnt, int *sel, int w, int ht) {
    (void)h;(void)it;(void)cnt;(void)w;(void)ht; return *sel;
}
double beam_gui_slider(int h, double *v, double mn, double mx, double st, int w) {
    (void)h;(void)mn;(void)mx;(void)st;(void)w; return *v;
}
void   beam_gui_progress(int h, double v, double mx, int w, int ht) { (void)h;(void)v;(void)mx;(void)w;(void)ht; }
void   beam_gui_separator(int h)      { (void)h; }
void   beam_gui_spacing(int h, int px){ (void)h;(void)px; }
void   beam_gui_image(int h, const char *p, int w, int ht) { (void)h;(void)p;(void)w;(void)ht; }

void beam_gui_row(int h, int ht, int cols)         { (void)h;(void)ht;(void)cols; }
void beam_gui_row_end(int h)                       { (void)h; }
void beam_gui_group_begin(int h, const char *t)    { (void)h;(void)t; }
void beam_gui_group_end(int h)                     { (void)h; }
void beam_gui_panel_begin(int h, const char *t, int w, int ht) { (void)h;(void)t;(void)w;(void)ht; }
void beam_gui_panel_end(int h)                     { (void)h; }

int   beam_gui_msgbox(int h, const char *t, const char *m)  { (void)h;(void)t;(void)m; return 1; }
int   beam_gui_confirm(int h, const char *t, const char *m) { (void)h;(void)t;(void)m; return 0; }
char *beam_gui_open_file(int h, const char *f)  { (void)h;(void)f; return strdup(""); }
char *beam_gui_save_file(int h, const char *f)  { (void)h;(void)f; return strdup(""); }
void  beam_gui_set_color(int h, int r, int g, int b) { (void)h;(void)r;(void)g;(void)b; }
void  beam_gui_set_style(int h, const char *n)  { (void)h;(void)n; }
double beam_gui_time(void)   { return 0.0; }
void  beam_gui_sleep(int ms) { (void)ms; }
