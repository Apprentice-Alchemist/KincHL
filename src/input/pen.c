#include "kinchl.h"
#include <kinc/input/pen.h>

#define MAKE_CB(name) \
    static vclosure * pen_##name##_cb = NULL;\
    static void internal_pen_##name##_cb(int window, int x, int y,float pressure){\
        if(pen_##name##_cb != NULL){\
            vdynamic args[4];\
            args[0].t = &hlt_i32;\
            args[0].v.i = window;\
            args[1].t = &hlt_i32;\
            args[1].v.i = x;\
            args[2].t = &hlt_i32;\
            args[2].v.i = y;\
            args[3].t = &hlt_f32;\
            args[3].v.f = pressure;\
            vdynamic* vargs[4] = { &args[0],&args[1],&args[2],&args[3] };\
            bool isExc = false;\
            vdynamic* exc = hl_dyn_call_safe(pen_##name##_cb, vargs, 4, &isExc);\
            if (isExc) {\
                handle_exception("pen " #name " callback",exc);\
            }\
        }\
    }\
    HL_PRIM void HL_NAME(pen_set_##name##_callback)(vclosure *cb){\
        pen_##name##_cb = cb;\
    }\
    DEFINE_PRIM(_VOID,pen_set_##name##_callback,_FUN(_VOID,_I32 _I32 _I32 _F32))
MAKE_CB(press)
MAKE_CB(move)
MAKE_CB(release)

void hl_pen_init() {
    hl_add_root(&pen_press_cb);
    hl_add_root(&pen_move_cb);
    hl_add_root(&pen_release_cb);
    kinc_pen_press_callback = internal_pen_press_cb;
    kinc_pen_move_callback = internal_pen_move_cb;
    kinc_pen_release_callback = internal_pen_release_cb;
}