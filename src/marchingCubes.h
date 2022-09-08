#ifndef MARCHING_CUBES
#define MARCHING_CUBES

#include <glad/glad.h>
#include <vector>

void generateArrays(std::vector<GLfloat>* Vertecies, std::vector<GLuint>* Indices);
void appendCube(std::vector<GLfloat>* vertecies, std::vector<GLuint>* indices, int index[3]);
float Noise_Function(float x, float y, float z);

#endif