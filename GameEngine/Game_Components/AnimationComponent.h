#ifndef ANIMATIONCOMPONENT_H
#define ANIMATIONCOMPONENT_H

#include "../Game.h"
#include "../DEFINITIONS.h"

#include <SFML/Graphics.hpp>

namespace SSEngine
{
    class AnimationComponent
    {
    private:
        class Animation
        {
        public:
            sf::Sprite& sprite;
            sf::Texture& m_TextureSheet;
            float animationTimer;
            float timer;
            bool m_Done;
            int width;
            int height;
            sf::IntRect m_StartRect;
            sf::IntRect m_CurrentRect;
            sf::IntRect m_EndRect;

            /*
             * @sprite: Sprite on which animation is to be done
             * @texture_sheet: Use which texture for the animation
             * @animation_timer: Speed of animation
             * @start_frame_x: index of starting frame in X axis
             * @start_frame_y: index of starting frame in Y axis
             * @frames_x: number of frames after start frame
             * @frame_y: number of frames after start frame
             * @width: width of tile in texture sheet
             * @height: height of tile in texture sheet
            */
            Animation( sf::Sprite& sprite, sf::Texture& texture_sheet,
                    float animation_timer,
                    int start_frame_x, int start_frame_y, int frames_x, int frames_y,
                    int width, int height) :
                    sprite( sprite ), m_TextureSheet( texture_sheet ),
                    animationTimer( animation_timer ), timer( 0.f ), m_Done( false ),
                    width( width ), height( height )
            {
                m_StartRect = sf::IntRect( start_frame_x * width,
                        start_frame_y * height, width, height );

                m_CurrentRect = m_StartRect;
                m_EndRect = sf::IntRect( (start_frame_x + frames_x) * width,
                        (start_frame_y + frames_y) * height, width, height );

                sprite.setTexture( m_TextureSheet, true );
                sprite.setTextureRect( m_StartRect );
            }

            // Accessor
            const bool& isDone() const
            {
                return m_Done;
            }

            // Functions
            const bool& play( const float& dt )
            {
                // Update timer
                m_Done = false;
                timer += 100.f * dt;
                if ( timer >= animationTimer )
                {
                    // reset timer
                    timer = 0.f;

                    if (m_CurrentRect != m_EndRect)
                    {
                        m_CurrentRect.left += width;
                    }
                    else //Reset
                    {
                        m_CurrentRect.left = m_StartRect.left;
                        m_Done = true;
                    }

                    sprite.setTextureRect( m_CurrentRect );
                }
                return m_Done;
            }

            const bool& play(const float& dt, float mod_percent)
            {
                //Update timer
                if (mod_percent < 0.5f)
                    mod_percent = 0.5f;

                m_Done = false;
                timer += mod_percent * 100.f * dt;
                if (timer >= animationTimer)
                {
                    //reset timer
                    timer = 0.f;

                    //Animate
                    if (m_CurrentRect != m_EndRect)
                    {
                        m_CurrentRect.left += width;
                    }
                    else //Reset
                    {
                        m_CurrentRect.left = m_StartRect.left;
                        m_Done = true;
                    }

                    sprite.setTextureRect(m_CurrentRect);
                }

                return m_Done;
            }

            void reset()
            {
                timer = animationTimer;
                m_CurrentRect = m_StartRect;
            }
        };

        sf::Sprite& m_Sprite;
        sf::Texture& m_TextureSheet;

        std::map<std::string, Animation*> m_Animations;
        Animation* m_LastAnimation;
        Animation* m_PriorityAnimation;

    public:
        AnimationComponent(sf::Sprite& sprite, sf::Texture& texture);
        virtual ~AnimationComponent();

        /* Accessor */
        const bool& isDone( const std::string& key );

        /* Functions */
        void AddAnimation( const std::string& key,
                float animation_timer,
                int start_frame_x, int start_frame_y,
                int frames_x, int frame_y, int width, int height );

        const bool& Play(const std::string &key, const float &dt, const bool &priority = false);
        const bool& play(const std::string& key, const float& dt, const float& modifier, const float& modifier_max, const bool priority = false);

    };
}


#endif // ANIMATIONCOMPONENT_H
