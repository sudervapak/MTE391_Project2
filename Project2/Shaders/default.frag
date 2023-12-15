#version 330 core
in vec3 Color;
in vec2 Texture;
out vec4 outColor;
uniform sampler2D tex0;
void main() {
    outColor = texture(tex0, Texture);
}