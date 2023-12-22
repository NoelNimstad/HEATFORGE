#pragma once 

#include <vector>
#include <iostream>
#include <unordered_map>

#include "spritesheet.h"
#include "vector.h"
#include "hfont.h"
#include "heatforge.h"
#include "readfile.h"

namespace Heatforge
{
    class Font
    {
        public:
            Font(const char * path, Heatforge * engine)
                : hfont(path), spritesheet(engine -> LoadSpritesheet(hfont.location.c_str(), hfont.x, hfont.y)) 
            {
                CHAR_MAP.insert({ L' ', -2 });
                CHAR_MAP.insert({ L'\n', -1 });
                CHAR_MAP.insert({ L'あ', 0 });
            };

            void Draw(std::vector<int> * intArray, Vector2 * position);
            std::vector<int> ConvertStringToIntArray(std::wstring string);
        private:
            HFont hfont;
            Spritesheet spritesheet;
            std::unordered_map<wchar_t, int> CHAR_MAP;
    };
}