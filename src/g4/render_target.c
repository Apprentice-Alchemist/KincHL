#include "graphics4.h"

MAKE_GET_SET_EX(g4_render_target, width, int, _I32)
MAKE_GET_SET_EX(g4_render_target, height, int, _I32)
MAKE_GET_SET_EX(g4_render_target, texWidth, int, _I32)
MAKE_GET_SET_EX(g4_render_target, texHeight, int, _I32)
MAKE_GET_SET_EX(g4_render_target, contextId, int, _I32)
MAKE_GET_SET_EX(g4_render_target, isCubeMap, bool, _BOOL)
MAKE_GET_SET_EX(g4_render_target, isDepthAttachment, bool, _BOOL)

HL_PRIM void HL_NAME(hl_g4_render_target_init)(hl_g4_render_target *renderTarget, int width, int height, int depthBufferBits, bool antialiasing,
                                               kinc_g4_render_target_format_t format, int stencilBufferBits, int contextId) {
    kinc_g4_render_target_init(&renderTarget->t, width, height, depthBufferBits, antialiasing, format, stencilBufferBits, contextId);
}
HL_PRIM void HL_NAME(hl_g4_render_target_init_cube)(hl_g4_render_target *renderTarget, int cubeMapSize, int depthBufferBits, bool antialiasing,
                                                    kinc_g4_render_target_format_t format, int stencilBufferBits, int contextId) {
    kinc_g4_render_target_init_cube(&renderTarget->t, cubeMapSize, depthBufferBits, antialiasing, format, stencilBufferBits, contextId);
}
HL_PRIM void HL_NAME(hl_g4_render_target_use_color_as_texture)(hl_g4_render_target *renderTarget, kinc_g4_texture_unit_t *unit) {
    kinc_g4_render_target_use_color_as_texture(&renderTarget->t, *unit);
}
HL_PRIM void HL_NAME(hl_g4_render_target_use_depth_as_texture)(hl_g4_render_target *renderTarget, kinc_g4_texture_unit_t *unit) {
    kinc_g4_render_target_use_depth_as_texture(&renderTarget->t, *unit);
}
HL_PRIM void HL_NAME(hl_g4_render_target_set_depth_stencil_from)(hl_g4_render_target *renderTarget, hl_g4_render_target *source) {
    kinc_g4_render_target_set_depth_stencil_from(&renderTarget->t, &source->t);
}
HL_PRIM void HL_NAME(hl_g4_render_target_get_pixels)(hl_g4_render_target *renderTarget, vbyte *data) {
    kinc_g4_render_target_get_pixels(&renderTarget->t, data);
}
HL_PRIM void HL_NAME(hl_g4_render_target_generate_mipmaps)(hl_g4_render_target *renderTarget, int levels) {
    kinc_g4_render_target_generate_mipmaps(&renderTarget->t, levels);
}

DEFINE_PRIM(_VOID, hl_g4_render_target_init, _RENDER_TARGET _I32 _I32 _I32 _BOOL _I32 _I32 _I32)
DEFINE_PRIM(_VOID, hl_g4_render_target_init_cube, _RENDER_TARGET _I32 _I32 _BOOL _I32 _I32 _I32)
DEFINE_PRIM(_VOID, hl_g4_render_target_use_color_as_texture, _RENDER_TARGET _TUNIT)
DEFINE_PRIM(_VOID, hl_g4_render_target_use_depth_as_texture, _RENDER_TARGET _TUNIT)
DEFINE_PRIM(_VOID, hl_g4_render_target_set_depth_stencil_from, _RENDER_TARGET _RENDER_TARGET)
DEFINE_PRIM(_VOID, hl_g4_render_target_get_pixels, _RENDER_TARGET _BYTES)
DEFINE_PRIM(_VOID, hl_g4_render_target_generate_mipmaps, _RENDER_TARGET _I32)