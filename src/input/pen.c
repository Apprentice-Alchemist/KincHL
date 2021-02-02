#include "kinchl.h"
#include <kinc/input/pen.h>

#define MAKE_CB(name) \
    vclosure * pen_##name##_cb = NULL;\
    void internal_pen_##name##_cb(int window, int x, int y,float pressure){\
        if(pen_##name##_cb != NULL){\
            vdynamic args[4] = {\
                {&hlt_i32,0},{&hlt_i32,0},{&hlt_i32,0},{&hlt_f32,0.0}\
            };\
            args[0].v.i = window;\
            args[1].v.i = x;\
            args[2].v.i = y;\
            args[3].v.f = pressure;\
            vdynamic* vargs[4] = { &args[0],&args[1],&args[2],&args[3] };\
            bool isExc = false;\
            vdynamic* exc = hl_dyn_call_safe(pen_##name##_cb, vargs, 4, &isExc);\
            if (isExc) {\
                kinc_log(KINC_LOG_LEVEL_ERROR, "Exception occured in pen" #name " callback");\
                print_exception_stack(exc);\
                kinc_stop();\
            }\
        }\
    }\
    HL_PRIM void HL_NAME(pen_set_##name##_callback)(vclosure *cb){\
        if(pen_##name##_cb != NULL){\
            hl_remove_root(pen_##name##_cb);\
        }\
        pen_##name##_cb = cb;\
        hl_add_root(pen_##name##_cb);\
        kinc_pen_##name##_callback = internal_pen_##name##_cb;\
    }\
    DEFINE_PRIM(_VOID,pen_set_##name##_callback,_FUN(_VOID,_I32 _I32 _I32 _F32))
MAKE_CB(press)
MAKE_CB(move)
MAKE_CB(release)