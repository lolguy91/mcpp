#include <src/com/mojang/lib3d/platform/Window.h>
#include <iostream>
using namespace std;

int main() {
    Window win(VideoMode(GLFWvidmode()),"2");
    std::cout << "Hello world!" << std::endl; 

    while (win.shouldClose())
    {
        
    }
    win.close();
}