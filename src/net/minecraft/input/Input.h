#ifndef __INPUT_H__
#define __INPUT_H__

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Input
{
    extern float mouseX;
    extern float mouseY;
    extern float mouseScrollX;
    extern float mouseScrollY;

    void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
    void mouseCallback(GLFWwindow* window, double xpos, double ypos);
    void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
    void mouseScrollCallback(GLFWwindow* window, double xoffset, double yoffset);
    bool isKeyDown(int key);

    bool isMouseButtonDown(int mouseButton);
}

#endif // __INPUT_H__