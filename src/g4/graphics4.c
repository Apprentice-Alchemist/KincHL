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
HL_PRIM void HL_NAME(hl_g4_viewport)(int x, int y, int width, int height) { kinc_g4_viewport(x, y, width, height); }
HL_PRIM void HL_NAME(hl_g4_scissor)(int x, int y, int width, int height) { kinc_g4_scissor(x, y, width, height); }
HL_PRIM void HL_NAME(hl_g4_disable_scissor)() { kinc_g4_disable_scissor(); }
HL_PRIM void HL_NAME(hl_g4_draw_indexed_vertices_from_to)(int start, int count) { kinc_g4_draw_indexed_vertices_from_to(start, count); }
HL_PRIM void HL_NAME(hl_g4_draw_indexed_vertices_from_to_from)(int start, int count, int vertex_offset) { kinc_g4_draw_indexed_vertices_from_to_from(start, count, vertex_offset); }
HL_PRIM void HL_NAME(hl_g4_draw_indexed_vertices_instanced)(int instanceCount) { kinc_g4_draw_indexed_vertices_instanced(instanceCount); }
HL_PRIM void HL_NAME(hl_g4_draw_indexed_vertices_instanced_from_to)(int instanceCount, int start, int count) { kinc_g4_draw_indexed_vertices_instanced_from_to(instanceCount, start, count); }
HL_PRIM void HL_NAME(hl_g4_set_texture_addressing)(kinc_g4_texture_unit_t* unit, kinc_g4_texture_direction_t dir, kinc_g4_texture_addressing_t addressing) { kinc_g4_set_texture_addressing(*unit, dir, addressing); }
HL_PRIM void HL_NAME(hl_g4_set_texture3d_addressing)(kinc_g4_texture_unit_t* unit, kinc_g4_texture_direction_t dir, kinc_g4_texture_addressing_t addressing) { kinc_g4_set_texture3d_addressing(*unit, dir, addressing); }

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
DEFINE_PRIM(_VOID, hl_g4_viewport, _I32 _I32 _I32 _I32)
DEFINE_PRIM(_VOID, hl_g4_scissor, _I32 _I32 _I32 _I32)
DEFINE_PRIM(_VOID, hl_g4_disable_scissor, _NO_ARG)
DEFINE_PRIM(_VOID, hl_g4_draw_indexed_vertices_from_to, _I32 _I32)
DEFINE_PRIM(_VOID, hl_g4_draw_indexed_vertices_from_to_from, _I32 _I32 _I32)
DEFINE_PRIM(_VOID, hl_g4_draw_indexed_vertices_instanced, _I32)
DEFINE_PRIM(_VOID, hl_g4_draw_indexed_vertices_instanced_from_to, _I32 _I32 _I32)
DEFINE_PRIM(_VOID, hl_g4_set_texture_addressing, _TUNIT _I32 _I32)
DEFINE_PRIM(_VOID, hl_g4_set_texture3d_addressing, _TUNIT _I32 _I32)