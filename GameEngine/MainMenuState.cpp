#include "MainMenuState.h"
#include "GameState.h"
// #include ""
#include "DEFINITIONS.h"

namespace MarioEngine
{
    MainMenuState::MainMenuState( GameDataRef data ) : m_Data ( std::move( data ) )
    {

    }

    // @override
    void MainMenuState::Init()
    {
        Debug( "**Initialized** Main menu state" )

        InitKeyBinds();
        Debug( "Key binding completed for Main Menu" )

        // Use sprites for background
        m_Background.setSize( sf::Vector2f( m_Data->window.getSize() ) );
        m_Background.setFillColor( sf::Color(97, 143, 216) );

        // Play Button
        m_Data->assets.LoadTexture( "Play Button", PLAY_BUTTON_FILEPATH );
        m_PlayButton.setTexture( m_Data->assets.GetTexture( "Play Button" ) );

        m_PlayButton.setPosition( (SCREEN_WIDTH / 2.0f) - (m_PlayButton.getGlobalBounds().width / 2.0f),
                                  (SCREEN_HEIGHT / 3.0f) );

        // m_Data->assets.LoadTexture( "Main Menu Background", MAIN_MENU_BACKGROUND_FILEPATH );
        // m_Data->assets.LoadTexture( "Main Menu Title", MAIN_MENU_TILE_FILEPATH );

        // m_BackgroundSprite.setTexture( m_Data->assets.GetTexture( "Main Menu Background" ) );
        // m_TitleSprite.setTexture( m_Data->assets.GetTexture( "Main Menu Title" ) );
    }

    void MainMenuState::InitKeyBinds()
    {
        std::fstream ifs ( MAIN_MENU_KEY_BIND_FILEPATH );

        if ( ifs.is_open() )
        {
            std::string keyAction;
            std::string key;

            while( ifs >> keyAction >> key )
            {
                m_KeyBinds[keyAction] = m_Data->input.getSupportedKeys().at( key );
            }
        }
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

            if ( m_Data->input.IsSpriteClicked( m_PlayButton, sf::Mouse::Left, m_Data->window ) )
            {
                m_Data->machine.AddState( StateRef ( new GameState( m_Data ) ), true );
            }

            if ( sf::Event::KeyPressed == event.type )
            {
                if ( sf::Keyboard::isKeyPressed(( sf::Keyboard::Key( m_KeyBinds["QUIT"] ) ) ) )
                {
                    m_Data->machine.RemoveState();
                    m_Data->window.close();
                }
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

        m_Data->window.draw( m_Background );
        m_Data->window.draw( m_PlayButton );

        m_Data->window.display();
    }
}