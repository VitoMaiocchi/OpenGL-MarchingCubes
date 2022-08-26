#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aCol;

uniform mat3 matrix;

out vec3 color;

void main()
{
   vec3 transformed = matrix * aPos;
   gl_Position = vec4(transformed, 1.0);
   color = aCol;
}