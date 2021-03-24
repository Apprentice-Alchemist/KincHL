#include "kinchl.h"
#include <kinc/audio1/audio.h>
#include <kinc/log.h>
// AUDIO 1
// DEFINE_OBJ_EX(a1_channel,kinc_a1_channel_t)
// ALLOC_OBJ_EX(a1_channel,kinc_a1_channel_t,kinc_a1_channel)
MAKE_GET(kinc_a1_channel_t, a1_channel, sound, kinc_a1_sound_t*, _ABSTRACT(kinc_a1_channel_t), _ABSTRACT(kinc_a1_sound_t))
MAKE_GET_SET(kinc_a1_channel_t, a1_channel, position, float, _ABSTRACT(kinc_a1_channel_t), _F32)
MAKE_GET_SET(kinc_a1_channel_t, a1_channel, loop, bool, _ABSTRACT(kinc_a1_channel_t), _BOOL)
MAKE_GET_SET(kinc_a1_channel_t, a1_channel, volume, float, _ABSTRACT(kinc_a1_channel_t), _F32)
MAKE_GET_SET(kinc_a1_channel_t, a1_channel, pitch, float, _ABSTRACT(kinc_a1_channel_t), _F32)
HL_PRIM kinc_a2_buffer_format_t* HL_NAME(hl_a1_sound_get_format)(kinc_a1_sound_t* o) {
    return &(o->format);
}
DEFINE_PRIM(_ABSTRACT(kinc_a2_buffer_format_t), hl_a1_sound_get_format, _ABSTRACT(kinc_a1_sound_t))
MAKE_GET_SET(kinc_a1_sound_t, a1_sound, left, int16_t*, _ABSTRACT(kinc_a1_sound_t), _BYTES)
MAKE_GET_SET(kinc_a1_sound_t, a1_sound, right, int16_t*, _ABSTRACT(kinc_a1_sound_t), _BYTES)
MAKE_GET_SET(kinc_a1_sound_t, a1_sound, size, int, _ABSTRACT(kinc_a1_sound_t), _I32)
MAKE_GET_SET(kinc_a1_sound_t, a1_sound, sample_rate_pos, float, _ABSTRACT(kinc_a1_sound_t), _F32)

HL_PRIM kinc_a1_sound_t* HL_NAME(hl_a1_sound_create)(vstring* filename) { return kinc_a1_sound_create(hl_to_utf8(filename->bytes)); }
HL_PRIM float HL_NAME(hl_a1_sound_get_volume)(kinc_a1_sound_t* s) { return kinc_a1_sound_volume(s); }
HL_PRIM float HL_NAME(hl_a1_sound_set_volume)(kinc_a1_sound_t* s, float value) { kinc_a1_sound_set_volume(s, value); return value; }
HL_PRIM void HL_NAME(hl_a1_sound_destroy)(kinc_a1_sound_t* s) { kinc_a1_sound_destroy(s); }

DEFINE_PRIM(_ABSTRACT(kinc_a1_sound_t), hl_a1_sound_create, _STRING)
DEFINE_PRIM(_F32, hl_a1_sound_get_volume, _ABSTRACT(kinc_a1_sound_t))
DEFINE_PRIM(_F32, hl_a1_sound_set_volume, _ABSTRACT(kinc_a1_sound_t) _F32)
DEFINE_PRIM(_VOID, hl_a1_sound_destroy, _ABSTRACT(kinc_a1_sound_t))
DEFINE_PRIM(_VOID, a1_init, _NO_ARG)
DEFINE_PRIM(_ABSTRACT(kinc_a1_channel_t), a1_play_sound, _ABSTRACT(kinc_a1_sound_t) _BOOL _F32 _BOOL)
DEFINE_PRIM(_VOID, a1_stop_sound, _ABSTRACT(kinc_a1_sound_t))

// AUDIO 2
MAKE_GET_SET(kinc_a2_buffer_format_t, a2_buffer_format, channels, int, _ABSTRACT(kinc_a2_buffer_format_t), _I32)
MAKE_GET_SET(kinc_a2_buffer_format_t, a2_buffer_format, samples_per_second, int, _ABSTRACT(kinc_a2_buffer_format_t), _I32)
MAKE_GET_SET(kinc_a2_buffer_format_t, a2_buffer_format, bits_per_sample, int, _ABSTRACT(kinc_a2_buffer_format_t), _I32)

