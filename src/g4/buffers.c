#include "graphics4.h"

HL_PRIM void HL_NAME(hl_g4_vertex_buffer_init)(hl_g4_vertex_buffer* buf, int count, hl_g4_vertex_structure* structure, int usage, int data_step_rate) {
    kinc_g4_vertex_buffer_init(&buf->t, count, &structure->t, usage, data_step_rate);
}
HL_PRIM float* HL_NAME(hl_g4_vertex_buffer_lock_all)(hl_g4_vertex_buffer* buf) {
    return kinc_g4_vertex_buffer_lock_all(&buf->t);
}
HL_PRIM void HL_NAME(hl_g4_vertex_buffer_unlock_all)(hl_g4_vertex_buffer* buf) {
    kinc_g4_vertex_buffer_unlock_all(&buf->t);
}
HL_PRIM float* HL_NAME(hl_g4_vertex_buffer_lock)(hl_g4_vertex_buffer* buf, int start, int count) {
    return kinc_g4_vertex_buffer_lock(&buf->t, start, count);
}
HL_PRIM void HL_NAME(hl_g4_vertex_buffer_unlock)(hl_g4_vertex_buffer* buf, int count) {
    kinc_g4_vertex_buffer_unlock(&buf->t, count);
}
HL_PRIM int HL_NAME(hl_g4_vertex_buffer_count)(hl_g4_vertex_buffer* buf) {
    return kinc_g4_vertex_buffer_count(&buf->t);
}
HL_PRIM int HL_NAME(hl_g4_vertex_buffer_stride)(hl_g4_vertex_buffer* buf) {
    return kinc_g4_vertex_buffer_stride(&buf->t);
}

HL_PRIM void HL_NAME(hl_g4_index_buffer_init)(hl_g4_index_buffer* buf, int count, int format) {
    kinc_g4_index_buffer_init(&buf->t, count, format);
}
HL_PRIM int* HL_NAME(hl_g4_index_buffer_lock)(hl_g4_index_buffer* buf) {
    return kinc_g4_index_buffer_lock(&buf->t);
}
HL_PRIM void HL_NAME(hl_g4_index_buffer_unlock)(hl_g4_index_buffer* buf) {
    kinc_g4_index_buffer_unlock(&buf->t);
}
HL_PRIM int HL_NAME(hl_g4_index_buffer_count)(hl_g4_index_buffer* buf) {
    return kinc_g4_index_buffer_count(&buf->t);
}

DEFINE_PRIM(_VOID, hl_g4_vertex_buffer_init, _ABSTRACT(g4_vertex_buffer) _I32 _VERTEX_STRUCTURE _I32 _I32)
DEFINE_PRIM(_BYTES, hl_g4_vertex_buffer_lock, _ABSTRACT(g4_vertex_buffer) _I32 _I32)
DEFINE_PRIM(_BYTES, hl_g4_vertex_buffer_lock_all, _ABSTRACT(g4_vertex_buffer))
DEFINE_PRIM(_VOID, hl_g4_vertex_buffer_unlock, _ABSTRACT(g4_vertex_buffer) _I32)
DEFINE_PRIM(_VOID, hl_g4_vertex_buffer_unlock_all, _ABSTRACT(g4_vertex_buffer))
DEFINE_PRIM(_I32, hl_g4_vertex_buffer_count, _ABSTRACT(g4_vertex_buffer))
DEFINE_PRIM(_I32, hl_g4_vertex_buffer_stride, _ABSTRACT(g4_vertex_buffer))
DEFINE_PRIM(_VOID, hl_g4_index_buffer_init, _ABSTRACT(g4_index_buffer) _I32 _I32)
DEFINE_PRIM(_BYTES, hl_g4_index_buffer_lock, _ABSTRACT(g4_index_buffer))
DEFINE_PRIM(_VOID, hl_g4_index_buffer_unlock, _ABSTRACT(g4_index_buffer))
DEFINE_PRIM(_I32, hl_g4_index_buffer_count, _ABSTRACT(g4_index_buffer))
