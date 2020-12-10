#include "kinchl.h"
#include <kinc/input/pen.h>

#define MAKE_CB(name) \
    vclosure * pen_##name##_cb = NULL;\
    void internal_pen_##name##_cb(int window, int x, int y,float pressure){\
        if(pen_##name##_cb != NULL){\
            hl_call4(void,pen_##name##_cb,int,window,int,x,int,y,float,pressure);\
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