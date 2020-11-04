#include "graphics4.h"

MAKE_OBJ_ARRAY(kinc_g4_vertex_buffer_t*, vertex_buffer, _ABSTRACT(kinc_g4_vertex_buffer_t))
MAKE_OBJ_ARRAY(kinc_g4_index_buffer_t*, index_buffer, _ABSTRACT(kinc_g4_index_buffer_t))
MAKE_OBJ_ARRAY(kinc_g4_vertex_structure_t*, vertex_structure, _ABSTRACT(kinc_g4_vertex_structure_t))
MAKE_OBJ_ARRAY(kinc_g4_render_target_t*,render_target,_ABSTRACT(kinc_g4_render_target_t))

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
HL_PRIM void HL_NAME(hl_g4_set_texture_addressing)(hl_tex_unit* unit, kinc_g4_texture_direction_t dir, kinc_g4_texture_addressing_t addressing) { kinc_g4_set_texture_addressing(unit->loc, dir, addressing); }
HL_PRIM void HL_NAME(hl_g4_set_texture3d_addressing)(hl_tex_unit* unit, kinc_g4_texture_direction_t dir, kinc_g4_texture_addressing_t addressing) { kinc_g4_set_texture3d_addressing(unit->loc, dir, addressing); }
HL_PRIM int HL_NAME(hl_g4_max_bound_textures)() { return kinc_g4_max_bound_textures(); }
HL_PRIM bool HL_NAME(hl_g4_render_targets_inverted_y)() { return kinc_g4_render_targets_inverted_y(); }
HL_PRIM bool HL_NAME(hl_g4_non_pow2_textures_supported)() { return kinc_g4_non_pow2_textures_supported(); }
HL_PRIM void HL_NAME(hl_g4_restore_render_target)() { kinc_g4_restore_render_target(); }
HL_PRIM void HL_NAME(hl_g4_set_render_targets)(kinc_g4_render_target_t** targets, int count) { kinc_g4_set_render_targets(targets, count); }
HL_PRIM void HL_NAME(hl_g4_set_render_target_face)(kinc_g4_render_target_t* texture, int face) { kinc_g4_set_render_target_face(texture, face); }
HL_PRIM void HL_NAME(hl_g4_set_texture)(hl_tex_unit* unit, kinc_g4_texture_t* texture) { kinc_g4_set_texture(unit->loc, texture); }
HL_PRIM void HL_NAME(hl_g4_set_image_texture)(hl_tex_unit* unit, kinc_g4_texture_t* texture) { kinc_g4_set_image_texture(unit->loc, texture); }
HL_PRIM bool HL_NAME(hl_g4_init_occlusion_query)(unsigned* occlusionQuery) { return kinc_g4_init_occlusion_query(occlusionQuery); }
HL_PRIM void HL_NAME(hl_g4_delete_occlusion_query)(unsigned occlusionQuery) { kinc_g4_delete_occlusion_query(occlusionQuery); }
HL_PRIM void HL_NAME(hl_g4_start_occlusion_query)(unsigned occlusionQuery) { kinc_g4_start_occlusion_query(occlusionQuery); }
HL_PRIM void HL_NAME(hl_g4_end_occlusion_query)(unsigned occlusionQuery) { kinc_g4_end_occlusion_query(occlusionQuery); }
HL_PRIM bool HL_NAME(hl_g4_are_query_results_available)(unsigned occlusionQuery) { return kinc_g4_are_query_results_available(occlusionQuery); }
HL_PRIM void HL_NAME(hl_g4_get_query_results)(unsigned occlusionQuery, unsigned* pixelCount) { kinc_g4_get_query_results(occlusionQuery, pixelCount); }
HL_PRIM void HL_NAME(hl_g4_set_texture_array)(hl_tex_unit* unit, kinc_g4_texture_array_t* array) { kinc_g4_set_texture_array(unit->loc, array); }
HL_PRIM int HL_NAME(hl_g4_antialiasing_samples)() { return kinc_g4_antialiasing_samples(); }
HL_PRIM void HL_NAME(hl_g4_set_antialiasing_samples)(int samples) { kinc_g4_set_antialiasing_samples(samples); }

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
DEFINE_PRIM(_I32, hl_g4_max_bound_textures, _NO_ARG)
DEFINE_PRIM(_BOOL, hl_g4_render_targets_inverted_y, _NO_ARG)
DEFINE_PRIM(_BOOL, hl_g4_non_pow2_textures_supported, _NO_ARG)
DEFINE_PRIM(_VOID, hl_g4_restore_render_target, _NO_ARG)
DEFINE_PRIM(_VOID, hl_g4_set_render_targets, _REF(_ABSTRACT(kinc_g4_render_target_t)) _I32)
DEFINE_PRIM(_VOID, hl_g4_set_render_target_face, _ABSTRACT(kinc_g4_render_target_t) _I32)
DEFINE_PRIM(_VOID, hl_g4_set_texture, _TUNIT _ABSTRACT(kinc_g4_texture_t))
DEFINE_PRIM(_VOID, hl_g4_set_image_texture, _TUNIT _ABSTRACT(kinc_g4_texture_t))
DEFINE_PRIM(_BOOL, hl_g4_init_occlusion_query, _REF(_I32))
DEFINE_PRIM(_VOID, hl_g4_delete_occlusion_query, _I32)
DEFINE_PRIM(_VOID, hl_g4_start_occlusion_query, _I32)
DEFINE_PRIM(_VOID, hl_g4_end_occlusion_query, _I32)
DEFINE_PRIM(_BOOL, hl_g4_are_query_results_available, _I32)
DEFINE_PRIM(_VOID, hl_g4_get_query_results, _I32 _REF(_I32))
DEFINE_PRIM(_VOID,hl_g4_set_texture_array,_TUNIT _ABSTRACT(kinc_g4_texture_array_t))
DEFINE_PRIM(_I32, hl_g4_antialiasing_samples, _NO_ARG)
DEFINE_PRIM(_VOID, hl_g4_set_antialiasing_samples, _I32)