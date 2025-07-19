//<--------------------START OF FILE-------------------->
#pragma once
#include <vector>
#include <math.h>
#include "../../GUI_Engine/GUI_Engine.h"
#include "../../Entity.h"
#define DRAWING
enum DrawMode
{
    POINT,
    LINE,
    RECTANGLE,
    CIRCLE,
    RIGHT_TRIANGLE   
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
    Canva(int width, int height);
    void Update(DrawMode drawMode);
    void ClearCanva();  
    void HandleInput(Event& event);
    void DRAWING RenderPoint(int x, int y);
    void DRAWING RenderRect(Rect rect);
    void DRAWING RenderLine(Line line);
    void DRAWING RenderRightTriangle(Rect rect);
    void DRAWING RenderCircle(int x, int y, float r);
    Texture* GetCanvaTex()
    {
        return canv;
    }
    void SetDrawMode(DrawMode pMode)
    {
        drawMode = pMode;
    }
private:
    Texture* canv;
    DrawMode drawMode;
    int WINDOW_WIDTH;
    int WINDOW_HEIGHT;
    int preMouseX;
    int preMouseY;
    int tmpX;
    int tmpY;
};
