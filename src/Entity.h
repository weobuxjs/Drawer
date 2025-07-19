#pragma once
#include "Renaming.h"
class Entity
{
public:
    Entity(int x, int y, int w, int h, Texture* pTex);
    int& GetX(){return collision.x;};
    int& GetY(){return collision.y;};
    Rect* GetCollision(){return &collision;};
    Texture* GetTexture(){return texture;};
    void SetX(int pX){collision.x = pX;}
    void SetY(int pY){collision.y = pY;}
    void SetActive(bool active);
    bool GetActive();
protected:
    Rect collision;
    Texture* texture;
    bool active;
};
