#include "vertexData.h"
#include "marchingCubes.h"
#include <vector>
#include <iostream>

VertexData::VertexData() {
	// Vertices coordinates

	/*
	GLfloat vertices[] = {
		-0.5f, -0.5f,  0.5f,		0.0f, 0.0f, 1.0f, 
         0.5f, -0.5f,  0.5f,		0.0f, 0.0f, 1.0f, 
         0.5f,  0.5f,  0.5f,		0.0f, 0.0f, 1.0f, 
        -0.5f,  0.5f,  0.5f,		0.0f, 0.0f, 1.0f, 

		-0.5f, -0.5f, -0.5f,		0.0f, 0.0f, -1.0f, 
         0.5f, -0.5f, -0.5f,		0.0f, 0.0f, -1.0f, 
         0.5f,  0.5f, -0.5f,		0.0f, 0.0f, -1.0f, 
        -0.5f,  0.5f, -0.5f,		0.0f, 0.0f, -1.0f, 

		 0.5f,  0.5f,  0.5f,		0.0f, 1.0f, 0.0f, 
        -0.5f,  0.5f,  0.5f,		0.0f, 1.0f, 0.0f, 
		 0.5f,  0.5f, -0.5f,		0.0f, 1.0f, 0.0f, 
        -0.5f,  0.5f, -0.5f,		0.0f, 1.0f, 0.0f, 

		 0.5f, -0.5f,  0.5f,		1.0f, 0.0f, 0.0f, 
         0.5f,  0.5f,  0.5f,		1.0f, 0.0f, 0.0f, 
		 0.5f, -0.5f, -0.5f,		1.0f, 0.0f, 0.0f,
         0.5f,  0.5f, -0.5f,		1.0f, 0.0f, 0.0f,

		-0.5f, -0.5f,  0.5f,		0.0f, -1.0f, 0.0f, 
         0.5f, -0.5f,  0.5f,		0.0f, -1.0f, 0.0f, 
		-0.5f, -0.5f, -0.5f,		0.0f, -1.0f, 0.0f,  
         0.5f, -0.5f, -0.5f,		0.0f, -1.0f, 0.0f,  

		-0.5f, -0.5f,  0.5f,		-1.0f, 0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,		-1.0f, 0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,		-1.0f, 0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,		-1.0f, 0.0f, 0.0f,
	};

    GLuint indices[] = {
        0, 1, 2,
        0, 2, 3,

		4, 6, 5,
        7, 6, 4,

		9, 8, 10,
        9, 10, 11,

		12, 14, 15,
        12, 15, 13,

		18, 19, 17,
        18, 17, 16,

		22, 20, 21,
        22, 21, 23,
    };
	*/


	std::vector<GLfloat> Vertices;
	std::vector<GLuint> Indices;

	generateArrays(&Vertices, &Indices);

	GLfloat vertices[Vertices.size()];
	std::copy(Vertices.begin(), Vertices.end(), vertices);

	GLuint indices[Indices.size()];
	std::copy(Indices.begin(), Indices.end(), indices);	

    vert_size = sizeof(vertices);
    indi_size = sizeof(indices);

	// Generate the VAO and VBO with only 1 object each
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

	// Make the VAO the current Vertex Array Object by binding it
	glBindVertexArray(VAO);

	// Bind the VBO specifying it's a GL_ARRAY_BUFFER
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	// Introduce the vertices into the VBO
	glBufferData(GL_ARRAY_BUFFER, vert_size, vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indi_size, indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3*sizeof(float)));
	glEnableVertexAttribArray(1);

	// Bind both the VBO and VAO to 0 so that we don't accidentally modify the VAO and VBO we created
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void VertexData::Draw() {
	// Bind the VAO so OpenGL knows to use it
    glBindVertexArray(VAO);
	// Draw the triangle using the GL_TRIANGLES primitive
    glDrawElements(GL_TRIANGLES, indi_size, GL_UNSIGNED_INT, 0);
}

void VertexData::Delete() {
    glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}
