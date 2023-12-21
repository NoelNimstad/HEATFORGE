#pragma once

#include <iostream>
#include <sstream>
#include <vector>

#include "heatforge.h"
#include "vector.h"
#include "lfont.h"

namespace Heatforge 
{
    class Text 
    {
        public:
            Text(std::wstring string, Heatforge * engine, LFont * font, int x, int y)
                : engine(engine), position(x, y), font(font), intArray(engine -> ConvertStringToIntArray(string)) {};

            void Draw();
            void ChangeText(std::wstring);
        private:
            Heatforge * engine;
            LFont * font;
            std::vector<int> intArray;
            Vector2 position;
    };
}