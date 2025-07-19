//<--------------------START OF FILE-------------------->
#pragma once

#include <SDL2/SDL.h>
#include <math.h>
namespace CommonFunc
{
    extern int mouseX;
    extern int mouseY;
    bool CheckMouseHover(int mouseX, int mouseY, SDL_Rect rect);
    float CalculateDistance(int x1, int y1, int x2, int y2);
}

//<--------------------END OF FILE-------------------->