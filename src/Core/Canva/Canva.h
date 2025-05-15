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
    void clearCanva(SDL_Renderer* renderer);
    SDL_Texture* getCanvaTex()
    {
        return canv;
    }
private:
    SDL_Texture* canv;
    int WINDOW_WIDTH;
    int WINDOW_HEIGHT;
    int preMouseX;
    int preMouseY;
};
#endif
