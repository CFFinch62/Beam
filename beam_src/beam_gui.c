/*
 * beam_gui.c - BEAM GUI abstraction layer
 * Phase 3: Real SDL2 + Nuklear implementation
 *
 * This file owns the Nuklear implementation — NK_IMPLEMENTATION must be
 * defined here and ONLY here.
 */

#define NK_INCLUDE_FIXED_TYPES
#define NK_INCLUDE_STANDARD_IO
#define NK_INCLUDE_STANDARD_VARARGS
#define NK_INCLUDE_DEFAULT_ALLOCATOR
#define NK_INCLUDE_VERTEX_BUFFER_OUTPUT
#define NK_INCLUDE_FONT_BAKING
#define NK_INCLUDE_DEFAULT_FONT
#define NK_IMPLEMENTATION
#include "nuklear.h"

#include <SDL2/SDL.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "beam_gui.h"
#include "tinyfiledialogs.h"

/* ------------------------------------------------------------------ */
/* Internal types                                                       */
/* ------------------------------------------------------------------ */

/* Vertex layout: pos(8) + uv(8) + color(4) = 20 bytes               */
struct beam_vertex {
    float   pos[2];
    float   uv[2];
    nk_byte col[4];
};

#define BEAM_MAX_WINDOWS 8
#define BEAM_LAYOUT_STACK_DEPTH 16

/* Per-level layout state (used to track beam_row inside groups) */
typedef struct {
    int row_active;
    int row_height;
    int row_cols;
    int group_open;   /* 1 if nk_group_begin succeeded; 0 to skip group_end */
} BeamLayoutFrame;

typedef struct {
    SDL_Window   *sdl_win;
    SDL_Renderer *sdl_ren;
    SDL_Texture  *font_tex;

    struct nk_context    ctx;
    struct nk_font_atlas atlas;
    struct nk_draw_null_texture null_tex;
    struct nk_font      *font;

    int open;

    /* Layout stack for beam_row / beam_group nesting */
    BeamLayoutFrame layout_stack[BEAM_LAYOUT_STACK_DEPTH];
    int             layout_depth;
} BeamWin;

static BeamWin g_windows[BEAM_MAX_WINDOWS];
static int     g_initialized = 0;

/* ------------------------------------------------------------------ */
/* Internal helpers                                                     */
/* ------------------------------------------------------------------ */

static BeamWin *get_win(int handle)
{
    if (handle < 0 || handle >= BEAM_MAX_WINDOWS) return NULL;
    if (!g_windows[handle].open) return NULL;
    return &g_windows[handle];
}

/* Current layout frame for a window */
static BeamLayoutFrame *cur_frame(BeamWin *bw)
{
    return &bw->layout_stack[bw->layout_depth];
}

/* Auto-set a single-row layout if not inside an explicit beam_row */
static void auto_row(BeamWin *bw, int height)
{
    if (!cur_frame(bw)->row_active)
        nk_layout_row_dynamic(&bw->ctx, height, 1);
}

/* ------------------------------------------------------------------ */
/* Font upload                                                          */
/* ------------------------------------------------------------------ */

static SDL_Texture *upload_font_atlas(SDL_Renderer *ren,
                                      const void *image,
                                      int w, int h)
{
    SDL_Surface *surf = SDL_CreateRGBSurfaceFrom(
        (void *)image, w, h, 32, w * 4,
        0x00FF0000u, 0x0000FF00u, 0x000000FFu, 0xFF000000u);
    if (!surf) return NULL;
    SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, surf);
    SDL_FreeSurface(surf);
    return tex;
}

/* ------------------------------------------------------------------ */
/* SDL input → Nuklear                                                  */
/* ------------------------------------------------------------------ */

