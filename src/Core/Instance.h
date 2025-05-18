#ifndef INSTANCE_H
#define INSTANCE_H

#include <SDL2/SDL.h>
#include <vector>
#include "Canva/Canva.h"
#include "../UI/Button.h"
#include "../commonFunction/commonFunc.h"
struct Point2D
{
    int x;
    int y;
    Point2D(int pX, int pY)
    {
        x = pX;
        y = pY;
    }
};
struct Pixel
{
    int x;
    int y;
    int length;
    Pixel(int pX, int pY, int pLength)
    {
        x = pX;
        y = pY;
        length = pLength;
    }
};
struct Line
{
    int x1;
    int y1;
    int x2;
    int y2;
};
class Instance
{
public:
    Instance();
    void run();
    void handleInput();
    void update();
    void deleteOverlapedPixel();
    void render();
    void cleanup(); 
    void clearScreen();
private:
    int mouseX;
    int mouseY;
    int temporalX;
    int temporalY;
    DrawMode drawMode;
    const int WINDOW_HEIGHT = 700;
    const int WINDOW_WIDTH = 1000;
    bool isRunning;
    bool isMouseHoldDown;
    bool isDrawing;
    SDL_Rect DRAWING tmpRect;
    Line DRAWING tmpLine;
    SDL_Event event;
    SDL_Window* window;
    SDL_Renderer* renderer;
    Canva* canva;
    // UI
    Button* clearScreenButton;
};

#endif
