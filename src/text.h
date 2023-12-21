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
            Text(std::string string, Heatforge * engine, Font * font, int x, int y)
                : engine(engine), position(x, y), font(font), intArray(engine -> ConvertStringToIntArray(string)) {};

            void Draw();
            void ChangeText(std::wstring);
        private:
            Heatforge * engine;
            Font * font;
            std::vector<int> intArray;
            Vector2 position;
    };
}