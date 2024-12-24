#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <math.h>
#include "shaderClass.h"
#include "vertexData.h"
#include "inputHandler.h"
#include <string>

int viewport_height = 800;
int viewport_width = 800;

void frame_buffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
	viewport_height = height;
	viewport_width = width;
}

int main() {
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	

	GLFWwindow* window = glfwCreateWindow(800, 800, "OpenGL Test", NULL, NULL);

	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	gladLoadGL();
	glViewport(0, 0, 800, 800);
	glfwSetFramebufferSizeCallback(window, frame_buffer_size_callback);

    Shader shaderProgram("resources/shader.vert","resources/shader.frag");

    VertexData vertexData;

	GLuint TransformID = glGetUniformLocation(shaderProgram.ID, "transform");
	GLuint RotationID = glGetUniformLocation(shaderProgram.ID, "rotation");

	InputHandler InputHandler(window);
	
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	int last_time = time(nullptr);

	// Main while loop
	while (!glfwWindowShouldClose(window))
	{
		int new_time = time(nullptr);
		int delta = new_time - last_time;
		last_time = new_time;

		InputHandler.handleInput(delta);

		glClearColor(0.32f, 0.81f, 0.58f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glClear(GL_DEPTH_BUFFER_BIT);

		shaderProgram.Activate();

		/*
		GLfloat Transform[3] = {3, 0, 0};
    	GLfloat Rotation[3][3] = {
        	0, 0, -1,
        	-1, 0, 0,
    	    0, 1, 0
    	}; */
		glUniformMatrix3fv(RotationID, 1, GL_FALSE, &InputHandler.rotation[0][0]);
		glUniform3fv(TransformID, 1, &InputHandler.transform[0]);	

		/*
		std::cout << std::to_string((*rotation)[0]);

		glUniformMatrix3fv(RotationID, 1, GL_FALSE, &(*rotation)[0] );
		glUniform3fv(TransformID, 1, &(*transform)[0] ); */
		

        vertexData.Draw();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

    vertexData.Delete();
	shaderProgram.Delete();
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}