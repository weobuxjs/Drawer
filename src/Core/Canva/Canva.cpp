//<--------------------START OF FILE-------------------->
#include "Canva.h"
Canva::Canva(SDL_Renderer* renderer, int width, int height) : Entity(0, 0, width, height, NULL)
{
    // These two values mustn't be changed.
    WINDOW_WIDTH = width;
    WINDOW_HEIGHT = height;
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
    preMouseX = -1;
    preMouseY = -1;
};
void Canva::update(SDL_Renderer* renderer, int mouseX, int mouseY)
{       
    SDL_Texture* screen = SDL_GetRenderTarget(renderer);
    SDL_SetRenderTarget(renderer, canv);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    if(preMouseX == -1 && preMouseY == -1)
    {
        SDL_RenderDrawPoint(renderer, mouseX, mouseX);
    }
    else if(mouseX >= 0 && mouseY >= 0) 
    {
        SDL_RenderDrawLine(renderer, preMouseX, preMouseY, mouseX, mouseY); 
    }
    SDL_SetRenderTarget(renderer, screen);
    preMouseX = mouseX;
    preMouseY = mouseY;
}
void Canva::clearCanva(SDL_Renderer* renderer)
{
    SDL_Texture* screen = SDL_GetRenderTarget(renderer);
    SDL_SetRenderTarget(renderer, canv);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_Rect blankScreen = {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};
    SDL_RenderFillRect(renderer, &blankScreen);
    SDL_SetRenderTarget(renderer, screen);
}
//<--------------------END OF FILE-------------------->