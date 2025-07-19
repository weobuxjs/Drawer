#pragma once
#include <functional>
#include "../Entity.h"
#include "../CommonFunction/CommonFunc.h"
class Button : public Entity
{
public:
    Button(int x, int y, int w, int h, std::function<void()> funcPt);
    void OnClick();
private:
    std::function<void()> func;
};
