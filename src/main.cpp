#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <math.h>
#include "shaderClass.h"
#include "vertexData.h"
#include "inputHandler.h"
#include <string>



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
	int windowSize[2] = {800, 800};
	
    //    ACTUALLY WICHTIG

    Shader shaderProgram("/home/vito/Documents/Coding/c++/test/resources/shader.vert","/home/vito/Documents/Coding/c++/test/resources/shader.frag");

    VertexData vertexData;

	GLuint TransformID = glGetUniformLocation(shaderProgram.ID, "transform");
	GLuint RotationID = glGetUniformLocation(shaderProgram.ID, "rotation");

	InputHandler InputHandler(window);
	
	glEnable(GL_CULL_FACE);

	int last_time = time(nullptr);

	// Main while loop
	while (!glfwWindowShouldClose(window))
	{
		int new_time = time(nullptr);
		int delta = new_time - last_time;
		last_time = new_time;

		InputHandler.handleInput(delta);

		glfwGetWindowSize(window, &windowSize[0], &windowSize[1]);
		glViewport(0, 0, windowSize[0], windowSize[1]);
		//std::cout << "X: " << std::to_string(windowSize[0]) << ",  Y: " << std::to_string(windowSize[1]) << "\n";

		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

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