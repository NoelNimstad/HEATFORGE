#pragma once

#include <iostream>
#include <sstream>
#include <vector>

#include "heatforge.h"
#include "vector.h"
#include "font.h"

namespace Heatforge 
{
    class Text 
    {
        public:
            Text(std::wstring string, Font * font, int x, int y)
                : position(x, y), font(font), intArray(font -> ConvertStringToIntArray(string)) {};

            void Draw();
            void ChangeText(std::wstring);
        private:
            Font * font;
            std::vector<int> intArray;
            Vector2 position;
    };
}