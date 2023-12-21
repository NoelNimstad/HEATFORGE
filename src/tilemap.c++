#include "tilemap.h"

Heatforge::Tilemap::Tilemap(Heatforge::Spritesheet * ss, const char * path)
{
    spritesheet = ss;
    std::vector<std::wstring> tiledata(Heatforge::ReadFile(path));

    for(const auto& line : tiledata)
    {
        std::vector<std::wstring> parts;
        std::wstringstream lineStream = std::wstringstream(line);
        std::wstring segment;

        while(std::getline(lineStream, segment, L'|'))
        {
            parts.push_back(segment);
        }

        tiles.push_back(Heatforge::Tile(std::stoi(parts.at(0)), std::stoi(parts.at(1)), std::stoi(parts.at(2))));
    }
}

void Heatforge::Tilemap::Draw()
{
    for(const auto& tile : tiles)
    {
        spritesheet -> SelectSprite(tile.id);
        spritesheet -> SetPosition(tile.x, tile.y);
        spritesheet -> Draw();
    }
}