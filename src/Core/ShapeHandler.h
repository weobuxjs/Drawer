#pragma once
#include "../GUI_Engine/GUI_Engine.h"
#include "Canva/Canva.h"
#include "../CommonFunction/CommonFunc.h"
class ShapeHandler
{
public:
    ShapeHandler(Canva* canva);
    void Update(bool isDrawing, int mouseX, int mouseY);
    void RenderDrawingShape();
    void UpdateDrawingShape();
    void SendDrawingShapeToCanva();
    void SwitchDrawingMode();
private:
    Canva* canva;
    DrawMode drawMode;
    Rect tmpRect;
    Line tmpLine;
    bool isDrawing;
    int tmpX;
    int tmpY;
    int mouseX;
    int mouseY;
};