#include <src/com/mojang/lib3d/platform/Window.h>
#include <iostream>

int main() {
    CreateWindow(VideoMode(GLFWvidmode()),"2");
    std::cout << "Hello world!" << std::endl; 

    while (shouldClose())
    {
        
    }
    close();
}