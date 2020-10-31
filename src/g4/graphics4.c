#include "graphics4.h"

MAKE_OBJ_ARRAY(kinc_g4_vertex_buffer_t*, vertex_buffer, _ABSTRACT(kinc_g4_vertex_buffer_t))
MAKE_OBJ_ARRAY(kinc_g4_index_buffer_t*, index_buffer, _ABSTRACT(kinc_g4_index_buffer_t))
MAKE_OBJ_ARRAY(kinc_g4_vertex_structure_t*, vertex_structure, _ABSTRACT(kinc_g4_vertex_structure_t))

HL_PRIM void HL_NAME(hl_g4_begin)(int index) { kinc_g4_begin(index); }
HL_PRIM void HL_NAME(hl_g4_clear)(unsigned int flags, unsigned int color, float depth, float stencil) { kinc_g4_clear(flags, color, depth, stencil); }
HL_PRIM void HL_NAME(hl_g4_end)(int index) { kinc_g4_end(index); }
HL_PRIM bool HL_NAME(hl_g4_swap_buffers)() { return kinc_g4_swap_buffers(); }
HL_PRIM void HL_NAME(hl_g4_flush)() { kinc_g4_flush(); }
HL_PRIM void HL_NAME(hl_g4_set_pipeline)(kinc_g4_pipeline_t* state) { kinc_g4_set_pipeline(state); }
HL_PRIM void HL_NAME(hl_g4_set_vertex_buffer)(kinc_g4_vertex_buffer_t* buf) { kinc_g4_set_vertex_buffer(buf); }
HL_PRIM void HL_NAME(hl_g4_set_vertex_buffers)(kinc_g4_vertex_buffer_t** buf, int count) { kinc_g4_set_vertex_buffers(buf, count); }
HL_PRIM void HL_NAME(hl_g4_set_index_buffer)(kinc_g4_index_buffer_t* buf) { kinc_g4_set_index_buffer(buf); }
HL_PRIM void HL_NAME(hl_g4_draw_indexed_vertices)() { kinc_g4_draw_indexed_vertices(); }

DEFINE_PRIM(_VOID, hl_g4_begin, _I32)
DEFINE_PRIM(_VOID, hl_g4_clear, _I32 _I32 _F32 _F32)
DEFINE_PRIM(_VOID, hl_g4_end, _I32)
DEFINE_PRIM(_BOOL, hl_g4_swap_buffers, _NO_ARG)
DEFINE_PRIM(_VOID, hl_g4_flush, _NO_ARG)

DEFINE_PRIM(_VOID, hl_g4_set_pipeline, _ABSTRACT(kinc_g4_pipeline_t))
DEFINE_PRIM(_VOID, hl_g4_set_vertex_buffer, _ABSTRACT(kinc_g4_vertex_buffer_t))
DEFINE_PRIM(_VOID, hl_g4_set_vertex_buffers, _REF(_ABSTRACT(kinc_g4_vertex_buffer_t)) _I32)
DEFINE_PRIM(_VOID, hl_g4_set_index_buffer, _ABSTRACT(kinc_g4_index_buffer_t))
DEFINE_PRIM(_VOID, hl_g4_draw_indexed_vertices, _NO_ARG)