#include <kinc/io/filereader.h>
#include <kinc/io/filewriter.h>
#include <kinchl.h>

#define _READER _ABSTRACT(file_reader)
#define _WRITER _ABSTRACT(file_writer)

DEFINE_OBJ_EX(file_reader, kinc_file_reader_t)
ALLOC_OBJ_EX(file_reader, kinc_file_reader_t, EMPTY_INIT, kinc_file_reader_close)

DEFINE_OBJ_EX(file_writer, kinc_file_writer_t)
ALLOC_OBJ_EX(file_writer, kinc_file_writer_t, EMPTY_INIT, kinc_file_writer_close)

HL_PRIM bool HL_NAME(hl_file_reader_open)(hl_file_reader *reader, const char *filename, int type) {
    return kinc_file_reader_open(&reader->t, filename, type);
}
HL_PRIM void HL_NAME(hl_file_reader_close)(hl_file_reader *reader) {
    kinc_file_reader_close(&reader->t);
}
HL_PRIM int HL_NAME(hl_file_reader_read)(hl_file_reader *reader, void *data, int size) {
    return kinc_file_reader_read(&reader->t, data, size);
}
HL_PRIM int HL_NAME(hl_file_reader_size)(hl_file_reader *reader) {
    return (int)kinc_file_reader_size(&reader->t);
}
HL_PRIM int HL_NAME(hl_file_reader_pos)(hl_file_reader *reader) {
    return kinc_file_reader_pos(&reader->t);
}
HL_PRIM void HL_NAME(hl_file_reader_seek)(hl_file_reader *reader, int pos) {
    kinc_file_reader_seek(&reader->t, pos);
}

HL_PRIM bool HL_NAME(hl_file_writer_open)(hl_file_writer *writer, const char *filepath) {
    return kinc_file_writer_open(&writer->t, filepath);
}
HL_PRIM void HL_NAME(hl_file_writer_write)(hl_file_writer *writer, void *data, int size) {
    kinc_file_writer_write(&writer->t, data, size);
}
HL_PRIM void HL_NAME(hl_file_writer_close)(hl_file_writer *writer) {
    kinc_file_writer_close(&writer->t);
}

DEFINE_PRIM(_BOOL, hl_file_reader_open, _READER _BYTES _I32)
DEFINE_PRIM(_VOID, hl_file_reader_close, _READER)
DEFINE_PRIM(_I32, hl_file_reader_read, _READER _BYTES _I32)
DEFINE_PRIM(_I32, hl_file_reader_size, _READER)
DEFINE_PRIM(_I32, hl_file_reader_pos, _READER _NO_ARG)
DEFINE_PRIM(_VOID, hl_file_reader_seek, _READER _I32)

DEFINE_PRIM(_BOOL, hl_file_writer_open, _WRITER _BYTES)
DEFINE_PRIM(_VOID, hl_file_writer_write, _WRITER _BYTES _I32)
DEFINE_PRIM(_VOID, hl_file_writer_close, _WRITER)