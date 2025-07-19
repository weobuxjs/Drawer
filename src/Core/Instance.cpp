#include "Instance.h"
Instance::Instance()
{

    isRunning = true;
    isMouseHoldDown = false;
    isDrawing = false;
    GUI::Init("Drawer", WINDOW_WIDTH, WINDOW_HEIGHT);
    canva = new Canva(WINDOW_WIDTH, WINDOW_HEIGHT);
    shapeHandler = new ShapeHandler(canva);
    clearScreenButton = new Button(0, 0, 100, 100,                               
                        [this](){canva->ClearCanva();});
    if(!canva)
    {
        printf("failed to initialize canva!\n");
    }
    temporalX = -1;
    temporalY = -1;
}
void Instance::HandleInput()
{
    while(SDL_PollEvent(&event))
    {
        SDL_GetMouseState(&mouseX, &mouseY);
        if(event.type == SDL_QUIT)
        {
            isRunning = false;
        }
        if(event.type == SDL_MOUSEBUTTONDOWN)
        {
            isMouseHoldDown = true;
            isDrawing = true;      
            if(CommonFunc::CheckMouseHover(mouseX, mouseY, *clearScreenButton->GetCollision()))
            {
                clearScreenButton->OnClick();
            }    
        }
        else if(event.type == SDL_MOUSEBUTTONUP)
        {
            isMouseHoldDown = false;
            isDrawing = false;            
        }
        if(event.type == SDL_KEYDOWN)
        {
            switch (event.key.keysym.sym)
            {
                case SDLK_s:
                    shapeHandler->SendDrawingShapeToCanva();
                    shapeHandler->SwitchDrawingMode();
                    break;
            }
        }
    }
}
void Instance::Render()
{    
    ClearScreen();
    GUI::Render(canva);

    GUI::SetColor(0, 0, 0, 0);
    shapeHandler->RenderDrawingShape();


    GUI::RenderPresent();
}
void Instance::Update()
{   
    CommonFunc::mouseX = mouseX;
    CommonFunc::mouseY = mouseY;
    shapeHandler->Update(isDrawing, mouseX, mouseY);
}
void Instance::Run()
{   
    while(isRunning)
    {
        HandleInput();
        Update();
        Render();
    }
}
void Instance::CleanUp()
{
    GUI::CleanUp();
}
void Instance::ClearScreen()
{
    GUI::SetColor(255, 255, 255, 255);
    GUI::ClearScreen();
}