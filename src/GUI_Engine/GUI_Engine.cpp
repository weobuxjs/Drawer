#include "GUI_Engine.h"
namespace GUI
{
    
    Window* window = NULL;
    Renderer* renderer = NULL;
    ColorKey currColor = {255, 255, 255, 255};
    int checkConnection;
    void Init(const char* title, int windowWidth, int windowHeight)
    {
        SDL_Init(SDL_INIT_EVERYTHING);
        window = SDL_CreateWindow(title, 
                                SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
                                windowWidth, windowHeight, 
                                SDL_WINDOW_SHOWN);
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        if(!window)
        {
            printf("Failed to init window\n");
        }
        if(!renderer)
        {
            printf("Failed to init renderer\n");    
        }
    }
    void Render(Entity* entity)
    {
        if(entity->GetActive())
        {
            SDL_RenderCopy(renderer, 
                entity->GetTexture(), 
                nullptr, entity->GetCollision());  
        }
 
    }
    void Render(Texture *tex, Rect *src, Rect *dst, int rotation, RendererFlip flipState)
    {
        Point center;
        Point* ptr = NULL;
        if(dst != NULL)
        {
            center = Point{dst->x + dst->w / 2, dst->y + dst->h / 2};
            ptr = &center;
        }   
        SDL_RenderCopyEx(renderer, tex, src, dst, rotation, ptr, flipState);
    }
    void ClearScreen()
    {
        SDL_RenderClear(renderer);
    }
    void DrawLine(int x1, int y1, int x2, int y2)
    {
        SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
    }
    void DrawRect(int x, int y, int w, int h)
    {
        Rect tmp = {x, y, w, h};
        SDL_RenderDrawRect(renderer, &tmp);
    }
    void SetColor(int r, int g, int b, int a)
    {
        currColor.r = r;
        currColor.g = g;
        currColor.b = b;
        currColor.a = a;
        SDL_SetRenderDrawColor(renderer, currColor.r, currColor.g, currColor.b, currColor.a);
    }
    Texture* CreateTexture(int width, int height)
    {
        Texture* tex = SDL_CreateTexture(renderer, 
            SDL_PIXELFORMAT_RGBA8888, 
            SDL_TEXTUREACCESS_TARGET, 
            width, height);
        return tex;
    }
    void RenderPresent()
    {
        SDL_RenderPresent(renderer);
    }
    void DrawPoint(int x, int y)
    {
        SDL_RenderDrawPoint(renderer, x, y);
    }
    void DrawCircle(int x, int y, float r, float precision)
    {
        for(float theta = 0; theta < 360; theta += precision)
        {
            DrawPoint(x + r * cos(theta * 3.14 / 180) , y + r * sin(theta* 3.14 / 180));
        }
    }
    void SetRenderTarget(Texture* renderTarget)
    {
        SDL_SetRenderTarget(renderer, renderTarget);
    }
    void CleanUp()
    {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
    }
    void DrawRect(Rect rect)
    {
        Rect tmp = rect;
        SDL_RenderDrawRect(renderer, &rect);
    }
    Texture* GetRenderTarget()
    {
        return SDL_GetRenderTarget(renderer);
    }

    void (*BindColor)(int r, int g, int b, int a) = SetColor;
    void (*BindRenderTarget)(Texture* renderTarget) = SetRenderTarget;
}

