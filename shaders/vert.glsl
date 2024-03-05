#version 460 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 normal;

uniform mat4 u_ModelMatrix;
uniform mat4 u_ViewMatrix;
uniform mat4 u_Projection;

out vec3 FragPos;
out vec3 Normal;

void main()
{
	gl_Position = u_Projection * u_ViewMatrix * u_ModelMatrix * vec4(position, 1.0f);
	FragPos = vec3(u_ModelMatrix * vec4(position, 1.0f));
	Normal = mat3(transpose(inverse(u_ModelMatrix))) * normal;
}