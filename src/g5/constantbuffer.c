#include "graphics5.h"

HL_PRIM void HL_NAME(hl_g5_constant_buffer_init)(hl_g5_constant_buffer *buf, int size) {
	kinc_g5_constant_buffer_init(&buf->t, size);
}

DEFINE_PRIM(_VOID, hl_g5_constant_buffer_init, _ABSTRACT(g5_constant_buffer) _I32)

HL_PRIM void HL_NAME(hl_g5_constant_buffer_lock)(hl_g5_constant_buffer *buf, int offset, int size) {
	kinc_g5_constant_buffer_lock(&buf->t, offset, size);
}

DEFINE_PRIM(_VOID, hl_g5_constant_buffer_lock, _ABSTRACT(g5_constant_buffer) _I32 _I32)

HL_PRIM void HL_NAME(hl_g5_constant_buffer_unlock)(hl_g5_constant_buffer *buf) {
	kinc_g5_constant_buffer_unlock(&buf->t);
}

DEFINE_PRIM(_VOID, hl_g5_constant_buffer_unlock, _ABSTRACT(g5_constant_buffer))

HL_PRIM void kinc_hl_g5_set_int(hl_g5_constant_buffer *buffer, int offset, int value) {
    kinc_g5_constant_buffer_set_int(&buffer->t, offset, value);
}

// HL_PRIM void kinc_hl_g5_set_int2(hl_g5_constant_buffer *buffer, int offset, int value1, int value2) {
//     kinc_g5_constant_buffer_set_int2(&buffer->t, offset, value1, value2);
// }

// HL_PRIM void kinc_hl_g5_set_int3(hl_g5_constant_buffer *buffer, int offset, int value1, int value2, int value3) {
//     kinc_g5_constant_buffer_set_int3(&buffer->t, offset, value1, value2, value3);
// }

// HL_PRIM void kinc_hl_g5_set_int4(hl_g5_constant_buffer *buffer, int offset, int value1, int value2, int value3, int value4) {
//     kinc_g5_constant_buffer_set_int4(&buffer->t, offset, value1, value2, value3, value4);
// }

// HL_PRIM void kinc_hl_g5_set_ints(hl_g5_constant_buffer *buffer, int offset, int *values, int count) {
//     kinc_g5_constant_buffer_set_ints(&buffer->t, offset, values, count);
// }

HL_PRIM void kinc_hl_g5_set_float(hl_g5_constant_buffer *buffer, int offset, float value) {
    kinc_g5_constant_buffer_set_float(&buffer->t, offset, value);
}

HL_PRIM void kinc_hl_g5_set_float2(hl_g5_constant_buffer *buffer, int offset, float value1, float value2) {
    kinc_g5_constant_buffer_set_float2(&buffer->t, offset, value1, value2);
}

HL_PRIM void kinc_hl_g5_set_float3(hl_g5_constant_buffer *buffer, int offset, float value1, float value2, float value3) {
    kinc_g5_constant_buffer_set_float3(&buffer->t, offset, value1, value2, value3);
}

HL_PRIM void kinc_hl_g5_set_float4(hl_g5_constant_buffer *buffer, int offset, float value1, float value2, float value3, float value4) {
    kinc_g5_constant_buffer_set_float4(&buffer->t, offset, value1, value2, value3, value4);
}

HL_PRIM void kinc_hl_g5_set_floats(hl_g5_constant_buffer *buffer, int offset, float *values, int count) {
    kinc_g5_constant_buffer_set_floats(&buffer->t, offset, values, count);
}

HL_PRIM void kinc_hl_g5_set_bool(hl_g5_constant_buffer *buffer, int offset, bool value) {
    kinc_g5_constant_buffer_set_bool(&buffer->t, offset, value);
}

HL_PRIM void kinc_hl_g5_set_matrix3(hl_g5_constant_buffer *buffer, int offset, kinc_matrix3x3_t *value) {
    kinc_g5_constant_buffer_set_matrix3(&buffer->t, offset, value);
}

HL_PRIM void kinc_hl_g5_set_matrix4(hl_g5_constant_buffer *buffer, int offset, kinc_matrix4x4_t *value) {
    kinc_g5_constant_buffer_set_matrix4(&buffer->t, offset, value);
}

DEFINE_PRIM(_VOID, hl_g5_set_int, _CONSTANT_BUFFER _I32 _I32)
// DEFINE_PRIM(_VOID, hl_g5_set_int2, _LOC _I32 _I32)
// DEFINE_PRIM(_VOID, hl_g5_set_int3, _LOC _I32 _I32 _I32)
// DEFINE_PRIM(_VOID, hl_g5_set_int4, _LOC _I32 _I32 _I32 _I32)
// DEFINE_PRIM(_VOID, hl_g5_set_ints, _LOC _BYTES _I32)
DEFINE_PRIM(_VOID, hl_g5_set_float, _CONSTANT_BUFFER _I32 _F32)
DEFINE_PRIM(_VOID, hl_g5_set_float2, _CONSTANT_BUFFER _I32 _F32 _F32)
DEFINE_PRIM(_VOID, hl_g5_set_float3, _CONSTANT_BUFFER _I32 _F32 _F32 _F32)
DEFINE_PRIM(_VOID, hl_g5_set_float4, _CONSTANT_BUFFER _I32 _F32 _F32 _F32 _F32)
DEFINE_PRIM(_VOID, hl_g5_set_floats, _CONSTANT_BUFFER _I32 _BYTES _I32)
DEFINE_PRIM(_VOID, hl_g5_set_bool, _CONSTANT_BUFFER _I32 _BOOL)
DEFINE_PRIM(_VOID, hl_g5_set_matrix3, _CONSTANT_BUFFER _I32 _ABSTRACT(kinc_matrix3x3_t))
DEFINE_PRIM(_VOID, hl_g5_set_matrix4, _CONSTANT_BUFFER _I32 _ABSTRACT(kinc_matrix4x4_t))