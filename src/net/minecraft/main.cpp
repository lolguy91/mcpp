#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main() {
    GLFWwindow* window;
 
    if (!glfwInit())
        exit(EXIT_FAILURE);
 
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
 
    window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
 
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

 
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
 
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
 
    glfwDestroyWindow(window);
 
    glfwTerminate();
    exit(EXIT_SUCCESS);
}