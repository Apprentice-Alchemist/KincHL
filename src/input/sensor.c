#include "kinchl.h"
#include <kinc/input/acceleration.h>
#include <kinc/input/rotation.h>

static vclosure* acceleration_cb = NULL;
static vclosure* rotation_cb = NULL;

static void internal_acceleration_cb(float x, float y, float z) {
    if (acceleration_cb != NULL) {
        vdynamic args[3];
        args[0].t = &hlt_f32;
        args[0].v.f = x;
        args[0].t = &hlt_f32;
        args[1].v.f = y;
        args[0].t = &hlt_f32;
        args[2].v.f = z;
        vdynamic* vargs[3] = { &args[0],&args[1],&args[2] };
        bool isExc = false;
        vdynamic* ret = hl_dyn_call_safe(acceleration_cb, vargs, 3, &isExc);
        if (isExc) {
            handle_exception("acceleration callback", ret);
        }
    }
}

static void internal_rotation_cb(float x, float y, float z) {
    if (rotation_cb != NULL) {
        vdynamic args[3];
        args[0].t = &hlt_f32;
        args[0].v.f = x;
        args[0].t = &hlt_f32;
        args[1].v.f = y;
        args[0].t = &hlt_f32;
        args[2].v.f = z;
        vdynamic* vargs[3] = { &args[0],&args[1],&args[2] };
        bool isExc = false;
        vdynamic* ret = hl_dyn_call_safe(acceleration_cb, vargs, 3, &isExc);
        if (isExc) {
            handle_exception("rotation callback",ret);
        }
    }
}

HL_PRIM void HL_NAME(set_acceleration_callback)(vclosure* cb) {
    if (!acceleration_cb) {
        if(!cb) return;
        hl_add_root(&acceleration_cb);
    }
    if(acceleration_cb && !cb){
        hl_remove_root(&acceleration_cb);
        acceleration_cb = NULL;
        kinc_acceleration_callback = NULL;
        return;
    }
    acceleration_cb = cb;
    kinc_acceleration_callback = internal_acceleration_cb;
}

HL_PRIM void HL_NAME(set_rotation_callback)(vclosure* cb) {
    if (!rotation_cb) {
        if (!cb) return;
        hl_add_root(&rotation_cb);
    }
    if (rotation_cb && !cb) {
        hl_remove_root(&rotation_cb);
        rotation_cb = NULL;
        kinc_rotation_callback = NULL;
        return;
    }
    rotation_cb = cb;
    kinc_rotation_callback = internal_rotation_cb;
}

DEFINE_PRIM(_VOID, set_acceleration_callback, _FUN(_VOID, _F32 _F32 _F32))
DEFINE_PRIM(_VOID, set_rotation_callback, _FUN(_VOID, _F32 _F32 _F32))