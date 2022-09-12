#include "graphics5.h"
#include "kinc/graphics5/commandlist.h"
#include "kinchl.h"

HL_PRIM void HL_NAME(hl_g5_command_list_init)(hl_g5_command_list *list) {
    kinc_g5_command_list_init(&list->t);
}

DEFINE_PRIM(_VOID, hl_g5_command_list_init, _COMMAND_LIST)

HL_PRIM void HL_NAME(hl_g5_command_list_begin)(hl_g5_command_list *list) {
    kinc_g5_command_list_begin(&list->t);
}

DEFINE_PRIM(_VOID, hl_g5_command_list_begin, _COMMAND_LIST)

HL_PRIM void HL_NAME(hl_g5_command_list_end)(hl_g5_command_list *list) {
    kinc_g5_command_list_end(&list->t);
}

DEFINE_PRIM(_VOID, hl_g5_command_list_end, _COMMAND_LIST)

HL_PRIM void HL_NAME(hl_g5_command_list_clear)(hl_g5_command_list *list, hl_g5_render_target *target, int flags, int color, float depth, int stencil) {
    kinc_g5_command_list_clear(&list->t, &target->t, flags, color, depth, stencil);
}

DEFINE_PRIM(_VOID, hl_g5_command_list_clear, _COMMAND_LIST _RENDER_TARGET _I32 _I32 _F32 _I32)

HL_PRIM void HL_NAME(hl_g5_command_list_render_target_to_framebuffer_barrier)(hl_g5_command_list *list, hl_g5_render_target *target) {
    kinc_g5_command_list_render_target_to_framebuffer_barrier(&list->t, &target->t);
}

DEFINE_PRIM(_VOID, hl_g5_command_list_render_target_to_framebuffer_barrier, _COMMAND_LIST _RENDER_TARGET)

HL_PRIM void HL_NAME(hl_g5_command_list_framebuffer_to_render_target_barrier)(hl_g5_command_list *list, hl_g5_render_target *target) {
    kinc_g5_command_list_framebuffer_to_render_target_barrier(&list->t, &target->t);
}

DEFINE_PRIM(_VOID, hl_g5_command_list_framebuffer_to_render_target_barrier, _COMMAND_LIST _RENDER_TARGET)

HL_PRIM void HL_NAME(hl_g5_command_list_texture_to_render_target_barrier)(hl_g5_command_list *list, hl_g5_render_target *render_target) {
    kinc_g5_command_list_texture_to_render_target_barrier(&list->t, &render_target->t);
}

DEFINE_PRIM(_VOID, hl_g5_command_list_texture_to_render_target_barrier, _COMMAND_LIST _RENDER_TARGET)

HL_PRIM void HL_NAME(hl_g5_command_list_render_target_to_texture_barrier)(hl_g5_command_list *list, hl_g5_render_target *render_target) {
    kinc_g5_command_list_render_target_to_texture_barrier(&list->t, &render_target->t);
}

DEFINE_PRIM(_VOID, hl_g5_command_list_render_target_to_texture_barrier, _COMMAND_LIST _RENDER_TARGET)

HL_PRIM void HL_NAME(hl_g5_command_list_draw_indexed_vertices)(hl_g5_command_list *list) {
    kinc_g5_command_list_draw_indexed_vertices(&list->t);
}

DEFINE_PRIM(_VOID, hl_g5_command_list_draw_indexed_vertices, _COMMAND_LIST)

HL_PRIM void HL_NAME(hl_g5_command_list_draw_indexed_vertices_from_to)(hl_g5_command_list *list, int start, int count) {
    kinc_g5_command_list_draw_indexed_vertices_from_to(&list->t, start, count);
}

DEFINE_PRIM(_VOID, hl_g5_command_list_draw_indexed_vertices_from_to, _COMMAND_LIST _I32 _I32)

HL_PRIM void HL_NAME(hl_g5_command_list_draw_indexed_vertices_from_to_from)(hl_g5_command_list *list, int start, int count, int vertex_offset) {
    kinc_g5_command_list_draw_indexed_vertices_from_to_from(&list->t, start, count, vertex_offset);
}

DEFINE_PRIM(_VOID, hl_g5_command_list_draw_indexed_vertices_from_to_from, _COMMAND_LIST _I32 _I32 _I32)

HL_PRIM void HL_NAME(hl_g5_command_list_draw_indexed_vertices_instanced)(hl_g5_command_list *list, int instanceCount) {
    kinc_g5_command_list_draw_indexed_vertices_instanced(&list->t, instanceCount);
}

DEFINE_PRIM(_VOID, hl_g5_command_list_draw_indexed_vertices_instanced, _COMMAND_LIST _I32)

HL_PRIM void HL_NAME(hl_g5_command_list_draw_indexed_vertices_instanced_from_to)(hl_g5_command_list *list, int instanceCount, int start, int count) {
    kinc_g5_command_list_draw_indexed_vertices_instanced_from_to(&list->t, instanceCount, start, count);
}

DEFINE_PRIM(_VOID, hl_g5_command_list_draw_indexed_vertices_instanced_from_to, _COMMAND_LIST _I32 _I32 _I32)

HL_PRIM void HL_NAME(hl_g5_command_list_viewport)(hl_g5_command_list *list, int x, int y, int width, int height) {
    kinc_g5_command_list_viewport(&list->t, x, y, width, height);
}

DEFINE_PRIM(_VOID, hl_g5_command_list_viewport, _COMMAND_LIST _I32 _I32 _I32 _I32)

HL_PRIM void HL_NAME(hl_g5_command_list_scissor)(hl_g5_command_list *list, int x, int y, int width, int height) {
    kinc_g5_command_list_scissor(&list->t, x, y, width, height);
}

