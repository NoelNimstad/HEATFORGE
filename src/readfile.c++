#include "readfile.h"

std::vector<std::wstring> Heatforge::ReadFile(const char * path)
{
    std::wifstream file;
    file.open(path);
    std::vector<std::wstring> result;
    std::wstring value;

    if(file.is_open())
    {
        while(std::getline(file, value))
        {
            result.push_back(value);
        }
        file.close();
    }

    return result;
}