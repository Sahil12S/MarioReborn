#include "MainMenuState.h"
#include "PauseState.h"
#include "DEFINITIONS.h"
#include <iostream>

namespace MarioEngine
{
    MainMenuState::MainMenuState( GameDataRef data ) : m_Data ( std::move( data ) )
    {

    }

    // @override
    void MainMenuState::Init()
    {
        std::clog << "Main menu" << std::endl;
        // m_Data->assets.LoadTexture( "Main Menu Background", MAIN_MENU_BACKGROUND_FILEPATH );
        // m_Data->assets.LoadTexture( "Main Menu Title", MAIN_MENU_TILE_FILEPATH );

        // m_BackgroundSprite.setTexture( m_Data->assets.GetTexture( "Main Menu Background" ) );
        // m_TitleSprite.setTexture( m_Data->assets.GetTexture( "Main Menu Title" ) );
    }

    void MainMenuState::InitKeyBinds()
    {
        m_KeyBinds["Quit"] = m_Data->input.getSupportedKeys().at("Escape");
    }

    // @override
    void MainMenuState::HandleInput()
    {
        sf::Event event;

        while ( m_Data->window.pollEvent( event ) )
        {
            if ( sf::Event::Closed == event.type )
            {
                m_Data->machine.RemoveState();
                m_Data->window.close();
            }
        }
    }

    // @override
    void MainMenuState::Update(float dt)
    {

    }

    // @override
    void MainMenuState::Draw()
    {
        m_Data->window.clear();
        m_Data->window.draw( m_BackgroundSprite );
        m_Data->window.display();
    }
}