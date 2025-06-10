//<--------------------START OF FILE-------------------->
#ifndef COMMON_FUNC_H
#define COMMON_FUNC_H

#include <SDL2/SDL.h>
namespace CommonFunc
{
    bool checkMouseCollision(int mouseX, int mouseY, SDL_Rect& rect);
    float calculateDistance(int x1, int y1, int x2, int y2);
}

#endif
//<--------------------END OF FILE-------------------->