//<--------------------START OF FILE-------------------->
#include "CommonFunc.h"
namespace CommonFunc
{
    int mouseX;
    int mouseY;
    bool CheckMouseHover(int mouseX, int mouseY, SDL_Rect rect)
    {
        if(mouseX < rect.x) return false;
        if(mouseX > rect.x + rect.w) return false;
        if(mouseY < rect.y) return false;
        if(mouseY > rect.y + rect.h) return false;
        return true;
    }
    float CalculateDistance(int x1, int y1, int x2, int y2)
    {
        return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    }
}

//<--------------------END OF FILE-------------------->