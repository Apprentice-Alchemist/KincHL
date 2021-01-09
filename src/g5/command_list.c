#include "graphics5.h"

ALLOC_OBJ_EX(g5_command_list, kinc_g5_command_list_t, kinc_g5_command_list_init, kinc_g5_command_list_destroy)

HL_PRIM void HL_NAME(hl_g5_command_list_begin)(hl_g5_command_list* list) {
    kinc_g5_command_list_begin(&list->t);
}
HL_PRIM void HL_NAME(hl_g5_command_list_end)(hl_g5_command_list* list) {
    kinc_g5_command_list_end(&list->t);
}
HL_PRIM void HL_NAME(hl_g5_command_list_clear)(hl_g5_command_list* list, hl_g5_render_target* renderTarget, unsigned flags, unsigned color, float depth,
    int stencil) {
    kinc_g5_command_list_clear(&list->t, &renderTarget->t, flags, color, depth, stencil);
}
HL_PRIM void HL_NAME(hl_g5_command_list_render_target_to_framebuffer_barrier)(hl_g5_command_list* list, hl_g5_render_target* renderTarget) {
    kinc_g5_command_list_render_target_to_framebuffer_barrier(&list->t, &renderTarget->t);
}
HL_PRIM void HL_NAME(hl_g5_command_list_framebuffer_to_render_target_barrier)(hl_g5_command_list* list, hl_g5_render_target* renderTarget) {
    kinc_g5_command_list_framebuffer_to_render_target_barrier(&list->t, &renderTarget->t);
}
HL_PRIM void HL_NAME(hl_g5_command_list_texture_to_render_target_barrier)(hl_g5_command_list* list, hl_g5_render_target* renderTarget) {
    kinc_g5_command_list_texture_to_render_target_barrier(&list->t, &renderTarget->t);
}
HL_PRIM void HL_NAME(hl_g5_command_list_render_target_to_texture_barrier)(hl_g5_command_list* list, hl_g5_render_target* renderTarget) {
    kinc_g5_command_list_render_target_to_texture_barrier(&list->t, &renderTarget->t);
}
HL_PRIM void HL_NAME(hl_g5_command_list_draw_indexed_vertices)(hl_g5_command_list* list) {
    kinc_g5_command_list_draw_indexed_vertices(&list->t);
}
HL_PRIM void HL_NAME(hl_g5_command_list_draw_indexed_vertices_from_to)(hl_g5_command_list* list, int start, int count) {
    kinc_g5_command_list_draw_indexed_vertices_from_to(&list->t, start, count);
}
HL_PRIM void HL_NAME(hl_g5_command_list_draw_indexed_vertices_from_to_from)(hl_g5_command_list* list, int start, int count, int vertex_offset) {
    kinc_g5_command_list_draw_indexed_vertices_from_to_from(&list->t, start, count, vertex_offset);
}
HL_PRIM void HL_NAME(hl_g5_command_list_viewport)(hl_g5_command_list* list, int x, int y, int width, int height) {
    kinc_g5_command_list_viewport(&list->t, x, y, width, height);
}
HL_PRIM void HL_NAME(hl_g5_command_list_scissor)(hl_g5_command_list* list, int x, int y, int width, int height) {
    kinc_g5_command_list_scissor(&list->t, x, y, width, height);
}
HL_PRIM void HL_NAME(hl_g5_command_list_disable_scissor)(hl_g5_command_list* list) {
    kinc_g5_command_list_disable_scissor(&list->t);
}
HL_PRIM void HL_NAME(hl_g5_command_list_set_pipeline)(hl_g5_command_list* list, hl_g5_pipeline* pipeline) {
    kinc_g5_command_list_set_pipeline(&list->t, &pipeline->t);
}

HL_PRIM void HL_NAME(hl_g5_command_list_set_vertex_buffers)(hl_g5_command_list* list, hl_g5_vertex_buffer* buffer, int offset) {
    // setting multiple vertex buffers is not supported on any of the G5 backends right now
    // with the possible exception of consoles
    kinc_g5_vertex_buffer_t* bufs[1] = { &buffer->t };
    int offsets[1] = { offset };
    kinc_g5_command_list_set_vertex_buffers(&list->t, bufs, offsets, 1);
}
HL_PRIM void HL_NAME(hl_g5_command_list_set_index_buffer)(hl_g5_command_list* list, hl_g5_index_buffer* buffer) {
    kinc_g5_command_list_set_index_buffer(&list->t, &buffer->t);
}
HL_PRIM void HL_NAME(hl_g5_command_list_set_render_targets)(hl_g5_command_list* list, varray* targets, int count) {
    kinc_g5_render_target_t** ts = malloc(sizeof(kinc_g5_render_target_t*) * count);
    for (int i = 0; i < count; i++) {
        ts[i] = &(hl_aptr(targets, hl_g5_render_target*)[i]->t);
    }
    kinc_g5_command_list_set_render_targets(&list->t, ts, count);
    free(ts);
}
HL_PRIM void HL_NAME(hl_g5_command_list_upload_index_buffer)(hl_g5_command_list* list, hl_g5_index_buffer* buffer) {
    kinc_g5_command_list_upload_index_buffer(&list->t, &buffer->t);
}
HL_PRIM void HL_NAME(hl_g5_command_list_upload_vertex_buffer)(hl_g5_command_list* list, hl_g5_vertex_buffer* buffer) {
    kinc_g5_command_list_upload_vertex_buffer(&list->t, &buffer->t);
}
HL_PRIM void HL_NAME(hl_g5_command_list_upload_texture)(hl_g5_command_list* list, hl_g5_texture* texture) {
    kinc_g5_command_list_upload_texture(&list->t, &texture->t);
}
HL_PRIM void HL_NAME(hl_g5_command_list_set_vertex_constant_buffer)(hl_g5_command_list* list, hl_g5_constant_buffer* buffer, int offset, size_t size) {
    kinc_g5_command_list_set_vertex_constant_buffer(&list->t,&buffer->t,offset,size);
}
HL_PRIM void HL_NAME(hl_g5_command_list_set_fragment_constant_buffer)(hl_g5_command_list* list, hl_g5_constant_buffer* buffer, int offset, size_t size) {
    kinc_g5_command_list_set_fragment_constant_buffer(&list->t, &buffer->t, offset, size);
}
HL_PRIM void HL_NAME(hl_g5_command_list_set_pipeline_layout)(hl_g5_command_list* list) {
    kinc_g5_command_list_set_pipeline_layout(&list->t);
}
HL_PRIM void HL_NAME(hl_g5_command_list_execute)(hl_g5_command_list* list) {
    kinc_g5_command_list_execute(&list->t);
}
HL_PRIM void HL_NAME(hl_g5_command_list_execute_and_wait)(hl_g5_command_list* list) {
    kinc_g5_command_list_execute_and_wait(&list->t);
}
HL_PRIM void HL_NAME(hl_g5_command_list_get_render_target_pixels)(hl_g5_command_list* list, hl_g5_render_target* render_target, uint8_t* data) {
    kinc_g5_command_list_get_render_target_pixels(&list->t,&render_target->t,data);
}
