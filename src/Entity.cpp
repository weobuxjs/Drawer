#include "Entity.h"
Entity::Entity(int x, int y, int w, int h, Texture* pTex)
{
    collision = {x, y, w, h};
    texture = pTex;
    active = true;
}
void Entity::SetActive(bool active)
{
    this->active = active;
}
bool Entity::GetActive()
{
    return active;
}