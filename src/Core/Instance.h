//<--------------------START OF FILE-------------------->
#ifndef INSTANCE_H
#define INSTANCE_H

#include <SDL2/SDL.h>
#include <vector>
#include <Canva.h>
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
class Instance
{
public:
    Instance();
    // bool init();
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
    const int WINDOW_HEIGHT = 700;
    const int WINDOW_WIDTH = 1000;
    bool isRunning;
    bool isMouseHoldDown;
    bool isDrawing;
    SDL_Event event;
    SDL_Window* window;
    SDL_Renderer* renderer;
    std::vector<SDL_Rect> pixel;
    Canva* canva;
    
    // UI
    Button* clearScreenButton;
};

#endif

//<--------------------END OF FILE-------------------->