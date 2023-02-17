#include "Window.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

void resizeCallback(GLFWwindow* nativeWindow, int newWidth, int newHeight)
{
	Window* window = (Window*)glfwGetWindowUserPointer(nativeWindow);
	window->width = newWidth;
	window->height = newHeight;
	glViewport(0, 0, newWidth, newHeight);
}

Window::Window(GLFWwindow* _nativeWindow)
{
    nativeWindow = _nativeWindow;
    glfwSetWindowUserPointer(_nativeWindow, this);
    glfwSetWindowSizeCallback(_nativeWindow, resizeCallback);
}

Window::~Window()
{

}
