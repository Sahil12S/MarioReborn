#pragma once

#include "Entity.h"
#include "../Game.h"
#include "../Game.h"
#include "../DEFINITIONS.h"

/*
    Properties of player
    - Walk
    - Run ( Accelerate )
    - Jump
    - Duck ( only when grown )
    - Die
    - Grow ( Power up )
    - Shoot ( Power )
*/

namespace SSEngine
{
    class Player : public Entity
    {
    private:
        GameDataRef m_Data;

        float m_MovementSpeed;
        float m_RunningFactor;

        bool m_IsJumping;
        bool m_IsFalling;
        bool m_IsMovingLeft;
        bool m_IsMovingRight;
        bool m_IsDucking;
        bool m_IsRunning;
        bool m_IsJumpingLeft;
        bool m_IsJumpingRight;

        bool m_JustJumped = false;

        // bool m_JumpDuration;
        // bool m_TimeThisJump;

        // In which direction is mario facing or walking
        short m_Direction;

        // Player Sprite
        sf::Sprite m_PlayerSprite;

        // Animation controllers
        std::map<std::string, sf::Texture> m_PlayerFrames;
        std::vector<sf::Texture> m_WalkAnimationFrames;
        unsigned int m_WalkAnimationIterator;

        // Clock to handle animation
        sf::Clock m_Clock;

        // Clock to handle movements
        sf::Clock m_MovementClock;


        /* Functions */
        void InitTextures();
        void InitSounds();
        void InitVariables();
        void InitComponents();

    public:
        // Constructor / Destructor
        Player( GameDataRef data );
        ~Player();

        // void HandleInput();

        // Spawn player
        void Spawn( sf::Vector2f startPos ) override;

        // Move player
        void Move( const float& dt, const float& dir_x, const float& dir_y ) override;

        void Animate( float dt );

        void Jump();
        // void Duck();
        void MoveLeft();
        void MoveRight();
        void Run();

        // void StopJump();
        // void StopDuck();
        void StopLeft();
        void StopRight();
        // void StopFalling();
        void StopRunning();

        void Update( float dt ) override;
        void Draw() override;
    };
}