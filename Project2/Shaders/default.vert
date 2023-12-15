#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;
layout (location = 2) in vec2 texture;
uniform vec3 offset;
uniform mat4 model;
out vec3 Color;
out vec2 Texture;
void main() {
    Color = color;
    gl_Position = model * vec4(position, 1.0);
    Texture = texture;
}
