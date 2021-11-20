#include "kinchl.h"
#include <kinc/input/gamepad.h>

static vclosure *gamepad_axis_cb = NULL;
static vclosure *gamepad_button_cb = NULL;

static void internal_gamepad_axis_cb(int gamepad, int axis, float value) {
    if (gamepad_axis_cb != NULL) {
        vdynamic args[3];
        vdynamic *vargs[3] = {&args[0], &args[1], &args[2]};
        vargs[0]->t = &hlt_i32;
        vargs[1]->t = &hlt_i32;
        vargs[2]->t = &hlt_f32;

        vargs[0]->v.i = gamepad;
        vargs[1]->v.i = axis;
        vargs[2]->v.f = value;
        bool isExc = false;
        vdynamic *exc = hl_dyn_call_safe(gamepad_axis_cb, vargs, 3, &isExc);
        if (isExc) {
            handle_exception("gamepad axis callback", exc);
        }
    }
}

static void internal_gamepad_button_cb(int gamepad, int button, float value) {
    if (gamepad_button_cb != NULL) {
        vdynamic args[3];
        vdynamic *vargs[3] = {&args[0], &args[1], &args[2]};
        vargs[0]->t = &hlt_i32;
        vargs[1]->t = &hlt_i32;
        vargs[2]->t = &hlt_f32;

        vargs[0]->v.i = gamepad;
        vargs[1]->v.i = button;
        vargs[2]->v.f = value;
        bool isExc = false;
        vdynamic *exc = hl_dyn_call_safe(gamepad_button_cb, vargs, 3, &isExc);
        if (isExc) {
            handle_exception("gamepad button callback", exc);
        }
    }
}

void hl_gamepad_init() {
    kinc_gamepad_set_axis_callback(internal_gamepad_axis_cb);
    kinc_gamepad_set_button_callback(internal_gamepad_button_cb);
    hl_add_root(&gamepad_axis_cb);
    hl_add_root(&gamepad_button_cb);
}

HL_PRIM void HL_NAME(hl_gamepad_set_axis_callback)(vclosure *cb) {
    gamepad_axis_cb = cb;
}

HL_PRIM void HL_NAME(hl_gamepad_set_button_callback)(vclosure *cb) {
    gamepad_button_cb = cb;
}

HL_PRIM vbyte *HL_NAME(hl_gamepad_vendor)(int gamepad) {
    return (vbyte *)kinc_gamepad_vendor(gamepad);
}
HL_PRIM vbyte *HL_NAME(hl_gamepad_product_name)(int gamepad) {
    return (vbyte *)kinc_gamepad_product_name(gamepad);
}
HL_PRIM bool HL_NAME(hl_gamepad_connected)(int gamepad) {
    return kinc_gamepad_connected(gamepad);
}

DEFINE_PRIM(_VOID, hl_gamepad_set_axis_callback, _FUN(_VOID, _I32 _I32 _F32))
DEFINE_PRIM(_VOID, hl_gamepad_set_button_callback, _FUN(_VOID, _I32 _I32 _F32))
DEFINE_PRIM(_BYTES, hl_gamepad_vendor, _I32)
DEFINE_PRIM(_BYTES, hl_gamepad_product_name, _I32)
DEFINE_PRIM(_BOOL, hl_gamepad_connected, _I32)