/*
 * beam_gui.h - BEAM GUI abstraction layer header
 *
 * Declares all beam_gui_* functions that sit between the BASIC command
 * handlers (beam_commands.c) and SDL2/Nuklear.
 *
 * Phase 2: stubs only. Phase 3 implements with real SDL2 + Nuklear.
 */

#ifndef BEAM_GUI_H
#define BEAM_GUI_H

/* Window management */
int  beam_gui_init(void);
int  beam_gui_open(int w, int h, const char *title);
void beam_gui_close(int handle);
int  beam_gui_running(int handle);
void beam_gui_begin(int handle);
void beam_gui_end(int handle);
void beam_gui_title(int handle, const char *title);
void beam_gui_size(int handle, int w, int h);

/* Widgets */
int    beam_gui_button(int handle, const char *label, int w, int h);
void   beam_gui_label(int handle, const char *text);
void   beam_gui_text(int handle, const char *text, int w, int h);
int    beam_gui_input(int handle, char *buf, int maxlen, int w);
int    beam_gui_checkbox(int handle, const char *label, int *val);
int    beam_gui_combo(int handle, const char *items, int count, int *sel, int w, int h);
double beam_gui_slider(int handle, double *val, double mn, double mx, double step, int w);
void   beam_gui_progress(int handle, double val, double max, int w, int h);
void   beam_gui_vbar(int handle, double val, double max, int w, int h);
void   beam_gui_separator(int handle);
void   beam_gui_spacing(int handle, int px);
void   beam_gui_image(int handle, const char *path, int w, int h);

/* Layout */
void beam_gui_row(int handle, int h, int cols);
void beam_gui_row_end(int handle);
void beam_gui_group_begin(int handle, const char *title, int height);
void beam_gui_group_end(int handle);
void beam_gui_panel_begin(int handle, const char *title, int w, int h);
void beam_gui_panel_end(int handle);

/* Dialogs & system */
int   beam_gui_msgbox(int handle, const char *title, const char *msg);
int   beam_gui_confirm(int handle, const char *title, const char *msg);
char *beam_gui_open_file(int handle, const char *filter);
char *beam_gui_save_file(int handle, const char *filter);
void  beam_gui_set_color(int handle, int r, int g, int b);
void  beam_gui_set_style(int handle, const char *name);
double beam_gui_time(void);
void  beam_gui_sleep(int ms);

#endif /* BEAM_GUI_H */
