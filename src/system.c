#include "kinchl.h"
#include "window.h"
#include <kinc/error.h>
#include <kinc/log.h>
#include <kinc/system.h>
#include <kinc/window.h>
#include <kinc/vr/vrinterface.h>
HL_PRIM int HL_NAME(hl_init)(vstring* title, int w, int h, win_opts_hl* win, fb_opts_hl* fb) {
  return kinc_init(hl_to_utf8(title->bytes), w, h, convert_win_opts_hl(win), convert_fb_opts_hl(fb));
}
HL_PRIM void HL_NAME(hl_start)() { kinc_start(); }
HL_PRIM void HL_NAME(hl_stop)() { kinc_stop(); }
HL_PRIM void HL_NAME(hl_log)(int level, vstring* msg) { kinc_log(level, hl_to_utf8(msg->bytes)); }

HL_PRIM vstring* HL_NAME(hl_application_name)() { return hl_alloc_strbytes(kinc_application_name()); }
HL_PRIM void HL_NAME(hl_set_application_name)(vstring* name) { kinc_set_application_name(hl_to_utf8(name->bytes)); }
HL_PRIM int HL_NAME(hl_width)() { return kinc_width(); }
HL_PRIM int HL_NAME(hl_height)() { return kinc_height(); }
// Not sure wether this is mean to be exposed
// HL_PRIM bool HL_NAME(hl_internal_handle_messages)(void);
HL_PRIM void HL_NAME(hl_load_url)(vstring* url) { kinc_load_url(hl_to_utf8(url->bytes)); }
HL_PRIM vstring* HL_NAME(hl_system_id)() { return hl_alloc_strbytes(hl_to_utf16(kinc_system_id())); }
// Not sure wether this is mean to be exposed
// HL_PRIM vstring* HL_NAME(hl_internal_save_path)() { return hl_alloc_strbytes(hl_to_utf16(kinc_internal_save_path())); }

HL_PRIM const char** HL_NAME(hl_video_formats)() {
  const char** formats = kinc_video_formats();
  int format_count = 0;
  for (; formats[format_count] != NULL; format_count++) {}
  varray* ret = hl_alloc_array(&hlt_dyn, format_count);
  for (int x = 0; x < format_count; x++) {
    hl_aptr(ret, vstring*)[x] = hl_alloc_strbytes(hl_to_utf16(formats[x]));
  }
  return ret;
}
HL_PRIM vstring* HL_NAME(hl_language)() { return hl_alloc_strbytes(hl_to_utf16(kinc_language())); }
HL_PRIM void HL_NAME(hl_vibrate)(int milliseconds) { kinc_vibrate(milliseconds); }
HL_PRIM float HL_NAME(hl_safe_zone)() { return kinc_safe_zone(); }
HL_PRIM bool HL_NAME(hl_automatic_safe_zone)() { return kinc_automatic_safe_zone(); }
HL_PRIM void HL_NAME(hl_set_safe_zone)(float value) { kinc_set_safe_zone(value); }
HL_PRIM double HL_NAME(hl_frequency)() { return kinc_frequency(); }
HL_PRIM kinc_ticks_t HL_NAME(hl_timestamp)() { return kinc_timestamp(); }
HL_PRIM double HL_NAME(hl_time)() { return kinc_time(); }
HL_PRIM void HL_NAME(hl_login)(){ kinc_login();}
HL_PRIM bool HL_NAME(hl_waiting_for_login)(){return kinc_waiting_for_login();}
HL_PRIM void HL_NAME(hl_unlock_achievement)(int id){kinc_unlock_achievement(id);}
HL_PRIM void HL_NAME(hl_disallow_user_change)(){kinc_disallow_user_change();}
HL_PRIM void HL_NAME(hl_allow_user_change)(){kinc_allow_user_change();}
HL_PRIM void HL_NAME(hl_set_keep_screen_on)(bool on){kinc_set_keep_screen_on(on);}

DEFINE_PRIM(_VOID, hl_start, _NO_ARG)
DEFINE_PRIM(_I32, hl_init, _STRING _I32 _I32 HL_WINDOW_OPTS HL_FRAMEBUFFER_OPTS)
DEFINE_PRIM(_VOID, hl_stop, _NO_ARG)
DEFINE_PRIM(_VOID, hl_log, _I32 _STRING)
DEFINE_PRIM(_STRING, hl_application_name, _NO_ARG)
DEFINE_PRIM(_VOID, hl_set_application_name, _STRING)
DEFINE_PRIM(_I32, hl_width, _NO_ARG)
DEFINE_PRIM(_I32, hl_height, _NO_ARG)
DEFINE_PRIM(_VOID, hl_load_url, _STRING)
DEFINE_PRIM(_STRING, hl_system_id, _NO_ARG)
DEFINE_PRIM(_ARR, hl_video_formats, _NO_ARG)
DEFINE_PRIM(_STRING, hl_language, _NO_ARG)
DEFINE_PRIM(_VOID, hl_vibrate, _I32)
DEFINE_PRIM(_F32, hl_safe_zone, _NO_ARG)
DEFINE_PRIM(_BOOL, hl_automatic_safe_zone, _NO_ARG)
DEFINE_PRIM(_VOID, hl_set_safe_zone, _F32)
DEFINE_PRIM(_F64, hl_frequency, _NO_ARG)
DEFINE_PRIM(_I64, hl_timestamp, _NO_ARG)
DEFINE_PRIM(_F64, hl_time, _NO_ARG)

DEFINE_PRIM(_VOID, hl_login, _NO_ARG)
DEFINE_PRIM(_BOOL, hl_waiting_for_login, _NO_ARG)
DEFINE_PRIM(_VOID, hl_unlock_achievement, _I32)
DEFINE_PRIM(_VOID, hl_disallow_user_change, _NO_ARG)
DEFINE_PRIM(_VOID, hl_allow_user_change, _NO_ARG)
DEFINE_PRIM(_VOID, hl_set_keep_screen_on, _BOOL)

void EMPTY_INIT(void* o) {}
void EMPTY_DESTROY(void* o) {}
MAKE_OBJ_ARRAY(float, single, _F32)
MAKE_OBJ_ARRAY(int, int, _I32)
MAKE_OBJ_ARRAY(bool, bool, _BOOL)
MAKE_OBJ_ARRAY(int, rtf, _I32)