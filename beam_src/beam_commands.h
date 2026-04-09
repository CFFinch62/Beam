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

#endif /* BEAM_COMMANDS_H */
