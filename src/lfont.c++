#include "lfont.h"

void Heatforge::LFont::Draw(std::vector<int> * intArray, Vector2 * position)
{
    Heatforge::Vector2 initial(position -> x, position -> y);

    for(const int & i : (*intArray))
    {
        if(i == -1)
        {
            initial.x = position -> x;
            initial.y += spritesheet -> height;
        } else 
        {
            spritesheet -> SelectSprite(i);
            spritesheet -> SetPosition(initial.x, initial.y);
            spritesheet -> Draw();
            initial.x += spritesheet -> width;
        }
    }
}