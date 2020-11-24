#include "window.h"
#include <kinc/log.h>
kinc_window_options_t* convert_win_opts_hl(win_opts_hl* win) {
  if (win == NULL) {
    return NULL;
  }

  kinc_window_options_t *window = hl_gc_alloc_raw(sizeof(kinc_window_options_t));
  window->display_index = win->display_index;
  window->height = win->height;
  window->mode = win->mode;
  window->title = win->title == NULL ? NULL : hl_to_utf8(win->title->bytes);
  window->width = win->width;
  window->window_features = win->window_features;
  window->x = win->x;
  window->y = win->y;
  window->visible = win->visible;
  return window;
}
kinc_framebuffer_options_t* convert_fb_opts_hl(fb_opts_hl* fb) {
  if (fb == NULL) {
    return NULL;
  }
  kinc_framebuffer_options_t *frame = hl_gc_alloc_raw(sizeof(kinc_framebuffer_options_t));
  frame->color_bits = fb->color_bits;
  frame->depth_bits = fb->depth_bits;
  frame->frequency = fb->frequency;
  frame->samples_per_pixel = fb->samples_per_pixel;
  frame->stencil_bits = fb->stencil_bits;
  frame->vertical_sync = fb->vertical_sync;
  return frame;
}

HL_PRIM int HL_NAME(hl_window_create)(win_opts_hl* win, fb_opts_hl* fb) {
  return kinc_window_create(convert_win_opts_hl(win), convert_fb_opts_hl(fb));
}

HL_PRIM void HL_NAME(hl_window_destroy)(int index) {
  kinc_window_destroy(index);
}
HL_PRIM int HL_NAME(hl_count_windows)(){ return kinc_count_windows();}
HL_PRIM void HL_NAME(hl_window_resize)(int window_index, int width, int height){kinc_window_resize(window_index,width,height);}
HL_PRIM void HL_NAME(hl_window_move)(int window_index, int x, int y){kinc_window_move(window_index,x,y);}
HL_PRIM void HL_NAME(hl_window_change_mode)(int window_index, kinc_window_mode_t mode){kinc_window_change_mode(window_index,mode);}
HL_PRIM void HL_NAME(hl_window_change_features)(int window_index, int features){kinc_window_change_features(window_index,features);}
HL_PRIM void HL_NAME(hl_window_change_framebuffer)(int window_index, fb_opts_hl* frame){kinc_window_change_framebuffer(window_index,convert_fb_opts_hl(frame));}
HL_PRIM int HL_NAME(hl_window_x)(int window_index){return kinc_window_x(window_index);}
HL_PRIM int HL_NAME(hl_window_y)(int window_index) { return kinc_window_y(window_index); }
HL_PRIM int HL_NAME(hl_window_width)(int window_index) { return kinc_window_width(window_index); }
HL_PRIM int HL_NAME(hl_window_height)(int window_index) { return kinc_window_height(window_index); }
HL_PRIM int HL_NAME(hl_window_display)(int window_index) { return kinc_window_display(window_index); }
HL_PRIM kinc_window_mode_t HL_NAME(hl_window_get_mode)(int window_index) { return kinc_window_get_mode(window_index); }
HL_PRIM void HL_NAME(hl_window_show)(int window_index){kinc_window_show(window_index);}
HL_PRIM void HL_NAME(hl_window_hide)(int window_index){kinc_window_hide(window_index);}
HL_PRIM void HL_NAME(hl_window_set_title)(int window_index, vstring* title){kinc_window_set_title(window_index,hl_to_utf8(title->bytes));}

void internal_resize_callback(int x,int y,vclosure *data){
  if(data != NULL){
    vdynamic* _x = hl_alloc_dynamic(&hlt_i32);
    _x->v.i = x;
    vdynamic* _y = hl_alloc_dynamic(&hlt_i32);
    _y->v.i = y;
    vdynamic* args[2] = { _x, _y };
    bool isexp;
    hl_dyn_call_safe(data, args, 2, &isexp);
    if(isexp){
      kinc_log(KINC_LOG_LEVEL_WARNING,"Exception in window_resize_callback");
    }
  }
}
HL_PRIM void HL_NAME(hl_window_set_resize_callback)(int window_index, vclosure *cb){
  kinc_window_set_resize_callback(window_index,internal_resize_callback,cb);
}
void internal_ppi_changed_callback(int ppi, vclosure* data) {
  if (data != NULL) {
    hl_call1(void,data,int,ppi);
  }
}
HL_PRIM void HL_NAME(hl_window_set_ppi_changed_callback)(int window_index, vclosure *cb){
  kinc_window_set_ppi_changed_callback(window_index,internal_ppi_changed_callback,cb);
}
HL_PRIM bool HL_NAME(hl_window_vsynced)(int window_index){ return kinc_window_vsynced(window_index);}

DEFINE_PRIM(_I32, hl_window_create, HL_WINDOW_OPTS HL_FRAMEBUFFER_OPTS)
DEFINE_PRIM(_VOID, hl_window_destroy, _I32)
DEFINE_PRIM(_I32, hl_count_windows, _NO_ARG)
DEFINE_PRIM(_VOID, hl_window_resize, _I32 _I32 _I32)
DEFINE_PRIM(_VOID, hl_window_move, _I32 _I32 _I32)
DEFINE_PRIM(_VOID, hl_window_change_mode, _I32 _I32)
DEFINE_PRIM(_VOID, hl_window_change_features, _I32 _I32)
DEFINE_PRIM(_VOID, hl_window_change_framebuffer, _I32 HL_FRAMEBUFFER_OPTS)
DEFINE_PRIM(_I32, hl_window_x, _I32)
DEFINE_PRIM(_I32, hl_window_y, _I32)
DEFINE_PRIM(_I32, hl_window_width, _I32)
DEFINE_PRIM(_I32, hl_window_height, _I32)
DEFINE_PRIM(_I32, hl_window_display, _I32)
DEFINE_PRIM(_I32, hl_window_get_mode, _I32)
DEFINE_PRIM(_VOID, hl_window_show, _I32)
DEFINE_PRIM(_VOID, hl_window_hide, _I32)
DEFINE_PRIM(_VOID, hl_window_set_title, _I32 _STRING)
DEFINE_PRIM(_VOID,hl_window_set_resize_callback,_I32 _FUN(_VOID,_I32 _I32))
DEFINE_PRIM(_VOID,hl_window_set_ppi_changed_callback,_I32 _FUN(_VOID,_I32))
DEFINE_PRIM(_BOOL,hl_window_vsynced,_I32)