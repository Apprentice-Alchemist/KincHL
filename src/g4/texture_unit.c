#include "graphics4.h"

HL_PRIM void kinc_hl_g4_set_texture_magnification_filter(kinc_g4_texture_unit_t* unit, kinc_g4_texture_filter_t filter) { kinc_g4_set_texture_magnification_filter(*unit, filter); }
HL_PRIM void kinc_hl_g4_set_texture3d_magnification_filter(kinc_g4_texture_unit_t* unit, kinc_g4_texture_filter_t filter) { kinc_g4_set_texture3d_magnification_filter(*unit, filter); }
HL_PRIM void kinc_hl_g4_set_texture_minification_filter(kinc_g4_texture_unit_t* unit, kinc_g4_texture_filter_t filter) { kinc_g4_set_texture_minification_filter(*unit, filter); }
HL_PRIM void kinc_hl_g4_set_texture3d_minification_filter(kinc_g4_texture_unit_t* unit, kinc_g4_texture_filter_t filter) { kinc_g4_set_texture3d_minification_filter(*unit, filter); }
HL_PRIM void kinc_hl_g4_set_texture_mipmap_filter(kinc_g4_texture_unit_t* unit, kinc_g4_mipmap_filter_t filter) { kinc_g4_set_texture_mipmap_filter(*unit, filter); }
HL_PRIM void kinc_hl_g4_set_texture3d_mipmap_filter(kinc_g4_texture_unit_t* unit, kinc_g4_mipmap_filter_t filter) { kinc_g4_set_texture3d_mipmap_filter(*unit, filter); }
HL_PRIM void kinc_hl_g4_set_texture_compare_mode(kinc_g4_texture_unit_t* unit, bool enabled) { kinc_g4_set_texture_compare_mode(*unit, enabled); }
HL_PRIM void kinc_hl_g4_set_cubemap_compare_mode(kinc_g4_texture_unit_t* unit, bool enabled) { kinc_g4_set_cubemap_compare_mode(*unit, enabled); }

DEFINE_PRIM(_VOID, hl_g4_set_texture_magnification_filter, _TUNIT _I32)
DEFINE_PRIM(_VOID, hl_g4_set_texture3d_magnification_filter, _TUNIT _I32)
DEFINE_PRIM(_VOID, hl_g4_set_texture_minification_filter, _TUNIT _I32)
DEFINE_PRIM(_VOID, hl_g4_set_texture3d_minification_filter, _TUNIT _I32)
DEFINE_PRIM(_VOID, hl_g4_set_texture_mipmap_filter, _TUNIT _I32)
DEFINE_PRIM(_VOID, hl_g4_set_texture3d_mipmap_filter, _TUNIT _I32)
DEFINE_PRIM(_VOID, hl_g4_set_texture_compare_mode, _TUNIT _BOOL)
DEFINE_PRIM(_VOID, hl_g4_set_cubemap_compare_mode, _TUNIT _BOOL)