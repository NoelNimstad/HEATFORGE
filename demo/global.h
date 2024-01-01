#pragma once
#include <iostream>

#include "../src/getpath.h"
std::string path = Heatforge::GetPath().string() + "/";

#include "../src/heatforge.h"
Heatforge::Heatforge _("Demo", 320, 240, 3, 2);

#include "../src/font.h"
Heatforge::Font MiniStad((path + "../Resources/MiniStad.hfont").c_str(), &_);

#include "../src/text.h"
Heatforge::Text dtext(L"something went wrong", &MiniStad, 100, 100);