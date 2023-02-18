#ifndef __RENDER_H__
#define __RENDER_H__
#include <glm/glm.hpp>
#include <net/minecraft/render/Window.h>
struct Vertex
{
	glm::vec2 position;
    glm::vec2 texcoord;
};


void initGlad();
void renderCrosshair();
void CreateCrosshair(Window context);

#endif // __RENDER_H__