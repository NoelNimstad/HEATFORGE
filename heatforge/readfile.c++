#include "readfile.h"

std::vector<std::string> Heatforge::ReadFile(char const * path)
{
    std::ifstream file;
    file.open(path);
    std::vector<std::string> result;
    std::string value;

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