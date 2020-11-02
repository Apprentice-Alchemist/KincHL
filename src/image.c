#include "kinchl.h"
#include <kinc/image.h>

ALLOC_OBJ(kinc_image_t,image,_ABSTRACT(kinc_image_t), EMPTY_INIT,kinc_image_destroy)

HL_PRIM size_t HL_NAME(hl_image_init)(kinc_image_t*img,void *mem,int w, int h,int format){
    return kinc_image_init(img,mem,w,h,format);
}
HL_PRIM size_t HL_NAME(hl_image_init3d)(kinc_image_t* img, void* mem, int w, int h,int depth, int format) {
    return kinc_image_init3d(img, mem, w, h, depth,format);
}
HL_PRIM void HL_NAME(hl_image_init_from_bytes)(kinc_image_t* img, void* mem, int w, int h, int depth, int format) {
    kinc_image_init_from_bytes(img,mem,w,h,format);
}
HL_PRIM size_t HL_NAME(hl_image_init_from_file)(kinc_image_t* img,vstring *name) {
    void* mem = hl_gc_alloc_noptr(kinc_image_size_from_file(hl_to_utf8(name->bytes)));
    return kinc_image_init_from_file(img,mem,hl_to_utf8(name->bytes));
}
DEFINE_PRIM(_I64,hl_image_init,_ABSTRACT(kinc_image_t) _BYTES _I32 _I32 _I32)
DEFINE_PRIM(_I64,hl_image_init_from_file,_ABSTRACT(kinc_image_t) _STRING)