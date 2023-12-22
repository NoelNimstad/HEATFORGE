#pragma once

#include <vector>
#include <iostream>
#include <unordered_map>

#include "readfile.h"

namespace Heatforge
{
    class HFont
    {
        public:
            HFont(std::string path);
            std::vector<std::wstring> contents;
            int x;
            int y;
    };
}