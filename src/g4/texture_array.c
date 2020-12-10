#include "graphics4.h"
#include "image.h"

HL_PRIM void HL_NAME(hl_g4_texture_array_init)(hl_g4_texture_array* arr, varray *texs) {
    kinc_image_t *arg = texs->size == 0 ? NULL : malloc(sizeof(hl_image) * (texs->size));
    for(int x = 0; x < texs->size; x++){
        arg[x] = (hl_aptr(texs,hl_image*)[x])->t;
    }
    kinc_g4_texture_array_init(&arr->t, arg, texs->size);
    free(arg);
}

DEFINE_PRIM(_VOID,hl_g4_texture_array_init,_TEXTURE_ARRAY _ARR);