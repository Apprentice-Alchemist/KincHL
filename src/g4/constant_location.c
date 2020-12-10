#include "graphics4.h"

HL_PRIM void kinc_hl_g4_set_int(kinc_g4_constant_location_t* location, int value) { kinc_g4_set_int(*location, value); }
HL_PRIM void kinc_hl_g4_set_int2(kinc_g4_constant_location_t* location, int value1, int value2) { kinc_g4_set_int2(*location, value1, value2); }
HL_PRIM void kinc_hl_g4_set_int3(kinc_g4_constant_location_t* location, int value1, int value2, int value3) { kinc_g4_set_int3(*location, value1, value2, value3); }
HL_PRIM void kinc_hl_g4_set_int4(kinc_g4_constant_location_t* location, int value1, int value2, int value3, int value4) { kinc_g4_set_int4(*location, value1, value2, value3, value4); }
HL_PRIM void kinc_hl_g4_set_ints(kinc_g4_constant_location_t* location, int* values, int count) { kinc_g4_set_ints(*location, values, count); }
HL_PRIM void kinc_hl_g4_set_float(kinc_g4_constant_location_t* location, float value) { kinc_g4_set_float(*location, value); }
HL_PRIM void kinc_hl_g4_set_float2(kinc_g4_constant_location_t* location, float value1, float value2) { kinc_g4_set_float2(*location, value1, value2); }
HL_PRIM void kinc_hl_g4_set_float3(kinc_g4_constant_location_t* location, float value1, float value2, float value3) { kinc_g4_set_float3(*location, value1, value2, value3); }
HL_PRIM void kinc_hl_g4_set_float4(kinc_g4_constant_location_t* location, float value1, float value2, float value3, float value4) { kinc_g4_set_float4(*location, value1, value2, value3, value4); }
HL_PRIM void kinc_hl_g4_set_floats(kinc_g4_constant_location_t* location, float* values, int count) { kinc_g4_set_floats(*location, values, count); }
HL_PRIM void kinc_hl_g4_set_bool(kinc_g4_constant_location_t* location, bool value) { kinc_g4_set_bool(*location, value); }
HL_PRIM void kinc_hl_g4_set_matrix3(kinc_g4_constant_location_t* location, kinc_matrix3x3_t* value) {
    kinc_g4_set_matrix3(*location, value);
}
HL_PRIM void kinc_hl_g4_set_matrix4(kinc_g4_constant_location_t* location, kinc_matrix4x4_t* value) { kinc_g4_set_matrix4(*location, value); }

DEFINE_PRIM(_VOID, hl_g4_set_int, _LOC _I32)
DEFINE_PRIM(_VOID, hl_g4_set_int2, _LOC _I32 _I32)
DEFINE_PRIM(_VOID, hl_g4_set_int3, _LOC _I32 _I32 _I32)
DEFINE_PRIM(_VOID, hl_g4_set_int4, _LOC _I32 _I32 _I32 _I32)
DEFINE_PRIM(_VOID, hl_g4_set_ints, _LOC _BYTES _I32)
DEFINE_PRIM(_VOID, hl_g4_set_float, _LOC _F32)
DEFINE_PRIM(_VOID, hl_g4_set_float2, _LOC _F32 _F32)
DEFINE_PRIM(_VOID, hl_g4_set_float3, _LOC _F32 _F32 _F32)
DEFINE_PRIM(_VOID, hl_g4_set_float4, _LOC _F32 _F32 _F32 _F32)
DEFINE_PRIM(_VOID, hl_g4_set_floats, _LOC _BYTES _I32)
DEFINE_PRIM(_VOID, hl_g4_set_bool, _LOC _BOOL)
DEFINE_PRIM(_VOID, hl_g4_set_matrix3, _LOC _ABSTRACT(kinc_matrix3x3_t))
DEFINE_PRIM(_VOID, hl_g4_set_matrix4, _LOC _ABSTRACT(kinc_matrix4x4_t))