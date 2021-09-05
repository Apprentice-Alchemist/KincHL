#include "g4/graphics4.h"
#include <kinc/compute/compute.h>

#define _CLOC _ABSTRACT(compute_constant_location)
#define _CUNIT _ABSTRACT(compute_texture_unit)
#define _CSHADER _ABSTRACT(compute_shader)

DEFINE_OBJ_EX(compute_shader, kinc_compute_shader_t)
ALLOC_OBJ_EX(compute_shader, kinc_compute_shader_t, EMPTY_INIT, kinc_compute_shader_destroy)

HL_PRIM void HL_NAME(hl_compute_shader_init)(hl_compute_shader *shader, vbyte *source, int length) {
    kinc_compute_shader_init(&shader->t, source, length);
}

HL_PRIM kinc_compute_constant_location_t *HL_NAME(hl_compute_shader_get_constant_location)(hl_compute_shader *shader, vbyte *name) {
    kinc_compute_constant_location_t *loc = hl_gc_alloc_raw(sizeof(kinc_compute_constant_location_t));
    *loc = kinc_compute_shader_get_constant_location(&shader->t, name);
    return loc;
}

HL_PRIM kinc_compute_texture_unit_t *HL_NAME(hl_compute_shader_get_texture_unit)(hl_compute_shader *shader, vbyte *name) {
    kinc_compute_texture_unit_t *unit = hl_gc_alloc_raw(sizeof(kinc_compute_texture_unit_t));
    *unit = kinc_compute_shader_get_texture_unit(&shader->t, name);
    return unit;
}

HL_PRIM void HL_NAME(hl_compute_set_floats)(kinc_compute_constant_location_t *location, float *values, int count) {
    kinc_compute_set_floats(*location, values, count);
}

HL_PRIM void HL_NAME(hl_compute_set_texture)(kinc_compute_texture_unit_t *unit, hl_g4_texture *texture, kinc_compute_access_t access) {
    kinc_compute_set_texture(*unit, &texture->t, access);
}

HL_PRIM void HL_NAME(hl_compute_set_render_target)(kinc_compute_texture_unit_t *unit, hl_g4_render_target *texture, kinc_compute_access_t access) {
    kinc_compute_set_render_target(*unit, &texture->t, access);
}

HL_PRIM void HL_NAME(hl_compute_set_sampled_texture)(kinc_compute_texture_unit_t *unit, hl_g4_texture *texture) {
    kinc_compute_set_sampled_texture(*unit, &texture->t);
}

HL_PRIM void HL_NAME(hl_compute_set_sampled_render_target)(kinc_compute_texture_unit_t *unit, hl_g4_render_target *target) {
    kinc_compute_set_sampled_render_target(*unit, &target->t);
}

HL_PRIM void HL_NAME(hl_compute_set_sampled_depth_from_render_target)(kinc_compute_texture_unit_t *unit, hl_g4_render_target *target) {
    kinc_compute_set_sampled_depth_from_render_target(*unit, &target->t);
}

HL_PRIM void HL_NAME(hl_compute_set_texture_addressing)(kinc_compute_texture_unit_t *unit, int dir, int addressing) {
    kinc_compute_set_texture_addressing(*unit, dir, addressing);
}

HL_PRIM void HL_NAME(hl_compute_set_texture_magnification_filter)(kinc_compute_texture_unit_t *unit, int filter) {
    kinc_compute_set_texture_magnification_filter(*unit, filter);
}

HL_PRIM void HL_NAME(hl_compute_set_texture_minification_filter)(kinc_compute_texture_unit_t *unit, int filter) {
    kinc_compute_set_texture_minification_filter(*unit, filter);
}

HL_PRIM void HL_NAME(hl_compute_set_texture_mipmap_filter)(kinc_compute_texture_unit_t *unit, int filter) {
    kinc_compute_set_texture_mipmap_filter(*unit, filter);
}

HL_PRIM void HL_NAME(hl_compute_set_texture3d_addressing)(kinc_compute_texture_unit_t *unit, int dir,
                                                          int addressing) {
    kinc_compute_set_texture3d_addressing(*unit, dir, addressing);
}

HL_PRIM void HL_NAME(hl_compute_set_texture3d_magnification_filter)(kinc_compute_texture_unit_t *unit, int filter) {
    kinc_compute_set_texture3d_magnification_filter(*unit, filter);
}

HL_PRIM void HL_NAME(hl_compute_set_texture3d_minification_filter)(kinc_compute_texture_unit_t *unit, int filter) {
    kinc_compute_set_texture3d_minification_filter(*unit, filter);
}

HL_PRIM void HL_NAME(hl_compute_set_texture3d_mipmap_filter)(kinc_compute_texture_unit_t *unit, int filter) {
    kinc_compute_set_texture3d_mipmap_filter(*unit, filter);
}

HL_PRIM void HL_NAME(hl_compute_set_shader)(hl_compute_shader *shader) {
    kinc_compute_set_shader(&shader->t);
}

HL_PRIM void HL_NAME(hl_compute_compute)(int x, int y, int z) {
    kinc_compute(x, y, z);
}

DEFINE_PRIM(_VOID, hl_compute_shader_init, _CSHADER _BYTES _I32)
DEFINE_PRIM(_CLOC, hl_compute_shader_get_constant_location, _CSHADER _BYTES)
DEFINE_PRIM(_CUNIT, hl_compute_shader_get_texture_unit, _CSHADER _BYTES)
DEFINE_PRIM(_VOID, hl_compute_set_floats, _CLOC _BYTES _I32)
DEFINE_PRIM(_VOID, hl_compute_set_texture, _CUNIT _TEXTURE _I32)
DEFINE_PRIM(_VOID, hl_compute_set_render_target, _CUNIT _RENDER_TARGET _I32)
DEFINE_PRIM(_VOID, hl_compute_set_sampled_texture, _CUNIT _TEXTURE)
DEFINE_PRIM(_VOID, hl_compute_set_sampled_render_target, _CUNIT _RENDER_TARGET)
DEFINE_PRIM(_VOID, hl_compute_set_sampled_depth_from_render_target, _CUNIT _RENDER_TARGET)
DEFINE_PRIM(_VOID, hl_compute_set_texture_addressing, _CUNIT _I32 _I32)
DEFINE_PRIM(_VOID, hl_compute_set_texture3d_addressing, _CUNIT _I32 _I32)
DEFINE_PRIM(_VOID, hl_compute_set_texture_magnification_filter, _CUNIT _I32)
DEFINE_PRIM(_VOID, hl_compute_set_texture3d_magnification_filter, _CUNIT _I32)
DEFINE_PRIM(_VOID, hl_compute_set_texture_minification_filter, _CUNIT _I32)
DEFINE_PRIM(_VOID, hl_compute_set_texture3d_minification_filter, _CUNIT _I32)
DEFINE_PRIM(_VOID, hl_compute_set_texture_mipmap_filter, _CUNIT _I32)
DEFINE_PRIM(_VOID, hl_compute_set_texture3d_mipmap_filter, _CUNIT _I32)
DEFINE_PRIM(_VOID, hl_compute_set_shader, _ABSTRACT(compute_shader))
DEFINE_PRIM(_VOID, hl_compute_compute, _I32 _I32 _I32)