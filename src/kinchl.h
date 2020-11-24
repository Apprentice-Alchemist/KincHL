#ifndef HL_NAME
#define HL_NAME(n) kinc_##n
#include <kinc/pch.h>
#undef min
#undef max
#include <hl.h>

typedef struct {
  void *finalizer;
  void *ptr;
} cffi_ptr;

void EMPTY_INIT(void* obj);
void EMPTY_DESTROY(void* obj);

#define ALLOC_OBJ(type,name, hl_type,init,destroy)\
  HL_PRIM type *HL_NAME( name## _hl_alloc)(){\
    type * o = (type*)hl_gc_alloc_raw(sizeof(type));\
    return o;\
  }\
  HL_PRIM void HL_NAME( name## _hl_init)(type * o){\
    init(o);\
  }\
  HL_PRIM void HL_NAME( name## _hl_destroy)(type * o){\
    destroy(o);\
  }\
  DEFINE_PRIM(hl_type, name## _hl_alloc,_NO_ARG)\
  DEFINE_PRIM(_VOID, name## _hl_init,hl_type)\
  DEFINE_PRIM(_VOID, name## _hl_destroy,hl_type)

#define MAKE_GET_SET(obj_type, name,field_name, type, hl_obj, hl_ret)                        \
  HL_PRIM type HL_NAME(name##_hl_get_##field_name)(obj_type * o) {           \
    return o-> field_name;                                                         \
  }                                                                           \
  HL_PRIM type HL_NAME(name##_hl_set_##field_name)(obj_type * o,type v) { \
    return o-> field_name = v;                                                     \
  }                                                                           \
  DEFINE_PRIM(hl_ret, name##_hl_get_##field_name, hl_obj)                       \
  DEFINE_PRIM(hl_ret, name##_hl_set_##field_name, hl_obj hl_ret)

#define MAKE_GET(obj_type,name,field_name,type,hl_obj,hl_ret)\
HL_PRIM type HL_NAME(name##_hl_get_##field_name)(obj_type * o) {\
    return o-> field_name;\
  }\
  DEFINE_PRIM(hl_ret, name##_hl_get_##field_name, hl_obj)

#define MAKE_OBJ_ARRAY(obj,name,hl_obj) \
  HL_PRIM obj* HL_NAME(hl_##name##_array_alloc)(int length){\
    obj * ret = (obj*)hl_gc_alloc_raw(sizeof(obj) * length);\
    for(int i = 0; i < length; i++){\
      ret[i] = NULL;\
    }\
    ret[length] = NULL;\
    return ret;\
  }\
  HL_PRIM obj HL_NAME(hl_##name##_array_get)(obj*o,int i){\
    return o[i];\
  }\
  HL_PRIM obj HL_NAME(hl_##name##_array_set)(obj*o,int i,obj v){\
    return o[i] = v;\
  }\
  DEFINE_PRIM(_REF(hl_obj),hl_##name##_array_alloc,_I32)\
  DEFINE_PRIM(hl_obj,hl_##name##_array_get,_REF(hl_obj) _I32)\
  DEFINE_PRIM(hl_obj,hl_##name##_array_set,_REF(hl_obj) _I32 hl_obj)
#endif