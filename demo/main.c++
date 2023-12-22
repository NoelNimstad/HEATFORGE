#include <iostream>

#include "../src/heatforge.h"
#include "../src/font.h"
#include "../src/text.h"

Heatforge::Heatforge _("日本語", 640, 480, 2, 16);

Heatforge::Font MiniStadJP("../Resources/MiniStadJP.hfont", &_);

Heatforge::Text label(L"ですか、ですが", &MiniStadJP, 20, 20);

void DrawPass()
{
    _.Clear();

    label.Draw();

    _.Update();
}

int main()
{
    _.Hook(DrawPass);

    _.Start();
    _.End();

    return 0;
}