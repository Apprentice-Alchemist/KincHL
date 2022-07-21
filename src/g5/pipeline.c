#include "../g4/graphics4.h"
#include "graphics5.h"

#include <kinc/io/filereader.h>

// HL_PRIM void HL_NAME(hl_g5_shader_init_from_source)(hl_g5_shader *s, vbyte *source, int type) {
//     kinc_g5_shader_init_from_source(&s->t, (char *)source, (kinc_g5_shader_type_t)type);
// }
HL_PRIM void HL_NAME(hl_g5_shader_init)(hl_g5_shader *s, vbyte *source, int length, int type) {
    kinc_g5_shader_init(&s->t, (void *)source, length, (kinc_g4_shader_type_t)type);
}
HL_PRIM void HL_NAME(hl_g5_shader_init_from_file)(hl_g5_shader *s, vstring *file, int type) {
    kinc_file_reader_t reader;
    char *name = hl_to_utf8(file->bytes);
    kinc_file_reader_open(&reader, name, KINC_FILE_TYPE_ASSET);
    int size = (int)kinc_file_reader_size(&reader);
    void *buf = hl_gc_alloc_noptr(size);
    kinc_file_reader_read(&reader, buf, size);
    kinc_file_reader_close(&reader);
    kinc_g5_shader_init(&s->t, buf, size, type);
}

// DEFINE_PRIM(_VOID, hl_g5_shader_init_from_source, _SHADER _BYTES _I32)
DEFINE_PRIM(_VOID, hl_g5_shader_init, _SHADER _BYTES _I32 _I32)
DEFINE_PRIM(_VOID, hl_g5_shader_init_from_file, _SHADER _STRING _I32)

typedef struct {
    hl_type *t;
    hl_g5_pipeline *_handle;
    varray *input_layout;
    hl_g5_shader *vertex_shader;
    hl_g5_shader *fragment_shader;
    hl_g5_shader *geometry_shader;
    hl_g5_shader *tessellation_control_shader;
    hl_g5_shader *tessellation_evaluation_shader;
    int cull_mode;
    bool depth_write;
    int depth_mode;
    int stencil_front_mode;
    int stencil_front_both_pass;
    int stencil_front_depth_fail;
    int stencil_front_fail;

    int stencil_back_mode;
    int stencil_back_both_pass;
    int stencil_back_depth_fail;
    int stencil_back_fail;
    int stencil_reference_value;
    int stencil_read_mask;
    int stencil_write_mask;

    int blend_source;
    int blend_destination;
    int blend_operation;
    int alpha_blend_source;
    int alpha_blend_destination;
    int alpha_blend_operation;
    // BlendingOperation alphaBlendOperation;
    varray *color_write_mask_red;
    varray *color_write_mask_green;
    varray *color_write_mask_blue;
    varray *color_write_mask_alpha;
    int color_attachment_count;
    varray *color_attachment;
    int depth_attachment_bits;
    int stencil_attachment_bits;
    bool conservative_rasterization;
} hl_g5_pipeline_haxe;

