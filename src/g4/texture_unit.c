#include "graphics4.h"

HL_PRIM void kinc_hl_g4_set_texture_magnification_filter(hl_tex_unit* unit, kinc_g4_texture_filter_t filter) { kinc_g4_set_texture_magnification_filter(unit->loc, filter); }
HL_PRIM void kinc_hl_g4_set_texture3d_magnification_filter(hl_tex_unit* texunit, kinc_g4_texture_filter_t filter) { kinc_g4_set_texture3d_magnification_filter(texunit->loc, filter); }
HL_PRIM void kinc_hl_g4_set_texture_minification_filter(hl_tex_unit* unit, kinc_g4_texture_filter_t filter) { kinc_g4_set_texture_minification_filter(unit->loc, filter); }
HL_PRIM void kinc_hl_g4_set_texture3d_minification_filter(hl_tex_unit* texunit, kinc_g4_texture_filter_t filter) { kinc_g4_set_texture3d_minification_filter(texunit->loc, filter); }
HL_PRIM void kinc_hl_g4_set_texture_mipmap_filter(hl_tex_unit* unit, kinc_g4_mipmap_filter_t filter) { kinc_g4_set_texture_mipmap_filter(unit->loc, filter); }
HL_PRIM void kinc_hl_g4_set_texture3d_mipmap_filter(hl_tex_unit* texunit, kinc_g4_mipmap_filter_t filter) { kinc_g4_set_texture3d_mipmap_filter(texunit->loc, filter); }
HL_PRIM void kinc_hl_g4_set_texture_compare_mode(hl_tex_unit* unit, bool enabled) { kinc_g4_set_texture_compare_mode(unit->loc, enabled); }
HL_PRIM void kinc_hl_g4_set_cubemap_compare_mode(hl_tex_unit* unit, bool enabled) { kinc_g4_set_cubemap_compare_mode(unit->loc, enabled); }

DEFINE_PRIM(_VOID, hl_g4_set_texture_magnification_filter, _TUNIT _I32)
DEFINE_PRIM(_VOID, hl_g4_set_texture3d_magnification_filter, _TUNIT _I32)
DEFINE_PRIM(_VOID, hl_g4_set_texture_minification_filter, _TUNIT _I32)
DEFINE_PRIM(_VOID, hl_g4_set_texture3d_minification_filter, _TUNIT _I32)
DEFINE_PRIM(_VOID, hl_g4_set_texture_mipmap_filter, _TUNIT _I32)
DEFINE_PRIM(_VOID, hl_g4_set_texture3d_mipmap_filter, _TUNIT _I32)
DEFINE_PRIM(_VOID, hl_g4_set_texture_compare_mode, _TUNIT _BOOL)
DEFINE_PRIM(_VOID, hl_g4_set_cubemap_compare_mode, _TUNIT _BOOL)