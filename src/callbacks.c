#include "kinchl.h"
#include <kinc/log.h>
#include <kinc/system.h>

#define MAKE_CALLBACK(name, expr, hl_type)                 \
    static vclosure *name##_cb = NULL;                     \
    static expr                                            \
        HL_PRIM void                                       \
        HL_NAME(hl_set_##name##_callback)(vclosure * cb) { \
        name##_cb = cb;                                    \
    }                                                      \
    DEFINE_PRIM(_VOID, hl_set_##name##_callback, hl_type)

MAKE_CALLBACK(
    update, void internal_update_callback(void) {
        if (update_cb == NULL)
            return;
        bool isexc = false;
        vdynamic *ret = hl_dyn_call_safe(update_cb, NULL, 0, &isexc);
        if (isexc) {
            handle_exception("update callback", ret);
        }
    },
    _FUN(_VOID, _NO_ARG))

MAKE_CALLBACK(
    foreground, void internal_foreground_callback(void) {
        if (foreground_cb == NULL)
            return;
        bool isexc = false;
        vdynamic *ret = hl_dyn_call_safe(foreground_cb, NULL, 0, &isexc);
        if (isexc) {
            handle_exception("foreground callback", ret);
        }
    },
    _FUN(_VOID, _NO_ARG))

MAKE_CALLBACK(
    resume, void internal_resume_callback(void) {
        if (resume_cb == NULL)
            return;
        bool isexc = false;
        vdynamic *ret = hl_dyn_call_safe(resume_cb, NULL, 0, &isexc);
        if (isexc) {
            handle_exception("resume callback", ret);
        }
    },
    _FUN(_VOID, _NO_ARG))

MAKE_CALLBACK(
    pause, void internal_pause_callback(void) {
        if (pause_cb == NULL)
            return;
        bool isexc = false;
        vdynamic *ret = hl_dyn_call_safe(pause_cb, NULL, 0, &isexc);
        if (isexc) {
            handle_exception("pause callback", ret);
        }
    },
    _FUN(_VOID, _NO_ARG))

MAKE_CALLBACK(
    background, void internal_background_callback(void) {
        if (background_cb == NULL)
            return;
        bool isexc = false;
        vdynamic *ret = hl_dyn_call_safe(background_cb, NULL, 0, &isexc);
        if (isexc) {
            handle_exception("background callback", ret);
        }
    },
    _FUN(_VOID, _NO_ARG))

MAKE_CALLBACK(
    shutdown, void internal_shutdown_callback(void) {
        if (shutdown_cb == NULL)
            return;
        bool isexc = false;
        vdynamic *ret = hl_dyn_call_safe(shutdown_cb, NULL, 0, &isexc);
        if (isexc) {
            handle_exception("shutdown callback", ret);
        }
    },
    _FUN(_VOID, _NO_ARG))

static char *convert_to_utf8(const wchar_t *s) {
    size_t len = wcstombs(NULL, s, 0) + 1;
    char *dest = hl_gc_alloc_noptr((int)len);
    wcstombs(dest, s, len);
    return dest;
}

MAKE_CALLBACK(
    drop_files, void internal_drop_files_callback(wchar_t *s) {
        if (drop_files_cb == NULL)
            return;
        vdynamic *arg1 = hl_alloc_dynamic(&hlt_bytes);
        arg1->v.ptr = convert_to_utf8(s);
        vdynamic *args[1] = {arg1};
        bool isexc = false;
        vdynamic *ret = hl_dyn_call_safe(drop_files_cb, args, 1, &isexc);
        if (isexc) {
            handle_exception("drop files callback", ret);
        }
    },
    _FUN(_VOID, _BYTES))

MAKE_CALLBACK(
    cut, char *internal_cut_callback(void) {
        if (cut_cb == NULL)
            return NULL;
        bool isexc = false;
        vdynamic *ret = hl_dyn_call_safe(cut_cb, NULL, 0, &isexc);
        if (isexc) {
            handle_exception("cut callback", ret);
            return NULL;
        }
        return hl_to_utf8(((vstring *)ret)->bytes);
    },
    _FUN(_STRING, _NO_ARG))

MAKE_CALLBACK(
    copy, char *internal_copy_callback(void) {
        if (copy_cb == NULL)
            return NULL;
        bool isexc = false;
        vdynamic *ret = hl_dyn_call_safe(copy_cb, NULL, 0, &isexc);
        if (isexc) {
            handle_exception("copy callback", ret);
            return NULL;
        }
        return hl_to_utf8(((vstring *)ret)->bytes);
    },
    _FUN(_STRING, _NO_ARG))

MAKE_CALLBACK(
    paste, void internal_paste_callback(char *s) {
        if (paste_cb == NULL)
            return;
        vdynamic *arg1 = hl_alloc_dynamic(&hlt_bytes);
        arg1->v.ptr = (void *)s;
        vdynamic *args[1] = {arg1};
        bool isexc = false;
        vdynamic *ret = hl_dyn_call_safe(paste_cb, args, 1, &isexc);
        if (isexc) {
            handle_exception("paste callback", ret);
        }
    },
    _FUN(_VOID, _BYTES))

MAKE_CALLBACK(
    login, void internal_login_callback(void) {
        if (login_cb == NULL)
            return;
        bool isexc = false;
        vdynamic *ret = hl_dyn_call_safe(login_cb, NULL, 0, &isexc);
        if (isexc) {
            handle_exception("login callback", ret);
        }
    },
    _FUN(_VOID, _NO_ARG))

MAKE_CALLBACK(
    logout, void internal_logout_callback(void) {
        if (logout_cb == NULL)
            return;
        bool isexc = false;
        vdynamic *ret = hl_dyn_call_safe(login_cb, NULL, 0, &isexc);
        if (isexc) {
            handle_exception("logout callback", ret);
        }
    },
    _FUN(_VOID, _NO_ARG))
#undef MAKE_CALLBACK

void hl_callbacks_init() {
#define _INIT(name)          \
    hl_add_root(&name##_cb); \
    kinc_set_##name##_callback(internal_##name##_callback);
    _INIT(update);
    _INIT(foreground);
    _INIT(resume);
    _INIT(pause);
    _INIT(background);
    _INIT(shutdown);
    _INIT(drop_files);
    _INIT(cut)
    _INIT(copy)
    _INIT(paste)
    _INIT(login)
    _INIT(logout)
#undef _INIT
}