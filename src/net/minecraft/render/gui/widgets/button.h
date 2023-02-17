#ifndef __BUTTON_H__
#define __BUTTON_H__
#include "widget.h"

class button :public widget
{
private:
    /* data */
public:
    button(int x,int y,int width,int height);
    ~button();

    void prepare();
    void draw();
    void update();
};




#endif // __BUTTON_H__