#ifndef __WIDGET_H__
#define __WIDGET_H__
#include <net/minecraft/render/Window.h>
#include <net/minecraft/Minecraft.h>
class widget
{
    Minecraft* mc = GetMinecraft();
public:
    widget();
    ~widget();
    virtual void prepare(Window context);
    virtual void draw();
    virtual void update();
};




#endif // __WIDGET_H__