static void handle_event(BeamWin *bw, SDL_Event *evt)
{
    struct nk_context *ctx = &bw->ctx;

    switch (evt->type) {
    case SDL_KEYUP:
    case SDL_KEYDOWN: {
        int down = (evt->type == SDL_KEYDOWN);
        SDL_Keycode sym = evt->key.keysym.sym;
        int ctrl = (evt->key.keysym.mod & KMOD_CTRL) != 0;
        if (sym == SDLK_RSHIFT || sym == SDLK_LSHIFT)
            nk_input_key(ctx, NK_KEY_SHIFT, down);
        else if (sym == SDLK_DELETE)     nk_input_key(ctx, NK_KEY_DEL, down);
        else if (sym == SDLK_RETURN)     nk_input_key(ctx, NK_KEY_ENTER, down);
        else if (sym == SDLK_TAB)        nk_input_key(ctx, NK_KEY_TAB, down);
        else if (sym == SDLK_BACKSPACE)  nk_input_key(ctx, NK_KEY_BACKSPACE, down);
        else if (sym == SDLK_HOME)       nk_input_key(ctx, NK_KEY_TEXT_LINE_START, down);
        else if (sym == SDLK_END)        nk_input_key(ctx, NK_KEY_TEXT_LINE_END, down);
        else if (sym == SDLK_PAGEUP)     nk_input_key(ctx, NK_KEY_SCROLL_UP, down);
        else if (sym == SDLK_PAGEDOWN)   nk_input_key(ctx, NK_KEY_SCROLL_DOWN, down);
        else if (sym == SDLK_UP)         nk_input_key(ctx, NK_KEY_UP, down);
        else if (sym == SDLK_DOWN)       nk_input_key(ctx, NK_KEY_DOWN, down);
        else if (sym == SDLK_LEFT) {
            if (ctrl) nk_input_key(ctx, NK_KEY_TEXT_WORD_LEFT, down);
            else       nk_input_key(ctx, NK_KEY_LEFT, down);
        } else if (sym == SDLK_RIGHT) {
            if (ctrl) nk_input_key(ctx, NK_KEY_TEXT_WORD_RIGHT, down);
            else       nk_input_key(ctx, NK_KEY_RIGHT, down);
        } else if (ctrl) {
            if (sym == SDLK_c)  nk_input_key(ctx, NK_KEY_COPY, down);
            else if (sym == SDLK_v) nk_input_key(ctx, NK_KEY_PASTE, down);
            else if (sym == SDLK_x) nk_input_key(ctx, NK_KEY_CUT, down);
            else if (sym == SDLK_z) nk_input_key(ctx, NK_KEY_TEXT_UNDO, down);
            else if (sym == SDLK_r) nk_input_key(ctx, NK_KEY_TEXT_REDO, down);
            else if (sym == SDLK_a) nk_input_key(ctx, NK_KEY_TEXT_SELECT_ALL, down);
        }
        break;
    }
    case SDL_MOUSEBUTTONDOWN:
    case SDL_MOUSEBUTTONUP: {
        int down = (evt->type == SDL_MOUSEBUTTONDOWN);
        int x = evt->button.x, y = evt->button.y;
        if (evt->button.button == SDL_BUTTON_LEFT)
            nk_input_button(ctx, NK_BUTTON_LEFT, x, y, down);
        else if (evt->button.button == SDL_BUTTON_MIDDLE)
            nk_input_button(ctx, NK_BUTTON_MIDDLE, x, y, down);
        else if (evt->button.button == SDL_BUTTON_RIGHT)
            nk_input_button(ctx, NK_BUTTON_RIGHT, x, y, down);
        break;
    }
    case SDL_MOUSEMOTION:
        nk_input_motion(ctx, evt->motion.x, evt->motion.y);
        break;
    case SDL_MOUSEWHEEL:
        nk_input_scroll(ctx, nk_vec2((float)evt->wheel.x, (float)evt->wheel.y));
        break;
    case SDL_TEXTINPUT: {
        nk_glyph g;
        memcpy(g, evt->text.text, NK_UTF_SIZE);
        nk_input_glyph(ctx, g);
        break;
    }
    default: break;
    }
}

/* ------------------------------------------------------------------ */
/* Nuklear → SDL2 render                                               */
/* ------------------------------------------------------------------ */

