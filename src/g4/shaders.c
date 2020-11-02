#include "graphics4.h"
#include <kinc/io/filereader.h>

ALLOC_OBJ(kinc_g4_shader_t, shader,_ABSTRACT(kinc_g4_shader_t), EMPTY_INIT,kinc_g4_shader_destroy)

HL_PRIM void HL_NAME(hl_g4_shader_init_from_source)(kinc_g4_shader_t* s, vbyte* source, int type) {
    kinc_g4_shader_init_from_source(s, (char*)source, (kinc_g4_shader_type_t)type);
}
HL_PRIM void HL_NAME(hl_g4_shader_init)(kinc_g4_shader_t* s, vbyte* source, int length, int type) {
    kinc_g4_shader_init(s, (void*)source, length, (kinc_g4_shader_type_t)type);
}
HL_PRIM void HL_NAME(hl_g4_shader_init_from_file)(kinc_g4_shader_t* s, vstring* file, int type) {
    kinc_file_reader_t reader;
    char* name = hl_to_utf8(file->bytes);
    kinc_file_reader_open(&reader, name, KINC_FILE_TYPE_ASSET);
    size_t size = kinc_file_reader_size(&reader);
    void* buf = hl_gc_alloc_noptr(size);
    kinc_file_reader_read(&reader, buf, size);
    kinc_file_reader_close(&reader);
    kinc_g4_shader_init(s, buf, size, type);
}

DEFINE_PRIM(_VOID, hl_g4_shader_init_from_source, _ABSTRACT(kinc_g4_shader_t) _BYTES _I32)
DEFINE_PRIM(_VOID, hl_g4_shader_init, _ABSTRACT(kinc_g4_shader_t) _BYTES _I32 _I32)
DEFINE_PRIM(_VOID, hl_g4_shader_init_from_file, _ABSTRACT(kinc_g4_shader_t) _STRING _I32)
