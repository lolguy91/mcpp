#ifndef __WIDGET_H__
#define __WIDGET_H__
#include <net/minecraft/render/Window.h>
class widget
{
public:
    widget();
    ~widget();
    virtual void prepare(Window context);
    virtual void draw();
    virtual void update();
};




#endif // __WIDGET_H__