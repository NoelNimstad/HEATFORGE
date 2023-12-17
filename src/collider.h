#pragma once

#include <iostream>
#include <vector>

#include "vector.h"

namespace Heatforge
{
    class Collider 
    {
        public:
            Collider(Vector2 * position, Vector2 * size)
                : position(position), size(size) {};
            
            bool isColliding;
            bool CalculateCollisions(std::vector<Collider*> * col);
            std::vector<Collider*> colliders;
        private:
            Vector2 * position;
            Vector2 * size;
    };
}