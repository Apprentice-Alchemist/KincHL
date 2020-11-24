#include "graphics4.h"
#include <kinc/log.h>
ALLOC_OBJ(kinc_g4_pipeline_t, pipeline, _ABSTRACT(kinc_g4_pipeline_t), kinc_g4_pipeline_init, kinc_g4_pipeline_destroy)
ALLOC_OBJ(kinc_g4_vertex_structure_t, vertex_structure, _ABSTRACT(kinc_g4_vertex_structure_t), kinc_g4_vertex_structure_init, EMPTY_DESTROY)

#define _MAKE_GET_SET(field_name,field_type,hl_ret) MAKE_GET_SET(kinc_g4_pipeline_t,pipeline,field_name,field_type,_ABSTRACT(kinc_g4_pipeline_t),hl_ret)
#define _MAKE_GET(field_name,field_type,hl_ret) MAKE_GET(kinc_g4_pipeline_t,pipeline,field_name,field_type,_ABSTRACT(kinc_g4_pipeline_t),hl_ret)
MAKE_GET_SET(kinc_g4_pipeline_t, pipeline, vertex_shader, kinc_g4_shader_t*, _ABSTRACT(kinc_g4_pipeline_t), _ABSTRACT(kinc_g4_shader_t))
MAKE_GET_SET(kinc_g4_pipeline_t, pipeline, fragment_shader, kinc_g4_shader_t*, _ABSTRACT(kinc_g4_pipeline_t), _ABSTRACT(kinc_g4_shader_t))
MAKE_GET_SET(kinc_g4_pipeline_t, pipeline, geometry_shader, kinc_g4_shader_t*, _ABSTRACT(kinc_g4_pipeline_t), _ABSTRACT(kinc_g4_shader_t))
MAKE_GET_SET(kinc_g4_pipeline_t, pipeline, tessellation_control_shader, kinc_g4_shader_t*, _ABSTRACT(kinc_g4_pipeline_t), _ABSTRACT(kinc_g4_shader_t))
MAKE_GET_SET(kinc_g4_pipeline_t, pipeline, tessellation_evaluation_shader, kinc_g4_shader_t*, _ABSTRACT(kinc_g4_pipeline_t), _ABSTRACT(kinc_g4_shader_t))
_MAKE_GET_SET(cull_mode, int, _I32)
_MAKE_GET_SET(depth_write, bool, _BOOL)
_MAKE_GET_SET(depth_mode, int, _I32)
_MAKE_GET_SET(stencil_mode, int, _I32)
_MAKE_GET_SET(stencil_both_pass, int, _I32)
_MAKE_GET_SET(stencil_depth_fail, int, _I32)
_MAKE_GET_SET(stencil_fail, int, _I32)
_MAKE_GET_SET(stencil_reference_value, int, _I32)
_MAKE_GET_SET(stencil_read_mask, int, _I32)
_MAKE_GET_SET(stencil_write_mask, int, _I32)
_MAKE_GET_SET(blend_source, int, _I32)
_MAKE_GET_SET(blend_destination, int, _I32)
_MAKE_GET_SET(alpha_blend_source, int, _I32)
_MAKE_GET_SET(alpha_blend_destination, int, _I32)
_MAKE_GET(color_write_mask_red, bool*, _BYTES)
_MAKE_GET(color_write_mask_green, bool*, _BYTES)
_MAKE_GET(color_write_mask_blue, bool*, _BYTES)
_MAKE_GET(color_write_mask_alpha, bool*, _BYTES)
_MAKE_GET_SET(color_attachment_count, int, _I32)
_MAKE_GET(color_attachment, int*, _BYTES)
_MAKE_GET_SET(depth_attachment_bits, int, _I32)
_MAKE_GET_SET(stencil_attachment_bits, int, _I32)
_MAKE_GET_SET(conservative_rasterization, bool, _BOOL)
#undef _MAKE_GET_SET
#undef _MAKE_GET

HL_PRIM kinc_g4_vertex_structure_t** HL_NAME(pipeline_hl_get_input_layout)(kinc_g4_pipeline_t* o) {
    return o->input_layout;
}

HL_PRIM kinc_g4_vertex_structure_t** HL_NAME(pipeline_hl_set_input_layout)(kinc_g4_pipeline_t* o, kinc_g4_vertex_structure_t** v) {
    for (int i = 0; v[i] != NULL; i++) {
        o->input_layout[i] = v[i];
    }
    return o->input_layout;
}

DEFINE_PRIM(_REF(_ABSTRACT(kinc_g4_vertex_structure_t)), pipeline_hl_get_input_layout, _ABSTRACT(kinc_g4_pipeline_t))
DEFINE_PRIM(_REF(_ABSTRACT(kinc_g4_vertex_structure_t)), pipeline_hl_set_input_layout, _ABSTRACT(kinc_g4_pipeline_t) _REF(_ABSTRACT(kinc_g4_vertex_structure_t)))

HL_PRIM void HL_NAME(hl_g4_pipeline_compile)(kinc_g4_pipeline_t* state) {
    kinc_g4_pipeline_compile(state);
}

HL_PRIM kinc_g4_constant_location_t* HL_NAME(hl_g4_pipeline_get_constant_location)(kinc_g4_pipeline_t* state, vstring* name) {
    kinc_g4_constant_location_t* ret = hl_gc_alloc_raw(sizeof(kinc_g4_constant_location_t));
    *ret = kinc_g4_pipeline_get_constant_location(state, hl_to_utf8(name->bytes));
    return ret;
}
HL_PRIM kinc_g4_texture_unit_t* HL_NAME(hl_g4_pipeline_get_texture_unit)(kinc_g4_pipeline_t* state, vstring* name) {
    kinc_g4_texture_unit_t* ret = hl_gc_alloc_raw(sizeof(kinc_g4_texture_unit_t));
    *ret = kinc_g4_pipeline_get_texture_unit(state, hl_to_utf8(name->bytes));
    return ret;
}

MAKE_GET_SET(kinc_g4_vertex_structure_t, vertex_structure, size, int, _ABSTRACT(kinc_g4_vertex_structure_t), _I32)

HL_PRIM void HL_NAME(hl_g4_vertex_structure_add)(kinc_g4_vertex_structure_t* obj, vstring* name, int d) {
    kinc_g4_vertex_structure_add(obj, hl_to_utf8(name->bytes), d);
}

DEFINE_PRIM(_VOID, hl_g4_pipeline_compile, _ABSTRACT(kinc_g4_pipeline_t))
DEFINE_PRIM(_VOID, hl_g4_vertex_structure_add, _ABSTRACT(kinc_g4_vertex_structure_t) _STRING _I32)
DEFINE_PRIM(_ABSTRACT(kinc_g4_constant_location_t), hl_g4_pipeline_get_constant_location, _ABSTRACT(kinc_g4_pipeline_t) _STRING)
DEFINE_PRIM(_ABSTRACT(kinc_g4_texture_unit_t), hl_g4_pipeline_get_texture_unit, _ABSTRACT(kinc_g4_pipeline_t) _STRING)