#include "kinchl.h"
#include <kinc/graphics5/commandlist.h>
// #include <kinc/graphics5/compute.h>
#include <kinc/graphics5/constantbuffer.h>
#include <kinc/graphics5/constantlocation.h>
#include <kinc/graphics5/graphics.h>
#include <kinc/graphics5/indexbuffer.h>
#include <kinc/graphics5/pipeline.h>
#include <kinc/graphics5/rendertarget.h>
#include <kinc/graphics5/shader.h>
#include <kinc/graphics5/texture.h>
#include <kinc/graphics5/textureunit.h>
#include <kinc/graphics5/vertexbuffer.h>

DEFINE_OBJ_EX(g5_command_list, kinc_g5_command_list_t)
DEFINE_OBJ_EX(g5_constant_buffer, kinc_g5_constant_buffer_t)
DEFINE_OBJ_EX(g5_constant_location, kinc_g5_constant_location_t)
DEFINE_OBJ_EX(g5_shader, kinc_g5_shader_t)
DEFINE_OBJ_EX(g5_texture, kinc_g5_texture_t)
DEFINE_OBJ_EX(g5_vertex_buffer, kinc_g5_vertex_buffer_t)
DEFINE_OBJ_EX(g5_index_buffer, kinc_g5_index_buffer_t)
DEFINE_OBJ_EX(g5_pipeline, kinc_g5_pipeline_t)
DEFINE_OBJ_EX(g5_render_target, kinc_g5_render_target_t)
DEFINE_OBJ_EX(g5_texture_unit, kinc_g5_texture_unit_t)

#define _COMMAND_LIST _ABSTRACT(g5_command_list)
#define _CONSTANT_BUFFER _ABSTRACT(g5_constant_buffer)
#define _PIPELINE _ABSTRACT(g5_pipeline)
#define _RENDER_TARGET _ABSTRACT(g5_render_target)
#define _SHADER _ABSTRACT(g5_shader)
#define _TEXTURE _ABSTRACT(g5_texture)
#define _VERTEX_BUFFER _ABSTRACT(g5_vertex_buffer)
#define _INDEX_BUFFER _ABSTRACT(g5_index_buffer)
#define _LOC _ABSTRACT(g5_constant_location)
#define _TUNIT _ABSTRACT(g5_texture_unit)