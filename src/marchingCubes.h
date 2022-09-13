#ifndef MARCHING_CUBES
#define MARCHING_CUBES

#include <glad/glad.h>
#include <vector>
#include "Vector.h"

void generateArrays(std::vector<GLfloat>* Vertecies, std::vector<GLuint>* Indices);
void appendCube(std::vector<GLfloat>* vertecies, std::vector<GLuint>* indices, int index[3]);
float Noise_Function(float x, float y, float z);
std::vector<float> Noise_Function_gradient(float x, float y, float z);
float PerlinNoise(Vector3f vector);
Vector3f PerlinNoise_gradient(Vector3f vector);

#endif