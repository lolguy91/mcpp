#include "test.h"
#include "widgets/button.h"

Test::Test(/* args */)
{
    widgets.push_back(button(0,0,100,100));
}

Test::~Test()
{
}

void Test::prepare(Window context){
for (widget w : widgets)
{
    w.prepare(context);
}

}
void Test::draw(){
for (widget w : widgets)
{
    w.draw();
}

}
void Test::update(){
for (widget w : widgets)
{
    w.update();
}

}