static void nk_render_for_win(BeamWin *bw)
{
    static const struct nk_draw_vertex_layout_element vertex_layout[] = {
        {NK_VERTEX_POSITION, NK_FORMAT_FLOAT,    NK_OFFSETOF(struct beam_vertex, pos)},
        {NK_VERTEX_TEXCOORD, NK_FORMAT_FLOAT,    NK_OFFSETOF(struct beam_vertex, uv)},
        {NK_VERTEX_COLOR,    NK_FORMAT_R8G8B8A8, NK_OFFSETOF(struct beam_vertex, col)},
        {NK_VERTEX_LAYOUT_END}
    };

    struct nk_convert_config cfg;
    memset(&cfg, 0, sizeof(cfg));
    cfg.vertex_layout        = vertex_layout;
    cfg.vertex_size          = sizeof(struct beam_vertex);
    cfg.vertex_alignment     = NK_ALIGNOF(struct beam_vertex);
    cfg.circle_segment_count = 22;
    cfg.curve_segment_count  = 22;
    cfg.arc_segment_count    = 22;
    cfg.global_alpha         = 1.0f;
    cfg.shape_AA             = NK_ANTI_ALIASING_ON;
    cfg.line_AA              = NK_ANTI_ALIASING_ON;
    cfg.tex_null             = bw->null_tex;

    struct nk_buffer vbuf, ibuf, cmdbuf;
    nk_buffer_init_default(&vbuf);
    nk_buffer_init_default(&ibuf);
    nk_buffer_init_default(&cmdbuf);

    nk_convert(&bw->ctx, &cmdbuf, &vbuf, &ibuf, &cfg);

    const struct beam_vertex *verts =
        (const struct beam_vertex *)nk_buffer_memory_const(&vbuf);
    const nk_draw_index *idx =
        (const nk_draw_index *)nk_buffer_memory_const(&ibuf);
    nk_size num_verts = nk_buffer_total(&vbuf) / sizeof(struct beam_vertex);

    int win_w, win_h;
    SDL_GetWindowSize(bw->sdl_win, &win_w, &win_h);

    /* Get DPI scale factor */
    int draw_w, draw_h;
    SDL_GL_GetDrawableSize(bw->sdl_win, &draw_w, &draw_h);
    float sx = (float)draw_w  / (float)win_w;
    float sy = (float)draw_h / (float)win_h;

    const struct nk_draw_command *cmd;
    const nk_draw_index *offset = idx;

    nk_draw_foreach(cmd, &bw->ctx, &cmdbuf) {
        if (!cmd->elem_count) continue;

        SDL_Rect clip;
        clip.x = (int)(cmd->clip_rect.x * sx);
        clip.y = (int)(cmd->clip_rect.y * sy);
        clip.w = (int)(cmd->clip_rect.w * sx);
        clip.h = (int)(cmd->clip_rect.h * sy);
        SDL_RenderSetClipRect(bw->sdl_ren, &clip);

        SDL_Texture *tex = (SDL_Texture *)cmd->texture.ptr;

        SDL_RenderGeometryRaw(bw->sdl_ren, tex,
            (const float *)verts->pos,          sizeof(struct beam_vertex),
            (const SDL_Color *)verts->col,       sizeof(struct beam_vertex),
            (const float *)verts->uv,            sizeof(struct beam_vertex),
            (int)num_verts,
            offset, (int)cmd->elem_count,
            sizeof(nk_draw_index));

        offset += cmd->elem_count;
    }

    SDL_RenderSetClipRect(bw->sdl_ren, NULL);
    nk_buffer_free(&vbuf);
    nk_buffer_free(&ibuf);
    nk_buffer_free(&cmdbuf);
    nk_clear(&bw->ctx);
}

/* ------------------------------------------------------------------ */
/* Nuklear theme helpers                                                */
/* ------------------------------------------------------------------ */

static void set_theme_dark(struct nk_context *ctx)
{
    struct nk_color table[NK_COLOR_COUNT];
    table[NK_COLOR_TEXT]                    = nk_rgba(210,210,210,255);
    table[NK_COLOR_WINDOW]                  = nk_rgba(57,67,71,215);
    table[NK_COLOR_HEADER]                  = nk_rgba(51,51,56,220);
    table[NK_COLOR_BORDER]                  = nk_rgba(46,46,46,255);
    table[NK_COLOR_BUTTON]                  = nk_rgba(48,83,111,255);
    table[NK_COLOR_BUTTON_HOVER]            = nk_rgba(58,93,121,255);
    table[NK_COLOR_BUTTON_ACTIVE]           = nk_rgba(63,98,126,255);
    table[NK_COLOR_TOGGLE]                  = nk_rgba(50,58,61,255);
    table[NK_COLOR_TOGGLE_HOVER]            = nk_rgba(45,53,56,255);
    table[NK_COLOR_TOGGLE_CURSOR]           = nk_rgba(48,83,111,255);
    table[NK_COLOR_SELECT]                  = nk_rgba(57,67,61,255);
    table[NK_COLOR_SELECT_ACTIVE]           = nk_rgba(48,83,111,255);
    table[NK_COLOR_SLIDER]                  = nk_rgba(50,58,61,255);
    table[NK_COLOR_SLIDER_CURSOR]           = nk_rgba(48,83,111,245);
    table[NK_COLOR_SLIDER_CURSOR_HOVER]     = nk_rgba(53,88,116,255);
    table[NK_COLOR_SLIDER_CURSOR_ACTIVE]    = nk_rgba(58,93,121,255);
    table[NK_COLOR_PROPERTY]               = nk_rgba(50,58,61,255);
    table[NK_COLOR_EDIT]                    = nk_rgba(50,58,61,225);
    table[NK_COLOR_EDIT_CURSOR]             = nk_rgba(210,210,210,255);
    table[NK_COLOR_COMBO]                   = nk_rgba(50,58,61,255);
    table[NK_COLOR_CHART]                   = nk_rgba(50,58,61,255);
    table[NK_COLOR_CHART_COLOR]             = nk_rgba(48,83,111,255);
    table[NK_COLOR_CHART_COLOR_HIGHLIGHT]   = nk_rgba(255,0,0,255);
    table[NK_COLOR_SCROLLBAR]              = nk_rgba(50,58,61,255);
    table[NK_COLOR_SCROLLBAR_CURSOR]        = nk_rgba(48,83,111,255);
    table[NK_COLOR_SCROLLBAR_CURSOR_HOVER]  = nk_rgba(53,88,116,255);
    table[NK_COLOR_SCROLLBAR_CURSOR_ACTIVE] = nk_rgba(58,93,121,255);
    table[NK_COLOR_TAB_HEADER]              = nk_rgba(48,83,111,255);
    nk_style_from_table(ctx, table);
}

