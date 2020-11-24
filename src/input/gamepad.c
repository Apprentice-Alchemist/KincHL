#include "kinchl.h"
#include <kinc/input/gamepad.h>
#include <kinc/log.h>

vclosure* gamepad_axis_cb = NULL;
vclosure* gamepad_button_cb = NULL;

void internal_gamepad_axis_cb(int gamepad, int axis, float value) {
    if (gamepad_axis_cb != NULL) {
        vdynamic* arg1 = hl_alloc_dynamic(&hlt_i32);
        arg1->v.i = gamepad;
        vdynamic* arg2 = hl_alloc_dynamic(&hlt_i32);
        arg1->v.i = axis;
        vdynamic* arg3 = hl_alloc_dynamic(&hlt_f32);
        arg3->v.f = value;
        vdynamic* args[3] = { arg1,arg2,arg3 };
        bool isexc = false;
        hl_dyn_call_safe(gamepad_axis_cb, args, 3, &isexc);
        if (isexc) {
            kinc_log(KINC_LOG_LEVEL_WARNING, "Exception occured in gamepad axis callback");
            varray* stack = hl_exception_stack();
            for (int i = 0; i < stack->size; i++) {
                kinc_log(KINC_LOG_LEVEL_INFO, hl_to_utf8(hl_to_string(hl_aptr(stack, vdynamic*)[i])));
                kinc_log(KINC_LOG_LEVEL_INFO, "\n");
            }
        }
    }
}
void internal_gamepad_button_cb(int gamepad, int button, float value) {
    if (gamepad_button_cb != NULL) {
        vdynamic* arg1 = hl_alloc_dynamic(&hlt_i32);
        arg1->v.i = gamepad;
        vdynamic* arg2 = hl_alloc_dynamic(&hlt_i32);
        arg1->v.i = button;
        vdynamic* arg3 = hl_alloc_dynamic(&hlt_f32);
        arg3->v.f = value;
        vdynamic* args[3] = { arg1,arg2,arg3 };
        bool isexc = false;
        hl_dyn_call_safe(gamepad_button_cb, args, 3, &isexc);
        if (isexc) {
            kinc_log(KINC_LOG_LEVEL_WARNING, "Exception occured in gamepad button callback");
            varray* stack = hl_exception_stack();
            for (int i = 0; i < stack->size; i++) {
                kinc_log(KINC_LOG_LEVEL_INFO, hl_to_utf8(hl_to_string(hl_aptr(stack, vdynamic*)[i])));
                kinc_log(KINC_LOG_LEVEL_INFO, "\n");
            }
        }
    }
}
HL_PRIM void HL_NAME(hl_gamepad_set_axis_callback)(vclosure* cb) {
    if (gamepad_axis_cb != NULL) {
        hl_remove_root(gamepad_axis_cb);
    }
    gamepad_axis_cb = cb;
    hl_add_root(gamepad_axis_cb);
    kinc_gamepad_axis_callback = internal_gamepad_axis_cb;
}
HL_PRIM void HL_NAME(hl_gamepad_set_button_callback)(vclosure* cb) {
    if (gamepad_button_cb != NULL) {
        hl_remove_root(gamepad_button_cb);
    }
    gamepad_button_cb = cb;
    hl_add_root(gamepad_button_cb);
    kinc_gamepad_button_callback = internal_gamepad_button_cb;
}

HL_PRIM vstring* HL_NAME(hl_gamepad_vendor)(int gamepad) {
    return (vstring*)hl_alloc_strbytes(hl_to_utf16(kinc_gamepad_vendor(gamepad)));
}
HL_PRIM vstring* HL_NAME(hl_gamepad_product_name)(int gamepad) {
    return (vstring*)hl_alloc_strbytes(hl_to_utf16(kinc_gamepad_product_name(gamepad)));
}
HL_PRIM bool HL_NAME(hl_gamepad_connected)(int gamepad) {
    return kinc_gamepad_connected(gamepad);
}

DEFINE_PRIM(_VOID, hl_gamepad_set_axis_callback, _FUN(_VOID, _I32 _I32 _F32))
DEFINE_PRIM(_VOID, hl_gamepad_set_button_callback, _FUN(_VOID, _I32 _I32 _F32))
DEFINE_PRIM(_STRING, hl_gamepad_vendor, _I32)
DEFINE_PRIM(_STRING, hl_gamepad_product_name, _I32)
DEFINE_PRIM(_BOOL, hl_gamepad_connected, _I32)