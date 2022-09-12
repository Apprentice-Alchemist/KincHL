#include "graphics5.h"
#include "kinc/graphics5/rendertarget.h"

MAKE_GET_SET_EX(g5_render_target, width, int, _I32)
MAKE_GET_SET_EX(g5_render_target, height, int, _I32)
MAKE_GET_SET_EX(g5_render_target, texWidth, int, _I32)
MAKE_GET_SET_EX(g5_render_target, texHeight, int, _I32)
MAKE_GET_SET_EX(g5_render_target, framebuffer_index, int, _I32)
MAKE_GET_SET_EX(g5_render_target, isCubeMap, bool, _BOOL)
MAKE_GET_SET_EX(g5_render_target, isDepthAttachment, bool, _BOOL)

HL_PRIM void HL_NAME(hl_g5_render_target_init)(hl_g5_render_target *renderTarget, int width, int height,
                                               kinc_g5_render_target_format_t format, int depthBufferBits, int stencilBufferBits) {
    kinc_g5_render_target_init(&renderTarget->t, width, height, format, depthBufferBits, stencilBufferBits);
}

HL_PRIM void HL_NAME(hl_g5_render_target_init_with_multisampling)(hl_g5_render_target *renderTarget, int width, int height,
                                                                  kinc_g5_render_target_format_t format, int depthBufferBits, int stencilBufferBits, int samples_per_pixel) {
    kinc_g5_render_target_init_with_multisampling(&renderTarget->t, width, height, format, depthBufferBits, stencilBufferBits, samples_per_pixel);
}

HL_PRIM void HL_NAME(hl_g5_render_target_init_framebuffer)(hl_g5_render_target *renderTarget, int width, int height,
                                                           kinc_g5_render_target_format_t format, int depthBufferBits, int stencilBufferBits) {
    kinc_g5_render_target_init_framebuffer(&renderTarget->t, width, height, format, depthBufferBits, stencilBufferBits);
}

HL_PRIM void HL_NAME(hl_g5_render_target_init_framebuffer_with_multisampling)(hl_g5_render_target *renderTarget, int width, int height,
                                                                              kinc_g5_render_target_format_t format, int depthBufferBits, int stencilBufferBits, int samples_per_pixel) {
    kinc_g5_render_target_init_framebuffer_with_multisampling(&renderTarget->t, width, height, format, depthBufferBits, stencilBufferBits, samples_per_pixel);
}

HL_PRIM void HL_NAME(hl_g5_render_target_init_cube)(hl_g5_render_target *renderTarget, int cubeMapSize,
                                                    kinc_g5_render_target_format_t format, int depthBufferBits, int stencilBufferBits) {
    kinc_g5_render_target_init_cube(&renderTarget->t, cubeMapSize, format, depthBufferBits, stencilBufferBits);
}
HL_PRIM void HL_NAME(hl_g5_render_target_init_cube_with_multisampling)(hl_g5_render_target *renderTarget, int cubeMapSize,
                                                                       kinc_g5_render_target_format_t format, int depthBufferBits, int stencilBufferBits, int samples_per_pixel) {
    kinc_g5_render_target_init_cube_with_multisampling(&renderTarget->t, cubeMapSize, format, depthBufferBits, stencilBufferBits, samples_per_pixel);
}
HL_PRIM void HL_NAME(hl_g5_render_target_use_color_as_texture)(hl_g5_render_target *renderTarget, kinc_g5_texture_unit_t *unit) {
    kinc_g5_render_target_use_color_as_texture(&renderTarget->t, *unit);
}
HL_PRIM void HL_NAME(hl_g5_render_target_use_depth_as_texture)(hl_g5_render_target *renderTarget, kinc_g5_texture_unit_t *unit) {
    kinc_g5_render_target_use_depth_as_texture(&renderTarget->t, *unit);
}
HL_PRIM void HL_NAME(hl_g5_render_target_set_depth_stencil_from)(hl_g5_render_target *renderTarget, hl_g5_render_target *source) {
    kinc_g5_render_target_set_depth_stencil_from(&renderTarget->t, &source->t);
}
// HL_PRIM void HL_NAME(hl_g5_render_target_get_pixels)(hl_g5_render_target *renderTarget, vbyte *data) {
//     kinc_g5_render_target_get_pixels(&renderTarget->t, data);
// }
// HL_PRIM void HL_NAME(hl_g5_render_target_generate_mipmaps)(hl_g5_render_target *renderTarget, int levels) {
//     kinc_g5_render_target_generate_mipmaps(&renderTarget->t, levels);
// }

DEFINE_PRIM(_VOID, hl_g5_render_target_init, _RENDER_TARGET _I32 _I32 _I32 _I32 _I32)
DEFINE_PRIM(_VOID, hl_g5_render_target_init_with_multisampling, _RENDER_TARGET _I32 _I32 _I32 _I32 _I32 _I32)
DEFINE_PRIM(_VOID, hl_g5_render_target_init_framebuffer, _RENDER_TARGET _I32 _I32 _I32 _I32 _I32)
DEFINE_PRIM(_VOID, hl_g5_render_target_init_framebuffer_with_multisampling, _RENDER_TARGET _I32 _I32 _I32 _I32 _I32 _I32)
DEFINE_PRIM(_VOID, hl_g5_render_target_init_cube, _RENDER_TARGET _I32 _I32 _I32 _I32)
DEFINE_PRIM(_VOID, hl_g5_render_target_init_cube_with_multisampling, _RENDER_TARGET _I32 _I32 _I32 _I32 _I32)
DEFINE_PRIM(_VOID, hl_g5_render_target_use_color_as_texture, _RENDER_TARGET _TUNIT)
DEFINE_PRIM(_VOID, hl_g5_render_target_use_depth_as_texture, _RENDER_TARGET _TUNIT)
DEFINE_PRIM(_VOID, hl_g5_render_target_set_depth_stencil_from, _RENDER_TARGET _RENDER_TARGET)
// DEFINE_PRIM(_VOID, hl_g5_render_target_get_pixels, _RENDER_TARGET _BYTES)
// DEFINE_PRIM(_VOID, hl_g5_render_target_generate_mipmaps, _RENDER_TARGET _I32)