static void set_theme_white(struct nk_context *ctx)
{
    struct nk_color table[NK_COLOR_COUNT];
    table[NK_COLOR_TEXT]                    = nk_rgba(20,20,20,255);
    table[NK_COLOR_WINDOW]                  = nk_rgba(240,240,240,255);
    table[NK_COLOR_HEADER]                  = nk_rgba(210,210,210,255);
    table[NK_COLOR_BORDER]                  = nk_rgba(180,180,180,255);
    table[NK_COLOR_BUTTON]                  = nk_rgba(180,180,200,255);
    table[NK_COLOR_BUTTON_HOVER]            = nk_rgba(160,160,180,255);
    table[NK_COLOR_BUTTON_ACTIVE]           = nk_rgba(140,140,160,255);
    table[NK_COLOR_TOGGLE]                  = nk_rgba(200,200,200,255);
    table[NK_COLOR_TOGGLE_HOVER]            = nk_rgba(180,180,180,255);
    table[NK_COLOR_TOGGLE_CURSOR]           = nk_rgba(80,80,200,255);
    table[NK_COLOR_SELECT]                  = nk_rgba(210,210,210,255);
    table[NK_COLOR_SELECT_ACTIVE]           = nk_rgba(80,80,200,255);
    table[NK_COLOR_SLIDER]                  = nk_rgba(200,200,200,255);
    table[NK_COLOR_SLIDER_CURSOR]           = nk_rgba(80,80,200,255);
    table[NK_COLOR_SLIDER_CURSOR_HOVER]     = nk_rgba(60,60,180,255);
    table[NK_COLOR_SLIDER_CURSOR_ACTIVE]    = nk_rgba(40,40,160,255);
    table[NK_COLOR_PROPERTY]               = nk_rgba(200,200,200,255);
    table[NK_COLOR_EDIT]                    = nk_rgba(250,250,250,255);
    table[NK_COLOR_EDIT_CURSOR]             = nk_rgba(20,20,20,255);
    table[NK_COLOR_COMBO]                   = nk_rgba(200,200,200,255);
    table[NK_COLOR_CHART]                   = nk_rgba(200,200,200,255);
    table[NK_COLOR_CHART_COLOR]             = nk_rgba(80,80,200,255);
    table[NK_COLOR_CHART_COLOR_HIGHLIGHT]   = nk_rgba(255,0,0,255);
    table[NK_COLOR_SCROLLBAR]              = nk_rgba(200,200,200,255);
    table[NK_COLOR_SCROLLBAR_CURSOR]        = nk_rgba(80,80,200,255);
    table[NK_COLOR_SCROLLBAR_CURSOR_HOVER]  = nk_rgba(60,60,180,255);
    table[NK_COLOR_SCROLLBAR_CURSOR_ACTIVE] = nk_rgba(40,40,160,255);
    table[NK_COLOR_TAB_HEADER]              = nk_rgba(180,180,200,255);
    nk_style_from_table(ctx, table);
}

/* Fragillidae amber: #D97706 */
static void set_theme_amber(struct nk_context *ctx)
{
    struct nk_color table[NK_COLOR_COUNT];
    table[NK_COLOR_TEXT]                    = nk_rgba(240,220,180,255);
    table[NK_COLOR_WINDOW]                  = nk_rgba(35,30,20,230);
    table[NK_COLOR_HEADER]                  = nk_rgba(55,45,20,255);
    table[NK_COLOR_BORDER]                  = nk_rgba(90,65,10,255);
    table[NK_COLOR_BUTTON]                  = nk_rgba(217,119,6,255);
    table[NK_COLOR_BUTTON_HOVER]            = nk_rgba(230,140,30,255);
    table[NK_COLOR_BUTTON_ACTIVE]           = nk_rgba(180,90,0,255);
    table[NK_COLOR_TOGGLE]                  = nk_rgba(60,50,25,255);
    table[NK_COLOR_TOGGLE_HOVER]            = nk_rgba(80,65,30,255);
    table[NK_COLOR_TOGGLE_CURSOR]           = nk_rgba(217,119,6,255);
    table[NK_COLOR_SELECT]                  = nk_rgba(60,50,25,255);
    table[NK_COLOR_SELECT_ACTIVE]           = nk_rgba(217,119,6,255);
    table[NK_COLOR_SLIDER]                  = nk_rgba(60,50,25,255);
    table[NK_COLOR_SLIDER_CURSOR]           = nk_rgba(217,119,6,255);
    table[NK_COLOR_SLIDER_CURSOR_HOVER]     = nk_rgba(230,140,30,255);
    table[NK_COLOR_SLIDER_CURSOR_ACTIVE]    = nk_rgba(180,90,0,255);
    table[NK_COLOR_PROPERTY]               = nk_rgba(60,50,25,255);
    table[NK_COLOR_EDIT]                    = nk_rgba(45,38,18,255);
    table[NK_COLOR_EDIT_CURSOR]             = nk_rgba(240,220,180,255);
    table[NK_COLOR_COMBO]                   = nk_rgba(60,50,25,255);
    table[NK_COLOR_CHART]                   = nk_rgba(60,50,25,255);
    table[NK_COLOR_CHART_COLOR]             = nk_rgba(217,119,6,255);
    table[NK_COLOR_CHART_COLOR_HIGHLIGHT]   = nk_rgba(255,60,0,255);
    table[NK_COLOR_SCROLLBAR]              = nk_rgba(50,42,18,255);
    table[NK_COLOR_SCROLLBAR_CURSOR]        = nk_rgba(217,119,6,255);
    table[NK_COLOR_SCROLLBAR_CURSOR_HOVER]  = nk_rgba(230,140,30,255);
    table[NK_COLOR_SCROLLBAR_CURSOR_ACTIVE] = nk_rgba(180,90,0,255);
    table[NK_COLOR_TAB_HEADER]              = nk_rgba(80,65,20,255);
    nk_style_from_table(ctx, table);
}

