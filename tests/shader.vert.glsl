#version 450

in vec3 pos;
// in vec2 uv;

// out vec2 tex_uv;

void main() {
	// tex_uv = uv;
	gl_Position = vec4(pos, 1.0);
}