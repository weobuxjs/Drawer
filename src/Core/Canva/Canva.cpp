//<--------------------START OF FILE-------------------->
#include "Canva.h"
Canva::Canva(SDL_Renderer* renderer, int width, int height) : Entity(0, 0, width, height, NULL)
{
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
    drawMode = RECTANGLE;
};

// void Canva::update(DrawMode drawMode, SDL_Renderer* renderer)
// {       

// }
void Canva::clearCanva(SDL_Renderer* renderer)
{
    SDL_Texture* screen = SDL_GetRenderTarget(renderer);
    SDL_SetRenderTarget(renderer, canv);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_Rect blankScreen = {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};
    SDL_RenderFillRect(renderer, &blankScreen);
    SDL_SetRenderTarget(renderer, screen);
}
void Canva::renderPoint(SDL_Renderer* renderer, int x, int y)
{
    SDL_Texture* screen = SDL_GetRenderTarget(renderer);
    SDL_SetRenderTarget(renderer, canv);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    if(preMouseX == -1 && preMouseY == -1)
    {
        SDL_RenderDrawPoint(renderer, x, y);
    }
    else if(x >= 0 && y >= 0) 
    {
        SDL_RenderDrawLine(renderer, preMouseX, preMouseY, x, y); 
    }
    SDL_SetRenderTarget(renderer, screen);
    preMouseX = x;
    preMouseY = y;
}
void Canva::renderRect(SDL_Renderer* renderer, SDL_Rect rect)
{
    SDL_Rect tmpRect = rect;
    SDL_Texture* screen = SDL_GetRenderTarget(renderer);
    SDL_SetRenderTarget(renderer, canv);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawRect(renderer, &tmpRect);
    SDL_SetRenderTarget(renderer, screen);
}
void Canva::renderLine(SDL_Renderer* renderer, Line line)
{
    SDL_Texture* screen = SDL_GetRenderTarget(renderer);
    SDL_SetRenderTarget(renderer, canv);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawLine(renderer, line.x1, line.y1, line.x2, line.y2);
    SDL_SetRenderTarget(renderer, screen);
}
void Canva::renderRightTriangle(SDL_Renderer* renderer, SDL_Rect rect)
{
    SDL_Texture* screen = SDL_GetRenderTarget(renderer);
    SDL_SetRenderTarget(renderer, canv);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawLine(renderer, rect.x, rect.y, rect.x, rect.y + rect.h);
    SDL_RenderDrawLine(renderer, rect.x, rect.y, rect.x + rect.w, rect.y);
    SDL_RenderDrawLine(renderer, rect.x, rect.y + rect.h, rect.x + rect.w, rect.y);
    SDL_SetRenderTarget(renderer, screen);
}
void Canva::renderCircle(SDL_Renderer* renderer, int x, int y, int r)
{
    SDL_Texture* screen = SDL_GetRenderTarget(renderer);
    SDL_SetRenderTarget(renderer, canv);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    for (float theta = 0; theta < 360; theta += 0.1)
    {
        SDL_RenderDrawPoint(renderer, x + r * cos(theta * 3.14 / 180), y + r * sin(theta* 3.14 / 180));
    }
    SDL_SetRenderTarget(renderer, screen);
}
//<--------------------END OF FILE-------------------->