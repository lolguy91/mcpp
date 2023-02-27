#ifndef __FONT_H__
#define __FONT_H__

#define ASCII_TEX_SIZE 128
#define ASCII_CHAR_SIZE 8
#define ASCII_NORM_CHAR_SIZE ASCII_CHAR_SIZE / ASCII_TEX_SIZE 

#include <net/minecraft/render/render.h>
#include "../../Minecraft.h"
#include <vector>
#include <string>

class FontRenderer{
    bool needsupdate;
    unsigned int vbo;
    unsigned int vao;
    unsigned int shader;
    Minecraft* mc = GetMinecraft();
    std::vector<Vertex> verticies;

    public:
    FontRenderer();

    void prepare(Window context);
    void addText(std::string text,int x, int y,int charsize,int spacing = 5);
    void clear();
    void draw();
    void update();

};

#endif // __FONT_H__