#ifndef HITBOX_COMPONENT_H
#define HITBOX_COMPONENT_H

#include <SFML/Graphics.hpp>
#include "../Game.h"
/*
 * Create a box around our sprite
 * Easy to manage sprite positions and collisions
 */

namespace SSEngine
{
    /* Forward declaration */
    struct GameData;
    typedef std::shared_ptr<GameData> GameDataRef;

    class HitboxComponent
    {
    private:
        GameDataRef m_Data;

        sf::Sprite& m_Sprite;
        sf::RectangleShape m_Hitbox;

        float m_OffsetX;
        float m_OffsetY;

        float m_ShiftX;

    public:
        HitboxComponent( GameDataRef data, sf::Sprite& sprite,
                const float& offset_x, const float& offset_y,
                const float& width, const float& height );
        virtual ~HitboxComponent();

        /* Functions */
        bool CheckIntersects( const sf::FloatRect& rect );

        void Update ( );
        void Draw();
    };
}

#endif //HITBOX_COMPONENT_H
