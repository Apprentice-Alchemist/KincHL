#include "graphics4.h"

ALLOC_OBJ(kinc_g4_texture_array_t,texture_array,_ABSTRACT(kinc_g4_texture_array_t),EMPTY_INIT,kinc_g4_destroy)

HL_PRIM void HL_NAME(hl_g4_texture_array_init)(kinc_g4_texture_array_t *arr){
    kinc_g4_texture_array_init(arr,NULL,0);
}