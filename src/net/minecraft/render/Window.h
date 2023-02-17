#ifndef __WINDOW_H__
#define __WINDOW_H__
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window
{
public:
unsigned int width,height;
GLFWwindow* nativeWindow;
Window(){}
Window(GLFWwindow* nativeWindow);
~Window();
};


#endif // __WINDOW_H__