DEFINE_PRIM(_VOID, hl_g5_command_list_scissor, _COMMAND_LIST _I32 _I32 _I32 _I32)

HL_PRIM void HL_NAME(hl_g5_command_list_disable_scissor)(hl_g5_command_list *list) {
    kinc_g5_command_list_disable_scissor(&list->t);
}

DEFINE_PRIM(_VOID, hl_g5_command_list_disable_scissor, _COMMAND_LIST)

HL_PRIM void HL_NAME(hl_g5_command_list_set_pipeline)(hl_g5_command_list *list, hl_g5_pipeline *pipeline) {
    kinc_g5_command_list_set_pipeline(&list->t, &pipeline->t);
}

DEFINE_PRIM(_VOID, hl_g5_command_list_set_pipeline, _COMMAND_LIST _PIPELINE)

HL_PRIM void HL_NAME(hl_g5_command_list_set_vertex_buffers)(hl_g5_command_list *list, varray *buffers, vbyte *offsets) {
    STACK_ALLOC(kinc_g5_vertex_buffer_t*, buffers->size, vbuffers);
    for (int i = 0; i < buffers->size; i++) {
        vbuffers[i] = &(hl_aptr(buffers, hl_g5_vertex_buffer*)[i]->t);
    }
    kinc_g5_command_list_set_vertex_buffers(&list->t, vbuffers, (int *)offsets, buffers->size);
}

DEFINE_PRIM(_VOID, hl_g5_command_list_set_vertex_buffers, _COMMAND_LIST _ARR _BYTES)

HL_PRIM void HL_NAME(hl_g5_command_list_set_index_buffer)(hl_g5_command_list *list, hl_g5_index_buffer *buffer) {
	kinc_g5_command_list_set_index_buffer(&list->t, &buffer->t);
}

DEFINE_PRIM(_VOID, hl_g5_command_list_set_index_buffer, _COMMAND_LIST _INDEX_BUFFER)

HL_PRIM void HL_NAME(hl_g5_command_list_set_render_targets)(hl_g5_command_list *list, varray *targets) {
    STACK_ALLOC(kinc_g5_render_target_t*, targets->size, rtargets);
    hl_g5_render_target **rt = hl_aptr(targets, hl_g5_render_target*);
	for (int i = 0; i < targets->size; i++) {
		rtargets[i] = &(rt[i]->t);
	}
	kinc_g5_command_list_set_render_targets(&list->t, rtargets, targets->size);
}

DEFINE_PRIM(_VOID, hl_g5_command_list_set_render_targets, _COMMAND_LIST _ARR)

HL_PRIM void HL_NAME(hl_g5_command_list_upload_index_buffer)(hl_g5_command_list *list, hl_g5_index_buffer*buffer) {
	kinc_g5_command_list_upload_index_buffer(&list->t, &buffer->t);
}

DEFINE_PRIM(_VOID, hl_g5_command_list_upload_index_buffer, _COMMAND_LIST _INDEX_BUFFER)

HL_PRIM void HL_NAME(hl_g5_command_list_upload_vertex_buffer)(hl_g5_command_list *list, hl_g5_vertex_buffer *buffer) {
    kinc_g5_command_list_upload_vertex_buffer(&list->t, &buffer->t);
}

DEFINE_PRIM(_VOID, hl_g5_command_list_upload_vertex_buffer, _COMMAND_LIST _VERTEX_BUFFER)

HL_PRIM void HL_NAME(hl_g5_command_list_upload_texture)(hl_g5_command_list *list, hl_g5_texture *texture) {
    kinc_g5_command_list_upload_texture(&list->t, &texture->t);
}

DEFINE_PRIM(_VOID, hl_g5_command_list_upload_texture, _COMMAND_LIST _TEXTURE)

HL_PRIM void HL_NAME(hl_g5_command_list_set_vertex_constant_buffer)(hl_g5_command_list *list, hl_g5_constant_buffer *buffer, int offset, int size) {
	kinc_g5_command_list_set_vertex_constant_buffer(&list->t, &buffer->t, offset, size);
}

DEFINE_PRIM(_VOID, hl_g5_command_list_set_vertex_constant_buffer, _COMMAND_LIST _CONSTANT_BUFFER _I32 _I32)

HL_PRIM void HL_NAME(hl_g5_command_list_set_fragment_constant_buffer)(hl_g5_command_list *list, hl_g5_constant_buffer *buffer, int offset, int size) {
    kinc_g5_command_list_set_fragment_constant_buffer(&list->t, &buffer->t, offset, size);
}

DEFINE_PRIM(_VOID, hl_g5_command_list_set_fragment_constant_buffer, _COMMAND_LIST _CONSTANT_BUFFER _I32 _I32)

HL_PRIM void HL_NAME(hl_g5_command_list_set_pipeline_layout)(hl_g5_command_list *list) {
	kinc_g5_command_list_set_pipeline_layout(&list->t);
}

DEFINE_PRIM(_VOID, hl_g5_command_list_set_pipeline_layout, _COMMAND_LIST)

HL_PRIM void HL_NAME(hl_g5_command_list_execute)(hl_g5_command_list *list) {
	kinc_g5_command_list_execute(&list->t);
}

DEFINE_PRIM(_VOID, hl_g5_command_list_execute, _COMMAND_LIST)

HL_PRIM void HL_NAME(hl_g5_command_list_wait_for_execution_to_finish)(hl_g5_command_list *list) {
    kinc_g5_command_list_wait_for_execution_to_finish(&list->t);
}

DEFINE_PRIM(_VOID, hl_g5_command_list_wait_for_execution_to_finish, _COMMAND_LIST)