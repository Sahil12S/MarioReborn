#include "GameState.h"
#include <iostream>
#include "PauseState.h"

namespace MarioEngine
{
    GameState::GameState( GameDataRef data ) : m_Data( std::move( data ) )
    {
        m_Player = new Entity( m_Data );
        InitKeyBinds();
    }

    void GameState::Init()
    {
        std::clog << "Game State" << std::endl;
    }

    // TODO: Implentation left for later.
    void GameState::InitKeyBinds()
    {
        std::cout << "Keys initialized for Game State" << std::endl;
        m_KeyBinds["QUIT"] = m_Data->input.getSupportedKeys().at( "Escape" );
        m_KeyBinds["MOVE_UP"] = m_Data->input.getSupportedKeys().at( "W" );
        m_KeyBinds["MOVE_LEFT"] = m_Data->input.getSupportedKeys().at( "A" );
        m_KeyBinds["MOVE_DOWN"] = m_Data->input.getSupportedKeys().at( "S" );
        m_KeyBinds["MOVE_RIGHT"] = m_Data->input.getSupportedKeys().at( "D" );
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
                // Check if game is paused
                if ( sf::Keyboard::isKeyPressed( sf::Keyboard::P ) )
                {
                    m_Data->machine.AddState( StateRef ( new PauseState ( m_Data )), false );
                }
                if ( sf::Keyboard::isKeyPressed(( sf::Keyboard::Key( m_KeyBinds["QUIT"] ) ) ) )
                {
                    m_Data->machine.RemoveState();
                    m_Data->window.close();
                }
            }
        }

        /*
         * Handle movements
         */
        if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key( m_KeyBinds["MOVE_UP"] ) ) )
        {
            m_Player->MoveUp();
        }
        else
        {
            m_Player->StopUp();
        }
        if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key( m_KeyBinds["MOVE_LEFT"] ) ) )
        {
            m_Player->MoveLeft();
        }
        else
        {
            m_Player->StopLeft();
        }
        if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key( m_KeyBinds["MOVE_DOWN"] ) ) )
        {
            m_Player->MoveDown();
        }
        else
        {
            m_Player->StopDown();
        }
        if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key( m_KeyBinds["MOVE_RIGHT"] ) ) )
        {
            m_Player->MoveRight();
        }
        else
        {
            m_Player->StopRight();
        }
    }

    void GameState::Update(float dt)
    {
        m_Player->Update( dt );
    }

    void GameState::Draw()
    {
        m_Data->window.clear();

        m_Player->Draw();

        m_Data->window.display();
    }
}