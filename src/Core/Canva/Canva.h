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
struct Line
{
    int x1;
    int y1;
    int x2;
    int y2;
};
class Canva : public Entity
{
public:
    Canva(SDL_Renderer* renderer, int width, int height);
    void update(DrawMode drawMode, SDL_Renderer* renderer);
    void clearCanva(SDL_Renderer* renderer);  
    void DRAWING renderPoint(SDL_Renderer* renderer, int x, int y);
    void DRAWING renderRect(SDL_Renderer* renderer, SDL_Rect rect);
    void DRAWING renderLine(SDL_Renderer* renderer, Line line);
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
    int DRAWING temporalX;
    int DRAWING temporalY;
};
#endif
