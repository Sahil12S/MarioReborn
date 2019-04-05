#pragma once

#include "Entity.h"
#include "Game.h"
#include "Game.h"
#include "DEFINITIONS.h"

namespace SSEngine
{
    class Player : public Entity
    {
    private:
        GameDataRef m_Data;



        // sf::RectangleShape m_Sprite;
        float m_MovementSpeed;
        float m_RunningFactor;

        // bool m_ShouldFlip;
        // bool m_IsIdle;

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


        sf::Sprite m_MarioSprite;
        // sf::Texture m_JumpTexture;
        // sf::Sprite m_ActionsSprite;

        // Animation controllers
        std::map<std::string, sf::Texture> m_MarioFrames;
        std::vector<sf::Texture> m_WalkAnimationFrames;
        unsigned int m_WalkAnimationIterator;

        // Clock to handle animation
        sf::Clock m_Clock;

        // Clock to handle movements
        sf::Clock m_MovementClock;

    public:
        Player( GameDataRef data );
        ~Player();

        // void HandleInput();

        void Move( const float& dt, const float& dir_x, const float& dir_y );

        void Spawn( sf::Vector2f startPos );

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

        void Update( float dt );
        void Draw();
    };
}