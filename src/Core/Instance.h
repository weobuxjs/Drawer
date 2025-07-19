#pragma once
#include <vector>
#include <math.h>
#include "../GUI_Engine/GUI_Engine.h"
#include "Canva/Canva.h"
#include "../CommonFunction/CommonFunc.h"
#include "../Renaming.h"
#include "../UI/Pop_Up.h"
#include "../UI/Button.h"
#include "ShapeHandler.h"
class Instance
{
public:
    Instance();
    void Run();
    void CleanUp(); 
private:
    void HandleInput();
    void Update();
    void DeleteOverlapedPixel();
    void Render();
    void ClearScreen();
    int mouseX;
    int mouseY;
    int temporalX;
    int temporalY;
    const int WINDOW_HEIGHT = 700;
    const int WINDOW_WIDTH = 1000;
    bool isRunning;
    bool isMouseHoldDown;
    bool isDrawing;
    Event event;
    Canva* canva;
    ShapeHandler* shapeHandler;
    // UI
    Button* clearScreenButton;
    Pop_Up* pop_up;
};
