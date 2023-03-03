#ifndef __BUTTON_H__
#define __BUTTON_H__
#include <net/minecraft/render/render.h>
#include "widget.h"


class button :public widget
{
private:
    unsigned int vbo;
    unsigned int vao;
    unsigned int shader;
    int x, y, width, height;
    bool hovered,gray,needsupdate = true;
    void applyUV(glm::vec2* uv);
    Vertex verts[6];
public:
    button(int x,int y,int width,int height,bool gray);

    void prepare(Window context) override;
    void draw() override;
    void update() override;
};




#endif // __BUTTON_H__