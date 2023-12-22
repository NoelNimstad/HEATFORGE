#pragma once 

#include <vector>
#include <iostream>
#include <sstream>
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
            Font(std::string path, Heatforge * engine)
                : hfont(path), spritesheet(engine -> LoadSpritesheet((path + "/atlas.png").c_str(), hfont.x, hfont.y)) 
            {
                CHAR_MAP.insert({ L' ', -2 });
                CHAR_MAP.insert({ L'\n', -1 });

                for(const auto & line : hfont.contents)
                {
                    std::vector<std::wstring> parts;
                    std::wstringstream lineStream = std::wstringstream(line);
                    std::wstring segment;

                    while(std::getline(lineStream, segment, L' '))
                    {
                        parts.push_back(segment);
                    }

                    std::cout << parts.size() << std::endl;

                    int index;
                    try 
                    {
                        index = std::stoi(parts.at(1));
                    } catch(const std::invalid_argument & e)
                    {
                        std::cout << e.what();
                        exit(1);
                    } catch(const std::out_of_range & e)
                    {
                        std::cout << e.what(); 
                        exit(1);
                    }

                    std::wcout << L"おはよう" << std::endl;
                }
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