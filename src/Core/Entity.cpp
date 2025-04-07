//<--------------------START OF FILE-------------------->
#include "Entity.h"
Entity::Entity(int x, int y, int w, int h, SDL_Texture* pTex)
{
    collision = {x, y, w, h};
    tex = pTex;
}
//<--------------------END OF FILE-------------------->