#pragma once
#include <SDL2/SDL.h>
#include <math.h>
#include "../Renaming.h"
#include "../Entity.h"

#ifdef GUI_ENGINE_IMPORT
#define GUI_ENGINE_API __declspec(dllimport)
#else
#define GUI_ENGINE_API __declspec(dllexport)
#endif

namespace GUI
{
    extern GUI_ENGINE_API Window* window;
    extern GUI_ENGINE_API Renderer* renderer;
    extern GUI_ENGINE_API ColorKey currColor;
    extern GUI_ENGINE_API Texture* defaultRenderTarget;
    extern GUI_ENGINE_API int checkConnection;
    GUI_ENGINE_API void Init(const char* title, int windowWidth, int windowHeight);
    GUI_ENGINE_API void Render(Entity* entity);
    GUI_ENGINE_API void Render(Texture *tex, Rect *src, Rect *dst, int rotation, RendererFlip flipState);
    GUI_ENGINE_API void ClearScreen();
    GUI_ENGINE_API void DrawLine(int x1, int y1, int x2, int y2);
    GUI_ENGINE_API void DrawRect(int x, int y, int w, int h);
    GUI_ENGINE_API void DrawRect(Rect rect);
    GUI_ENGINE_API void DrawPoint(int x, int y);
    GUI_ENGINE_API void DrawCircle(int x, int y, float r, float precision = 0.1);
    GUI_ENGINE_API void RenderPresent();
    GUI_ENGINE_API void CleanUp();
    GUI_ENGINE_API void SetColor(int r, int g, int b, int a);
    GUI_ENGINE_API void SetDefaultRenderTarget(Texture* renderTarget);
    GUI_ENGINE_API Texture* GetRenderTarget();
    extern GUI_ENGINE_API void (*BindColor)(int r, int g, int b, int a);
    GUI_ENGINE_API void SetRenderTarget(Texture* renderTarget);
    extern GUI_ENGINE_API void (*BindRenderTarget)(Texture* renderTarget);
    GUI_ENGINE_API Texture* CreateTexture(int width, int height);
}
