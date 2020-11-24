#include "graphics4.h"
#include <kinc/error.h>
ALLOC_OBJ(kinc_g4_texture_array_t, texture_array, _ABSTRACT(kinc_g4_texture_array_t), EMPTY_INIT, kinc_g4_texture_array_destroy)

HL_PRIM void HL_NAME(hl_g4_texture_array_init)(kinc_g4_texture_array_t* arr, varray *texs) {
    kinc_image_t *arg = texs->size == 0 ? NULL : hl_gc_alloc_raw(sizeof(kinc_image_t) * (texs->size));
    // kinc_affirm_message(arg != NULL,"Arg was null : %s",__FILE__);
    for(int x = 0; x < texs->size; x++){
        arg[x] = *(hl_aptr(texs,kinc_image_t*)[x]);
    }
    kinc_g4_texture_array_init(arr, arg, texs->size);
}

DEFINE_PRIM(_VOID,hl_g4_texture_array_init,_ABSTRACT(kinc_g4_texture_array_t) _ARR);