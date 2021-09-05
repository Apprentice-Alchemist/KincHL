#version 450

in vec2 texcoord;

out vec4 FragColor;

uniform sampler2D texsampler;

void main() {
	vec4 color = texture(texsampler, texcoord);
	FragColor = vec4(color.r, color.g, color.b, 1.0);
}