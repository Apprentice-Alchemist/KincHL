#include "graphics4.h"

ALLOC_OBJ(kinc_g4_pipeline_t, pipeline, _ABSTRACT(kinc_g4_pipeline_t), kinc_g4_pipeline_init, kinc_g4_pipeline_destroy)
ALLOC_OBJ(kinc_g4_vertex_structure_t, vertex_structure, _ABSTRACT(kinc_g4_vertex_structure_t), EMPTY_INIT, EMPTY_DESTROY)

MAKE_GET_SET(kinc_g4_pipeline_t, pipeline, vertex_shader, kinc_g4_shader_t*, _ABSTRACT(kinc_g4_pipeline_t), _ABSTRACT(kinc_g4_shader_t))
MAKE_GET_SET(kinc_g4_pipeline_t, pipeline, fragment_shader, kinc_g4_shader_t*, _ABSTRACT(kinc_g4_pipeline_t), _ABSTRACT(kinc_g4_shader_t))
MAKE_GET_SET(kinc_g4_pipeline_t, pipeline, geometry_shader, kinc_g4_shader_t*, _ABSTRACT(kinc_g4_pipeline_t), _ABSTRACT(kinc_g4_shader_t))
MAKE_GET_SET(kinc_g4_pipeline_t, pipeline, tessellation_control_shader, kinc_g4_shader_t*, _ABSTRACT(kinc_g4_pipeline_t), _ABSTRACT(kinc_g4_shader_t))
MAKE_GET_SET(kinc_g4_pipeline_t, pipeline, tessellation_evaluation_shader, kinc_g4_shader_t*, _ABSTRACT(kinc_g4_pipeline_t), _ABSTRACT(kinc_g4_shader_t))


HL_PRIM kinc_g4_vertex_structure_t** HL_NAME(pipeline_hl_get_input_layout)(kinc_g4_pipeline_t* o) {
    return o->input_layout;
}
HL_PRIM kinc_g4_vertex_structure_t** HL_NAME(pipeline_hl_set_input_layout)(kinc_g4_pipeline_t* o, kinc_g4_vertex_structure_t** v) {
    if (o->input_layout != NULL) {
        for (int i = 0; v[i] != NULL; i++) {
            o->input_layout[i] = v[i];
        }
    }
    return o->input_layout;
}
DEFINE_PRIM(_REF(_ABSTRACT(kinc_g4_vertex_structure_t)), pipeline_hl_get_input_layout, _ABSTRACT(kinc_g4_pipeline_t))
DEFINE_PRIM(_REF(_ABSTRACT(kinc_g4_vertex_structure_t)), pipeline_hl_set_input_layout, _ABSTRACT(kinc_g4_pipeline_t) _REF(_ABSTRACT(kinc_g4_vertex_structure_t)))

HL_PRIM void HL_NAME(hl_g4_pipeline_compile)(kinc_g4_pipeline_t* state) {
    kinc_g4_pipeline_compile(state);
}


MAKE_GET_SET(kinc_g4_vertex_structure_t, vertex_structure, size, int, _ABSTRACT(kinc_g4_vertex_structure_t), _I32)

HL_PRIM void HL_NAME(hl_g4_vertex_structure_add)(kinc_g4_vertex_structure_t* obj, vstring* name, int d) {
    kinc_g4_vertex_structure_add(obj, hl_to_utf8(name->bytes), d);
}

DEFINE_PRIM(_VOID, hl_g4_pipeline_compile, _ABSTRACT(kinc_g4_pipeline_t))
DEFINE_PRIM(_VOID, hl_g4_vertex_structure_add, _ABSTRACT(kinc_g4_vertex_structure_t) _STRING _I32)