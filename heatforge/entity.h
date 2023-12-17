#pragma once

#include "spritesheet.h"
#include "vector.h"
#include "collider.h"

namespace Heatforge
{
    class Entity 
    {
        public:
            Entity(Spritesheet * spritesheet, Vector2 * position)
                : spritesheet(spritesheet), position(position), size(spritesheet -> width, spritesheet -> height), collider(position, &size)
            {
                spritesheet -> SelectSprite(0);
            };
            Spritesheet * spritesheet;
            Vector2 * position;
            
            void Draw();

            Vector2 size;
            Collider collider;
        private:
    };
}