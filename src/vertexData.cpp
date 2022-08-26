#include "vertexData.h"

VertexData::VertexData() {
	// Vertices coordinates
	GLfloat vertices[] = {
		-0.5f, -0.5f,  0.5f,		1.0f, 0.0f, 0.0f,
         0.5f, -0.5f,  0.5f,		0.0f, 1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,		0.0f, 0.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,		0.0f, 0.9f, 0.7f,
		-0.5f, -0.5f, -0.5f,		1.0f, 0.2f, 0.0f,
         0.5f, -0.5f, -0.5f,		0.0f, 1.0f, 0.2f,
         0.5f,  0.5f, -0.5f,		0.0f, 2.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,		0.2f, 0.9f, 0.7f
	};

    GLuint indices[] = {
        0, 1, 2,
        0, 2, 3,

		4, 6, 5,
        7, 6, 4,

		3, 2, 6,
        3, 6, 7,

		1, 5, 6,
        1, 6, 2,

		4, 5, 1,
        4, 1, 0,

		4, 0, 3,
        4, 3, 7,
    };

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
