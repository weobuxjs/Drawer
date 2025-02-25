//<--------------------START OF FILE-------------------->
#include "Canva.h"
Canva::Canva(SDL_Renderer* renderer, int width, int height) : Entity(0, 0, width, height, NULL)
{
    canv = SDL_CreateTexture(renderer, 
        SDL_PIXELFORMAT_RGBA8888, 
        SDL_TEXTUREACCESS_TARGET, 
        width, height);
    
};
void Canva::update(SDL_Renderer* renderer, int mouseX, int mouseY)
{
    SDL_Texture* screen = SDL_GetRenderTarget(renderer);
    SDL_SetRenderTarget(renderer, canv);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    // RENDERING
    SDL_Rect tRect = {mouseX, mouseY, 10, 10};
    SDL_RenderFillRect(renderer, &tRect);
    SDL_SetRenderTarget(renderer, screen);
}
//<--------------------END OF FILE-------------------->