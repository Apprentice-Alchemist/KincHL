#include "kinchl.h"
#include <kinc/input/acceleration.h>
#include <kinc/input/rotation.h>

vclosure * acceleration_cb = NULL;
vclosure * rotation_cb = NULL;

void internal_acceleration_cb(float x,float y,float z){
    if(acceleration_cb != NULL){
        void (*fun)(float,float,float) = acceleration_cb->hasValue ? acceleration_cb->value : acceleration_cb->fun;
        fun(x,y,z);
    }
}
void internal_rotation_cb(float x, float y, float z) {
    if (rotation_cb != NULL) {
        void (*fun)(float, float, float) = rotation_cb->hasValue ? rotation_cb->value : rotation_cb->fun;
        fun(x, y, z);
    }
}

HL_PRIM void HL_NAME(set_acceleration_callback)(vclosure *cb){
    if(acceleration_cb != NULL){
        hl_remove_root(acceleration_cb);
    }
    acceleration_cb = cb;
    hl_add_root(acceleration_cb);
    kinc_acceleration_callback = internal_acceleration_cb;
}
HL_PRIM void HL_NAME(set_rotation_callback)(vclosure* cb) {
    if (rotation_cb != NULL) {
        hl_remove_root(rotation_cb);
    }
    rotation_cb = cb;
    hl_add_root(rotation_cb);
    kinc_rotation_callback = internal_rotation_cb;
}

DEFINE_PRIM(_VOID,set_acceleration_callback,_FUN(_VOID,_F32 _F32 _F32))
DEFINE_PRIM(_VOID,set_rotation_callback,_FUN(_VOID,_F32 _F32 _F32))