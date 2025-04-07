//<--------------------START OF FILE-------------------->
#include "Canva.h"
Canva::Canva(SDL_Renderer* renderer, int width, int height) : Entity(0, 0, width, height, NULL)
{
    canv = SDL_CreateTexture(renderer, 
        SDL_PIXELFORMAT_RGBA8888, 
        SDL_TEXTUREACCESS_TARGET, 
        width, height);
    if(!canv)
    {
        printf("Failed to initialize canva surface!\n: %s", SDL_GetError());
    }
    else
    {
        SDL_Texture* screen = SDL_GetRenderTarget(renderer);
        SDL_SetRenderTarget(renderer, canv);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderTarget(renderer, screen);
    }
};
void Canva::update(SDL_Renderer* renderer, int mouseX, int mouseY)
{
    SDL_Texture* screen = SDL_GetRenderTarget(renderer);
    SDL_SetRenderTarget(renderer, canv);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    // printf("ATT %d %d\n", mouseX, mouseY);
    SDL_Rect tRect = {mouseX, mouseY, 10, 10};
    SDL_RenderFillRect(renderer, &tRect);
    SDL_SetRenderTarget(renderer, screen);
}
//<--------------------END OF FILE-------------------->