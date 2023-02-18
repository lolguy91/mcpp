#ifndef __TEST_H__
#define __TEST_H__
#include "gui.h"

class Test :public gui
{
std::vector<widget> widgets;
public:
    Test(/* args */);
    ~Test();

    void prepare(Window context);
    void draw();
    void update();
};


#endif // __TEST_H__