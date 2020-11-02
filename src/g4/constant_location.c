#include "graphics4.h"
#include <kinc/error.h>
#include <kinc/log.h>
HL_PRIM void kinc_hl_g4_set_int(hl_const_loc* location, int value) { kinc_g4_set_int(location->loc, value); }
HL_PRIM void kinc_hl_g4_set_int2(hl_const_loc* location, int value1, int value2) { kinc_g4_set_int2(location->loc, value1, value2); }
HL_PRIM void kinc_hl_g4_set_int3(hl_const_loc* location, int value1, int value2, int value3) { kinc_g4_set_int3(location->loc, value1, value2, value3); }
HL_PRIM void kinc_hl_g4_set_int4(hl_const_loc* location, int value1, int value2, int value3, int value4) { kinc_g4_set_int4(location->loc, value1, value2, value3, value4); }
HL_PRIM void kinc_hl_g4_set_ints(hl_const_loc* location, int* values, int count) { kinc_g4_set_ints(location->loc, values, count); }
HL_PRIM void kinc_hl_g4_set_float(hl_const_loc* location, float value) { kinc_g4_set_float(location->loc, value); }
HL_PRIM void kinc_hl_g4_set_float2(hl_const_loc* location, float value1, float value2) { kinc_g4_set_float2(location->loc, value1, value2); }
HL_PRIM void kinc_hl_g4_set_float3(hl_const_loc* location, float value1, float value2, float value3) { kinc_g4_set_float3(location->loc, value1, value2, value3); }
HL_PRIM void kinc_hl_g4_set_float4(hl_const_loc* location, float value1, float value2, float value3, float value4) { kinc_g4_set_float4(location->loc, value1, value2, value3, value4); }
HL_PRIM void kinc_hl_g4_set_floats(hl_const_loc* location, float* values, float count) { kinc_g4_set_floats(location->loc, values, count); }
HL_PRIM void kinc_hl_g4_set_bool(hl_const_loc* location, bool value) { kinc_g4_set_bool(location->loc, value); }
HL_PRIM void kinc_hl_g4_set_matrix3(hl_const_loc* location, kinc_matrix3x3_t* value) {
    kinc_g4_set_matrix3(location->loc, value);
}
HL_PRIM void kinc_hl_g4_set_matrix4(hl_const_loc* location, kinc_matrix4x4_t* value) { kinc_g4_set_matrix4(location->loc, value); }

DEFINE_PRIM(_VOID, hl_g4_set_int, _LOC _I32)
DEFINE_PRIM(_VOID, hl_g4_set_int2, _LOC _I32 _I32)
DEFINE_PRIM(_VOID, hl_g4_set_int3, _LOC _I32 _I32 _I32)
DEFINE_PRIM(_VOID, hl_g4_set_int4, _LOC _I32 _I32 _I32 _I32)
DEFINE_PRIM(_VOID, hl_g4_set_ints, _LOC _REF(_I32) _I32)
DEFINE_PRIM(_VOID, hl_g4_set_float, _LOC _F32)
DEFINE_PRIM(_VOID, hl_g4_set_float2, _LOC _F32 _F32)
DEFINE_PRIM(_VOID, hl_g4_set_float3, _LOC _F32 _F32 _F32)
DEFINE_PRIM(_VOID, hl_g4_set_float4, _LOC _F32 _F32 _F32 _F32)
DEFINE_PRIM(_VOID, hl_g4_set_floats, _LOC _REF(_F32) _I32)
DEFINE_PRIM(_VOID, hl_g4_set_bool, _LOC _BOOL)
DEFINE_PRIM(_VOID, hl_g4_set_matrix3, _LOC _ABSTRACT(kinc_matrix3x3_t))
DEFINE_PRIM(_VOID, hl_g4_set_matrix4, _LOC _ABSTRACT(kinc_matrix4x4_t))