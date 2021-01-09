#include "kinchl.h"
#include <kinc/input/mouse.h>
#define MAKE_CALLBACK(cb_name) \
HL_PRIM void HL_NAME(mouse_set_##cb_name##_callback)(vclosure* cb) {\
    if (!mouse_##cb_name##_cb) {\
        if(!cb) return;\
        hl_add_root(&mouse_##cb_name##_cb);\
    }\
    if(mouse_##cb_name##_cb && !cb){\
        hl_remove_root(&mouse_##cb_name##_cb);\
        mouse_##cb_name##_cb = NULL;\
        kinc_mouse_##cb_name##_callback = NULL;\
        return;\
    }\
    mouse_##cb_name##_cb = cb;\
    kinc_mouse_##cb_name##_callback = internal_mouse_##cb_name##_cb;\
}
vclosure* mouse_press_cb = NULL;
vclosure* mouse_release_cb = NULL;
vclosure* mouse_move_cb = NULL;
vclosure* mouse_scroll_cb = NULL;
vclosure* mouse_enter_window_cb = NULL;
vclosure* mouse_leave_window_cb = NULL;
void internal_mouse_press_cb(int window, int button, int x, int y) {
    if (mouse_press_cb != NULL) {
        hl_call4(void, mouse_press_cb, int, window, int, button, int, x, int, y);
    }
}
void internal_mouse_release_cb(int window, int button, int x, int y) {
    if (mouse_release_cb != NULL) {
        hl_call4(void, mouse_release_cb, int, window, int, button, int, x, int, y);
    }
}
void internal_mouse_move_cb(int window, int x, int y, int movement_x, int movement_y) {
    if (mouse_move_cb != NULL) {
        vdynamic *args[5] = {hl_make_dyn(&window, &hlt_i32), hl_make_dyn(&x, &hlt_i32), hl_make_dyn(&y, &hlt_i32), hl_make_dyn(&movement_x, &hlt_i32), hl_make_dyn(&movement_y, &hlt_i32)};
        hl_dyn_call(mouse_move_cb,args,5);
    }
}
void internal_mouse_scroll_cb(int window, int delta) {
    if (mouse_scroll_cb != NULL) {
        hl_call2(void, mouse_scroll_cb, int, window, int, delta);
    }
}
void internal_mouse_enter_window_cb(int window) {
    if (mouse_enter_window_cb != NULL) {
        hl_call1(void, mouse_enter_window_cb, int, window);
    }
}
void internal_mouse_leave_window_cb(int window) {
    if (mouse_leave_window_cb != NULL) {
        hl_call1(void, mouse_leave_window_cb, int, window);
    }
}
MAKE_CALLBACK(press)
MAKE_CALLBACK(release)
MAKE_CALLBACK(move)
MAKE_CALLBACK(scroll)
MAKE_CALLBACK(enter_window)
MAKE_CALLBACK(leave_window)

DEFINE_PRIM(_BOOL, mouse_can_lock, _I32)
DEFINE_PRIM(_BOOL, mouse_is_locked, _I32)
DEFINE_PRIM(_VOID, mouse_lock, _I32)
DEFINE_PRIM(_VOID, mouse_unlock, _I32)
DEFINE_PRIM(_VOID, mouse_set_cursor, _I32)
DEFINE_PRIM(_VOID, mouse_show, _NO_ARG)
DEFINE_PRIM(_VOID, mouse_hide, _NO_ARG)
DEFINE_PRIM(_VOID, mouse_set_position, _I32 _I32 _I32)
DEFINE_PRIM(_VOID, mouse_get_position, _I32 _REF(_I32) _REF(_I32))
DEFINE_PRIM(_VOID, mouse_set_press_callback, _FUN(_VOID, _I32 _I32 _I32 _I32))
DEFINE_PRIM(_VOID, mouse_set_release_callback, _FUN(_VOID, _I32 _I32 _I32 _I32))
DEFINE_PRIM(_VOID, mouse_set_move_callback, _FUN(_VOID, _I32 _I32 _I32 _I32 _I32))
DEFINE_PRIM(_VOID, mouse_set_scroll_callback, _FUN(_VOID, _I32 _I32))
DEFINE_PRIM(_VOID, mouse_set_enter_window_callback, _FUN(_VOID, _I32))
DEFINE_PRIM(_VOID, mouse_set_leave_window_callback, _FUN(_VOID, _I32))