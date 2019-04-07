#include "Player.h"

namespace SSEngine
{
    void Player::InitTextures()
    {
        m_Data->assets.LoadTexture( "Mario Sheet", MARIO_SHEET_FILEPATH );
        // m_WalkAnimationFrames.emplace_back( m_Data->assets.GetTexture( "Mario Idle") );
/*        m_WalkAnimationFrames.emplace_back( m_Data->assets.GetTexture( "Mario Walk 01" ) );
        m_WalkAnimationFrames.emplace_back( m_Data->assets.GetTexture( "Mario Walk 02" ) );
        m_WalkAnimationFrames.emplace_back( m_Data->assets.GetTexture( "Mario Walk 03" ) );


        m_PlayerFrames["Idle"] = m_Data->assets.GetTexture( "Mario Idle" );
        m_PlayerFrames["Jump"] = m_Data->assets.GetTexture( "Mario Jump" );
        m_PlayerFrames["Turn"] = m_Data->assets.GetTexture( "Mario Turn" );*/

        // m_JumpTexture = m_Data->assets.GetTexture( "Mario Jump" );
    }

    void Player::InitSounds()
    {

    }

    void Player::InitVariables()
    {
        // Trigger variables
        m_IsJumping = false;
        m_IsFalling = false;
        m_IsMovingLeft = false;
        m_IsMovingRight = false;
        m_IsDucking = false;
        m_IsRunning = false;

        /*m_RunningFactor = 1.0f;*/
        /*m_WalkAnimationIterator = 0;*/

        // Set default facing direction
        m_Direction = MarioMovement::eRight;

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

        SetTexture( m_Data->assets.GetTexture( "Mario Idle") );

        CreateMovementComponent( ENTITY_MOVEMENT_SPEED, 0, 0 );
        CreateAnimationComponent( m_Data->assets.GetTexture( "Mario Sheet" ) );

        // Animation name, animation timer, start pos X, start pos Y, frames X, frames Y, tile size
        m_AC->AddAnimation("IDLE_RIGHT", 0.f, 0, 2, 0, 0, TILE_WIDTH, TILE_HEIGHT ); // No animation when idle
        m_AC->AddAnimation("WALK_RIGHT", WALK_ANIMATION_DURATION, 1, 2, 2, 0, TILE_WIDTH, TILE_HEIGHT );
        m_AC->AddAnimation("JUMP", 0.f, 5, 2, 0, 0, TILE_WIDTH, TILE_HEIGHT ); // No animation when jumping
    }

    Player::~Player() = default;

/*    void Player::SetPosition(sf::Vector2f startPos)
    {
        m_PlayerSprite.setTexture( m_WalkAnimationFrames.at( 0 ) );
        m_PlayerSprite.setPosition( startPos );
        m_PlayerSprite.scale( 2.0f, 2.0f );

        sf::Vector2f origin = sf::Vector2f( m_PlayerSprite.getGlobalBounds().width / 2,
                                            m_PlayerSprite.getGlobalBounds().height / 2 );

        m_PlayerSprite.setOrigin( origin );
        // Debug( m_PlayerSprite.getPosition().x )
    }*/

    /*void Player::CreateMovementComponent(const float& maxVelocity)
    {
        m_MC = new MovementComponent( maxVelocity );
    }*/

    /*void Player::Animate( float dt )
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
    }*/


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
        // m_MC->Update( dt );


        //TODO: Correct flipping positions
        if ( m_IsMovingLeft )
        {
            // Walking in left direction
            if (m_Direction != MarioMovement::eLeft )
            {
                m_Direction = MarioMovement::eLeft;
                m_Sprite.setOrigin( 20.0f, 0.0f );
                m_Sprite.scale( -1.0f, 1.0f );
            }

            Move( dt, -1.0f, 0.0f);

            // Animate( dt );

        }
        else if ( m_IsMovingRight )
        {
            // Walking towards right
            if (m_Direction != MarioMovement::eRight )
            {
                m_Direction = MarioMovement::eRight;
                m_Sprite.setOrigin( 0.0f, 0.0f );
                m_Sprite.scale( -1.0f, 1.0f );

            }
            Move( dt, 1.0f, 0.0f);

            m_AC->Play("WALK_RIGHT", dt);
            // Animate( dt );

        }
        else
        {
            // Standing idle
            m_AC->Play("IDLE_RIGHT", dt);
        }


        // Complete the jump if you are moving in some direction
        if ( m_IsJumping )
        {
            // m_Sprite.setTexture( m_PlayerFrames["Jump"] );

            if ( m_IsMovingRight )
            {
                Move( dt, JUMP_SPEED * dt, -JUMP_SPEED * dt );
            }
            else if ( m_IsMovingLeft )
            {
                Move( dt, -JUMP_SPEED * dt, -JUMP_SPEED * dt );
            }
            else
            {
                Move( dt, 0.0f, -JUMP_SPEED * dt );
            }
            m_AC->Play( "JUMP", dt );
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

        if ( m_Sprite.getPosition().y > SCREEN_HEIGHT - 100 )
        {
            m_IsFalling = false;
        }

    }

    void Player::Draw()
    {
        m_Data->window.draw( m_Sprite );
    }
}
