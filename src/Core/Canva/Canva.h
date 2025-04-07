//<--------------------START OF FILE-------------------->
#ifndef CANVA_H
#define CANVA_H
#include <vector>
#include <SDL2/SDL.h>
#include "../Entity.h"
class Canva : public Entity
{
public:
    Canva(SDL_Renderer* renderer, int width, int height);
    void update(SDL_Renderer* renderer, int mouseX, int mouseY);
    SDL_Texture* getCanv()
    {
        return canv;
    }
private:
    SDL_Texture* canv;
};
#endif
