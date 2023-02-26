#ifndef __MINECRAFT_H__
#define __MINECRAFT_H__
#include <GLFW/glfw3.h>
#include "GameConfig.h"
#include "render/Window.h"
#include "render/gui/widgets/button.h"
#include "TextureManager.h"

struct Minecraft
{
    TextureManager tm;
    GameConfig config;
    Window window;
    button test;
    button test2;
    bool running;
};

bool IsRunning();
Minecraft* GetMinecraft();

void MCinit(GameConfig config,GLFWwindow* _window);
void MCupdate();

#endif // __MINECRAFT_H__