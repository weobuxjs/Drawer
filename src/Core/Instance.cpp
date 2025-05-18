#include "Instance.h"
Instance::Instance()
{
    isRunning = true;
    isMouseHoldDown = false;
    isDrawing = false;
    drawMode = LINE;
    window = SDL_CreateWindow("Drawer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if(!window)
    {
        printf("%s\n", SDL_GetError());
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC ); 
    if(!renderer)
    {
        printf("%s\n", SDL_GetError());
    }
    clearScreenButton = new Button(0, 0, 100, 100);
    canva = new Canva(renderer, WINDOW_WIDTH, WINDOW_HEIGHT);
    if(!canva)
    {
        printf("failed to initialize canva!\n");
    }
    temporalX = -1;
    temporalY = -1;

}
// bool Instance::init()
// {
    
// }
void Instance::handleInput()
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
      
        }
        else if(event.type == SDL_MOUSEBUTTONUP)
        {
            isMouseHoldDown = false;
            isDrawing = false;            
        }
    }
}
void Instance::render()
{    
    clearScreen();
    SDL_RenderCopy(renderer, canva->getCanvaTex(), NULL, NULL);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    if(drawMode == RECTANGLE)
    {
        SDL_RenderDrawRect(renderer, &tmpRect);
    }
    else if(drawMode == LINE)
    {
        SDL_RenderDrawLine(renderer, tmpLine.x1, tmpLine.y1, tmpLine.x2, tmpLine.y2);  
    }
    
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &clearScreenButton->getCollision());
    SDL_RenderPresent(renderer);
}
void Instance::update()
{   
    if(commonFunc::checkMouseCollision(mouseX, mouseY, clearScreenButton->getCollision()) && isMouseHoldDown)
    {
        canva->clearCanva(renderer);
    }      
    if(isDrawing) 
    {        
        if(drawMode == POINT)
        {
            canva->update(renderer, mouseX, mouseY);
        }
        else if(drawMode == RECTANGLE)
        {
            if(temporalX == -1 && temporalY == -1)
            {
                temporalX = mouseX;
                temporalY = mouseY;
            }
            tmpRect = {temporalX, temporalY, mouseX - temporalX, mouseY - temporalY};
            // printf("%d %d %d %d\n", tmpRect.x, tmpRect.y, tmpRect.w, tmpRect.h);
        }
        else
        {
            if(temporalX == -1 && temporalY == -1)
            {
                temporalX = mouseX;
                temporalY = mouseY;
            }
            tmpLine = {temporalX, temporalY, mouseX, mouseY};
        }
    }
    else
    {
        canva->update(renderer, -1, -1);
    }
}
void Instance::run()
{   
    while(isRunning)
    {
        
        handleInput();
        update();
        render();
    }
}
void Instance::cleanup()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
}
void Instance::clearScreen()
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
}
