//<--------------------START OF FILE-------------------->
#include "Instance.h"
Instance::Instance()
{
    isRunning = true;
    isMouseHoldDown = false;
    isDrawing = false;
    window = SDL_CreateWindow("Drawer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC ); 
    clearScreenButton = new Button(0, 0, 100, 100);
    Canva(renderer, WINDOW_WIDTH, WINDOW_HEIGHT);
}
// bool Instance::init()
// {
    
// }
void Instance::handleInput()
{
    while(SDL_PollEvent(&event))
    {
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
        if(event.type == SDL_MOUSEMOTION)
        {
            SDL_GetMouseState(&mouseX, &mouseY);
            if(isDrawing)
            {
                // SDL_Rect rect = {mouseX, mouseY, 10, 10};
                // pixel.push_back(rect);
                canva->update(renderer, mouseX, mouseY);
            }
        }
        if(event.type == SDL_MOUSEBUTTONDOWN){
            // if(commonFunc::checkMouseCollision(mouseX, mouseY, clearScreenButton->getCollision()))
            // {
            //     pixel.clear();
            // }
        }
    }
}
void Instance::render()
{    
    clearScreen();

    // SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    // SDL_RenderFillRects(renderer, pixel.data(), pixel.size());
    SDL_RenderCopy(renderer, canva->getCanv(), NULL, NULL);
    
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
    SDL_RenderFillRect(renderer, &clearScreenButton->getCollision());
    
    SDL_RenderPresent(renderer);
}
void Instance::update()
{
    // deleteOverlapedPixel();
    // canva
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
void Instance::deleteOverlapedPixel()
{
    for(int i = 0; i < pixel.size(); i++)
    {
        SDL_Rect* A = &pixel[i];
        if(!A) 
        {
            continue;
        }
        for(int j = i + 1; j < pixel.size(); j++)
        {
            SDL_Rect* B = &pixel[j];
            if(!B)
            {
                continue;
            }
            if(A->x == B->x && A->y == B->y)
            {
                pixel.erase(pixel.begin() + i);
                i--;
            }
        }
    }
}
void Instance::clearScreen(){
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
}

//<--------------------END OF FILE-------------------->