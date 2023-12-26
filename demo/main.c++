#include <iostream>

#include "../src/heatforge.h"
#include "../src/font.h"
#include "../src/text.h"

Heatforge::Heatforge _("RPG Demo", 320, 240, 3, 16);

Heatforge::Font MiniStad("../Resources/MiniStad.hfont", &_);

Heatforge::Text label(L"abcdefghijklmnopqrstuvwxyz0123456789:-+.!?%=&", &MiniStad, 277, 223);

bool debug = false;
void Debug()
{
    if(_.inputs[_.keys['d']])
    {
        debug = !debug;
    }
    
    _.Clear();

    if(debug)
    {

        std::wstringstream ss; 
        ss << L"d: " << _.delta << L"ms\nv: 0.6.1a";

        label.ChangeText(ss.str());
        label.Draw();
    }

    _.Update();   
}

int main()
{
    _.Hook(&Debug);

    _.Start();
    _.End();

    return 0;
}