//<--------------------START OF FILE-------------------->
#include "Instance.h"
Instance::Instance()
{
    isRunning = true;
    isMouseHoldDown = false;
    isDrawing = false;
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
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &clearScreenButton->getCollision());
    SDL_RenderPresent(renderer);
}
void Instance::update()
{   
    if(commonFunc::checkMouseCollision(mouseX, mouseY, clearScreenButton->getCollision()))
    {
        canva->clearCanva(renderer);
    }      
    if(isDrawing) 
    {        
        canva->update(renderer, mouseX, mouseY);
        // printf("Drawing\n");
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
// void Instance::deleteOverlapedPixel()
// {
//     for(int i = 0; i < pixel.size(); i++)
//     {
//         SDL_Rect* A = &pixel[i];
//         if(!A) 
//         {
//             continue;
//         }
//         for(int j = i + 1; j < pixel.size(); j++)
//         {
//             SDL_Rect* B = &pixel[j];
//             if(!B)
//             {
//                 continue;
//             }
//             if(A->x == B->x && A->y == B->y)
//             {
//                 pixel.erase(pixel.begin() + i);
//                 i--;
//             }
//         }
//     }
// }
void Instance::clearScreen()
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
}

//<--------------------END OF FILE-------------------->