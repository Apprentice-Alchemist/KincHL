#include "kinchl.h"
#include <kinc/system.h>
#include <kinc/input/surface.h>

#define MAKE_CB(name) \
    static vclosure * surface_##name##_cb = NULL;\
    static void internal_surface_##name##_cb(int index, int x, int y){\
        if(surface_##name##_cb != NULL){\
            vdynamic args[3] = {\
                {&hlt_i32,0},{&hlt_i32,0},{&hlt_i32,0}\
            };\
            args[0].v.i = index;\
            args[1].v.i = x;\
            args[2].v.i = y;\
            vdynamic* vargs[3] = { &args[0],&args[1],&args[2] };\
            bool isExc = false;\
            vdynamic* exc = hl_dyn_call_safe(surface_##name##_cb, vargs, 3, &isExc);\
            if (isExc) {\
                handle_exception("surface" #name "callback", exc);\
            }\
        }\
    }\
    HL_PRIM void HL_NAME(surface_set_##name##_callback)(vclosure * cb) {\
        if(!surface_##name##_cb){\
            if(!cb) return;\
            hl_remove_root(surface_##name##_cb);\
        }\
        if(surface_##name##_cb && !cb){\
            hl_remove_root(&surface_##name##_cb);\
            surface_##name##_cb = NULL;\
            kinc_surface_##name##_callback = NULL;\
            return;\
        }\
        surface_##name##_cb = cb;\
        kinc_surface_##name##_callback = internal_surface_##name##_cb;\
    }\
    DEFINE_PRIM(_VOID,surface_set_##name##_callback,_FUN(_VOID,_I32 _I32 _I32))

MAKE_CB(touch_start)
MAKE_CB(move)
MAKE_CB(touch_end)
