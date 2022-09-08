#ifndef INPUT_HANDLER
#define INPUT_HANDLER

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class InputHandler {
    public:
        InputHandler(GLFWwindow* window);
        void handleInput(int delta);
        GLfloat transform[3];
        GLfloat rotation[3][3];
    private:
        float pitch;
        float yaw;
        GLFWwindow* Window;
        float sens = 0.005;
        float speed = 0.03;
};

#endif