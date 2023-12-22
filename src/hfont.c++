#include "hfont.h"

Heatforge::HFont::HFont(std::string path)
{
    std::vector<std::wstring> info = Heatforge::ReadFile((path + "/info.txt").c_str());

    if(info.size() < 3)
    {
        std::cout << "font " << path << " does not contain sufficient information!";
        exit(1);
    }

    std::wstring tileWidth = info.at(0);
    std::wstring tileHeight = info.at(1);
    info.erase(info.begin(), info.begin() + 2);

    try 
    {
        x = std::stoi(tileWidth);
        y = std::stoi(tileHeight);
    } catch(const std::invalid_argument & e)
    {
        std::cout << e.what();
        exit(1);
    } catch(const std::out_of_range & e)
    {
        std::cout << e.what(); 
        exit(1);
    }

    contents = info;
}