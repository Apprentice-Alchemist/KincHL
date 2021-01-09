#ifndef HL_NAME
#define HL_NAME(n) kinc_##n
#include <kinc/pch.h>
#undef min
#undef max
#include <hl.h>
#include <kinc/log.h>
void EMPTY_INIT(void* obj);
void EMPTY_DESTROY(void* obj);
void print_exception_stack(vdynamic *exc);


#define DEFINE_OBJ_EX(name,type_name)\
  typedef struct {\
    void (*finalizer)(type_name*);\
    type_name t;\
  } hl_##name;

#define ALLOC_OBJ_EX(name,type_name,init_func,destroy_func)\
  HL_PRIM void HL_NAME(hl_##name##_destroy)(hl_##name* obj){\
    destroy_func(&obj->t);\
  }\
  HL_PRIM hl_##name*HL_NAME(hl_##name##_alloc)(){\
    hl_##name * o = (hl_##name*)hl_gc_alloc_finalizer(sizeof(hl_##name));\
    o->finalizer = (void (*)(type_name*))kinc_hl_##name##_destroy;\
    memset(&o->t,0,sizeof(type_name));\
    init_func(&o->t);\
    return o;\
  }\
  DEFINE_PRIM(_ABSTRACT(name),hl_##name##_alloc, _NO_ARG)\
  DEFINE_PRIM(_VOID,hl_##name##_destroy, _ABSTRACT(name))

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

#define MAKE_GET_SET_EX(name,field_name, type, hl_ret)                        \
  HL_PRIM type HL_NAME(hl_##name##_get_##field_name)(hl_##name * o) {           \
    return o->t.field_name;                                                         \
  }                                                                           \
  HL_PRIM type HL_NAME(hl_##name##_set_##field_name)(hl_##name * o,type v) { \
    return o->t.field_name = v;                                                     \
  }                                                                           \
  DEFINE_PRIM(hl_ret, hl_##name##_get_##field_name, _ABSTRACT(name))                       \
  DEFINE_PRIM(hl_ret, hl_##name##_set_##field_name, _ABSTRACT(name) hl_ret)
#define MAKE_GET_EX(name, field_name,type,hl_ret)\
  HL_PRIM type HL_NAME(hl_##name##_get_##field_name)(hl_##name *o){\
    return o->t.field_name;\
  }\
  DEFINE_PRIM(hl_ret,hl_##name##_get_##field_name,hl_ret)

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