#include "GameSettingsState.h"
#include <iostream>

namespace MarioEngine
{
    GameSettingsState::GameSettingsState(MarioEngine::GameDataRef data) : m_Data ( move( data ) )
    {}

    void GameSettingsState::Init()
    {
        std::clog << "Game Settings State" << std::endl;
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