#ifndef GUI_ENGINE_H
#define GUI_ENGINE_H
#include <SDL2/SDL.h>
#include "../Entity.h"
static SDL_Window* window = NULL;
static SDL_Renderer* renderer = NULL;
void Init(const char* title, int wndowWidth, int windowHeight, int windowPosX, int windowPosY);
void render(Entity* entity);
void render(SDL_Texture *tex, SDL_Rect *src, SDL_Rect *dst, int rotation);
void clearScreen(SDL_Color screenColor = {255, 255, 255, 255});

#endif