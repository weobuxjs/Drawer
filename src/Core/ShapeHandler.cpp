#include "ShapeHandler.h"
ShapeHandler::ShapeHandler(Canva* canva)
{
    drawMode = POINT;
    this->canva = canva;
}
void ShapeHandler::Update(bool isDrawing, int mouseX, int mouseY)
{
    this->isDrawing = isDrawing;
    this->mouseX = mouseX;
    this->mouseY = mouseY;
    if(isDrawing) 
    {        
        UpdateDrawingShape();
    }
    else
    {
        SendDrawingShapeToCanva();
    }
}
void ShapeHandler::UpdateDrawingShape()
{
    switch(drawMode)
    {
        case POINT:
            canva->RenderPoint(mouseX, mouseY);
            break;        
        case LINE:
        if(tmpX == -1 && tmpY == -1)
        {
            tmpX = mouseX;
            tmpY = mouseY;
        }
        tmpLine = {tmpX, tmpY, mouseX, mouseY};
        break;
        case RECTANGLE:
            if(tmpX == -1 && tmpY == -1)
            {
                tmpX = mouseX;
                tmpY = mouseY;
            }
            tmpRect = {tmpX, tmpY, mouseX - tmpX, mouseY - tmpY};
            break;

        case CIRCLE:
            if(tmpX == -1 && tmpY == -1)
            {
                tmpX = mouseX;
                tmpY = mouseY;
            }
            break;
        case RIGHT_TRIANGLE:        
            if(tmpX == -1 && tmpY == -1)
            {
                tmpX = mouseX;
                tmpY = mouseY;
            }
            tmpRect = {tmpX, tmpY, mouseX - tmpX, mouseY - tmpY};
            break;
        default:
            break;
    }
}
void ShapeHandler::RenderDrawingShape()
{
    switch(drawMode)
    {
        case POINT:
            GUI::DrawPoint(tmpX, tmpY);
            break;
        case LINE:
            GUI::DrawLine(tmpLine.x1, tmpLine.y1, tmpLine.x2, tmpLine.y2);
            break; 
        case RECTANGLE:
            GUI::DrawRect(tmpRect.x, tmpRect.y, tmpRect.w, tmpRect.h);
            break;
        case CIRCLE:
            if(isDrawing)
            {
                float r = CommonFunc::CalculateDistance(tmpX, tmpY, mouseX, mouseY);
                GUI::DrawCircle(tmpX, tmpY, r, 0.01);
            }
            break;
        case RIGHT_TRIANGLE:
            GUI::DrawLine(tmpRect.x, tmpRect.y, tmpRect.x, tmpRect.y + tmpRect.h);
            GUI::DrawLine(tmpRect.x, tmpRect.y, tmpRect.x + tmpRect.w, tmpRect.y);
            GUI::DrawLine(tmpRect.x, tmpRect.y + tmpRect.h, tmpRect.x + tmpRect.w, tmpRect.y);
            break;
    }
}
void ShapeHandler::SendDrawingShapeToCanva()
{
    switch(drawMode)
    {
        case POINT:
            canva->RenderPoint(-1, -1);
            break;
        case RECTANGLE:
            canva->RenderRect(tmpRect);
            break;
        case LINE:
            canva->RenderLine(tmpLine);
            break;
        case CIRCLE:
            if(tmpX != -1 && tmpY != -1)
            {
                canva->RenderCircle(tmpX, tmpY, CommonFunc::CalculateDistance(tmpX, tmpY, mouseX, mouseY));
            }
            break;
        case RIGHT_TRIANGLE:
            canva->RenderRightTriangle(tmpRect);
            break;
    }
    tmpX = -1;
    tmpY = -1;
    tmpRect = {-1, -1, -1, -1};
    tmpLine = {-1, -1, -1, -1};
}
void ShapeHandler::SwitchDrawingMode()
{
    drawMode = DrawMode((drawMode + 1) % 5);
}