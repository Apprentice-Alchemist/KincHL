#include "window.h"

kinc_window_options_t* convert_win_opts_hl(win_opts_hl* win) {
  if (win == NULL) {
    return NULL;
  }

  kinc_window_options_t window;
  window.display_index = win->display_index;
  window.height = win->height;
  window.mode = win->mode;
  window.title = hl_to_utf8(win->title->bytes);
  window.width = win->width;
  window.window_features = win->window_features;
  window.x = win->x;
  window.y = win->y;
  return &window;
}
kinc_framebuffer_options_t* convert_fb_opts_hl(fb_opts_hl* fb) {
  if (fb == NULL) {
    return NULL;
  }
  kinc_framebuffer_options_t frame;
  frame.color_bits = fb->color_bits;
  frame.depth_bits = fb->depth_bits;
  frame.frequency = fb->frequency;
  frame.samples_per_pixel = fb->samples_per_pixel;
  frame.stencil_bits = fb->stencil_bits;
  frame.vertical_sync = fb->vertical_sync;
  return &frame;
}

HL_PRIM int HL_NAME(hl_window_create)(win_opts_hl* win, fb_opts_hl* fb) {
  return kinc_window_create(convert_win_opts_hl(win), convert_fb_opts_hl(fb));
}

HL_PRIM void HL_NAME(hl_window_destroy)(int index) {
  kinc_window_destroy(index);
}

DEFINE_PRIM(_I32, hl_window_create, HL_WINDOW_OPTS HL_FRAMEBUFFER_OPTS)
DEFINE_PRIM(_VOID, hl_window_destroy, _I32)