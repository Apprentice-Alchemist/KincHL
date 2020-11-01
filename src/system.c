#include "kinchl.h"
#include "window.h"
#include <kinc/error.h>
#include <kinc/log.h>
#include <kinc/system.h>
#include <kinc/window.h>
#include <kinc/math/quaternion.h>
#include <kinc/math/core.h>
#include <kinc/math/random.h>
#include <kinc/math/matrix.h>
#include <kinc/math/vector.h>
HL_PRIM int HL_NAME(hl_init)(vstring* title, int w, int h, win_opts_hl* win,
  fb_opts_hl* fb) {
  kinc_log(KINC_LOG_LEVEL_INFO, "Starting KincHL");
  kinc_window_options_t window;
  kinc_framebuffer_options_t frame;
  if (win != NULL)
  {
    window.display_index = win->display_index;
    window.height = win->height;
    window.mode = win->mode;
    window.title = hl_to_utf8(win->title->bytes);
    window.width = win->width;
    window.window_features = win->window_features;
    window.x = win->x;
    window.y = win->y;
  }
  if (fb != NULL)
  {
    frame.color_bits = fb->color_bits;
    frame.depth_bits = fb->depth_bits;
    frame.frequency = fb->frequency;
    frame.samples_per_pixel = fb->samples_per_pixel;
    frame.stencil_bits = fb->stencil_bits;
    frame.vertical_sync = fb->vertical_sync;
  }
  return kinc_init(hl_to_utf8(title->bytes), w, h, convert_win_opts_hl(win),
    convert_fb_opts_hl(fb));
}

HL_PRIM void HL_NAME(hl_start)() { kinc_start(); }
HL_PRIM void HL_NAME(hl_stop)(){ kinc_stop();}
DEFINE_PRIM(_VOID, hl_start, _NO_ARG);
DEFINE_PRIM(_I32, hl_init, _STRING _I32 _I32 HL_WINDOW_OPTS HL_FRAMEBUFFER_OPTS)
DEFINE_PRIM(_VOID,hl_stop,_NO_ARG)

void EMPTY_INIT(void*o){}
void EMPTY_DESTROY(void*o){}
MAKE_OBJ_ARRAY(float, single, _F32)
MAKE_OBJ_ARRAY(int, int, _I32)