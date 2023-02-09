#ifndef __MINECRAFT_H__
#define __MINECRAFT_H__
#include "GameConfig.h"
#include <GLFW/glfw3.h>
bool IsRunning();
void MCinit(GameConfig config,GLFWwindow* _window);
void MCupdate();

#endif // __MINECRAFT_H__