HL_PRIM void HL_NAME(hl_g5_pipeline_compile)(hl_g5_pipeline_haxe *state) {
#define GET(n) n == NULL ? NULL : &(n->t)
#define COPY(x) pipe->x = state->x
    kinc_g5_pipeline_t *pipe = &(state->_handle->t);
    hl_g4_vertex_structure **arr = hl_aptr(state->input_layout, hl_g4_vertex_structure *);
    for (int i = 0; i < 16 && arr[i] != NULL; i++) {
        pipe->inputLayout[i] = &(arr[i]->t);
    }
    pipe->inputLayout[state->input_layout->size > 15 ? 15 : state->input_layout->size] = NULL;
    pipe->vertexShader = GET(state->vertex_shader);
    pipe->fragmentShader = GET(state->fragment_shader);
    pipe->geometryShader = GET(state->geometry_shader);
    pipe->tessellationControlShader = GET(state->tessellation_control_shader);
    pipe->tessellationEvaluationShader = GET(state->tessellation_evaluation_shader);
    pipe->cullMode = state->cull_mode;
    pipe->depthWrite = state->depth_write;
    pipe->depthMode = state->depth_mode;
    // pipe->stencilFrontMode = state->stencil_front_mode;
    // COPY(depth_write);
    // COPY(depth_mode);
    // COPY(stencil_front_mode);
    // COPY(stencil_front_both_pass);
    // COPY(stencil_front_depth_fail);
    // COPY(stencil_front_fail);

    // COPY(stencil_back_mode);
    // COPY(stencil_back_both_pass);
    // COPY(stencil_back_depth_fail);
    // COPY(stencil_back_fail);
    // COPY(stencil_reference_value);
    // COPY(stencil_read_mask);
    // COPY(stencil_write_mask);
    COPY(blend_source);
    COPY(blend_destination);
    COPY(blend_operation);
    COPY(alpha_blend_source);
    COPY(alpha_blend_destination);
    COPY(alpha_blend_operation);
    for (int i = 0; i < 8 && i < state->color_write_mask_red->size; i++) {
        pipe->colorWriteMaskRed[i] = hl_aptr(state->color_write_mask_red, bool)[i];
    }
    for (int i = 0; i < 8 && i < state->color_write_mask_green->size; i++) {
        pipe->colorWriteMaskGreen[i] = hl_aptr(state->color_write_mask_green, bool)[i];
    }
    for (int i = 0; i < 8 && i < state->color_write_mask_blue->size; i++) {
        pipe->colorWriteMaskBlue[i] = hl_aptr(state->color_write_mask_blue, bool)[i];
    }
    for (int i = 0; i < 8 && i < state->color_write_mask_alpha->size; i++) {
        pipe->colorWriteMaskAlpha[i] = hl_aptr(state->color_write_mask_alpha, bool)[i];
    }
    pipe->colorAttachmentCount = state->color_attachment_count;
    for (int i = 0; i < 8 && i < state->color_attachment->size; i++) {
        pipe->colorAttachment[i] = hl_aptr(state->color_attachment, kinc_g5_render_target_format_t)[i];
    }
    pipe->depthAttachmentBits = state->depth_attachment_bits;
    pipe->stencilAttachmentBits = state->stencil_attachment_bits;
    pipe->conservativeRasterization = state->conservative_rasterization;
#undef GET
#undef COPY
    kinc_g5_pipeline_compile(pipe);
}

HL_PRIM kinc_g5_constant_location_t *HL_NAME(hl_g5_pipeline_get_constant_location)(hl_g5_pipeline *state, vstring *name) {
    kinc_g5_constant_location_t *ret = hl_gc_alloc_raw(sizeof(kinc_g5_constant_location_t));
    *ret = kinc_g5_pipeline_get_constant_location(&(state->t), hl_to_utf8(name->bytes));
    return ret;
}
HL_PRIM kinc_g5_texture_unit_t *HL_NAME(hl_g5_pipeline_get_texture_unit)(hl_g5_pipeline *state, vstring *name) {
    kinc_g5_texture_unit_t *ret = hl_gc_alloc_raw(sizeof(kinc_g5_texture_unit_t));
    *ret = kinc_g5_pipeline_get_texture_unit(&(state->t), hl_to_utf8(name->bytes));
    return ret;
}

// MAKE_GET_SET_EX(g5_vertex_structure, size, int, _I32)
// MAKE_GET_SET_EX(g5_vertex_structure, instanced, bool, _BOOL)

// HL_PRIM void HL_NAME(hl_g5_vertex_structure_add)(hl_g5_vertex_structure *obj, vstring *name, int d) {
//     kinc_g5_vertex_structure_add(&(obj->t), hl_to_utf8(name->bytes), d);
// }

DEFINE_PRIM(_VOID, hl_g5_pipeline_compile, _DYN)
// DEFINE_PRIM(_VOID, hl_g5_vertex_structure_add, _ABSTRACT(g4_vertex_structure) _STRING _I32)
DEFINE_PRIM(_LOC, hl_g5_pipeline_get_constant_location, _PIPELINE _STRING)
DEFINE_PRIM(_TUNIT, hl_g5_pipeline_get_texture_unit, _PIPELINE _STRING)