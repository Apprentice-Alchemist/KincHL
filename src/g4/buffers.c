#include "graphics4.h"
ALLOC_OBJ(kinc_g4_vertex_buffer_t, vertex_buffer, _ABSTRACT(kinc_g4_vertex_buffer_t), EMPTY_INIT, kinc_g4_vertex_buffer_destroy)
ALLOC_OBJ(kinc_g4_index_buffer_t, index_buffer, _ABSTRACT(kinc_g4_index_buffer_t), EMPTY_INIT, kinc_g4_index_buffer_destroy)

HL_PRIM void HL_NAME(hl_g4_vertex_buffer_init)(kinc_g4_vertex_buffer_t* buf, int count, kinc_g4_vertex_structure_t* structure, int usage, int data_step_rate) { kinc_g4_vertex_buffer_init(buf, count, structure, usage, data_step_rate); }
HL_PRIM float* HL_NAME(hl_g4_vertex_buffer_lock_all)(kinc_g4_vertex_buffer_t* buf) { return kinc_g4_vertex_buffer_lock_all(buf); }
HL_PRIM void HL_NAME(hl_g4_vertex_buffer_unlock_all)(kinc_g4_vertex_buffer_t* buf) { kinc_g4_vertex_buffer_unlock_all(buf); }
HL_PRIM float* HL_NAME(hl_g4_vertex_buffer_lock)(kinc_g4_vertex_buffer_t* buf, int start, int count) { return kinc_g4_vertex_buffer_lock(buf, start, count); }
HL_PRIM void HL_NAME(hl_g4_vertex_buffer_unlock)(kinc_g4_vertex_buffer_t* buf, int start, int count) { kinc_g4_vertex_buffer_unlock(buf, start, count); }
HL_PRIM int HL_NAME(hl_g4_vertex_buffer_count)(kinc_g4_vertex_buffer_t* buf) { return kinc_g4_vertex_buffer_count(buf); }
HL_PRIM int HL_NAME(hl_g4_vertex_buffer_stride)(kinc_g4_vertex_buffer_t* buf) { return kinc_g4_vertex_buffer_stride(buf); }
HL_PRIM void HL_NAME(hl_g4_index_buffer_init)(kinc_g4_index_buffer_t* buf, int count, int format) { kinc_g4_index_buffer_init(buf, count, format); }
HL_PRIM int* HL_NAME(hl_g4_index_buffer_lock)(kinc_g4_index_buffer_t* buf) { return kinc_g4_index_buffer_lock(buf); }
HL_PRIM void HL_NAME(hl_g4_index_buffer_unlock)(kinc_g4_index_buffer_t* buf) { kinc_g4_index_buffer_unlock(buf); }
HL_PRIM int HL_NAME(hl_g4_index_buffer_count)(kinc_g4_index_buffer_t* buf) { return kinc_g4_index_buffer_count(buf); }

DEFINE_PRIM(_VOID, hl_g4_vertex_buffer_init, _ABSTRACT(kinc_g4_vertex_buffer_t) _I32 _ABSTRACT(kinc_g4_vertex_structure_t) _I32 _I32)
DEFINE_PRIM(_REF(_F32), hl_g4_vertex_buffer_lock, _ABSTRACT(kinc_g4_vertex_buffer_t) _I32 _I32)
DEFINE_PRIM(_REF(_F32), hl_g4_vertex_buffer_lock_all, _ABSTRACT(kinc_g4_vertex_buffer_t))
DEFINE_PRIM(_VOID, hl_g4_vertex_buffer_unlock, _ABSTRACT(kinc_g4_vertex_buffer_t) _I32 _I32)
DEFINE_PRIM(_VOID, hl_g4_vertex_buffer_unlock_all, _ABSTRACT(kinc_g4_vertex_buffer_t))
DEFINE_PRIM(_I32, hl_g4_vertex_buffer_count, _ABSTRACT(kinc_g4_vertex_buffer_t))
DEFINE_PRIM(_I32, hl_g4_vertex_buffer_stride, _ABSTRACT(kinc_g4_vertex_buffer_t))
DEFINE_PRIM(_VOID, hl_g4_index_buffer_init, _ABSTRACT(kinc_g4_index_buffer_t) _I32 _I32)
DEFINE_PRIM(_REF(_I32), hl_g4_index_buffer_lock, _ABSTRACT(kinc_g4_index_buffer_t))
DEFINE_PRIM(_VOID, hl_g4_index_buffer_unlock, _ABSTRACT(kinc_g4_index_buffer_t))
DEFINE_PRIM(_I32, hl_g4_index_buffer_count, _ABSTRACT(kinc_g4_index_buffer_t))