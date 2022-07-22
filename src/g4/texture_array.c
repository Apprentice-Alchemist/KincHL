#include "graphics4.h"
#include "image.h"
#include "kinchl.h"

HL_PRIM void HL_NAME(hl_g4_texture_array_init)(hl_g4_texture_array *arr, varray *texs) {
    STACK_ALLOC(kinc_image_t, texs->size, arg);
    for (int x = 0; x < texs->size; x++) {
        arg[x] = (hl_aptr(texs, hl_image *)[x])->t;
    }
    kinc_g4_texture_array_init(&arr->t, arg, texs->size);
}

DEFINE_PRIM(_VOID, hl_g4_texture_array_init, _TEXTURE_ARRAY _ARR);