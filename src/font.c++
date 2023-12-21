#include "font.h"

void Heatforge::Font::Draw(std::vector<int> * intArray, Vector2 * position)
{
    int initial = position -> x;

    for(const int & i : (*intArray))
    {
        spritesheet -> SelectSprite(i);
        spritesheet -> SetPosition(initial, position -> y);
        spritesheet -> Draw();
        initial += spritesheet -> width;
    }
}