#ifndef __GUI_H__
#define __GUI_H__

#include "widgets/widget.h"
#include <vector>


class gui
{
private:
    std::vector<widget> widgets;
public:
    gui();
    ~gui();

    void prepare(Window context);
    void draw();
    void update();
};


#endif // __GUI_H__