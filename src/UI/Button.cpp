#include "Button.h"
Button::Button(int x, int y, int w, int h, std::function<void()> funcPtr) : Entity(x, y, w, h, NULL)
{
    func = funcPtr;
}
void Button::OnClick()
{
    if(func) 
    {
        func();
    }
}
