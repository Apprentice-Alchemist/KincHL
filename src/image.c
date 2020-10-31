#include "kinchl.h"
#include <kinc/image.h>

HL_PRIM kinc_image_t * HL_NAME(hl_create_image_from_file)(vstring *name){
    kinc_image_t * img = hl_gc_alloc_raw(sizeof(kinc_image_t));
    void *img_mem = hl_gc_alloc_noptr(kinc_image_size_from_file(hl_to_utf8(name->bytes)));
    kinc_image_init_from_file(img,img_mem,hl_to_utf8(name->bytes));
    return img;
}

DEFINE_PRIM(_ABSTRACT(kinc_image_t),hl_create_image_from_file,_STRING)