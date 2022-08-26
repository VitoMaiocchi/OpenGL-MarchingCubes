#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <math.h>
#include "shaderClass.h"
#include "vertexData.h"



int main()
{
    // Initialize GLFW
	glfwInit();

	// Tell GLFW what version of OpenGL we are using 
	// In this case we are using OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Tell GLFW we are using the CORE profile
	// So that means we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create a GLFWwindow object of 800 by 800 pixels, naming it "YoutubeOpenGL"
	GLFWwindow* window = glfwCreateWindow(800, 800, "OpenGL Test", NULL, NULL);
	// Error check if the window fails to create
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	// Introduce the window into the current context
	glfwMakeContextCurrent(window);

	//Load GLAD so it configures OpenGL
	gladLoadGL();
	// Specify the viewport of OpenGL in the Window
	// In this case the viewport goes from x = 0, y = 0, to x = 800, y = 800
	glViewport(0, 0, 800, 800);


    //    ACTUALLY WICHTIG

    Shader shaderProgram("/home/vito/Documents/Coding/c++/test/resources/shader.vert","/home/vito/Documents/Coding/c++/test/resources/shader.frag");

    VertexData vertexData;

	GLuint MatrixID = glGetUniformLocation(shaderProgram.ID, "matrix");

	float angle = 0.0f;

	glEnable(GL_CULL_FACE);

	// Main while loop
	while (!glfwWindowShouldClose(window))
	{

		GLfloat matrix[3][3] = {
			cosf(angle), 0, sinf(angle),
			0, 0.8, -0.2,
			-sinf(angle), 0.2, cosf(angle) * 0.8f
		};
		angle = angle + 0.01f;

		// Specify the color of the background
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		// Clean the back buffer and assign the new color to it
		glClear(GL_COLOR_BUFFER_BIT);
		// Tell OpenGL which Shader Program we want to use

		shaderProgram.Activate();

		glUniformMatrix3fv(MatrixID, 1, GL_FALSE, &matrix[0][0]);

        vertexData.Draw();

		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);
		// Take care of all GLFW events
		glfwPollEvents();
	}



	// Delete all the objects we've created
    vertexData.Delete();
	shaderProgram.Delete();

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}