/* ------------------------------------------------------------------ */
/* Public API — Window Management                                       */
/* ------------------------------------------------------------------ */

int beam_gui_init(void)
{
    if (g_initialized) return 1;
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_EVENTS) < 0) {
        fprintf(stderr, "BEAM: SDL_Init failed: %s\n", SDL_GetError());
        return 0;
    }
    SDL_SetHint(SDL_HINT_VIDEO_HIGHDPI_DISABLED, "0");
    memset(g_windows, 0, sizeof(g_windows));
    g_initialized = 1;
    return 1;
}

int beam_gui_open(int w, int h, const char *title)
{
    if (!g_initialized && !beam_gui_init()) return -1;

    int slot = -1;
    for (int i = 0; i < BEAM_MAX_WINDOWS; i++) {
        if (!g_windows[i].open) { slot = i; break; }
    }
    if (slot < 0) {
        fprintf(stderr, "BEAM: too many windows\n");
        return -1;
    }

    BeamWin *bw = &g_windows[slot];
    memset(bw, 0, sizeof(*bw));

    bw->sdl_win = SDL_CreateWindow(
        title,
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        w, h,
        SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI);
    if (!bw->sdl_win) {
        fprintf(stderr, "BEAM: SDL_CreateWindow: %s\n", SDL_GetError());
        return -1;
    }

    bw->sdl_ren = SDL_CreateRenderer(
        bw->sdl_win, -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!bw->sdl_ren) {
        /* fallback: software renderer */
        bw->sdl_ren = SDL_CreateRenderer(bw->sdl_win, -1, SDL_RENDERER_SOFTWARE);
    }
    if (!bw->sdl_ren) {
        SDL_DestroyWindow(bw->sdl_win);
        return -1;
    }

    /* Bake the default font into an SDL texture */
    nk_font_atlas_init_default(&bw->atlas);
    nk_font_atlas_begin(&bw->atlas);

    int atlas_w, atlas_h;
    const void *img = nk_font_atlas_bake(&bw->atlas, &atlas_w, &atlas_h,
                                          NK_FONT_ATLAS_RGBA32);
    bw->font_tex = upload_font_atlas(bw->sdl_ren, img, atlas_w, atlas_h);

    nk_font_atlas_end(&bw->atlas,
        nk_handle_ptr(bw->font_tex), &bw->null_tex);

    bw->font = bw->atlas.default_font;

    /* Initialise the Nuklear context */
    nk_init_default(&bw->ctx, &bw->font->handle);
    bw->ctx.clip.copy     = NULL;
    bw->ctx.clip.paste    = NULL;
    bw->ctx.clip.userdata = nk_handle_ptr(NULL);

    bw->open = 1;
    bw->layout_depth = 0;
    bw->layout_stack[0].row_active = 0;

    /* Apply default dark theme */
    set_theme_dark(&bw->ctx);

    return slot;
}

void beam_gui_close(int handle)
{
    BeamWin *bw = get_win(handle);
    if (!bw) return;

    nk_font_atlas_clear(&bw->atlas);
    nk_free(&bw->ctx);

    if (bw->font_tex)  SDL_DestroyTexture(bw->font_tex);
    if (bw->sdl_ren)   SDL_DestroyRenderer(bw->sdl_ren);
    if (bw->sdl_win)   SDL_DestroyWindow(bw->sdl_win);

    memset(bw, 0, sizeof(*bw));
}

int beam_gui_running(int handle)
{
    BeamWin *bw = get_win(handle);
    return (bw && bw->open) ? 1 : 0;
}

void beam_gui_title(int handle, const char *title)
{
    BeamWin *bw = get_win(handle);
    if (!bw) return;
    SDL_SetWindowTitle(bw->sdl_win, title);
}

