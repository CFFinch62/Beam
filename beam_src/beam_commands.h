/*
 * beam_commands.h - BEAM GUI command and function stubs
 * Declarations for handlers called from main.c and function.c
 */

#ifndef BEAM_COMMANDS_H
#define BEAM_COMMANDS_H

/* Void command handlers (called from main.c dispatch) */
void beam_cmd_close(void);
void beam_cmd_title(void);
void beam_cmd_size(void);
void beam_cmd_begin(void);
void beam_cmd_end(void);
void beam_cmd_label(void);
void beam_cmd_text(void);
void beam_cmd_image(void);
void beam_cmd_progress(void);
void beam_cmd_vbar(void);
void beam_cmd_separator(void);
void beam_cmd_spacing(void);
void beam_cmd_row(void);
void beam_cmd_row_end(void);
void beam_cmd_group_begin(void);
void beam_cmd_group_end(void);
void beam_cmd_panel_begin(void);
void beam_cmd_panel_end(void);
void beam_cmd_set_color(void);
void beam_cmd_set_style(void);
void beam_cmd_sleep(void);

/* Numeric function handlers (called from function.c dispatch) */
double beam_fn_open(int w, int h, const char *title);
double beam_fn_running(int win);
double beam_fn_button(const char *label, int w, int h);
double beam_fn_input(const char *buf, int maxlen, int w);
double beam_fn_checkbox(const char *label, int checked);
double beam_fn_combo(const char *items, int count, int sel, int w, int h);
double beam_fn_slider(double val, double mn, double mx, double step, int w);
double beam_fn_time(void);
double beam_fn_msgbox(const char *title, const char *msg);
double beam_fn_confirm(const char *title, const char *msg);

/* String function handlers */
char *beam_fn_open_file(const char *filter);
char *beam_fn_save_file(const char *filter);

/* Input buffer accessor — returns the live Nuklear edit buffer so that
 * function.c can propagate the current text to a BASIC string variable. */
const char *beam_fn_input_get_buf(void);

/* Set to 1 by function.c to request a one-shot clear of the edit buffer
 * on the next call to beam_fn_input().                                  */
extern int g_beam_input_clear_request;

/* NMEA 0183 serial support */
#include "beam_nmea.h"

/* Void command handler */
void beam_cmd_nmea_close(void);

/* Numeric function handler */
double beam_fn_nmea_open(const char *port, int baud);

/* String function handlers (return heap-allocated strings) */
char *beam_fn_nmea_read(int handle);
char *beam_fn_nmea_field(const char *sentence, int n);

#endif /* BEAM_COMMANDS_H */
