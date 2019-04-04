#include "Entity.h"
#include "DEFINITIONS.h"
#include <iostream>

namespace MarioEngine
{
    Entity::Entity( GameDataRef data ) : m_Data( std::move( data ) )
    {
        std::clog << "Entity" << std::endl;
        m_Shape.setSize( sf::Vector2f( 50.0f, 50.0f ) );
        m_Shape.setFillColor( sf::Color::White );
        m_MovementSpeed = ENTITY_MOVEMENT_SPEED;

        upPressed = downPressed = leftPressed = rightPressed = false;
    }

    void Entity::Move(const float& dt, const float dir_x, const float dir_y)
    {
        m_Shape.move( dir_x * m_MovementSpeed * dt, dir_y * m_MovementSpeed * dt );
    }

    void Entity::Update(float dt)
    {
        if ( leftPressed )
        {
            Move( dt, -1.0f, 0.0f );
        }
        if ( rightPressed )
        {
            Move( dt, 1.0f, 0.0f );
        }
        if ( upPressed )
        {
            Move( dt, 0.0f, -1.0f );
        }
        if ( downPressed )
        {
            Move( dt, 0.0f, 1.0f );
        }
    }

    void Entity::Draw()
    {
        m_Data->window.draw( m_Shape );
    }

    void Entity::MoveUp()
    {
        upPressed = true;
    }

    void Entity::MoveLeft()
    {
        leftPressed = true;
    }

    void Entity::MoveDown()
    {
        downPressed = true;
    }

    void Entity::MoveRight()
    {
        rightPressed = true;
    }

    void Entity::StopUp()
    {
        upPressed = false;
    }

    void Entity::StopLeft()
    {
        leftPressed = false;
    }

    void Entity::StopDown()
    {
        downPressed = false;
    }

    void Entity::StopRight()
    {
        rightPressed = false;
    }
}