MAKE_GET_SET(kinc_a2_buffer_t, a2_buffer, data, vbyte*, _ABSTRACT(kinc_a2_buffer_t), _BYTES)
MAKE_GET_SET(kinc_a2_buffer_t, a2_buffer, data_size, int, _ABSTRACT(kinc_a2_buffer_t), _I32)
MAKE_GET_SET(kinc_a2_buffer_t, a2_buffer, read_location, int, _ABSTRACT(kinc_a2_buffer_t), _I32)
MAKE_GET_SET(kinc_a2_buffer_t, a2_buffer, write_location, int, _ABSTRACT(kinc_a2_buffer_t), _I32)
HL_PRIM kinc_a2_buffer_format_t* HL_NAME(hl_a2_buffer_get_format)(kinc_a2_buffer_t* o) {
    return &(o->format);
}
DEFINE_PRIM(_ABSTRACT(kinc_a2_buffer_format_t), hl_a2_buffer_get_format, _ABSTRACT(kinc_a2_buffer_t))

bool audio_thread_registered = false;
vclosure* a2_cb = NULL;

static void internal_a2_callback(kinc_a2_buffer_t* buffer, int samples) {
    // if (!audio_thread_registered) {
    //     vdynamic* ret;
    //     hl_register_thread(&ret);
    //     audio_thread_registered = true;
    // }

    if (a2_cb != NULL) {
        // hl_blocking(true);
        hl_call2(void, a2_cb, kinc_a2_buffer_t*, buffer, int, samples);
        // hl_blocking(false);
    }
}

HL_PRIM void HL_NAME(hl_a2_set_callback)(vclosure* cb) {
    if (!a2_cb) {
        if (!cb) return;
        hl_add_root(&a2_cb);
    }
    if (cb) {
        a2_cb = cb;
        kinc_a2_set_callback(internal_a2_callback);
    }else{
        kinc_a2_set_callback(NULL);
    }
}
HL_PRIM int HL_NAME(a2_get_samples_per_second)() {
    return kinc_a2_samples_per_second;
}
HL_PRIM int HL_NAME(a2_set_samples_per_second)(int v) {
    kinc_a2_samples_per_second = v;
    return v;
}
DEFINE_PRIM(_VOID, a2_update, _NO_ARG)
DEFINE_PRIM(_VOID, a2_init, _NO_ARG)
DEFINE_PRIM(_VOID, a2_shutdown, _NO_ARG)
DEFINE_PRIM(_VOID, hl_a2_set_callback, _FUN(_VOID, _ABSTRACT(kinc_a2_buffer_t) _I32))
DEFINE_PRIM(_I32, a2_get_samples_per_second, _NO_ARG)
DEFINE_PRIM(_I32, a2_set_samples_per_second, _I32)

// HL_PRIM float HL_NAME(sampleLinear)(int16_t* data, float position) {
//     int pos1 = (int)position;
//     int pos2 = (int)(position + 1);
//     float sample1 = data[pos1] / 32767.0f;
//     float sample2 = data[pos2] / 32767.0f;
//     float a = position - pos1;
//     return sample1 * (1 - a) + sample2 * a;
// }

// DEFINE_PRIM(_F32, sampleLinear, _BYTES _F32)

// #define STB_VORBIS_HEADER_ONLY
// #include <kinc/audio1/stb_vorbis.c>

// HL_PRIM vbyte* kinc_sound_init_vorbis(vbyte* data, int length) {
//     return (vbyte*)stb_vorbis_open_memory(data, length, NULL, NULL);
// }

// HL_PRIM bool kinc_sound_next_vorbis_samples(vbyte* vorbis, vbyte* samples, int length, bool loop, bool atend) {
//     int read = stb_vorbis_get_samples_float_interleaved((stb_vorbis*)vorbis, 2, (float*)samples, length);
//     if (read < length / 2) {
//         if (loop) {
//             stb_vorbis_seek_start((stb_vorbis*)vorbis);
//         }
//         else {
//             atend = true;
//         }
//         for (int i = read; i < length; ++i) {
//             samples[i] = 0;
//         }
//     }
//     return atend;
// }

// DEFINE_PRIM(_BYTES, sound_init_vorbis, _BYTES _I32)
// DEFINE_PRIM(_BOOL, sound_next_vorbis_samples, _BYTES _BYTES _I32 _BOOL _BOOL)