#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;
uniform vec3 offset;
uniform mat4 model;
out vec3 Color;
void main() {
    Color = color;
    gl_Position = model * vec4(position, 1.0);
}
