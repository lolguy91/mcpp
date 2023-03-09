#ifndef __MINECRAFT_H__
#define __MINECRAFT_H__
#include "GameConfig.h"
#include "render/Window.h"
#include "render/TextureManager.h"


struct Minecraft
{
    TextureManager tm;
    GameConfig config;
    Window window;
    bool running;
};

bool IsRunning();
Minecraft* GetMinecraft();

void MCinit(GameConfig config,GLFWwindow* _window);
void MCupdate();

#endif // __MINECRAFT_H__