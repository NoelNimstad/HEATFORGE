#pragma once
#include <sstream>
#include "global.h"

bool debug = false;
bool debugKeyDown = false;
void Debug()
{
    bool d = _.GetKey(L"d");

    if(d && !debugKeyDown)
    {
        debugKeyDown = true;
        debug = !debug;
    } if(!d)
    {
        debugKeyDown = false;
    }

    if(debug)
    {
        std::wstringstream ss; 
        ss << L"d: " << _.delta << L"ms\nv: 0.6.1a";

        dtext.ChangeText(ss.str());
        dtext.Draw();
    }
}