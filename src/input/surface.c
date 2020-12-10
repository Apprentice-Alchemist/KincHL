#include "kinchl.h"
#include <kinc/input/surface.h>

#define MAKE_CB(name) \
    vclosure * surface_##name##_cb = NULL;\
    void internal_surface_##name##_cb(int index, int x, int y){\
        if(surface_##name##_cb != NULL){\
            hl_call3(void,surface_##name##_cb,int,index,int,x,int,y);\
        }\
    }\
    HL_PRIM void HL_NAME(surface_set_##name##_callback)(vclosure *cb){\
        if(surface_##name##_cb != NULL){\
            hl_remove_root(surface_##name##_cb);\
        }\
        surface_##name##_cb = cb;\
        hl_add_root(surface_##name##_cb);\
        kinc_surface_##name##_callback = internal_surface_##name##_cb;\
    }\
    DEFINE_PRIM(_VOID,surface_set_##name##_callback,_FUN(_VOID,_I32 _I32 _I32))

MAKE_CB(touch_start)
MAKE_CB(move)
MAKE_CB(touch_end)
