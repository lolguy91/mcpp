#include "gui.h"
std::vector<widget> widgets;
gui::gui()
{
}

gui::~gui()
{
}


void gui::prepare(Window context){
for (auto w : widgets)
{
    w.prepare(context);
}

}
void gui::draw(){
for (auto w : widgets)
{
    w.draw();
}

}
void gui::update(){
for (auto w : widgets)
{
    w.update();
}

}