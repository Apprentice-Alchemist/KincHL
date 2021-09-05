#version 450

in vec3 pos;
in vec2 tex;

out vec2 texcoord;

uniform mat3 mvp;

void main() {
	gl_Position = vec4(mvp * vec3(pos.x, pos.y, 0.5), 1.0);
	texcoord = tex;
}