#include "Window.h"
#include "../input/Input.h"
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
	width =  640;
	height = 480;
	nativeWindow = _nativeWindow;
	
	glfwSetWindowUserPointer(_nativeWindow, this);
	glfwSetWindowSizeCallback(_nativeWindow, resizeCallback);

	glfwSetMouseButtonCallback(_nativeWindow,Input::mouseButtonCallback);
	glfwSetCursorPosCallback(_nativeWindow,Input::mouseCallback);
	glfwSetScrollCallback(_nativeWindow,Input::mouseScrollCallback);
	glfwSetKeyCallback(_nativeWindow,Input::keyCallback);

}

Window::~Window()
{

}
