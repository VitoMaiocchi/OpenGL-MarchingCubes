#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aCol;

uniform vec3 transform;
uniform mat3 rotation;

out vec3 color;

void main()
{
   float factor = 0.84;
   float near_plane = 0.1;
   float render_distance = 1000;

   vec3 transformed = rotation * (aPos - transform);
   transformed.x = transformed.x / abs(transformed.z) * factor;
   transformed.y = transformed.y / abs(transformed.z) * factor;
   //transformed.z = transformed.z / 200;
   transformed.z = (transformed.z - near_plane) * 2/render_distance - 1;
   gl_Position = vec4(transformed, 1.0);
   color = aCol;
}