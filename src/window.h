#pragma once

#include <kinc/window.h>
#include <kinchl.h>

#define HL_WINDOW_OPTS _OBJ(_STRING _I32 _I32 _I32 _I32 _I32 _BOOL _I32 _I32)
#define HL_FRAMEBUFFER_OPTS _OBJ(_I32 _I32 _I32 _I32 _I32 _BOOL)

typedef struct {
    hl_type *type;
    vstring *title;
    int x;
    int y;
    int width;
    int height;
    int display_index;
    bool visible;
    int window_features;
    kinc_window_mode_t mode;
} win_opts_hl;

typedef struct {
    hl_type *type;
    int color_bits;
    int depth_bits;
    int frequency;
    int samples_per_pixel;
    int stencil_bits;
    bool vertical_sync;
} fb_opts_hl;

kinc_window_options_t *convert_win_opts_hl(win_opts_hl *o);
kinc_framebuffer_options_t *convert_fb_opts_hl(fb_opts_hl *o);
