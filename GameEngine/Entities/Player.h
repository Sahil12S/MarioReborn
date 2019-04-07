#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "../Game.h"
#include "../Game.h"
#include "../DEFINITIONS.h"
#include "../Game_Components/MovementComponent.h"

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


        /* Variables */
        float m_RunningFactor;

        bool m_IsJumping;
        bool m_IsFalling;
        bool m_IsMovingLeft;
        bool m_IsMovingRight;
        bool m_IsDucking;
        bool m_IsRunning;


        bool m_JustJumped = false;

        // bool m_JumpDuration;
        // bool m_TimeThisJump;

        // In which direction is mario facing or walking
        short m_Direction;


        // Animation controllers
        std::map<std::string, sf::Texture> m_PlayerFrames;
        std::vector<sf::Texture> m_WalkAnimationFrames;
        unsigned int m_WalkAnimationIterator;

        // Clock to handle animation
        sf::Clock m_Clock;

        // Clock to handle movements
        sf::Clock m_MovementClock;


        /* Initializers */
        void InitTextures();
        void InitSounds();
        void InitVariables();
        void InitComponents();

    public:
        // Constructor / Destructor
        explicit Player( GameDataRef data );
        ~Player() override;

        /* Overridden functions */
        // void SetPosition( sf::Vector2f startPos ) override;
        // void CreateMovementComponent( const float& maxVelocity ) override;
        /*void Animate( float dt );*/


        /* Functions */
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

#endif // PLAYER_H