#include "kinchl.h"
#include <kinc/system.h>
#include <kinc/log.h>


#define MAKE_CALLBACK(name,expr,hl_type)\
  static vclosure* name##_cb = NULL;\
  static expr\
  HL_PRIM void HL_NAME(hl_set_ ##name## _callback)(vclosure *cb){\
    if(!name## _cb){\
      if(!cb) return;\
      hl_add_root(&name##_cb);\
    }\
    if(name##_cb && !cb) {\
      hl_remove_root(&name##_cb);\
      name##_cb = NULL;\
      kinc_set_##name##_callback(NULL);\
    }\
    name## _cb = cb;\
    kinc_set_ ##name## _callback(internal_ ##name## _callback);\
  }\
  DEFINE_PRIM(_VOID,hl_set_ ##name## _callback,hl_type)

MAKE_CALLBACK(update, void internal_update_callback() {
  bool isexc = false;
  hl_dyn_call_safe(update_cb, NULL, 0, &isexc);
  if (isexc) {
    kinc_log(KINC_LOG_LEVEL_WARNING, "Exception occured in update callback");
    varray* stack = hl_exception_stack();
    for (int i = 0; i < stack->size; i++) {
      kinc_log(KINC_LOG_LEVEL_INFO, hl_to_utf8(hl_to_string(hl_aptr(stack, vdynamic*)[i])));
      kinc_log(KINC_LOG_LEVEL_INFO, "\n");
    }
    kinc_stop();
  }
}, _FUN(_VOID, _NO_ARG))

MAKE_CALLBACK(foreground, void internal_foreground_callback() {
  bool isexc = false;
  hl_dyn_call_safe(foreground_cb, NULL, 0, &isexc);
  if (isexc) {
    kinc_log(KINC_LOG_LEVEL_WARNING, "Exception occured in foreground callback");
    varray* stack = hl_exception_stack();
    for (int i = 0; i < stack->size; i++) {
      kinc_log(KINC_LOG_LEVEL_INFO, hl_to_utf8(hl_to_string(hl_aptr(stack, vdynamic*)[i])));
      kinc_log(KINC_LOG_LEVEL_INFO, "\n");
    }
  }
}, _FUN(_VOID, _NO_ARG))

MAKE_CALLBACK(resume, void internal_resume_callback() {
  bool isexc = false;
  hl_dyn_call_safe(resume_cb, NULL, 0, &isexc);
  if (isexc) {
    kinc_log(KINC_LOG_LEVEL_WARNING, "Exception occured in resume callback");
    varray* stack = hl_exception_stack();
    for (int i = 0; i < stack->size; i++) {
      kinc_log(KINC_LOG_LEVEL_INFO, hl_to_utf8(hl_to_string(hl_aptr(stack, vdynamic*)[i])));
      kinc_log(KINC_LOG_LEVEL_INFO, "\n");
    }
  }
}, _FUN(_VOID, _NO_ARG))

MAKE_CALLBACK(pause, void internal_pause_callback() {
  bool isexc = false;
  hl_dyn_call_safe(pause_cb, NULL, 0, &isexc);
  if (isexc) {
    kinc_log(KINC_LOG_LEVEL_WARNING, "Exception occured in pause callback");
    varray* stack = hl_exception_stack();
    for (int i = 0; i < stack->size; i++) {
      kinc_log(KINC_LOG_LEVEL_INFO, hl_to_utf8(hl_to_string(hl_aptr(stack, vdynamic*)[i])));
      kinc_log(KINC_LOG_LEVEL_INFO, "\n");
    }
  }
}, _FUN(_VOID, _NO_ARG))

MAKE_CALLBACK(background, void internal_background_callback() {
  bool isexc = false;
  hl_dyn_call_safe(background_cb, NULL, 0, &isexc);
  if (isexc) {
    kinc_log(KINC_LOG_LEVEL_WARNING, "Exception occured in background callback");
    varray* stack = hl_exception_stack();
    for (int i = 0; i < stack->size; i++) {
      kinc_log(KINC_LOG_LEVEL_INFO, hl_to_utf8(hl_to_string(hl_aptr(stack, vdynamic*)[i])));
      kinc_log(KINC_LOG_LEVEL_INFO, "\n");
    }
  }
}, _FUN(_VOID, _NO_ARG))

MAKE_CALLBACK(shutdown, void internal_shutdown_callback() {
  bool isexc = false;
  void * ret = hl_dyn_call_safe(shutdown_cb, NULL, 0, &isexc);
  if (isexc) {
    print_exception_stack((vdynamic*)ret);
  }
}, _FUN(_VOID, _NO_ARG))

MAKE_CALLBACK(drop_files, void internal_drop_files_callback(wchar_t* s) {
  vdynamic* arg1 = hl_alloc_strbytes(s);
  vdynamic* args[1] = { arg1 };
  bool isexc = false;
  hl_dyn_call_safe(drop_files_cb, args, 1, &isexc);
  if (isexc) {
    kinc_log(KINC_LOG_LEVEL_WARNING, "Exception occured in drop files callback");
    varray* stack = hl_exception_stack();
    for (int i = 0; i < stack->size; i++) {
      kinc_log(KINC_LOG_LEVEL_INFO, hl_to_utf8(hl_to_string(hl_aptr(stack, vdynamic*)[i])));
      kinc_log(KINC_LOG_LEVEL_INFO, "\n");
    }
  }
}, _FUN(_VOID, _STRING))

MAKE_CALLBACK(cut, char* internal_cut_callback() {
  bool isexc = false;
  char* ret = hl_to_utf8(((vstring*)hl_dyn_call_safe(cut_cb, NULL, 0, &isexc))->bytes);
  if (isexc) {
    kinc_log(KINC_LOG_LEVEL_WARNING, "Exception occured in cut callback");
    varray* stack = hl_exception_stack();
    for (int i = 0; i < stack->size; i++) {
      kinc_log(KINC_LOG_LEVEL_INFO, hl_to_utf8(hl_to_string(hl_aptr(stack, vdynamic*)[i])));
      kinc_log(KINC_LOG_LEVEL_INFO, "\n");
    }
    return NULL;
  }
  return ret;
}, _FUN(_STRING, _NO_ARG))

MAKE_CALLBACK(copy, char* internal_copy_callback() {
  bool isexc = false;
  char* ret = hl_to_utf8(((vstring*)hl_dyn_call_safe(copy_cb, NULL, 0, &isexc))->bytes);
  if (isexc) {
    kinc_log(KINC_LOG_LEVEL_WARNING, "Exception occured in copy callback");
    varray* stack = hl_exception_stack();
    for (int i = 0; i < stack->size; i++) {
      kinc_log(KINC_LOG_LEVEL_INFO, hl_to_utf8(hl_to_string(hl_aptr(stack, vdynamic*)[i])));
      kinc_log(KINC_LOG_LEVEL_INFO, "\n");
    }
    return NULL;
  }
  return ret;
}, _FUN(_STRING, _NO_ARG))

MAKE_CALLBACK(paste, void internal_paste_callback(char* s) {
  vdynamic* arg1 = hl_alloc_strbytes(hl_to_utf16(s));
  vdynamic* args[1] = { arg1 };
  bool isexc = false;
  hl_dyn_call_safe(paste_cb, args, 1, &isexc);
  if (isexc) {
    kinc_log(KINC_LOG_LEVEL_WARNING, "Exception occured in paste callback");
    varray* stack = hl_exception_stack();
    // hl_dump_stack();
    if (stack != NULL) {
      for (int i = 0; i < stack->size; i++) {
        kinc_log(KINC_LOG_LEVEL_WARNING, hl_to_utf8(hl_aptr(stack, uchar*)[i]));
      }
    }
  }
}, _FUN(_VOID, _STRING))

MAKE_CALLBACK(login, void internal_login_callback() {
  bool isexc = false;
  hl_dyn_call_safe(login_cb, NULL, 0, &isexc);
  if (isexc) {
    kinc_log(KINC_LOG_LEVEL_WARNING, "Exception occured in login callback");
    varray* stack = hl_exception_stack();
    for (int i = 0; i < stack->size; i++) {
      kinc_log(KINC_LOG_LEVEL_INFO, hl_to_utf8(hl_to_string(hl_aptr(stack, vdynamic*)[i])));
      kinc_log(KINC_LOG_LEVEL_INFO, "\n");
    }
  }
}, _FUN(_VOID, _NO_ARG))

MAKE_CALLBACK(logout, void internal_logout_callback() {
  bool isexc = false;
  hl_dyn_call_safe(login_cb, NULL, 0, &isexc);
  if (isexc) {
    kinc_log(KINC_LOG_LEVEL_WARNING, "Exception occured in login callback");
    varray* stack = hl_exception_stack();
    for (int i = 0; i < stack->size; i++) {
      kinc_log(KINC_LOG_LEVEL_INFO, hl_to_utf8(hl_to_string(hl_aptr(stack, vdynamic*)[i])));
      kinc_log(KINC_LOG_LEVEL_INFO, "\n");
    }
  }
}, _FUN(_VOID, _NO_ARG))