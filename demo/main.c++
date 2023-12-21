#include <iostream>

#include "../src/heatforge.h"
#include "../src/lfont.h"
#include "../src/text.h"

Heatforge::Heatforge _("日本語", 400, 300, 3, 16);

Heatforge::Spritesheet MiniStadJPAtlas = _.LoadSpritesheet("../Resources/MiniStadJPAtlas.png", 10, 10);
Heatforge::LFont MiniStadJP(&MiniStadJPAtlas);

Heatforge::Text label(L"あおいおう\nあおあお", &_, &MiniStadJP, 20, 20);

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