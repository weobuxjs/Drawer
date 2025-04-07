//<--------------------START OF FILE-------------------->
#ifndef BUTTON_H
#define BUTTON_H

#include <SDL2/SDL.h>
#include <../Core/Entity.h>
class Button : public Entity
{
public:
    Button(int x, int y, int w, int h) : Entity(x, y, w, h, nullptr){};
};

#endif
//<--------------------END OF FILE-------------------->