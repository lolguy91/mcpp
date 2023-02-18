#ifndef __BUTTON_H__
#define __BUTTON_H__
#include "widget.h"

class button :public widget
{
private:
    int x, y, width, height;
public:
    button(int x,int y,int width,int height);
    ~button();

    void prepare(Window context);
    void draw();
    void update();
};




#endif // __BUTTON_H__