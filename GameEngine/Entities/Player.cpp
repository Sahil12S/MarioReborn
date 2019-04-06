#include "Player.h"

namespace SSEngine
{
    void Player::InitTextures()
    {

    }

    void Player::InitSounds()
    {

    }

    void Player::InitVariables()
    {

    }

    void Player::InitComponents()
    {

    }

    Player::Player( GameDataRef data ) : m_Data( move( data ) )
    {
        InitTextures();
        InitSounds();
        InitVariables();
        InitComponents();

        m_MovementSpeed = ENTITY_MOVEMENT_SPEED;
        m_RunningFactor = 1.0f;

        // Initialize all triggers
        m_IsJumping = m_IsFalling = m_IsMovingLeft = m_IsMovingRight = m_IsDucking = m_IsRunning = false;
        m_IsJumpingLeft = m_IsJumpingRight = false;

        // Set default facing direction
        m_Direction = MarioMovement::eRight;

        // m_ShouldFlip = false;
        // m_IsIdle = false;

        m_WalkAnimationIterator = 0;
        // m_WalkAnimationFrames.emplace_back( m_Data->assets.GetTexture( "Mario Idle") );
        m_WalkAnimationFrames.emplace_back( m_Data->assets.GetTexture( "Mario Walk 01" ) );
        m_WalkAnimationFrames.emplace_back( m_Data->assets.GetTexture( "Mario Walk 02" ) );
        m_WalkAnimationFrames.emplace_back( m_Data->assets.GetTexture( "Mario Walk 03" ) );


        m_PlayerFrames["Idle"] = m_Data->assets.GetTexture( "Mario Idle" );
        m_PlayerFrames["Jump"] = m_Data->assets.GetTexture( "Mario Jump" );
        m_PlayerFrames["Turn"] = m_Data->assets.GetTexture( "Mario Turn" );

        // m_JumpTexture = m_Data->assets.GetTexture( "Mario Jump" );
    }

    Player::~Player()
    {

    }

    void Player::Spawn(sf::Vector2f startPos)
    {
        m_PlayerSprite.setTexture( m_WalkAnimationFrames.at( 0 ) );
        m_PlayerSprite.setPosition( startPos );
        m_PlayerSprite.scale( 2.0f, 2.0f );

        sf::Vector2f origin = sf::Vector2f( m_PlayerSprite.getGlobalBounds().width / 2,
                                            m_PlayerSprite.getGlobalBounds().height / 2 );

        m_PlayerSprite.setOrigin( origin );
        // Debug( m_PlayerSprite.getPosition().x )
    }

    void Player::Animate( float dt )
    {
        if ( m_Clock.getElapsedTime().asSeconds() > WALKING_ANIMATION_DURATION )
        {
            // We just want to animate from index 1 to 3.
            // As at index 0 we have idle position
            m_WalkAnimationIterator++;
            m_WalkAnimationIterator %= m_WalkAnimationFrames.size() - 1;

            m_PlayerSprite.setTexture( m_WalkAnimationFrames.at( m_WalkAnimationIterator + 1 ) );

            m_Clock.restart();
        }
    }

    void Player::Move(const float &dt, const float& dir_x, const float& dir_y)
    {
        m_PlayerSprite.move( dir_x * m_MovementSpeed * dt, dir_y * m_MovementSpeed * dt );
    }

    void Player::Jump()
    {
        if ( !m_IsFalling && !m_JustJumped )
        {
            m_IsJumping = true;
            m_JustJumped = true;
            m_IsFalling = false;
            m_MovementClock.restart();
        }
    }

    void Player::Run()
    {
        m_IsRunning = true;
    }

    /*void Player::Duck()
    {
        if ( !m_IsJumping && !m_IsFalling )
        {
            m_IsDucking = true;
        }
    }*/

    void Player::MoveLeft()
    {
        m_IsMovingLeft = true;
    }

    void Player::MoveRight()
    {
        m_IsMovingRight = true;
    }

    /*void Player::StopJump()
    {
        m_IsJumping = false;
    }

    void Player::StopDuck()
    {
        m_IsDucking = false;
    }*/

    void Player::StopLeft()
    {
        m_IsMovingLeft = false;
    }

    void Player::StopRight()
    {
        m_IsMovingRight = false;
    }

    /*void Player::StopFalling()
    {
        m_IsFalling = false;
    }*/

    void Player::StopRunning()
    {
        m_IsRunning = false;
    }

    void Player::Update(float dt)
    {
        //TODO: Correct fliping positions
        if ( m_IsMovingLeft )
        {
            // Walking in left direction
            if (m_Direction != MarioMovement::eLeft )
            {
                m_Direction = MarioMovement::eLeft;
                m_PlayerSprite.setOrigin( 20.0f, 16.0f );
                m_PlayerSprite.scale( -1.0f, 1.0f );
            }

            // m_IsIdle = false;
            Move( dt, -1.0f, 0.0f );

            Animate( dt );

        }
        else if ( m_IsMovingRight )
        {
            // Walking towards right
            if (m_Direction != MarioMovement::eRight )
            {
                m_Direction = MarioMovement::eRight;
                // sf::Vector2f t = m_PlayerSprite.getPosition();
                // Debug( t.x )
                m_PlayerSprite.setOrigin( 0.0f, 16.0f );
                m_PlayerSprite.scale( -1.0f, 1.0f );

            }
            // m_IsIdle = false;
            Move( dt, 1.0f, 0.0f );

            Animate( dt );

        }
        else
        {
            // Standing idle
            m_PlayerSprite.setTexture( m_PlayerFrames["Idle"] );
        }


        // Complete the jump if you are moving in some direction
        if ( m_IsJumping )
        {
            m_PlayerSprite.setTexture( m_PlayerFrames["Jump"] );

            if ( m_IsMovingRight || m_IsJumpingRight )
            {
                m_IsJumpingRight = true;
                Move( dt, JUMP_SPEED * dt, -JUMP_SPEED * dt );
            }
            else if ( m_IsMovingLeft || m_IsJumpingLeft )
            {
                m_IsJumpingLeft = true;
                Move( dt, -JUMP_SPEED * dt, -JUMP_SPEED * dt );
            }
            else
            {
                m_IsJumpingLeft = false;
                m_IsJumpingRight = false;
                Move( dt, 0.0f, -JUMP_SPEED * dt );
            }
        }
        // And fall vertically downward if no directional key is pressed.
        else if ( m_IsFalling )
        {
            if ( m_IsMovingRight )
            {
                Move( dt, GRAVITY * dt, GRAVITY * dt );
            }
            else if ( m_IsMovingLeft )
            {
                Move( dt, -GRAVITY * dt, GRAVITY * dt );
            }
            else
            {
                Move( dt, 0.0f, JUMP_SPEED * dt );
            }
        }

        if ( m_JustJumped && m_MovementClock.getElapsedTime().asSeconds() > JUMP_DURATION )
        {
            m_MovementClock.restart();
            m_IsJumping = false;
            m_JustJumped = false;
            m_IsFalling = true;
        }

        if ( m_PlayerSprite.getPosition().y > SCREEN_HEIGHT - 100 )
        {
            m_IsFalling = false;
            m_IsJumpingLeft = false;
            m_IsJumpingRight = false;
        }

    }

    void Player::Draw()
    {
        m_Data->window.draw( m_PlayerSprite );
    }
}
