//<--------------------START OF FILE-------------------->
#include "commonFunc.h"
bool commonFunc::checkMouseCollision(int mouseX, int mouseY, SDL_Rect& rect)
{
    if(mouseX < rect.x) return false;
    if(mouseX > rect.x + rect.w) return false;
    if(mouseY < rect.y) return false;
    if(mouseY > rect.y + rect.h) return false;
    return true;
}
//<--------------------END OF FILE-------------------->