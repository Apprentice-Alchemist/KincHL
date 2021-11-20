#ifdef INCLUDE_KRAFIX
#include "kinchl.h"

extern void krafix_compile(const char *source, char *output, int *length, const char *targetlang, const char *system, const char *shadertype);

HL_PRIM void HL_NAME(krafix_compile)(vbyte *source, vbyte *output, int *length, vbyte *targetlang, vbyte *system, vbyte *shadertype) {
    krafix_compile((const char *)source, (char *)output, length, (const char *)targetlang, (const char *)system, (const char *)shadertype);
}

DEFINE_PRIM(_VOID, krafix_compile, _BYTES _BYTES _REF(_I32) _BYTES _BYTES _BYTES)
#endif