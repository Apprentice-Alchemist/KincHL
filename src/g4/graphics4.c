#include "graphics4.h"

ALLOC_OBJ_EX(g4_pipeline, kinc_g4_pipeline_t, kinc_g4_pipeline_init, kinc_g4_pipeline_destroy)
ALLOC_OBJ_EX(g4_render_target, kinc_g4_render_target_t, EMPTY_INIT, kinc_g4_render_target_destroy)
ALLOC_OBJ_EX(g4_shader, kinc_g4_shader_t, EMPTY_INIT, kinc_g4_shader_destroy)
ALLOC_OBJ_EX(g4_texture, kinc_g4_texture_t, EMPTY_INIT, kinc_g4_texture_destroy)
ALLOC_OBJ_EX(g4_vertex_structure, kinc_g4_vertex_structure_t, kinc_g4_vertex_structure_init, EMPTY_DESTROY)
ALLOC_OBJ_EX(g4_vertex_buffer, kinc_g4_vertex_buffer_t, EMPTY_INIT, kinc_g4_vertex_buffer_destroy)
ALLOC_OBJ_EX(g4_index_buffer, kinc_g4_index_buffer_t, EMPTY_INIT, kinc_g4_index_buffer_destroy)
ALLOC_OBJ_EX(g4_texture_array, kinc_g4_texture_array_t, EMPTY_INIT, kinc_g4_texture_array_destroy)

HL_PRIM void HL_NAME(hl_g4_begin)(int index) {
    kinc_g4_begin(index);
}
HL_PRIM void HL_NAME(hl_g4_clear)(unsigned int flags, unsigned int color, float depth, int stencil) {
    kinc_g4_clear(flags, color, depth, stencil);
}
HL_PRIM void HL_NAME(hl_g4_end)(int index) {
    kinc_g4_end(index);
}
HL_PRIM bool HL_NAME(hl_g4_swap_buffers)() {
    return kinc_g4_swap_buffers();
}
HL_PRIM void HL_NAME(hl_g4_flush)() {
    kinc_g4_flush();
}
HL_PRIM void HL_NAME(hl_g4_set_pipeline)(hl_g4_pipeline *state) {
    kinc_g4_set_pipeline(&state->t);
}
HL_PRIM void HL_NAME(hl_g4_set_vertex_buffer)(hl_g4_vertex_buffer *buf) {
    kinc_g4_set_vertex_buffer(&buf->t);
}
HL_PRIM void HL_NAME(hl_g4_set_vertex_buffers)(varray *bufs) {
    kinc_g4_vertex_buffer_t **arr = malloc(sizeof(kinc_g4_vertex_buffer_t *) * bufs->size);
    memset(arr, 0, sizeof(kinc_g4_vertex_buffer_t *) * bufs->size);
    for (int i = 0; i < bufs->size; i++) {
        hl_g4_vertex_buffer *b = hl_aptr(bufs, hl_g4_vertex_buffer *)[i];
        arr[i] = &(b->t);
    }
    // arr[bufs->size] = NULL;
    kinc_g4_set_vertex_buffers(arr, bufs->size);
    free(arr);
}
HL_PRIM void HL_NAME(hl_g4_set_index_buffer)(hl_g4_index_buffer *buf) {
    kinc_g4_set_index_buffer(&buf->t);
}
HL_PRIM void HL_NAME(hl_g4_draw_indexed_vertices)() {
    kinc_g4_draw_indexed_vertices();
}
HL_PRIM void HL_NAME(hl_g4_viewport)(int x, int y, int width, int height) {
    kinc_g4_viewport(x, y, width, height);
}
HL_PRIM void HL_NAME(hl_g4_scissor)(int x, int y, int width, int height) {
    kinc_g4_scissor(x, y, width, height);
}
HL_PRIM void HL_NAME(hl_g4_disable_scissor)() {
    kinc_g4_disable_scissor();
}
HL_PRIM void HL_NAME(hl_g4_draw_indexed_vertices_from_to)(int start, int count) {
    kinc_g4_draw_indexed_vertices_from_to(start, count);
}
HL_PRIM void HL_NAME(hl_g4_draw_indexed_vertices_from_to_from)(int start, int count, int vertex_offset) {
    kinc_g4_draw_indexed_vertices_from_to_from(start, count, vertex_offset);
}
HL_PRIM void HL_NAME(hl_g4_draw_indexed_vertices_instanced)(int instanceCount) {
    kinc_g4_draw_indexed_vertices_instanced(instanceCount);
}
HL_PRIM void HL_NAME(hl_g4_draw_indexed_vertices_instanced_from_to)(int instanceCount, int start, int count) {
    kinc_g4_draw_indexed_vertices_instanced_from_to(instanceCount, start, count);
}
HL_PRIM void HL_NAME(hl_g4_set_texture_addressing)(kinc_g4_texture_unit_t *unit, kinc_g4_texture_direction_t dir, kinc_g4_texture_addressing_t addressing) {
    kinc_g4_set_texture_addressing(*unit, dir, addressing);
}
HL_PRIM void HL_NAME(hl_g4_set_texture3d_addressing)(kinc_g4_texture_unit_t *unit, kinc_g4_texture_direction_t dir, kinc_g4_texture_addressing_t addressing) {
    kinc_g4_set_texture3d_addressing(*unit, dir, addressing);
}
HL_PRIM int HL_NAME(hl_g4_max_bound_textures)() {
    return kinc_g4_max_bound_textures();
}
HL_PRIM bool HL_NAME(hl_g4_render_targets_inverted_y)() {
    return kinc_g4_render_targets_inverted_y();
}
HL_PRIM bool HL_NAME(hl_g4_non_pow2_textures_supported)() {
    return kinc_g4_non_pow2_textures_supported();
}
HL_PRIM void HL_NAME(hl_g4_restore_render_target)() {
    kinc_g4_restore_render_target();
}
HL_PRIM void HL_NAME(hl_g4_set_render_targets)(varray *targets) {
    kinc_g4_render_target_t **arr = malloc(sizeof(kinc_g4_render_target_t *) * targets->size);
    for (int i = 0; i < targets->size; i++) {
        kinc_g4_render_target_t *t = &(hl_aptr(targets, hl_g4_render_target *)[i]->t);
        arr[i] = t;
    }
    kinc_g4_set_render_targets(arr, targets->size);
    free(arr);
}
HL_PRIM void HL_NAME(hl_g4_set_render_target_face)(hl_g4_render_target *texture, int face) {
    kinc_g4_set_render_target_face(&texture->t, face);
}
HL_PRIM void HL_NAME(hl_g4_set_texture)(kinc_g4_texture_unit_t *unit, hl_g4_texture *texture) {
    kinc_g4_set_texture(*unit, &texture->t);
}
HL_PRIM void HL_NAME(hl_g4_set_image_texture)(kinc_g4_texture_unit_t *unit, hl_g4_texture *texture) {
    kinc_g4_set_image_texture(*unit, &texture->t);
}

