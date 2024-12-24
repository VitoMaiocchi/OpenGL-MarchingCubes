#include "inputHandler.h"
#include "main.hpp"
#include <math.h>
#include <iostream>
#include <string>

//InputHandler::InputHandler(GLFWwindow* window, GLfloat* transform[3], GLfloat* rotation[9]) {
InputHandler::InputHandler(GLFWwindow* window) {
    pitch = 0;
    yaw = 0;
    Window = window;

    transform[0] = -3;
    transform[1] = 0;
    transform[2] = 0;

    rotation[0][0] = 0;
    rotation[0][1] = 0;
    rotation[0][2] = 1;

    rotation[1][0] = -1;
    rotation[1][1] = 0;
    rotation[1][2] = 0;

    rotation[2][0] = 0;
    rotation[2][1] = 1;
    rotation[2][2] = 0;
}

void InputHandler::handleInput(int delta) {
    int height = viewport_height;
    int width = viewport_width;

    float forward = 0;
    float right = 0;
    float up = 0;

    double mouse_x = 0;
    double mouse_y = 0;

    if (glfwGetKey(Window, GLFW_KEY_W) == GLFW_PRESS) {
        forward++;
    }
    if (glfwGetKey(Window, GLFW_KEY_S) == GLFW_PRESS) {
        forward--;
    }
    if (glfwGetKey(Window, GLFW_KEY_D) == GLFW_PRESS) {
        right++;
    }
    if (glfwGetKey(Window, GLFW_KEY_A) == GLFW_PRESS) {
        right--;
    }
    if (glfwGetKey(Window, GLFW_KEY_E) == GLFW_PRESS) {
        up++;
    }
    if (glfwGetKey(Window, GLFW_KEY_Q) == GLFW_PRESS) {
        up--;
    }
    int mode = glfwGetInputMode(Window, GLFW_CURSOR);

    if (glfwGetMouseButton(Window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS) {
        if (mode != GLFW_CURSOR_DISABLED) {
            glfwSetInputMode(Window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
            glfwSetCursorPos(Window, width/2, height/2);
            //if (glfwRawMouseMotionSupported()) glfwSetInputMode(Window, GLFW_RAW_MOUSE_MOTION, GLFW_TRUE);
        }

        glfwGetCursorPos(Window, &mouse_x, &mouse_y);  

        //std::cout << "X: " << std::to_string(width) << ",  Y: " << std::to_string(height) << "\n";
        //std::cout << "X: " << std::to_string(mouse_x) << ",  Y: " << std::to_string(mouse_y) << "\n";

        mouse_x = (mouse_x - (double)width/2) ;// / (double)width;
        mouse_y = (mouse_y - (double)height/2) ;// / (double)height;

        //std::cout << "X: " << std::to_string(mouse_x) << ",  Y: " << std::to_string(mouse_y) << "\n\n";
        glfwSetCursorPos(Window, width/2, height/2);

    } else if (mode != GLFW_CURSOR_NORMAL) {
        glfwSetInputMode(Window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
        //if (glfwRawMouseMotionSupported()) glfwSetInputMode(Window, GLFW_RAW_MOUSE_MOTION, GLFW_FALSE);
    }
    constexpr double sens = 0.006;
    yaw -= mouse_x * sens;
    pitch -= mouse_y * sens;


    if (pitch > M_PI / 2) pitch = M_PI / 2;
    else if (pitch < -M_PI / 2) pitch = -M_PI / 2;

    rotation[0][0] = sinf(yaw) * height/width;
    rotation[0][1] = -sinf(pitch) * cosf(yaw);
    rotation[0][2] = cosf(yaw) * cosf(pitch);

    rotation[1][0] = -cosf(yaw)* height/width;
    rotation[1][1] = -sinf(pitch) * sinf(yaw);
    rotation[1][2] = sinf(yaw);

    rotation[2][0] = 0;
    rotation[2][1] = cosf(pitch);
    rotation[2][2] = sinf(pitch);

    transform[0] = transform[0] +speed*( +sinf(yaw) * right    + cosf(yaw)*cosf(pitch) * forward  -sinf(pitch) * cosf(yaw) * up );
    transform[1] = transform[1] +speed*( -cosf(yaw) * right    + sin(yaw) * forward               -sinf(pitch) * sinf(yaw) * up );
    transform[2] = transform[2] +speed*(                       + sinf(pitch) * forward            +cosf(pitch) * up );    
    
    /*
    GLfloat new_rotation[9] = {
        sinf(yaw), -sinf(pitch), -cosf(yaw) * cosf(pitch),
        -cosf(yaw), 0, -sinf(yaw),
        0, cosf(pitch), -sinf(pitch)
    }; */
}