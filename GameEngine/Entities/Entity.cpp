#include "Entity.h"

namespace SSEngine
{
    /* Constructors & Destructors */
    Entity::Entity( )
    {
        m_MC = nullptr;
    }

    Entity::~Entity()
    {
        delete m_MC;
    }

    /* Component functions */
    void Entity::SetTexture( sf::Texture& tex )
    {
        m_Sprite.setTexture( tex );
        m_Sprite.scale( 2.0f, 2.0f );
    }

    void Entity::CreateMovementComponent(const float& maxVelocity, const float& acceleration, const float& deceleration )
    {
        m_MC = new MovementComponent( m_Sprite, maxVelocity, acceleration, deceleration );
    }

    /* Functions */
    void Entity::SetPosition(sf::Vector2f position )
    {
        m_Sprite.setPosition( position );
    }

    void Entity::Move(const float &dt, const float &dir_x, const float &dir_y)
    {
        if ( m_MC )
        {
            m_MC->Move( dt, dir_x, dir_y);
        }
        // m_Sprite.move( m_MC->GetVelocity() * dt );
    }

    void Entity::Update(float dt)
    {

    }

    void Entity::Draw()
    {
    }
}