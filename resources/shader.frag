#version 330 core
out vec4 FragColor;

in vec3 color;

void main() {
   FragColor = vec4( (vec3(0.84f, 0.41f, 0.8f) + color / 5) , 1.0f);
}