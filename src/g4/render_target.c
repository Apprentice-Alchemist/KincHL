#include "graphics4.h"

ALLOC_OBJ(kinc_g4_render_target_t, render_target, _ABSTRACT(kinc_g4_render_target_t), EMPTY_INIT, kinc_g4_render_target_destroy)
MAKE_GET_SET(kinc_g4_render_target_t, render_target, width, int, _ABSTRACT(kinc_g4_render_target_t), _I32)
MAKE_GET_SET(kinc_g4_render_target_t, render_target, height, int, _ABSTRACT(kinc_g4_render_target_t), _I32)
MAKE_GET_SET(kinc_g4_render_target_t, render_target, texWidth, int, _ABSTRACT(kinc_g4_render_target_t), _I32)
MAKE_GET_SET(kinc_g4_render_target_t, render_target, texHeight, int, _ABSTRACT(kinc_g4_render_target_t), _I32)
MAKE_GET_SET(kinc_g4_render_target_t, render_target, contextId, int, _ABSTRACT(kinc_g4_render_target_t), _I32)
MAKE_GET_SET(kinc_g4_render_target_t, render_target, isCubeMap, bool, _ABSTRACT(kinc_g4_render_target_t), _BOOL)
MAKE_GET_SET(kinc_g4_render_target_t, render_target, isDepthAttachment, bool, _ABSTRACT(kinc_g4_render_target_t), _BOOL)

HL_PRIM void HL_NAME(hl_g4_render_target_init)(kinc_g4_render_target_t* renderTarget, int width, int height, int depthBufferBits, bool antialiasing,
    kinc_g4_render_target_format_t format, int stencilBufferBits, int contextId) {
    kinc_g4_render_target_init(renderTarget, width, height, depthBufferBits, antialiasing, format, stencilBufferBits, contextId);
}
HL_PRIM void HL_NAME(hl_g4_render_target_init_cube)(kinc_g4_render_target_t* renderTarget, int cubeMapSize, int depthBufferBits, bool antialiasing,
    kinc_g4_render_target_format_t format, int stencilBufferBits, int contextId) {
    kinc_g4_render_target_init_cube(renderTarget, cubeMapSize, depthBufferBits, antialiasing, format, stencilBufferBits, contextId);
}
HL_PRIM void HL_NAME(hl_g4_render_target_use_color_as_texture)(kinc_g4_render_target_t* renderTarget, kinc_g4_texture_unit_t* unit) { kinc_g4_render_target_use_color_as_texture(renderTarget, *unit); }
HL_PRIM void HL_NAME(hl_g4_render_target_use_depth_as_texture)(kinc_g4_render_target_t* renderTarget, kinc_g4_texture_unit_t* unit) { kinc_g4_render_target_use_depth_as_texture(renderTarget, *unit); }
HL_PRIM void HL_NAME(hl_g4_render_target_set_depth_stencil_from)(kinc_g4_render_target_t* renderTarget, kinc_g4_render_target_t* source) { kinc_g4_render_target_set_depth_stencil_from(renderTarget, source); }
HL_PRIM void HL_NAME(hl_g4_render_target_get_pixels)(kinc_g4_render_target_t* renderTarget, vbyte* data) { kinc_g4_render_target_get_pixels(renderTarget, data); }
HL_PRIM void HL_NAME(hl_g4_render_target_generate_mipmaps)(kinc_g4_render_target_t* renderTarget, int levels) { kinc_g4_render_target_generate_mipmaps(renderTarget, levels); }

DEFINE_PRIM(_VOID, hl_g4_render_target_init, _ABSTRACT(kinc_g4_render_target_t) _I32 _I32 _I32 _BOOL _I32 _I32 _I32)
DEFINE_PRIM(_VOID, hl_g4_render_target_init_cube, _ABSTRACT(kinc_g4_render_target_t) _I32 _I32 _BOOL _I32 _I32 _I32)
DEFINE_PRIM(_VOID, hl_g4_render_target_use_color_as_texture, _ABSTRACT(kinc_g4_render_target_t) _TUNIT)
DEFINE_PRIM(_VOID, hl_g4_render_target_use_depth_as_texture, _ABSTRACT(kinc_g4_render_target_t) _TUNIT)
DEFINE_PRIM(_VOID, hl_g4_render_target_set_depth_stencil_from, _ABSTRACT(kinc_g4_render_target_t) _ABSTRACT(kinc_g4_render_target_t))
DEFINE_PRIM(_VOID, hl_g4_render_target_get_pixels, _ABSTRACT(kinc_g4_render_target_t) _BYTES)
DEFINE_PRIM(_VOID, hl_g4_render_target_generate_mipmaps, _ABSTRACT(kinc_g4_render_target_t) _I32)