void beam_gui_size(int handle, int w, int h)
{
    BeamWin *bw = get_win(handle);
    if (!bw) return;
    SDL_SetWindowSize(bw->sdl_win, w, h);
}

void beam_gui_begin(int handle)
{
    BeamWin *bw = get_win(handle);
    if (!bw) return;

    /* Process SDL events */
    SDL_Event evt;
    nk_input_begin(&bw->ctx);
    while (SDL_PollEvent(&evt)) {
        if (evt.type == SDL_QUIT) {
            bw->open = 0;
        }
        /* Close when the window's own X button is clicked */
        if (evt.type == SDL_WINDOWEVENT) {
            if (evt.window.event == SDL_WINDOWEVENT_CLOSE) {
                Uint32 wid = SDL_GetWindowID(bw->sdl_win);
                if (evt.window.windowID == wid) bw->open = 0;
            }
        }
        handle_event(bw, &evt);
    }
    nk_input_end(&bw->ctx);

    if (!bw->open) return;

    /* Open a full-window Nuklear panel */
    int win_w, win_h;
    SDL_GetWindowSize(bw->sdl_win, &win_w, &win_h);

    nk_flags flags = NK_WINDOW_NO_SCROLLBAR | NK_WINDOW_BACKGROUND;
    nk_begin(&bw->ctx, "__beam__",
              nk_rect(0, 0, (float)win_w, (float)win_h), flags);

    /* Reset layout stack */
    bw->layout_depth = 0;
    bw->layout_stack[0].row_active = 0;
}

void beam_gui_end(int handle)
{
    BeamWin *bw = get_win(handle);
    if (!bw || !bw->open) return;

    nk_end(&bw->ctx);

    /* Clear + render + present */
    SDL_SetRenderDrawColor(bw->sdl_ren, 30, 30, 30, 255);
    SDL_RenderClear(bw->sdl_ren);
    nk_render_for_win(bw);
    SDL_RenderPresent(bw->sdl_ren);

    /* Cap to ~60 fps when vsync not available */
    SDL_Delay(1);
}

/* ------------------------------------------------------------------ */
/* Public API — Widgets                                                 */
/* ------------------------------------------------------------------ */

int beam_gui_button(int handle, const char *label, int w, int h)
{
    BeamWin *bw = get_win(handle);
    if (!bw) return 0;
    if (cur_frame(bw)->row_active)
        return nk_button_label(&bw->ctx, label);
    nk_layout_row_static(&bw->ctx, h, w, 1);
    return nk_button_label(&bw->ctx, label);
}

void beam_gui_label(int handle, const char *text)
{
    BeamWin *bw = get_win(handle);
    if (!bw) return;
    auto_row(bw, 20);
    nk_label(&bw->ctx, text, NK_TEXT_LEFT);
}

void beam_gui_text(int handle, const char *text, int w, int h)
{
    BeamWin *bw = get_win(handle);
    if (!bw) return;
    auto_row(bw, h);
    /* nk_text_wrap renders text with word-wrap inside the current cell */
    nk_text_wrap(&bw->ctx, text, (int)strlen(text));
    (void)w;
}

int beam_gui_input(int handle, char *buf, int maxlen, int w)
{
    BeamWin *bw = get_win(handle);
    if (!bw) return 0;
    if (cur_frame(bw)->row_active)
        return nk_edit_string_zero_terminated(&bw->ctx,
            NK_EDIT_SIMPLE, buf, maxlen,
            nk_filter_default) & NK_EDIT_COMMITED ? 1 : 0;
    nk_layout_row_static(&bw->ctx, 28, w, 1);
    nk_flags res = nk_edit_string_zero_terminated(&bw->ctx,
        NK_EDIT_SIMPLE, buf, maxlen, nk_filter_default);
    return (res & NK_EDIT_COMMITED) ? 1 : 0;
}

int beam_gui_checkbox(int handle, const char *label, int *val)
{
    BeamWin *bw = get_win(handle);
    if (!bw) return *val;
    auto_row(bw, 20);
    nk_checkbox_label(&bw->ctx, label, val);
    return *val;
}

int beam_gui_combo(int handle, const char *items, int count,
                   int *sel, int w, int h)
{
    BeamWin *bw = get_win(handle);
    if (!bw) return *sel;

    /* Split newline-delimited items into a pointer array */
    const char *ptrs[64];
    char buf[1024];
    int  n = 0;
    strncpy(buf, items, sizeof(buf) - 1);
    buf[sizeof(buf) - 1] = '\0';
    char *p = buf;
    while (*p && n < 64) {
        ptrs[n++] = p;
        char *nl = strchr(p, '\n');
        if (!nl) break;
        *nl = '\0';
        p = nl + 1;
    }
    if (n == 0) return *sel;
    if (*sel >= n) *sel = n - 1;

    auto_row(bw, h);
    *sel = nk_combo(&bw->ctx, ptrs, n, *sel, h, nk_vec2((float)w, (float)(h * n)));
    (void)count;
    return *sel;
}

