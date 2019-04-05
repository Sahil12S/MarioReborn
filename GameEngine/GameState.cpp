#include "GameState.h"
#include "PauseState.h"
#include "MainMenuState.h"
#include "DEFINITIONS.h"

#include <sstream>

namespace SSEngine
{
    GameState::GameState( GameDataRef data ) : m_Data( std::move( data ) )
    {
    }

    void GameState::Init()
    {
        // Initialize keys
        InitKeyBinds();

        // std::clog << "[DEBUG]: ";
        Debug( "**Initialized** Game State" )
        m_Data->assets.LoadTexture( "Mario Idle", MARIO_IDLE_FILEPATH );
        m_Data->assets.LoadTexture( "Mario Walk 01", MARIO_WALK_01_FILEPATH );
        m_Data->assets.LoadTexture( "Mario Walk 02", MARIO_WALK_02_FILEPATH );
        m_Data->assets.LoadTexture( "Mario Walk 03", MARIO_WALK_03_FILEPATH );
        m_Data->assets.LoadTexture( "Mario Jump", MARIO_JUMP_FILEPATH );
        m_Data->assets.LoadTexture( "Mario Turn", MARIO_TURN_FILEPATH );

        // TODO: Make collision with ground
        m_Player = new Player( m_Data );
        m_Player->Spawn( sf::Vector2f( 100, SCREEN_HEIGHT - 100 ) );
    }

    // TODO: Implementation left for later.
    void GameState::InitKeyBinds()
    {
        std::ifstream ifs ( GAMESTATE_KEY_BIND_FILEPATH );

        if ( ifs.is_open() )
        {
            std::string keyAction;
            std::string key;

            while ( ifs >> keyAction >> key )
            {
                m_KeyBinds[keyAction] = m_Data->input.getSupportedKeys().at( key );
            }
        }

        ifs.close();

        Debug( "Key bindings initialized for Game State" )
    }

    void GameState::HandleInput()
    {
        sf::Event event;

        while ( m_Data->window.pollEvent( event ) )
        {
            if ( sf::Event::Closed == event.type )
            {
                m_Data->machine.RemoveState();
                m_Data->window.close();
            }
            if ( sf::Event::KeyPressed == event.type )
            {
                // Go to Pause Screen if game is paused
                if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key( m_KeyBinds["PAUSE"] ) ) )
                {
                    m_Data->machine.AddState( StateRef ( new PauseState ( m_Data )), false );
                }

                // Go to Main Menu on pressing of Escape
                if ( sf::Keyboard::isKeyPressed(( sf::Keyboard::Key( m_KeyBinds["QUIT"] ) ) ) )
                {
                    m_Data->machine.AddState( StateRef ( new MainMenuState ( m_Data )), true );
                }
            }
        }

        /*
         * Handle movements
         */
        // Jump
        if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key( m_KeyBinds["JUMP"] ) ) )
        {
            m_Player->Jump();
        }

        // Walk Left
        if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key( m_KeyBinds["MOVE_LEFT"] ) ) )
        {
            m_Player->MoveLeft();
        }
        else
        {
            m_Player->StopLeft();
        }

        // Walk right
        if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key( m_KeyBinds["MOVE_RIGHT"] ) ) )
        {
            m_Player->MoveRight();
        }
        else
        {
            m_Player->StopRight();
        }

        // Run
        if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key( m_KeyBinds["RUN"] ) ) )
        {
            m_Player->Run();
        }
        else
        {
            m_Player->StopRunning();
        }

        // if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key( m_KeyBinds["MOVE_DOWN"] ) ) )
        // {
        //     m_Player->Duck();
        // }

    }

    void GameState::Update(float dt)
    {
        m_Data->input.UpdateMousePosition( m_Data->window );
        m_Player->Update( dt );
    }

    void GameState::Draw()
    {
        m_Data->window.clear();

        m_Player->Draw();

        // Draw coordinates on mouse pointer for debugging
        sf::Text mouseText;
        mouseText.setPosition( m_Data->input.GetViewMousePosition().x + 5, m_Data->input.GetViewMousePosition().y );
        mouseText.setFont( m_Data->assets.GetFont( "Debug Font" ) );
        mouseText.setCharacterSize( 20 );
        std::stringstream ss;
        ss << m_Data->input.GetViewMousePosition().x << ", " << m_Data->input.GetViewMousePosition().y;
        mouseText.setString( ss.str() );
        m_Data->window.draw( mouseText );

        m_Data->window.display();
    }
}