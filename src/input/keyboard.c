#include "kinchl.h"
#include <kinc/input/keyboard.h>
#include <kinc/input/pen.h>
DEFINE_PRIM(_VOID,keyboard_show,_NO_ARG)
DEFINE_PRIM(_VOID,keyboard_hide,_NO_ARG)
DEFINE_PRIM(_BOOL,keyboard_active,_NO_ARG)

vclosure *key_down_cb = NULL;
vclosure *key_up_cb = NULL;
vclosure *key_press_cb = NULL;

void internal_key_down_cb(int key){
    if(key_down_cb != NULL){
        hl_call1(void,key_down_cb,int,key);
    }
}

void internal_key_up_cb(int key){
    if (key_up_cb != NULL) {
        hl_call1(void, key_up_cb, int, key);
    }
}

void internal_key_press_cb(unsigned c){
    if (key_up_cb != NULL) {
        hl_call1(void, key_press_cb, int, c);
    }
}

HL_PRIM void HL_NAME(keyboard_set_key_down_callback)(vclosure *cb){
    if(key_down_cb != NULL){
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
DEFINE_PRIM(_VOID,keyboard_set_key_down_callback,_FUN(_VOID,_I32))
DEFINE_PRIM(_VOID,keyboard_set_key_up_callback,_FUN(_VOID,_I32))
DEFINE_PRIM(_VOID, keyboard_set_key_press_callback, _FUN(_VOID, _I32))