double beam_gui_slider(int handle, double *val, double mn, double mx,
                       double step, int w)
{
    BeamWin *bw = get_win(handle);
    if (!bw) return *val;
    if (cur_frame(bw)->row_active) {
        float fval = (float)*val;
        nk_slider_float(&bw->ctx, (float)mn, &fval, (float)mx, (float)step);
        *val = fval;
        return *val;
    }
    nk_layout_row_static(&bw->ctx, 20, w, 1);
    float fval = (float)*val;
    nk_slider_float(&bw->ctx, (float)mn, &fval, (float)mx, (float)step);
    *val = fval;
    return *val;
}

void beam_gui_progress(int handle, double val, double max, int w, int h)
{
    BeamWin *bw = get_win(handle);
    if (!bw) return;
    if (!cur_frame(bw)->row_active)
        nk_layout_row_static(&bw->ctx, h, w, 1);
    nk_size v = (nk_size)val;
    nk_progress(&bw->ctx, &v, (nk_size)max, NK_FIXED);
}

void beam_gui_separator(int handle)
{
    BeamWin *bw = get_win(handle);
    if (!bw) return;
    auto_row(bw, 4);
    /* Draw an empty row as a visual separator */
    nk_rule_horizontal(&bw->ctx, bw->ctx.style.window.border_color, nk_false);
}

void beam_gui_spacing(int handle, int px)
{
    BeamWin *bw = get_win(handle);
    if (!bw) return;
    auto_row(bw, px);
    nk_spacing(&bw->ctx, 1);
}

void beam_gui_image(int handle, const char *path, int w, int h)
{
    BeamWin *bw = get_win(handle);
    if (!bw) return;
    /* Load image from file as SDL_Texture */
    SDL_Surface *surf = SDL_LoadBMP(path);
    if (!surf) {
        /* Fallback: draw a labelled placeholder */
        auto_row(bw, h);
        nk_label(&bw->ctx, path, NK_TEXT_CENTERED);
        return;
    }
    SDL_Texture *tex = SDL_CreateTextureFromSurface(bw->sdl_ren, surf);
    SDL_FreeSurface(surf);
    if (!tex) return;

    auto_row(bw, h);
    struct nk_image img = nk_image_ptr(tex);
    nk_image(&bw->ctx, img);
    /* NOTE: caller is responsible for destroying texture after window closes */
    (void)w;
}

/* ------------------------------------------------------------------ */
/* Public API — Layout                                                  */
/* ------------------------------------------------------------------ */

void beam_gui_row(int handle, int h, int cols)
{
    BeamWin *bw = get_win(handle);
    if (!bw) return;
    nk_layout_row_dynamic(&bw->ctx, h, cols);
    cur_frame(bw)->row_active = 1;
    cur_frame(bw)->row_height = h;
    cur_frame(bw)->row_cols   = cols;
}

void beam_gui_row_end(int handle)
{
    BeamWin *bw = get_win(handle);
    if (!bw) return;
    cur_frame(bw)->row_active = 0;
}

void beam_gui_group_begin(int handle, const char *title)
{
    BeamWin *bw = get_win(handle);
    if (!bw) return;

    /* If not in an explicit beam_row, set a layout row that fills remaining
     * vertical space so nk_group_begin has valid bounds.               */
    if (!cur_frame(bw)->row_active) {
        struct nk_vec2 sz = nk_window_get_content_region_size(&bw->ctx);
        float h = sz.y > 30 ? sz.y - 10.0f : 200.0f;
        nk_layout_row_dynamic(&bw->ctx, h, 1);
    }

    int ok = nk_group_begin(&bw->ctx, title, NK_WINDOW_BORDER | NK_WINDOW_TITLE);

    /* Push a new layout frame for content inside the group */
    if (bw->layout_depth + 1 < BEAM_LAYOUT_STACK_DEPTH) {
        bw->layout_depth++;
        bw->layout_stack[bw->layout_depth].row_active = 0;
        bw->layout_stack[bw->layout_depth].group_open = ok;
    }
}

void beam_gui_group_end(int handle)
{
    BeamWin *bw = get_win(handle);
    if (!bw) return;
    /* Only call nk_group_end if the matching nk_group_begin succeeded */
    if (bw->layout_depth > 0) {
        if (bw->layout_stack[bw->layout_depth].group_open)
            nk_group_end(&bw->ctx);
        bw->layout_depth--;
    } else {
        nk_group_end(&bw->ctx);
    }
}

