#include "tilemap.h"

Heatforge::Tilemap::Tilemap(Heatforge::Spritesheet * ss, char const * path)
{
    spritesheet = ss;
    std::vector<std::string> tiledata(Heatforge::ReadFile(path));

    for(const auto& line : tiledata)
    {
        std::vector<std::string> parts;
        std::stringstream lineStream = std::stringstream(line);
        std::string segment;

        while(std::getline(lineStream, segment, '|'))
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