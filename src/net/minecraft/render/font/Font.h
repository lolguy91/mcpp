#ifndef __FONT_H__
#define __FONT_H__

#define ASCII_TEX_SIZE 128

#include <net/minecraft/render/render.h>
#include "../../Minecraft.h"
#include <vector>

class FontRenderer{
    unsigned int vbo;
    unsigned int vao;
    unsigned int shader;
    Minecraft* mc = GetMinecraft();
    std::vector<Vertex> verticies;

    public:
    FontRenderer();

    void prepare(Window context);
    void draw();
    void update();

};

#endif // __FONT_H__