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
    kinc_g5_command_list_framebuffer_to_render_target_barrier(&list->t,&renderTarget->t);
}
HL_PRIM void HL_NAME(hl_g5_command_list_texture_to_render_target_barrier)(hl_g5_command_list* list, hl_g5_render_target* renderTarget) {
    kinc_g5_command_list_texture_to_render_target_barrier(&list->t,&renderTarget->t);
}
HL_PRIM void HL_NAME(hl_g5_command_list_render_target_to_texture_barrier)(hl_g5_command_list* list, hl_g5_render_target* renderTarget) {
    kinc_g5_command_list_render_target_to_texture_barrier(&list->t,&renderTarget->t);
}
HL_PRIM void HL_NAME(hl_g5_command_list_draw_indexed_vertices)(hl_g5_command_list* list) {
    kinc_g5_command_list_draw_indexed_vertices(&list->t);
}
HL_PRIM void HL_NAME(hl_g5_command_list_draw_indexed_vertices_from_to)(hl_g5_command_list* list, int start, int count) {

}
HL_PRIM void HL_NAME(hl_g5_command_list_draw_indexed_vertices_from_to_from)(hl_g5_command_list* list, int start, int count, int vertex_offset) {

}
HL_PRIM void HL_NAME(hl_g5_command_list_viewport)(hl_g5_command_list* list, int x, int y, int width, int height) {

}
HL_PRIM void HL_NAME(hl_g5_command_list_scissor)(hl_g5_command_list* list, int x, int y, int width, int height) {

}
HL_PRIM void HL_NAME(hl_g5_command_list_disable_scissor)(hl_g5_command_list* list) {

}
HL_PRIM void HL_NAME(hl_g5_command_list_set_pipeline)(hl_g5_command_list* list, hl_g5_pipeline* pipeline) {

}
HL_PRIM void HL_NAME(hl_g5_command_list_set_vertex_buffers)(hl_g5_command_list* list, hl_g5_vertex_buffer** buffers, int* offsets, int count) {

}
HL_PRIM void HL_NAME(hl_g5_command_list_set_index_buffer)(hl_g5_command_list* list, hl_g5_index_buffer* buffer) {

}
HL_PRIM void HL_NAME(hl_g5_command_list_set_render_targets)(hl_g5_command_list* list, hl_g5_render_target** targets, int count) {

}
HL_PRIM void HL_NAME(hl_g5_command_list_upload_index_buffer)(hl_g5_command_list* list, hl_g5_index_buffer* buffer) {

}
HL_PRIM void HL_NAME(hl_g5_command_list_upload_vertex_buffer)(hl_g5_command_list* list, hl_g5_vertex_buffer* buffer) {

}
HL_PRIM void HL_NAME(hl_g5_command_list_upload_texture)(hl_g5_command_list* list, hl_g5_texture* texture) {

}
HL_PRIM void HL_NAME(hl_g5_command_list_set_vertex_constant_buffer)(hl_g5_command_list* list, hl_g5_constant_buffer* buffer, int offset, size_t size) {

}
HL_PRIM void HL_NAME(hl_g5_command_list_set_fragment_constant_buffer)(hl_g5_command_list* list, hl_g5_constant_buffer* buffer, int offset, size_t size) {

}
HL_PRIM void HL_NAME(hl_g5_command_list_set_pipeline_layout)(hl_g5_command_list* list) {

}
HL_PRIM void HL_NAME(hl_g5_command_list_execute)(hl_g5_command_list* list) {

}
HL_PRIM void HL_NAME(hl_g5_command_list_execute_and_wait)(hl_g5_command_list* list) {

}
HL_PRIM void HL_NAME(hl_g5_command_list_get_render_target_pixels)(hl_g5_command_list* list, hl_g5_render_target* render_target, uint8_t* data) {

}