//HL_PRIM bool HL_NAME(hl_g4_init_occlusion_query)(unsigned* occlusionQuery) { return kinc_g4_init_occlusion_query(occlusionQuery); }
//HL_PRIM void HL_NAME(hl_g4_delete_occlusion_query)(unsigned occlusionQuery) { kinc_g4_delete_occlusion_query(occlusionQuery); }
//HL_PRIM void HL_NAME(hl_g4_start_occlusion_query)(unsigned occlusionQuery) { kinc_g4_start_occlusion_query(occlusionQuery); }
//HL_PRIM void HL_NAME(hl_g4_end_occlusion_query)(unsigned occlusionQuery) { kinc_g4_end_occlusion_query(occlusionQuery); }
//HL_PRIM bool HL_NAME(hl_g4_are_query_results_available)(unsigned occlusionQuery) { return kinc_g4_are_query_results_available(occlusionQuery); }
//HL_PRIM void HL_NAME(hl_g4_get_query_results)(unsigned occlusionQuery, unsigned* pixelCount) { kinc_g4_get_query_results(occlusionQuery, pixelCount); }

HL_PRIM void HL_NAME(hl_g4_set_texture_array)(kinc_g4_texture_unit_t *unit, hl_g4_texture_array *array) {
    kinc_g4_set_texture_array(*unit, &array->t);
}
HL_PRIM int HL_NAME(hl_g4_antialiasing_samples)() {
    return kinc_g4_antialiasing_samples();
}
HL_PRIM void HL_NAME(hl_g4_set_antialiasing_samples)(int samples) {
    kinc_g4_set_antialiasing_samples(samples);
}

DEFINE_PRIM(_VOID, hl_g4_begin, _I32)
DEFINE_PRIM(_VOID, hl_g4_clear, _I32 _I32 _F32 _I32)
DEFINE_PRIM(_VOID, hl_g4_end, _I32)
DEFINE_PRIM(_BOOL, hl_g4_swap_buffers, _NO_ARG)
DEFINE_PRIM(_VOID, hl_g4_flush, _NO_ARG)
DEFINE_PRIM(_VOID, hl_g4_set_pipeline, _PIPELINE)
DEFINE_PRIM(_VOID, hl_g4_set_vertex_buffer, _VERTEX_BUFFER)
DEFINE_PRIM(_VOID, hl_g4_set_vertex_buffers, _ARR)
DEFINE_PRIM(_VOID, hl_g4_set_index_buffer, _INDEX_BUFFER)
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
DEFINE_PRIM(_VOID, hl_g4_set_render_targets, _ARR)
DEFINE_PRIM(_VOID, hl_g4_set_render_target_face, _RENDER_TARGET _I32)
DEFINE_PRIM(_VOID, hl_g4_set_texture, _TUNIT _TEXTURE)
DEFINE_PRIM(_VOID, hl_g4_set_image_texture, _TUNIT _TEXTURE)
//DEFINE_PRIM(_BOOL, hl_g4_init_occlusion_query, _REF(_I32))
//DEFINE_PRIM(_VOID, hl_g4_delete_occlusion_query, _I32)
//DEFINE_PRIM(_VOID, hl_g4_start_occlusion_query, _I32)
//DEFINE_PRIM(_VOID, hl_g4_end_occlusion_query, _I32)
//DEFINE_PRIM(_BOOL, hl_g4_are_query_results_available, _I32)
//DEFINE_PRIM(_VOID, hl_g4_get_query_results, _I32 _REF(_I32))
DEFINE_PRIM(_VOID, hl_g4_set_texture_array, _TUNIT _TEXTURE_ARRAY)
DEFINE_PRIM(_I32, hl_g4_antialiasing_samples, _NO_ARG)
DEFINE_PRIM(_VOID, hl_g4_set_antialiasing_samples, _I32)
