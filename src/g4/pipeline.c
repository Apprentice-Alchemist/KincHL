#include "graphics4.h"

typedef struct {
    hl_type* t;
    hl_g4_pipeline* _handle;
    varray* input_layout;
    hl_g4_shader* vertex_shader;
    hl_g4_shader* fragment_shader;
    hl_g4_shader* geometry_shader;
    hl_g4_shader* tessellation_control_shader;
    hl_g4_shader* tessellation_evaluation_shader;
    kinc_g4_cull_mode_t cull_mode;
    bool depth_write;
    kinc_g4_compare_mode_t depth_mode;
    kinc_g4_compare_mode_t stencil_mode;
    kinc_g4_stencil_action_t stencil_both_pass;
    kinc_g4_stencil_action_t stencil_depth_fail;
    kinc_g4_stencil_action_t stencil_fail;
    int stencil_reference_value;
    int stencil_read_mask;
    int stencil_write_mask;
    kinc_g4_blending_operation_t blend_source;
    kinc_g4_blending_operation_t blend_destination;
    // BlendingOperation blendOperation;
    kinc_g4_blending_operation_t alpha_blend_source;
    kinc_g4_blending_operation_t alpha_blend_destination;
    // BlendingOperation alphaBlendOperation;
    varray* color_write_mask_red;
    varray* color_write_mask_green;
    varray* color_write_mask_blue;
    varray* color_write_mask_alpha;
    int color_attachment_count;
    varray* color_attachment;
    int depth_attachment_bits;
    int stencil_attachment_bits;
    bool conservative_rasterization;
} hl_g4_pipeline_haxe;

HL_PRIM void HL_NAME(hl_g4_pipeline_compile)(hl_g4_pipeline_haxe* state) {
#define GET(n) n == NULL ? NULL : &(n->t);
#define COPY(x) pipe->x = state->x;
    kinc_g4_pipeline_t* pipe = &(state->_handle->t);
    hl_g4_vertex_structure** arr = hl_aptr(state->input_layout, hl_g4_vertex_structure*);
    for (int i = 0; i < 16 && arr[i] != NULL; i++) {
        pipe->input_layout[i] = &(arr[i]->t);
    }
    pipe->input_layout[state->input_layout->size > 15 ? 15 : state->input_layout->size] = NULL;
    pipe->vertex_shader = GET(state->vertex_shader);
    pipe->fragment_shader = GET(state->fragment_shader);
    pipe->geometry_shader = GET(state->geometry_shader);
    pipe->tessellation_control_shader = GET(state->tessellation_control_shader);
    pipe->tessellation_evaluation_shader = GET(state->tessellation_evaluation_shader);
    COPY(cull_mode);
    COPY(depth_write);
    COPY(depth_mode);
    COPY(stencil_mode);
    COPY(stencil_both_pass);
    COPY(stencil_depth_fail);
    COPY(stencil_fail);
    COPY(stencil_reference_value);
    COPY(stencil_read_mask);
    COPY(stencil_write_mask);
    COPY(blend_source);
    COPY(blend_destination);
    COPY(alpha_blend_source);
    COPY(alpha_blend_destination);
    for (int i = 0; i < 8 && i < state->color_write_mask_red->size; i++) {
        pipe->color_write_mask_red[i] = hl_aptr(state->color_write_mask_red, bool)[i];
    }
    for (int i = 0; i < 8 && i < state->color_write_mask_green->size; i++) {
        pipe->color_write_mask_green[i] = hl_aptr(state->color_write_mask_green, bool)[i];
    }
    for (int i = 0; i < 8 && i < state->color_write_mask_blue->size; i++) {
        pipe->color_write_mask_blue[i] = hl_aptr(state->color_write_mask_blue, bool)[i];
    }
    for (int i = 0; i < 8 && i < state->color_write_mask_alpha->size; i++) {
        pipe->color_write_mask_alpha[i] = hl_aptr(state->color_write_mask_alpha, bool)[i];
    }
    COPY(color_attachment_count);
    for (int i = 0; i < 8 && i < state->color_attachment->size; i++) {
        pipe->color_attachment[i] = hl_aptr(state->color_attachment, kinc_g4_render_target_format_t)[i];
    }
    COPY(depth_attachment_bits);
    COPY(stencil_attachment_bits);
    COPY(conservative_rasterization);
#undef GET
#undef COPY
    kinc_g4_pipeline_compile(pipe);
}

HL_PRIM kinc_g4_constant_location_t* HL_NAME(hl_g4_pipeline_get_constant_location)(hl_g4_pipeline* state, vstring* name) {
    kinc_g4_constant_location_t* ret = hl_gc_alloc_raw(sizeof(kinc_g4_constant_location_t));
    *ret = kinc_g4_pipeline_get_constant_location(&(state->t), hl_to_utf8(name->bytes));
    return ret;
}
HL_PRIM kinc_g4_texture_unit_t* HL_NAME(hl_g4_pipeline_get_texture_unit)(hl_g4_pipeline* state, vstring* name) {
    kinc_g4_texture_unit_t* ret = hl_gc_alloc_raw(sizeof(kinc_g4_texture_unit_t));
    *ret = kinc_g4_pipeline_get_texture_unit(&(state->t), hl_to_utf8(name->bytes));
    return ret;
}

MAKE_GET_SET_EX(g4_vertex_structure, size, int, _I32)
MAKE_GET_SET_EX(g4_vertex_structure, instanced, bool, _BOOL)


HL_PRIM void HL_NAME(hl_g4_vertex_structure_add)(hl_g4_vertex_structure* obj, vstring* name, int d) {
    kinc_g4_vertex_structure_add(&(obj->t), hl_to_utf8(name->bytes), d);
}

DEFINE_PRIM(_VOID, hl_g4_pipeline_compile, _DYN)
DEFINE_PRIM(_VOID, hl_g4_vertex_structure_add, _VERTEX_STRUCTURE _STRING _I32)
DEFINE_PRIM(_LOC, hl_g4_pipeline_get_constant_location, _PIPELINE _STRING)
DEFINE_PRIM(_TUNIT, hl_g4_pipeline_get_texture_unit, _PIPELINE _STRING)