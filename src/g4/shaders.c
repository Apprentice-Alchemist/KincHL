#include "graphics4.h"
#include <kinc/io/filereader.h>

HL_PRIM void HL_NAME(hl_g4_shader_init_from_source)(hl_g4_shader *s, vbyte *source, int type) {
    kinc_g4_shader_init_from_source(&s->t, (char *)source, (kinc_g4_shader_type_t)type);
}
HL_PRIM void HL_NAME(hl_g4_shader_init)(hl_g4_shader *s, vbyte *source, int length, int type) {
    kinc_g4_shader_init(&s->t, (void *)source, length, (kinc_g4_shader_type_t)type);
}
HL_PRIM void HL_NAME(hl_g4_shader_init_from_file)(hl_g4_shader *s, vstring *file, int type) {
    kinc_file_reader_t reader;
    char *name = hl_to_utf8(file->bytes);
    kinc_file_reader_open(&reader, name, KINC_FILE_TYPE_ASSET);
    int size = (int)kinc_file_reader_size(&reader);
    void *buf = hl_gc_alloc_noptr(size);
    kinc_file_reader_read(&reader, buf, size);
    kinc_file_reader_close(&reader);
    kinc_g4_shader_init(&s->t, buf, size, type);
}

DEFINE_PRIM(_VOID, hl_g4_shader_init_from_source, _SHADER _BYTES _I32)
DEFINE_PRIM(_VOID, hl_g4_shader_init, _SHADER _BYTES _I32 _I32)
DEFINE_PRIM(_VOID, hl_g4_shader_init_from_file, _SHADER _STRING _I32)
