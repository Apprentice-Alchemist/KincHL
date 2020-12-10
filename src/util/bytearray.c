// #define HL_NAME(n) kinc_##n
// #include <hl.h>
// #include <stdint.h>

// #define _BYTEARRAY _OBJ(_BYTES _I32)
// typedef struct {
//     hl_type* t;
//     vbyte* bytes;
//     int length;
// } bytearray;

// HL_PRIM int HL_NAME(bytearray_geti16)(bytearray* b, int pos) {
//     if (pos > b->length) {
//         return 0;
//     }
//     return (int)(((int16_t*)(b->bytes))[pos]);
// }

// DEFINE_PRIM(_I32, bytearray_geti16, _BYTEARRAY _I32);