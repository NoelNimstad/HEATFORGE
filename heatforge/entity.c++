#include "entity.h"

void Heatforge::Entity::Draw()
{
    spritesheet -> SetPosition((int)(position -> x), (int)(position -> y));
    spritesheet -> Draw();
}