//<--------------------START OF FILE-------------------->
#ifndef CANVA_H
#define CANVA_H
#include <vector>
#include <SDL2/SDL.h>
#include "../Entity.h"
#define DRAWING
enum DrawMode
{
    POINT,
    LINE,
    RECTANGLE
};
class Canva : public Entity
{
public:
    Canva(SDL_Renderer* renderer, int width, int height);
    void update(SDL_Renderer* renderer, int mouseX, int mouseY);
    void clearCanva(SDL_Renderer* renderer);  
    // void DRAWING renderPoint(SDL_Renderer *renderer, int x, int y);
    // void DRAWING renderRect(SDL_Renderer *renderer, int x, int y);
    // void DRAWING tmpRender(SDL_Renderer *renderer, int x, int y);
    SDL_Texture* getCanvaTex()
    {
        return canv;
    }
    void setDrawMode(DrawMode pMode)
    {
        drawMode = pMode;
    }
private:
    SDL_Texture* canv;
    DrawMode drawMode;
    int WINDOW_WIDTH;
    int WINDOW_HEIGHT;
    int preMouseX;
    int preMouseY;
    // int DRAWING temporalX;
    // int DRAWING temporalY;
};
#endif
