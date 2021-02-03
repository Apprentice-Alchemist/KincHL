#include "kinchl.h"
#include <kinc/input/keyboard.h>

DEFINE_PRIM(_VOID, keyboard_show, _NO_ARG)
DEFINE_PRIM(_VOID, keyboard_hide, _NO_ARG)
DEFINE_PRIM(_BOOL, keyboard_active, _NO_ARG)

static vclosure* key_down_cb = NULL;
static vclosure* key_up_cb = NULL;
static vclosure* key_press_cb = NULL;

static void internal_key_down_cb(int key) {
    if (key_down_cb != NULL) {
        vdynamic args[3];
        vdynamic* vargs[3] = { &args[0] };
        vargs[0]->t = &hlt_i32;
        vargs[0]->v.i = key;

        bool isExc = false;
        vdynamic* exc = hl_dyn_call_safe(key_down_cb, vargs, 1, &isExc);
        if (isExc) {
            handle_exception("key down callback", exc);
        }
    }
}

static void internal_key_up_cb(int key) {
    if (key_up_cb != NULL) {
        vdynamic args[3];
        vdynamic* vargs[3] = { &args[0] };
        vargs[0]->t = &hlt_i32;
        vargs[0]->v.i = key;

        bool isExc = false;
        vdynamic* exc = hl_dyn_call_safe(key_up_cb, vargs, 1, &isExc);
        if (isExc) {
            handle_exception("key up callback", exc);
        }
    }
}

static void internal_key_press_cb(unsigned c) {
    if (key_up_cb != NULL) {
        vdynamic args[3];
        vdynamic* vargs[3] = { &args[0] };
        vargs[0]->t = &hlt_i32;
        vargs[0]->v.i = c;

        bool isExc = false;
        vdynamic* exc = hl_dyn_call_safe(key_press_cb, vargs, 1, &isExc);
        if (isExc) {
            handle_exception("key press callback", exc);
        }
    }
}

HL_PRIM void HL_NAME(keyboard_set_key_down_callback)(vclosure* cb) {
    if (!key_down_cb) {
        if (!cb) return;
        hl_add_root(&key_down_cb);
    }
    if (key_down_cb && !cb) {
        hl_remove_root(&key_down_cb);
        key_down_cb = NULL;
        kinc_keyboard_key_down_callback = NULL;
        return;
    }
    key_down_cb = cb;
    kinc_keyboard_key_down_callback = internal_key_down_cb;
}

HL_PRIM void HL_NAME(keyboard_set_key_up_callback)(vclosure* cb) {
    if (!key_up_cb) {
        if (!cb) return;
        hl_add_root(&key_up_cb);
    }
    if (key_up_cb && !cb) {
        hl_remove_root(&key_up_cb);
        key_up_cb = NULL;
        kinc_keyboard_key_up_callback = NULL;
        return;
    }
    key_up_cb = cb;
    kinc_keyboard_key_up_callback = internal_key_up_cb;
}

HL_PRIM void HL_NAME(keyboard_set_key_press_callback)(vclosure* cb) {
    if (!key_press_cb) {
        if (!cb) return;
        hl_add_root(&key_press_cb);
    }
    if (key_press_cb && !cb) {
        hl_remove_root(&key_press_cb);
        key_press_cb = NULL;
        kinc_keyboard_key_press_callback = NULL;
        return;
    }
    key_press_cb = cb;
    kinc_keyboard_key_press_callback = internal_key_press_cb;
}

DEFINE_PRIM(_VOID, keyboard_set_key_down_callback, _FUN(_VOID, _I32))
DEFINE_PRIM(_VOID, keyboard_set_key_up_callback, _FUN(_VOID, _I32))
DEFINE_PRIM(_VOID, keyboard_set_key_press_callback, _FUN(_VOID, _I32))