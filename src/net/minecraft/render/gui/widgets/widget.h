#ifndef __WIDGET_H__
#define __WIDGET_H__
#include <net/minecraft/render/Window.h>

class widget
{
private:

public:
    widget(/* args */);
    ~widget();

    void prepare(Window context);
    void draw();
    void update();
};




#endif // __WIDGET_H__