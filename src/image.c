#include "image.h"

ALLOC_OBJ_EX(image, kinc_image_t, EMPTY_INIT, kinc_image_destroy)

MAKE_GET_SET_EX(image, width, int, _I32)
MAKE_GET_SET_EX(image, height, int, _I32)
MAKE_GET_SET_EX(image, depth, int, _I32)
MAKE_GET_SET_EX(image, data_size, int, _I32)
MAKE_GET_SET_EX(image, format, int, _I32)

HL_PRIM size_t HL_NAME(hl_image_init)(hl_image *img, void *mem, int w, int h, int format) {
    return kinc_image_init(&img->t, mem, w, h, format);
}

HL_PRIM size_t HL_NAME(hl_image_init3d)(hl_image *img, void *mem, int w, int h, int depth, int format) {
    return kinc_image_init3d(&img->t, mem, w, h, depth, format);
}

HL_PRIM void HL_NAME(hl_image_init_from_bytes)(hl_image *img, void *mem, int w, int h, int format) {
    kinc_image_init_from_bytes(&img->t, mem, w, h, format);
}

HL_PRIM size_t HL_NAME(hl_image_init_from_file)(hl_image *img, vstring *name) {
    void *mem = hl_gc_alloc_noptr((int)kinc_image_size_from_file(hl_to_utf8(name->bytes)));
    return kinc_image_init_from_file(&img->t, mem, hl_to_utf8(name->bytes));
}

DEFINE_PRIM(_I64, hl_image_init, _ABSTRACT(image) _BYTES _I32 _I32 _I32)
DEFINE_PRIM(_I64, hl_image_init_from_file, _ABSTRACT(image) _STRING)
DEFINE_PRIM(_VOID, hl_image_init_from_bytes, _ABSTRACT(image) _BYTES _I32 _I32 _I32)