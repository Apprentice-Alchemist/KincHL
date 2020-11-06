#include "kinchl.h"
#include <kinc/system.h>



#define MAKE_CALLBACK(name,expr,hl_type)\
  static vclosure* ##name##_cb = NULL;\
  static expr\
  HL_PRIM void HL_NAME(hl_set_##name##_callback)(vclosure *cb){\
    if(##name##_cb != NULL){\
      hl_remove_root(##name##_cb);\
    }\
    ##name##_cb = cb;\
    if(cb != NULL){\
      hl_add_root(##name##_cb);\
      kinc_set_##name##_callback(internal_##name##_callback);\
    }\
  }\
  DEFINE_PRIM(_VOID,hl_set_##name##_callback,hl_type)
// static vclosure* update_cb = NULL;
// static vclosure* foreground_cb = NULL;
// static vclosure* resume_cb = NULL;
// static vclosure* pause_cb = NULL;
// static vclosure* background_cb = NULL;
// static vclosure* shutdown_cb = NULL;
// static vclosure* drop_file_cb = NULL;
// static vclosure* cut_cb = NULL;
// static vclosure* copy_cb = NULL;
// static vclosure* paste_cb = NULL;
// static vclosure* login_cb = NULL;
// static vclosure* logout_cb = NULL;

MAKE_CALLBACK(update,void internal_update_callback() {
    hl_dyn_call(update_cb, NULL, 0);
},_FUN(_VOID,_NO_ARG))

MAKE_CALLBACK(foreground,void internal_foreground_callback(){
  hl_dyn_call(foreground_cb,NULL,0);
},_FUN(_VOID,_NO_ARG))

MAKE_CALLBACK(resume, void internal_resume_callback() {
  hl_dyn_call(resume_cb, NULL, 0);
}, _FUN(_VOID, _NO_ARG))

MAKE_CALLBACK(pause, void internal_pause_callback() {
  hl_dyn_call(pause_cb, NULL, 0);
}, _FUN(_VOID, _NO_ARG))

MAKE_CALLBACK(background, void internal_background_callback() {
  hl_dyn_call(background_cb, NULL, 0);
}, _FUN(_VOID, _NO_ARG))

MAKE_CALLBACK(shutdown, void internal_shutdown_callback() {
  hl_dyn_call(shutdown_cb, NULL, 0);
}, _FUN(_VOID, _NO_ARG))

MAKE_CALLBACK(drop_files, void internal_drop_files_callback(wchar_t* s) {
  hl_call1(void,drop_files_cb,vstring*,hl_alloc_strbytes(s));
},_FUN(_VOID,_STRING))

MAKE_CALLBACK(cut, char* internal_cut_callback() {
  return hl_to_utf8(hl_call0(vstring*, cut_cb)->bytes);
}, _FUN(_STRING, _NO_ARG))

MAKE_CALLBACK(copy, char* internal_copy_callback() {
  return hl_to_utf8(hl_call0(vstring*, copy_cb)->bytes);
}, _FUN(_STRING, _NO_ARG))

MAKE_CALLBACK(paste, void internal_paste_callback(char* s) {
  hl_call1(void, paste_cb,vstring*,hl_alloc_strbytes(hl_to_utf8(s)));
}, _FUN(_VOID, _STRING))

MAKE_CALLBACK(login, void internal_login_callback() {
  hl_call0(void, login_cb);
}, _FUN(_VOID, _NO_ARG))

MAKE_CALLBACK(logout, void internal_logout_callback() {
  hl_call0(void, logout_cb);
}, _FUN(_VOID, _NO_ARG))