#include "graphics5.h"
#include "kinc/graphics5/rendertarget.h"
#include <hl.h>

ALLOC_OBJ_EX(g5_command_list, kinc_g5_command_list_t, kinc_g5_command_list_init, kinc_g5_command_list_destroy)
ALLOC_OBJ_EX(g5_constant_buffer, kinc_g5_constant_buffer_t, EMPTY_INIT, kinc_g5_constant_buffer_destroy)
ALLOC_OBJ_EX(g5_shader, kinc_g5_shader_t, EMPTY_INIT, kinc_g5_shader_destroy)
ALLOC_OBJ_EX(g5_texture, kinc_g5_texture_t, EMPTY_INIT, kinc_g5_texture_destroy)
ALLOC_OBJ_EX(g5_vertex_buffer, kinc_g5_vertex_buffer_t, EMPTY_INIT, kinc_g5_vertex_buffer_destroy)
ALLOC_OBJ_EX(g5_index_buffer, kinc_g5_index_buffer_t, EMPTY_INIT, kinc_g5_index_buffer_destroy)
ALLOC_OBJ_EX(g5_pipeline, kinc_g5_pipeline_t, EMPTY_INIT, kinc_g5_pipeline_destroy)
ALLOC_OBJ_EX(g5_render_target, kinc_g5_render_target_t, EMPTY_INIT, kinc_g5_render_target_destroy)

HL_PRIM bool HL_NAME(hl_g5_fullscreen)() {
    return kinc_g5_fullscreen;
}

HL_PRIM void HL_NAME(hl_g5_begin)(hl_g5_render_target *render_target, int window) {
    kinc_g5_begin(&render_target->t, window);
}

DEFINE_PRIM(_VOID, hl_g5_begin, _RENDER_TARGET _I32);

HL_PRIM void HL_NAME(hl_g5_flush)() {
    kinc_g5_flush();
}

DEFINE_PRIM(_VOID, hl_g5_flush, _NO_ARG);

HL_PRIM void HL_NAME(hl_g5_end)(int window) {
    kinc_g5_end(window);
}

DEFINE_PRIM(_VOID, hl_g5_end, _I32);

HL_PRIM void HL_NAME(hl_g5_swap_buffers)() {
    kinc_g5_swap_buffers();
}

DEFINE_PRIM(_VOID, hl_g5_swap_buffers, _NO_ARG);

HL_PRIM int HL_NAME(hl_g5_max_bound_textures)() {
    return kinc_g5_max_bound_textures();
}

DEFINE_PRIM(_I32, hl_g5_max_bound_textures, _NO_ARG);

HL_PRIM bool HL_NAME(hl_g5_non_pow2_textures_supported)() {
    return kinc_g5_non_pow2_textures_qupported();
}

DEFINE_PRIM(_BOOL, hl_g5_non_pow2_textures_supported, _NO_ARG);

HL_PRIM bool HL_NAME(hl_g5_render_targets_inverted_y)() {
    return kinc_g5_render_targets_inverted_y();
}

DEFINE_PRIM(_BOOL, hl_g5_render_targets_inverted_y, _NO_ARG);

HL_PRIM int HL_NAME(hl_g5_antialiasing_samples)() {
    return kinc_g5_antialiasing_samples();
}

DEFINE_PRIM(_I32, hl_g5_antialiasing_samples, _NO_ARG);

HL_PRIM void HL_NAME(hl_g5_set_antialiasing_samples)(int samples) {
    kinc_g5_set_antialiasing_samples(samples);
}

DEFINE_PRIM(_VOID, hl_g5_set_antialiasing_samples, _I32);