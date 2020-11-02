#include "kinchl.h"
#include <kinc/math/matrix.h>
#include <kinc/system.h>
HL_PRIM kinc_matrix3x3_t* HL_NAME(hl_matrix3x3_alloc)() {
    kinc_matrix3x3_t * m = hl_gc_alloc_raw(sizeof(kinc_matrix3x3_t));
    memset(m->m, 0, sizeof(m->m));
    return m;
}
HL_PRIM float HL_NAME(hl_matrix3x3_get)(kinc_matrix3x3_t* mat, int x, int y) {
    return kinc_matrix3x3_get(mat, x, y);
}
HL_PRIM void HL_NAME(hl_matrix3x3_set)(kinc_matrix3x3_t* mat, int x, int y, float value) {
    kinc_matrix3x3_set(mat, x, y, value);
}
HL_PRIM kinc_matrix3x3_t* HL_NAME(hl_matrix3x3_identity)() {
    kinc_matrix3x3_t ret = kinc_matrix3x3_identity();
    return &ret;
}
HL_PRIM kinc_matrix3x3_t* HL_NAME(hl_matrix3x3_rotation_x)(float alpha) {
    kinc_matrix3x3_t ret = kinc_matrix3x_rotation_x(alpha);
    return &ret;
}
HL_PRIM kinc_matrix3x3_t* HL_NAME(hl_matrix3x3_rotation_y)(float alpha) {
    kinc_matrix3x3_t ret = kinc_matrix3x_rotation_y(alpha);
    return &ret;
}
HL_PRIM kinc_matrix3x3_t* HL_NAME(hl_matrix3x3_rotation_z)(float alpha) {
    kinc_matrix3x3_t ret = kinc_matrix3x_rotation_z(alpha);
    return &ret;
}
DEFINE_PRIM(_ABSTRACT(kinc_matrix3x3_t), hl_matrix3x3_alloc, _NO_ARG)
DEFINE_PRIM(_F32, hl_matrix3x3_get, _ABSTRACT(kinc_matrix3x3_t) _I32 _I32)
DEFINE_PRIM(_VOID, hl_matrix3x3_set, _ABSTRACT(kinc_matrix3x3_t) _I32 _I32 _F32)
DEFINE_PRIM(_ABSTRACT(kinc_matrix3x3_t), hl_matrix3x3_identity, _NO_ARG)
DEFINE_PRIM(_ABSTRACT(kinc_matrix3x3_t), hl_matrix3x3_rotation_x, _F32)
DEFINE_PRIM(_ABSTRACT(kinc_matrix3x3_t), hl_matrix3x3_rotation_y, _F32)
DEFINE_PRIM(_ABSTRACT(kinc_matrix3x3_t), hl_matrix3x3_rotation_z, _F32)