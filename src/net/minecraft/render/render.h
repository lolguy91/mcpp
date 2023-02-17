#ifndef __RENDER_H__
#define __RENDER_H__
#include <glm/glm.hpp>

struct Vertex
{
	glm::vec2 position;
    glm::vec2 texcoord;
};


void initGlad();
void renderCrosshair();
void CreateCrosshair();

#endif // __RENDER_H__