#include "gui.h"
gui::gui()
{
}

gui::~gui()
{
}


void gui::prepare(){
for (widget w : widgets)
{
    w.prepare();
}

}
void gui::draw(){
for (widget w : widgets)
{
    w.draw();
}

}
void gui::update(){
for (widget w : widgets)
{
    w.update();
}

}