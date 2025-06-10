#ifndef INSTANCE_H
#define INSTANCE_H
#include <SDL2/SDL.h>
#include <vector>
#include <math.h>
#include "Canva/Canva.h"
#include "../UI/Button.h"
#include "../CommonFunction/CommonFunc.h"
class Instance
{
public:
    Instance();
    void run();
    void cleanUp(); 
private:
    void handleInput();
    void update();
    void deleteOverlapedPixel();
    void render();
    void clearScreen();
    void renderDrawingShape();
    void updateDrawingShape();
    void sendDrawingShapeToCanva();
    void switchDrawingMode();
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
    SDL_Rect tmpRect;
    Line tmpLine;
    SDL_Event event;
    SDL_Window* window;
    SDL_Renderer* renderer;
    Canva* canva;
    // UI
    Button* clearScreenButton;
};

#endif
