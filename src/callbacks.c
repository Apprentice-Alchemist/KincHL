#include "kinchl.h"
#include <kinc/system.h>

vclosure* update_cb = NULL;
vclosure* background_cb = NULL;
vclosure* cut_cb = NULL;
vclosure* drop_file_cb = NULL;
vclosure* paste_cb = NULL;

void internal_update_callback() {
  if (update_cb != NULL) {
    hl_dyn_call(update_cb, NULL, 0);
  }
}

void internal_background_callback() {
  if (background_cb != NULL) {
    hl_dyn_call(background_cb, NULL, 0);
  }
}

char* internal_cut_callback() {
  if (cut_cb != NULL) {
    vstring* (*fun)() = cut_cb->hasValue ? cut_cb->value : cut_cb->fun;
    return hl_to_utf8(fun()->bytes);
  }
  else {
    return NULL;
  }
}

void internal_drop_files_callback(wchar_t* s) {
  if (drop_file_cb != NULL) {
    void (*fun)(vbyte*) = drop_file_cb->hasValue ? drop_file_cb->value : drop_file_cb->fun;
    vstring* str = hl_alloc_strbytes(s);
    fun(str);
  }
}

void internal_paste_callback(char* s) {
  if (paste_cb != NULL) {
    void (*fun)(vbyte*) = paste_cb->hasValue ? paste_cb->value : paste_cb->fun;
    vstring* str = hl_alloc_strbytes(hl_to_utf16(s));
    fun(str);
  }
}

HL_PRIM void HL_NAME(hl_set_update_callback)(vclosure* cb) {
  if (update_cb != NULL) {
    hl_remove_root(update_cb);
  }
  hl_add_root(cb);
  update_cb = cb;
  kinc_set_update_callback(internal_update_callback);
}

HL_PRIM void HL_NAME(hl_set_background_callback)(vclosure* cb) {
  if (background_cb != NULL) {
    hl_remove_root(background_cb);
  }
  hl_add_root(cb);
  background_cb = cb;
  kinc_set_background_callback(internal_background_callback);
}

HL_PRIM void HL_NAME(hl_set_cut_callback)(vclosure* cb) {
  if (cut_cb != NULL) {
    hl_remove_root(cut_cb);
  }
  hl_add_root(cb);
  cut_cb = cb;
  kinc_set_cut_callback(internal_cut_callback);
}

HL_PRIM void HL_NAME(hl_set_paste_callback)(vclosure* cb) {
  if (paste_cb != NULL) {
    hl_remove_root(paste_cb);
  }
  hl_add_root(cb);
  paste_cb = cb;
  kinc_set_paste_callback(internal_paste_callback);
}

HL_PRIM void HL_NAME(hl_set_drop_file_callback)(vclosure* cb) {
  if (drop_file_cb != NULL) {
    hl_remove_root(drop_file_cb);
  }
  hl_add_root(cb);
  drop_file_cb = cb;
  kinc_set_drop_files_callback(internal_drop_files_callback);
}

DEFINE_PRIM(_VOID, hl_set_update_callback, _FUN(_VOID, _NO_ARG))
DEFINE_PRIM(_VOID, hl_set_background_callback, _FUN(_VOID, _NO_ARG))
DEFINE_PRIM(_VOID, hl_set_cut_callback, _FUN(_STRING, _NO_ARG))
DEFINE_PRIM(_VOID, hl_set_paste_callback, _FUN(_VOID, _STRING))
DEFINE_PRIM(_VOID, hl_set_drop_file_callback, _FUN(_VOID, _STRING))