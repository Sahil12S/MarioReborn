#include "GameSettingsState.h"
#include "DEFINITIONS.h"

namespace MarioEngine
{
    GameSettingsState::GameSettingsState(MarioEngine::GameDataRef data) : m_Data ( move( data ) )
    {}

    void GameSettingsState::Init()
    {
        Debug( "Game Settings State" );
    }

    void GameSettingsState::InitKeyBinds()
    {
        m_KeyBinds["Quit"] = m_Data->input.getSupportedKeys().at( "Escape" );
    }

    void GameSettingsState::HandleInput()
    {
        sf::Event event;

        while ( m_Data->window.pollEvent( event ) )
        {
            if ( sf::Event::Closed == event.type )
            {
                m_Data->window.close();
            }
        }
    }

    void GameSettingsState::Update(float dt)
    {

    }

    void GameSettingsState::Draw()
    {

    }
}