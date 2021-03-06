#include "HitboxComponent.h"

namespace SSEngine
{

    HitboxComponent::HitboxComponent( GameDataRef data, sf::Sprite& sprite,
            const float& offset_x, const float& offset_y,
            const float& width, const float& height ) :
            m_Data( std::move( data ) ), m_Sprite( sprite ), m_OffsetX( offset_x ), m_OffsetY( offset_y )
    {

        m_ShiftX = (m_Sprite.getGlobalBounds().width - width) / 2.f ;
        // Debug( x_shift )
        m_Hitbox.setPosition( m_Sprite.getPosition().x + offset_x - m_ShiftX, m_Sprite.getPosition().y + offset_y );
        // m_Hitbox.setOrigin( m_Sprite.getOrigin() );

        m_Hitbox.setSize( sf::Vector2f( width, height ) );
        m_Hitbox.setFillColor( sf::Color::Transparent );
        m_Hitbox.setOutlineThickness( 1.f );
        m_Hitbox.setOutlineColor( sf::Color::Magenta );

        Debug( "--For sprite position--" )
        Debug( m_Sprite.getPosition().x )
        Debug( m_Sprite.getPosition().y )
        Debug( "--For sprite global bounds--" )
        Debug( m_Sprite.getGlobalBounds().left )
        Debug( m_Sprite.getGlobalBounds().top )
        Debug( m_Sprite.getGlobalBounds().width )
        Debug( m_Sprite.getGlobalBounds().height )
        Debug( "--For sprite origin--" )
        Debug( m_Sprite.getOrigin().x )
        Debug( m_Sprite.getOrigin().y )
        Debug( "--For hitbox--" )
        Debug( m_Hitbox.getPosition().x )
        Debug( m_Hitbox.getPosition().y )
        Debug( "--For hitbox global bounds--" )
        Debug( m_Hitbox.getGlobalBounds().left )
        Debug( m_Hitbox.getGlobalBounds().top )
        Debug( m_Hitbox.getGlobalBounds().width )
        Debug( m_Hitbox.getGlobalBounds().height )
        Debug( "--For hitbox origin--" )
        Debug( m_Hitbox.getOrigin().x )
        Debug( m_Hitbox.getOrigin().y )

        Debug( "Hitbox component created" )
    }

    HitboxComponent::~HitboxComponent()
    {

    }

    bool HitboxComponent::CheckIntersects(const sf::FloatRect& rect)
    {
        return m_Hitbox.getGlobalBounds().intersects( rect );
    }

    void HitboxComponent::Update()
    {
        m_Hitbox.setPosition( m_Sprite.getPosition().x + m_OffsetX + m_ShiftX,
                m_Sprite.getPosition().y + m_OffsetY );
    }

    void HitboxComponent::Draw()
    {
        m_Data->window.draw( m_Hitbox );
    }
}