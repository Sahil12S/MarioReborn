#pragma once

#include <SFML/Graphics.hpp>

namespace SSEngine
{
    class Entity
    {
    public:
        virtual void Spawn( sf::Vector2f startPos ) = 0;

        virtual void Move( const float& dt, const float& dir_x, const float& dir_y ) = 0;

        virtual void Update( float dt ) = 0;

        virtual void Draw() = 0;
    };
}