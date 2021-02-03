#include "kinchl.h"
#include <kinc/display.h>
typedef struct {
    kinc_display_mode_t internal;
} hl_display_mode;
DEFINE_PRIM(_VOID,display_init,_NO_ARG)
DEFINE_PRIM(_I32,primary_display,_NO_ARG)
DEFINE_PRIM(_I32,count_displays,_NO_ARG)
DEFINE_PRIM(_BOOL,display_available,_I32)
HL_PRIM vstring* HL_NAME(hl_display_name)(int index){return (vstring*)hl_alloc_strbytes(hl_to_utf16(kinc_display_name(index)));}
DEFINE_PRIM(_STRING,hl_display_name,_I32)
HL_PRIM hl_display_mode* HL_NAME(hl_display_current_mode)(int index){
    hl_display_mode *ret = hl_gc_alloc_raw(sizeof(hl_display_mode));
    ret->internal = kinc_display_current_mode(index);
    return ret;
}
DEFINE_PRIM(_ABSTRACT(kinc_display_mode_t),hl_display_current_mode,_I32)
DEFINE_PRIM(_I32,display_count_available_modes,_I32)
HL_PRIM hl_display_mode* HL_NAME(hl_display_available_mode)(int index,int mode_index) {
    hl_display_mode* ret = hl_gc_alloc_raw(sizeof(hl_display_mode));
    ret->internal = kinc_display_available_mode(index,mode_index);
    return ret;
}
DEFINE_PRIM(_ABSTRACT(kinc_display_mode_t), hl_display_available_mode, _I32 _I32)

#define __MAKE_GET(field_name,type,hl_ret)\
HL_PRIM type HL_NAME(hl_display_mode_get_ ##field_name)(hl_display_mode * o) {\
    return o->internal. field_name;\
  }\
  DEFINE_PRIM(hl_ret, hl_display_mode_get_ ##field_name, _ABSTRACT(kinc_display_mode_t))
__MAKE_GET(x,int,_I32)
__MAKE_GET(y,int,_I32)
__MAKE_GET(width, int, _I32)
__MAKE_GET(height, int, _I32)
__MAKE_GET(pixels_per_inch, int, _I32)
__MAKE_GET(frequency, int, _I32)
__MAKE_GET(bits_per_pixel, int, _I32)
