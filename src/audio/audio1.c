#include "kinchl.h"
#include <kinc/audio1/audio.h>

HL_PRIM kinc_a1_sound_t *HL_NAME(hl_a1_sound_create)(vstring *filename){return kinc_a1_sound_create(hl_to_utf8(filename->bytes));}
DEFINE_PRIM(_ABSTRACT(kinc_a1_sound_t),hl_a1_sound_create,_STRING)
DEFINE_PRIM(_ABSTRACT(kinc_a1_channel_t),a1_play_sound,_ABSTRACT(kinc_a1_sound_t) _BOOL _F32 _BOOL)
DEFINE_PRIM(_VOID,a1_init,_NO_ARG)
DEFINE_PRIM(_F32,a1_sound_volume,_ABSTRACT(kinc_a1_sound_t))
DEFINE_PRIM(_VOID,a1_sound_set_volume,_ABSTRACT(kinc_a1_sound_t) _F32)