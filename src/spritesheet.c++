#include "spritesheet.h"

void Heatforge::Spritesheet::SelectSprite(int index)
{
    selection.x = (index % rows) * width;
    selection.y = (floor(index / rows)) * height;
    selection.w = width;
    selection.h = height;
}

void Heatforge::Spritesheet::SetPosition(int x, int y)
{
    position.x = x * scale;
    position.y = y * scale;
    position.w = selection.w * scale;
    position.h = selection.h * scale;
}

void Heatforge::Spritesheet::Draw()
{
    SDL_RenderCopy(renderer, texture, &selection, &position);
}