#pragma once

#include <SFML/Graphics.hpp>
#include "Game.h"

namespace MarioEngine
{
    class Entity
    {
    private:
        GameDataRef m_Data;

        bool upPressed;
        bool downPressed;
        bool leftPressed;
        bool rightPressed;

    protected:
        sf::RectangleShape m_Shape;
        float m_MovementSpeed;

    public:
        Entity( GameDataRef data );
        ~Entity() {};

        virtual void Move( const float& dt, const float dir_x, const float dir_y );

        virtual void Update( float dt );
        virtual void Draw();

        void MoveUp();
        void MoveLeft();
        void MoveDown();
        void MoveRight();

        void StopUp();
        void StopLeft();
        void StopDown();
        void StopRight();
    };
}