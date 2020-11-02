#include "graphics4.h"

ALLOC_OBJ(kinc_g4_texture_t, texture, _ABSTRACT(kinc_g4_texture_t), EMPTY_INIT, kinc_g4_texture_destroy)
MAKE_GET_SET(kinc_g4_texture_t, texture, tex_width, int, _ABSTRACT(kinc_g4_texture_t), _I32)
MAKE_GET_SET(kinc_g4_texture_t, texture, tex_height, int, _ABSTRACT(kinc_g4_texture_t), _I32)
MAKE_GET_SET(kinc_g4_texture_t, texture, tex_depth, int, _ABSTRACT(kinc_g4_texture_t), _I32)
MAKE_GET_SET(kinc_g4_texture_t, texture, format, int, _ABSTRACT(kinc_g4_texture_t), _I32)

HL_PRIM void kinc_hl_g4_texture_init(kinc_g4_texture_t* texture, int width, int height, kinc_image_format_t format) { kinc_g4_texture_init(texture, width, height, format); }
HL_PRIM void kinc_hl_g4_texture_init3d(kinc_g4_texture_t* texture, int width, int height, int depth, kinc_image_format_t format) { kinc_g4_texture_init3d(texture, width, height, depth, format); }
HL_PRIM void kinc_hl_g4_texture_init_from_image(kinc_g4_texture_t* texture, kinc_image_t* image) { kinc_g4_texture_init_from_image(texture, image); }
HL_PRIM void kinc_hl_g4_texture_init_from_image3d(kinc_g4_texture_t* texture, kinc_image_t* image) { kinc_g4_texture_init_from_image3d(texture, image); }
HL_PRIM unsigned char* kinc_hl_g4_texture_lock(kinc_g4_texture_t* texture) { return kinc_g4_texture_lock(texture); }
HL_PRIM void kinc_hl_g4_texture_unlock(kinc_g4_texture_t* texture) { kinc_g4_texture_unlock(texture); }
HL_PRIM void kinc_hl_g4_texture_clear(kinc_g4_texture_t* texture, int x, int y, int z, int width, int height, int depth, unsigned color) { kinc_g4_texture_clear(texture, x, y, z, width, height, depth, color); }
HL_PRIM void kinc_hl_g4_texture_generate_mipmaps(kinc_g4_texture_t* texture, int levels) { kinc_g4_texture_generate_mipmaps(texture, levels); }
HL_PRIM void kinc_hl_g4_texture_set_mipmap(kinc_g4_texture_t* texture, kinc_image_t* mipmap, int level) { kinc_g4_texture_set_mipmap(texture, mipmap, level); }
HL_PRIM int kinc_hl_g4_texture_stride(kinc_g4_texture_t* texture) { return kinc_g4_texture_stride(texture); }

DEFINE_PRIM(_VOID, hl_g4_texture_init, _ABSTRACT(kinc_g4_texture_t) _I32 _I32 _I32)
DEFINE_PRIM(_VOID, hl_g4_texture_init3d, _ABSTRACT(kinc_g4_texture_t) _I32 _I32 _I32 _I32)
DEFINE_PRIM(_VOID, hl_g4_texture_init_from_image, _ABSTRACT(kinc_g4_texture_t) _ABSTRACT(kinc_image_t))
DEFINE_PRIM(_VOID, hl_g4_texture_init_from_image3d, _ABSTRACT(kinc_g4_texture_t) _ABSTRACT(kinc_image_t))
DEFINE_PRIM(_BYTES, hl_g4_texture_lock, _ABSTRACT(kinc_g4_texture_t))
DEFINE_PRIM(_VOID, hl_g4_texture_unlock, _ABSTRACT(kinc_g4_texture_t))
DEFINE_PRIM(_VOID, hl_g4_texture_clear, _ABSTRACT(kinc_g4_texture_t) _I32 _I32 _I32 _I32 _I32 _I32 _I32)
DEFINE_PRIM(_VOID, hl_g4_texture_generate_mipmaps, _ABSTRACT(kinc_g4_texture_t) _I32)
DEFINE_PRIM(_VOID, hl_g4_texture_set_mipmap, _ABSTRACT(kinc_g4_texture_t) _ABSTRACT(kinc_image_t) _I32)
DEFINE_PRIM(_I32, hl_g4_texture_stride, _ABSTRACT(kinc_g4_texture_t))