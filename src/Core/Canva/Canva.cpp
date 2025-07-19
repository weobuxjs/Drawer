//<--------------------START OF FILE-------------------->
#include "Canva.h"
Canva::Canva(int width, int height) : Entity(0, 0, width, height, NULL)
{
    WINDOW_WIDTH = width;
    WINDOW_HEIGHT = height;
    canv = GUI::CreateTexture(width, height);
    if(!canv)
    {
        printf("Failed to initialize canva surface!\n: %s", SDL_GetError());
    }
    else
    {
        SDL_Texture* screen = GUI::GetRenderTarget();
        GUI::SetRenderTarget(canv);
        GUI::SetColor(255, 255, 255, 255);
        GUI::ClearScreen();
        GUI::SetRenderTarget(screen);
    }
    preMouseX = -1;
    preMouseY = -1;
    drawMode = RECTANGLE;
    texture = canv;
};
void Canva::ClearCanva()
{
    Texture* screen = GUI::GetRenderTarget();
    GUI::SetRenderTarget(canv);
    GUI::SetColor(255, 255, 255, 255);
    GUI::ClearScreen();
    GUI::SetRenderTarget(screen);
}
void Canva::RenderPoint(int x, int y)
{
    SDL_Texture* screen = GUI::GetRenderTarget();
    GUI::SetRenderTarget(canv);
    GUI::SetColor(0, 0, 0, 255);
    if(preMouseX == -1 && preMouseY == -1)
    {
        GUI::DrawPoint(x, y);
    }
    else if(x >= 0 && y >= 0) 
    {
        GUI::DrawLine(preMouseX, preMouseY, x, y);
    }
    preMouseX = x;
    preMouseY = y;
    GUI::SetRenderTarget(screen);
}
void Canva::RenderRect(Rect rect)
{
    SDL_Rect tmpRect = rect;
    SDL_Texture* screen = GUI::GetRenderTarget();
    GUI::SetRenderTarget(canv);
    GUI::SetColor(0, 0, 0, 255);
    GUI::DrawRect(tmpRect);
    GUI::SetRenderTarget(screen);
}
void Canva::RenderLine(Line line)
{
    SDL_Texture* screen = GUI::GetRenderTarget();
    GUI::SetRenderTarget(canv);
    GUI::SetColor(0, 0, 0, 255);
    GUI::DrawLine(line.x1, line.y1, line.x2, line.y2);
    GUI::SetRenderTarget(screen);
}
void Canva::RenderRightTriangle(Rect rect)
{
    SDL_Texture* screen = GUI::GetRenderTarget();
    GUI::SetRenderTarget(canv);
    GUI::SetColor(0, 0, 0, 255);
    GUI::DrawLine(rect.x, rect.y, rect.x, rect.y + rect.h);
    GUI::DrawLine(rect.x, rect.y, rect.x + rect.w, rect.y);
    GUI::DrawLine(rect.x, rect.y + rect.h, rect.x + rect.w, rect.y);
    GUI::SetRenderTarget(screen);
}
void Canva::RenderCircle(int x, int y, float r)
{
    SDL_Texture* screen = GUI::GetRenderTarget();
    GUI::SetRenderTarget(canv);
    GUI::SetColor(0, 0, 0, 255);
    GUI::DrawCircle(x, y, r);
    GUI::SetRenderTarget(screen);
}
//<--------------------END OF FILE-------------------->