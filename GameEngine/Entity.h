#pragma once

#include <SFML/Graphics.hpp>
#include "Game.h"

namespace SSEngine
{
    class Entity
    {
    /*private:
        GameDataRef m_Data;*/

        /*bool upPressed;
        bool downPressed;
        bool leftPressed;
        bool rightPressed;*/

    /*protected:
        sf::Sprite m_Sprite;

        float m_MovementSpeed;*/

    public:
        // Entity( GameDataRef data );
        // ~Entity() {};

        virtual void Move( const float& dt, const float& dir_x, const float& dir_y ) = 0;

        // virtual void HandleInput() = 0;

        virtual void Spawn( sf::Vector2f startPos ) = 0;

        virtual void Update( float dt ) = 0;
        virtual void Draw() = 0;

        /* All movement specific to characters with their specific properties */
        /*void MoveUp();
        void MoveLeft();
        void MoveDown();
        void MoveRight();

        void StopUp();
        void StopLeft();
        void StopDown();
        void StopRight();*/
    };
}