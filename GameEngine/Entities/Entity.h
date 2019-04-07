#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

#include "../Game.h"
#include "../Game_Components/MovementComponent.h"
#include "../Game_Components/AnimationComponent.h"
#include <memory>

namespace SSEngine
{
    // Forward declaring the class to let the compiler know about its existence.
    class AnimationComponent;
    class MovementComponent;

    class Entity
    {
    protected:
        sf::Sprite m_Sprite;

        MovementComponent* m_MC;
        AnimationComponent* m_AC;

    public:
        /* Constructors and Destructors*/
        Entity( );
        virtual ~Entity();

        /* Component functions */
        void SetTexture( sf::Texture& tex );
        void CreateMovementComponent( const float& maxVelocity, const float& acceleration, const float& deceleration );
        void CreateAnimationComponent( sf::Texture& texture );

        /* Functions */
        virtual void SetPosition(sf::Vector2f position );

        virtual void Move( const float& dt, const float& dir_x, const float& dir_y );
        virtual void Update( float dt );
        virtual void Draw();
    };
}

#endif // ENTITY_H