void beam_gui_panel_begin(int handle, const char *title, int w, int h)
{
    BeamWin *bw = get_win(handle);
    if (!bw) return;
    if (!cur_frame(bw)->row_active)
        nk_layout_row_dynamic(&bw->ctx, (float)h, 1);
    int ok = nk_group_begin(&bw->ctx, title,
        NK_WINDOW_BORDER | NK_WINDOW_TITLE | NK_WINDOW_SCROLL_AUTO_HIDE);
    if (bw->layout_depth + 1 < BEAM_LAYOUT_STACK_DEPTH) {
        bw->layout_depth++;
        bw->layout_stack[bw->layout_depth].row_active = 0;
        bw->layout_stack[bw->layout_depth].group_open = ok;
    }
    (void)w;
}

void beam_gui_panel_end(int handle)
{
    BeamWin *bw = get_win(handle);
    if (!bw) return;
    if (bw->layout_depth > 0) {
        if (bw->layout_stack[bw->layout_depth].group_open)
            nk_group_end(&bw->ctx);
        bw->layout_depth--;
    } else {
        nk_group_end(&bw->ctx);
    }
}

/* ------------------------------------------------------------------ */
/* Public API — Dialogs & System                                        */
/* ------------------------------------------------------------------ */

int beam_gui_msgbox(int handle, const char *title, const char *msg)
{
    /* Modal dialogs via SDL message box — no Nuklear overlay needed */
    (void)handle;
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, title, msg, NULL);
    return 1;
}

int beam_gui_confirm(int handle, const char *title, const char *msg)
{
    (void)handle;
    SDL_MessageBoxButtonData btns[] = {
        {SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 1, "Yes"},
        {SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT, 0, "No"},
    };
    SDL_MessageBoxData data = {
        SDL_MESSAGEBOX_INFORMATION,
        NULL, title, msg,
        2, btns, NULL
    };
    int result = 0;
    SDL_ShowMessageBox(&data, &result);
    return result;
}

/* Parse a filter string like "*.txt|*.md|Image files|*.png|*.jpg" into
 * a tinyfiledialogs pattern array.  Pairs of (description, patterns) are
 * accepted but we flatten everything into individual patterns for simplicity.
 * Returns the number of patterns; fills pat[] and desc[0].              */
static int parse_filter(const char *filter,
                         const char *pat[32], char desc_buf[256])
{
    static char fbuf[512];
    strncpy(fbuf, filter ? filter : "*", sizeof(fbuf) - 1);
    fbuf[sizeof(fbuf) - 1] = '\0';
    desc_buf[0] = '\0';

    int n = 0;
    char *p = fbuf;
    while (*p && n < 32) {
        char *sep = strchr(p, '|');
        if (sep) *sep = '\0';
        /* skip pure-text description tokens (no '*' or '.') */
        if (strchr(p, '*') || strchr(p, '.')) {
            pat[n++] = p;
            if (!desc_buf[0]) {
                snprintf(desc_buf, 255, "%s files", p);
            }
        }
        if (!sep) break;
        p = sep + 1;
    }
    if (n == 0) { pat[0] = "*"; n = 1; }
    return n;
}

char *beam_gui_open_file(int handle, const char *filter)
{
    (void)handle;
    tinyfd_verbose = 0;
    tinyfd_silent  = 1;

    const char *pat[32];
    char desc[256];
    int npat = parse_filter(filter, pat, desc);

    char *result = tinyfd_openFileDialog(
        "Open File", "", npat, pat, desc[0] ? desc : NULL, 0);
    return strdup(result ? result : "");
}

char *beam_gui_save_file(int handle, const char *filter)
{
    (void)handle;
    tinyfd_verbose = 0;
    tinyfd_silent  = 1;

    const char *pat[32];
    char desc[256];
    int npat = parse_filter(filter, pat, desc);

    char *result = tinyfd_saveFileDialog(
        "Save File", "", npat, pat, desc[0] ? desc : NULL);
    return strdup(result ? result : "");
}

void beam_gui_set_color(int handle, int r, int g, int b)
{
    BeamWin *bw = get_win(handle);
    if (!bw) return;
    /* Set button and text color as a simple foreground override */
    bw->ctx.style.button.normal.data.color  = nk_rgb(r, g, b);
    bw->ctx.style.button.hover.data.color   = nk_rgb(r > 20 ? r-20 : 0,
                                                       g > 20 ? g-20 : 0,
                                                       b > 20 ? b-20 : 0);
    bw->ctx.style.text.color = nk_rgb(r, g, b);
}

void beam_gui_set_style(int handle, const char *name)
{
    BeamWin *bw = get_win(handle);
    if (!bw) return;
    if (strcmp(name, "white") == 0)       set_theme_white(&bw->ctx);
    else if (strcmp(name, "amber") == 0)  set_theme_amber(&bw->ctx);
    else                                   set_theme_dark(&bw->ctx);
}

double beam_gui_time(void)
{
    return (double)SDL_GetTicks();
}

void beam_gui_sleep(int ms)
{
    SDL_Delay((Uint32)ms);
}
