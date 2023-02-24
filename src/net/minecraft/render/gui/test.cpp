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
for(auto var : widgets)
{
    var.prepare(context);
}

}
void Test::draw(){
for(auto var : widgets)
{
    var.draw();
}

}
void Test::update(){
for(auto var : widgets)
{
    var.update();
}

}