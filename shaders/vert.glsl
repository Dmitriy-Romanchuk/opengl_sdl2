#version 460 core

layout (location = 0) in vec3 position;

uniform float uOffset;

void main()
{
    gl_Position = vec4(position.x, position.y + uOffset, position.z, 1.0);
}

