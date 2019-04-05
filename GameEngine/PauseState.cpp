#include "PauseState.h"
#include "MainMenuState.h"
#include "DEFINITIONS.h"

namespace SSEngine
{
    PauseState::PauseState(SSEngine::GameDataRef data) : m_Data( std::move( data ) )
    {

    }

    void PauseState::Init()
    {
        Debug( "Pause State" );
    }

    void PauseState::InitKeyBinds()
    {
        m_KeyBinds["Quit"] = m_Data->input.getSupportedKeys().at( " Escape" );
    }

    void PauseState::HandleInput()
    {
        sf::Event event;

        while ( m_Data->window.pollEvent( event ) )
        {
            if ( sf::Event::Closed == event.type )
            {
                // delete m_Data;
                m_Data->window.close();
            }

            if ( sf::Event::KeyPressed == event.type )
            {
                // TODO: Implement Going back to Game or to Main Menu
                if ( sf::Keyboard::isKeyPressed( sf::Keyboard::R ) )
                {
                    // std::cout << "Key Pressed in Pause state" << std::endl;
                    m_Data->machine.RemoveState();
                }
                if ( sf:: Keyboard::isKeyPressed( sf::Keyboard::M ) )
                {
                    m_Data->machine.RemoveState();
                    m_Data->machine.AddState( StateRef( new MainMenuState( m_Data ) ), true );
                }
            }
        }
    }

    void PauseState::Update(float dt)
    {
        m_Data->input.UpdateMousePosition( m_Data->window );
    }

    void PauseState::Draw()
    {
        m_Data->window.clear();
        m_Data->window.draw( m_BackgroundSprite );
        m_Data->window.display();
    }
}
