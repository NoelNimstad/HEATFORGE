#include "hfont.h"

Heatforge::HFont::HFont(const char * path)
{
    std::vector<std::wstring> file = Heatforge::ReadFile(path);

    if(file.size() < 4)
    {
        std::cout << "font " << path << " does not contain sufficient information!";
        exit(1);
    }

    std::wstring tileWidth = file.at(0);
    std::wstring tileHeight = file.at(1);
    std::wstring pathInformation = file.at(2);
    file.erase(file.begin(), file.begin() + 3);
    
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
}