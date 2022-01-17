#pragma once

#include "kinchl.h"
#include <kinc/graphics4/graphics.h>
#include <kinc/graphics4/indexbuffer.h>
#include <kinc/graphics4/pipeline.h>
#include <kinc/graphics4/rendertarget.h>
#include <kinc/graphics4/shader.h>
#include <kinc/graphics4/texture.h>
#include <kinc/graphics4/texturearray.h>
#include <kinc/graphics4/vertexbuffer.h>
#include <kinc/graphics4/vertexstructure.h>

DEFINE_OBJ_EX(g4_pipeline, kinc_g4_pipeline_t)
DEFINE_OBJ_EX(g4_render_target, kinc_g4_render_target_t)
DEFINE_OBJ_EX(g4_shader, kinc_g4_shader_t)
DEFINE_OBJ_EX(g4_texture, kinc_g4_texture_t)
DEFINE_OBJ_EX(g4_vertex_structure, kinc_g4_vertex_structure_t)
DEFINE_OBJ_EX(g4_vertex_buffer, kinc_g4_vertex_buffer_t)
DEFINE_OBJ_EX(g4_index_buffer, kinc_g4_index_buffer_t)
DEFINE_OBJ_EX(g4_texture_array, kinc_g4_texture_array_t)

#define _PIPELINE _ABSTRACT(g4_pipeline)
#define _RENDER_TARGET _ABSTRACT(g4_render_target)
#define _SHADER _ABSTRACT(g4_shader)
#define _TEXTURE _ABSTRACT(g4_texture)
#define _VERTEX_STRUCTURE _ABSTRACT(g4_vertex_structure)
#define _VERTEX_BUFFER _ABSTRACT(g4_vertex_buffer)
#define _INDEX_BUFFER _ABSTRACT(g4_index_buffer)
#define _TEXTURE_ARRAY _ABSTRACT(g4_texture_array)
#define _LOC _ABSTRACT(g4_constant_location)
#define _TUNIT _ABSTRACT(g4_texture_unit)