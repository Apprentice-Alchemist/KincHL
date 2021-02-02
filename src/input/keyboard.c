#include "kinchl.h"
#include <kinc/input/keyboard.h>

DEFINE_PRIM(_VOID, keyboard_show, _NO_ARG)
DEFINE_PRIM(_VOID, keyboard_hide, _NO_ARG)
DEFINE_PRIM(_BOOL, keyboard_active, _NO_ARG)

vclosure* key_down_cb = NULL;
vclosure* key_up_cb = NULL;
vclosure* key_press_cb = NULL;

void internal_key_down_cb(int key) {
    if (key_down_cb != NULL) {
        vdynamic args[3];
        vdynamic* vargs[3] = { &args[0] };
        vargs[0]->t = &hlt_i32;
        vargs[0]->v.i = key;

        bool isExc = false;
        vdynamic* exc = hl_dyn_call_safe(key_down_cb, vargs, 1, &isExc);
        if (isExc) {
            kinc_log(KINC_LOG_LEVEL_ERROR, "Exception occured in key down callback.");
            print_exception_stack(exc);
            kinc_stop();
        }
    }
}

void internal_key_up_cb(int key) {
    if (key_up_cb != NULL) {
        vdynamic args[3];
        vdynamic* vargs[3] = { &args[0] };
        vargs[0]->t = &hlt_i32;
        vargs[0]->v.i = key;

        bool isExc = false;
        vdynamic* exc = hl_dyn_call_safe(key_up_cb, vargs, 1, &isExc);
        if (isExc) {
            kinc_log(KINC_LOG_LEVEL_ERROR, "Exception occured in key up callback.");
            print_exception_stack(exc);
            kinc_stop();
        }
    }
}

void internal_key_press_cb(unsigned c) {
    if (key_up_cb != NULL) {
        vdynamic args[3];
        vdynamic* vargs[3] = { &args[0] };
        vargs[0]->t = &hlt_i32;
        vargs[0]->v.i = c;

        bool isExc = false;
        vdynamic* exc = hl_dyn_call_safe(key_press_cb, vargs, 1, &isExc);
        if (isExc) {
            kinc_log(KINC_LOG_LEVEL_ERROR, "Exception occured in key press callback.");
            print_exception_stack(exc);
            kinc_stop();
        }
    }
}

HL_PRIM void HL_NAME(keyboard_set_key_down_callback)(vclosure* cb) {
    if (key_down_cb != NULL) {
        hl_remove_root(key_down_cb);
    }
    key_down_cb = cb;
    hl_add_root(key_down_cb);
    kinc_keyboard_key_down_callback = internal_key_down_cb;
}

HL_PRIM void HL_NAME(keyboard_set_key_up_callback)(vclosure* cb) {
    if (key_up_cb != NULL) {
        hl_remove_root(key_up_cb);
    }
    key_up_cb = cb;
    hl_add_root(key_up_cb);
    kinc_keyboard_key_up_callback = internal_key_up_cb;
}

HL_PRIM void HL_NAME(keyboard_set_key_press_callback)(vclosure* cb) {
    if (key_press_cb != NULL) {
        hl_remove_root(key_press_cb);
    }
    key_press_cb = cb;
    hl_add_root(key_press_cb);
    kinc_keyboard_key_press_callback = internal_key_press_cb;
}

DEFINE_PRIM(_VOID, keyboard_set_key_down_callback, _FUN(_VOID, _I32))
DEFINE_PRIM(_VOID, keyboard_set_key_up_callback, _FUN(_VOID, _I32))
DEFINE_PRIM(_VOID, keyboard_set_key_press_callback, _FUN(_VOID, _I32))