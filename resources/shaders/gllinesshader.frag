#version 410 core

in vec3 colour;

out vec4 FragColour;

void main() {
    FragColour = vec4(colour, 1);
} 