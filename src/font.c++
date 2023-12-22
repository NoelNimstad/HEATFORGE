#include "font.h"

void Heatforge::Font::Draw(std::vector<int> * intArray, Vector2 * position)
{
    Vector2 initial(position -> x, position -> y);

    for(const int & i : (*intArray))
    {
        if(i == -1)
        {
            initial.x = position -> x;
            initial.y += spritesheet.height;
        } else 
        {
            spritesheet.SelectSprite(i);
            spritesheet.SetPosition(initial.x, initial.y);
            spritesheet.Draw();
            initial.x += spritesheet.width;
        }
    }
}

std::vector<int> Heatforge::Font::ConvertStringToIntArray(std::wstring string)
{
    std::vector<int> result;
    result.reserve(string.size());

    for(const wchar_t & c : string)
    {
        auto it = CHAR_MAP.find(c);
        if(it != CHAR_MAP.end())
        {
            result.push_back(it -> second);
        }
        else
        {
            std::cout << c << " is not a valid string character" << std::endl;
        }
    }

    return result;
}