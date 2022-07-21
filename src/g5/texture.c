#include "graphics5.h"
#include "image.h"

MAKE_GET_SET_EX(g5_texture, texWidth, int, _I32)
MAKE_GET_SET_EX(g5_texture, texHeight, int, _I32)
// MAKE_GET_SET_EX(g5_texture, texDepth, int, _I32)
MAKE_GET_SET_EX(g5_texture, format, int, _I32)

HL_PRIM void kinc_hl_g5_texture_init(hl_g5_texture *texture, int width, int height, kinc_image_format_t format) {
    kinc_g5_texture_init(&texture->t, width, height, format);
}
HL_PRIM void kinc_hl_g5_texture_init3d(hl_g5_texture *texture, int width, int height, int depth, kinc_image_format_t format) {
    kinc_g5_texture_init3d(&texture->t, width, height, depth, format);
}
HL_PRIM void kinc_hl_g5_texture_init_from_image(hl_g5_texture *texture, hl_image *image) {
    kinc_g5_texture_init_from_image(&texture->t, &image->t);
}

HL_PRIM void kinc_hl_g5_texture_init_non_sampled_access(hl_g5_texture *texture, int width, int height, kinc_image_format_t format) {
	kinc_g5_texture_init_non_sampled_access(&texture->t, width, height, format);
}
// HL_PRIM void kinc_hl_g5_texture_init_from_image3d(hl_g5_texture *texture, hl_image *image) {
//     kinc_g5_texture_init_from_image3d(&texture->t, &image->t);
// }
HL_PRIM unsigned char *kinc_hl_g5_texture_lock(hl_g5_texture *texture) {
    return kinc_g5_texture_lock(&texture->t);
}
HL_PRIM void kinc_hl_g5_texture_unlock(hl_g5_texture *texture) {
    kinc_g5_texture_unlock(&texture->t);
}
HL_PRIM void kinc_hl_g5_texture_clear(hl_g5_texture *texture, int x, int y, int z, int width, int height, int depth, unsigned color) {
    kinc_g5_texture_clear(&texture->t, x, y, z, width, height, depth, color);
}
HL_PRIM void kinc_hl_g5_texture_generate_mipmaps(hl_g5_texture *texture, int levels) {
    kinc_g5_texture_generate_mipmaps(&texture->t, levels);
}
HL_PRIM void kinc_hl_g5_texture_set_mipmap(hl_g5_texture *texture, hl_image *mipmap, int level) {
    kinc_g5_texture_set_mipmap(&texture->t, &mipmap->t, level);
}
HL_PRIM int kinc_hl_g5_texture_stride(hl_g5_texture *texture) {
    return kinc_g5_texture_stride(&texture->t);
}

DEFINE_PRIM(_VOID, hl_g5_texture_init, _TEXTURE _I32 _I32 _I32)
DEFINE_PRIM(_VOID, hl_g5_texture_init3d, _TEXTURE _I32 _I32 _I32 _I32)
DEFINE_PRIM(_VOID, hl_g5_texture_init_from_image, _TEXTURE _ABSTRACT(image))
DEFINE_PRIM(_VOID, hl_g5_texture_init_non_sampled_access, _TEXTURE _I32 _I32 _I32)
// DEFINE_PRIM(_VOID, hl_g5_texture_init_from_image3d, _TEXTURE _ABSTRACT(image))
DEFINE_PRIM(_BYTES, hl_g5_texture_lock, _TEXTURE)
DEFINE_PRIM(_VOID, hl_g5_texture_unlock, _TEXTURE)
DEFINE_PRIM(_VOID, hl_g5_texture_clear, _TEXTURE _I32 _I32 _I32 _I32 _I32 _I32 _I32)
DEFINE_PRIM(_VOID, hl_g5_texture_generate_mipmaps, _TEXTURE _I32)
DEFINE_PRIM(_VOID, hl_g5_texture_set_mipmap, _TEXTURE _ABSTRACT(image) _I32)
DEFINE_PRIM(_I32, hl_g5_texture_stride, _TEXTURE)