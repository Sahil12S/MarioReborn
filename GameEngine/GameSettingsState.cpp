#include "GameSettingsState.h"
#include "MainMenuState.h"
#include "DEFINITIONS.h"

/*
 * TODO:
 * Handle input from file
 * Make sure using escape we go to Main Menu
 */

namespace SSEngine
{
    GameSettingsState::GameSettingsState(SSEngine::GameDataRef data) : m_Data ( move( data ) )
    {}


    GameSettingsState::~GameSettingsState()
    {
        delete m_Hud;
        for ( const auto& button : m_Buttons )
        {
            delete button.second;
        }
    }

    void GameSettingsState::Init()
    {
        Debug( "Game Settings State" )

        // Set Background
        m_Background.setSize( sf::Vector2f( m_Data->window.getSize() ) );
        m_Background.setFillColor( sf::Color(97, 143, 216) );

        // TODO: Load all textures in Splash State
        m_Data->assets.LoadFont( "Button Font", BUTTON_FONT_FILEPATH );

        m_Hud = new HUD( m_Data );
        m_Hud->SetTitle( "Main Menu Font", "SETTINGS" );

        m_Buttons["Home"] = new Button( m_Data );
        m_Buttons["Exit"] = new Button( m_Data );

        m_Buttons["Exit"]->SetButtonPosition( 2 * SCREEN_WIDTH / 3.0f - BUTTON_WIDTH / 2.0f, SCREEN_HEIGHT - BUTTON_HEIGHT / 0.8f );
        m_Buttons["Exit"]->SetButtonProperties( "Button Font", "Exit" );

        m_Buttons["Home"]->SetButtonPosition( SCREEN_WIDTH / 3.0f - BUTTON_WIDTH / 2.0f, SCREEN_HEIGHT - BUTTON_HEIGHT / 0.8f );
        m_Buttons["Home"]->SetButtonProperties( "Button Font", "Home" );

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
                m_Data->machine.RemoveState();
                m_Data->window.close();
            }

            if ( m_Buttons["Exit"]->isPressed() )
            {
                m_Data->machine.RemoveState();
                m_Data->window.close();
            }

            if ( m_Buttons["Home"]->isPressed() )
            {
                m_Data->machine.AddState( StateRef ( new MainMenuState ( m_Data ) ), true );
            }
        }
    }

    void GameSettingsState::Update(float dt)
    {
        m_Data->input.UpdateMousePosition( m_Data->window );

        for ( auto button : m_Buttons )
        {
            button.second->Update(m_Data->input.GetViewMousePosition());
        }
    }

    void GameSettingsState::Draw()
    {
        m_Data->window.clear();

        m_Data->window.draw( m_Background );

        m_Hud->Draw( true );

        for ( auto button : m_Buttons )
        {
            button.second->Draw();
        }

        m_Data->window.display();
    }
}