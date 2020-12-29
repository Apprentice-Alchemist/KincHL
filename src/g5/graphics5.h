#ifndef _GRAPHICS5_H_
#define _GRAPHICS5_H_
#include "kinchl.h"
#include <kinc/graphics5/commandlist.h>
#include <kinc/graphics5/constantbuffer.h>
#include <kinc/graphics5/constantlocation.h>
#include <kinc/graphics5/graphics.h>
#include <kinc/graphics5/indexbuffer.h>
#include <kinc/graphics5/pipeline.h>
#include <kinc/graphics5/raytrace.h>
#include <kinc/graphics5/rendertarget.h>
#include <kinc/graphics5/shader.h>
#include <kinc/graphics5/texture.h>
#include <kinc/graphics5/textureunit.h>
#include <kinc/graphics5/vertexbuffer.h>
#include <kinc/graphics5/vertexstructure.h>

DEFINE_OBJ_EX(g5_command_list,kinc_g5_command_list_t)
DEFINE_OBJ_EX(g5_constant_buffer,kinc_g5_constant_buffer_t)
DEFINE_OBJ_EX(g5_index_buffer,kinc_g5_index_buffer_t)
DEFINE_OBJ_EX(g5_pipeline,kinc_g5_pipeline_t)
#ifdef KORE_RAYTRACE
DEFINE_OBJ_EX(g5_raytrace_pipeline,kinc_g5_raytrace_pipeline_t)
DEFINE_OBJ_EX(g5_acceleration_structure,kinc_g5_acceleration_structure_t)
#endif
DEFINE_OBJ_EX(g5_render_target,kinc_g5_render_target_t)
DEFINE_OBJ_EX(g5_shader,kinc_g5_shader_t)
DEFINE_OBJ_EX(g5_texture,kinc_g5_texture_t)
DEFINE_OBJ_EX(g5_vertex_buffer,kinc_g5_vertex_buffer_t)
DEFINE_OBJ_EX(g5_vertex_structure,kinc_g5_vertex_structure_t)
#endif