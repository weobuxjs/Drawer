#ifndef ENTITY_H
#define ENTITY_H
#include <SDL2/SDL.h>
class Entity
{
public:
    Entity(int x, int y, int w, int h, SDL_Texture* pTex);
    int& getX(){return collision.x;};
    int& getY(){return collision.y;};
    SDL_Rect &getCollision(){return collision;};
    void setX(int pX){collision.x = pX;}
    void setY(int pY){collision.y = pY;}
private:
    SDL_Rect collision;
    SDL_Texture* tex;
};
#endif
