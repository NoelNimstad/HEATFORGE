#pragma once 

#include <iostream>
#include <math.h>

namespace Heatforge 
{
    class Vector2 
    {
        public:
            Vector2(float x, float y)
                : x(x), y(y) {};
            float x;
            float y;
            void Zero();

            Vector2 operator+(const Vector2 & other)
            {
                return Vector2(other.x + this -> x, other.y + this -> y);
            }

            Vector2 operator+=(const Vector2 & other)
            {
                this -> x += other.x;
                this -> y += other.y;
                return * this;
            }

            Vector2 operator-(const Vector2 & other)
            {
                return Vector2(other.x - this -> x, other.y - this -> y);
            }

            Vector2 operator-=(const Vector2 & other)
            {
                this -> x -= other.x;
                this -> y -= other.y;
                return * this;
            }

            Vector2 operator*(const float & other)
            {
                return Vector2(this -> x * other, this -> y * other);
            }

            Vector2 operator*=(const float & other)
            {
                this -> x *= other;
                this -> y *= other;
                return * this;
            }

            Vector2 operator/(const float & other)
            {
                return Vector2(this -> x / other, this -> y / other);
            }

            Vector2 operator/=(const float & other)
            {
                this -> x /= other;
                this -> y /= other;
                return * this;
            }

            Vector2 operator!()
            {
                return Vector2(this -> x * -1, this -> y * -1);
            }

            float operator--()
            {
                return sqrtf((this -> x * this -> x) + (this -> y * this -> y));
            }

            Vector2 operator()()
            {
                if(this -> x == 0 && this -> y == 0)
                {
                    return Vector2(0, 0);
                }

                Vector2 copy(this -> x, this -> y);
                return copy / --copy;
            }

            float operator*(const Vector2 & other)
            {
                return (this -> x * other.x) + (this -> y * other.y);
            }
    };
}