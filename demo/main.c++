#include <iostream>

#include "../src/heatforge.h"
#include "../src/lfont.h"
#include "..src/font.h"
#include "../src/ltext.h"

Heatforge::Heatforge _("日本語", 400, 300, 3, 16);

Heatforge::Spritesheet MiniStadJPAtlas = _.LoadSpritesheet("../Resources/MiniStadJPAtlas.png", 10, 10);
Heatforge::LFont LMiniStadJP(&MiniStadJPAtlas);
Heatforge::Font MiniStadJP("../Resources/MiniStadJP.hfont");

Heatforge::LText label(L"あおいおう\nあおあお", &_, &LMiniStadJP, 20, 20);

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