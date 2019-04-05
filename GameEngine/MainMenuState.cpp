#include "MainMenuState.h"
#include "GameState.h"
#include "GameSettingsState.h"
#include "DEFINITIONS.h"

namespace SSEngine
{
    MainMenuState::MainMenuState( GameDataRef data ) : m_Data ( std::move( data ) )
    {

    }

    MainMenuState::~MainMenuState()
    {
        delete m_Hud;
        for ( const auto& button : m_Buttons )
        {
            delete button.second;
        }
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

        // TODO: Load all textures in splash state
        // Buttons
       /* m_Data->assets.LoadTexture( "Play Button", PLAY_BUTTON_FILEPATH );
        m_Data->assets.LoadTexture( "Exit Button", EXIT_BUTTON_FILEPATH );
        m_Data->assets.LoadTexture( "Settings Button", SETTINGS_BUTTON_FILEPATH );

        m_PlayButton.setTexture( m_Data->assets.GetTexture( "Play Button" ) );
        m_ExitButton.setTexture( m_Data->assets.GetTexture( "Exit Button" ) );
        m_SettingsButton.setTexture( m_Data->assets.GetTexture( "Settings Button" ) );


        m_PlayButton.setPosition( ( SCREEN_WIDTH / 1.5f ) - (m_PlayButton.getGlobalBounds().width / 2.0f ),
                                  ( SCREEN_HEIGHT - m_PlayButton.getGlobalBounds().height -
                                  m_SettingsButton.getGlobalBounds().height - m_ExitButton.getGlobalBounds().height ) );

        m_ExitButton.setPosition( ( SCREEN_WIDTH ) - (m_ExitButton.getGlobalBounds().width),
                                  ( SCREEN_HEIGHT - m_ExitButton.getGlobalBounds().height - m_SettingsButton.getGlobalBounds().height) );
        m_SettingsButton.setPosition( ( SCREEN_WIDTH / 1.5f) - (m_SettingsButton.getGlobalBounds().width / 2.0f ),
                                  ( SCREEN_HEIGHT - m_SettingsButton.getGlobalBounds().height ) );*/

        m_Data->assets.LoadFont( "Main Menu Font", MAIN_MENU_FONT_FILEPATH );
        m_Data->assets.LoadFont( "Button Font", BUTTON_FONT_FILEPATH );
        m_Data->assets.LoadFont( "Debug Font", DEBUG_FONT_FILEPATH );

        m_Hud = new HUD( m_Data );
        m_Hud->SetTitle( "Main Menu Font", "WHO'S WATCHING??" );

        //Draw Buttons
        m_Buttons["Play"] = new Button( m_Data );
        m_Buttons["Exit"] = new Button( m_Data );
        m_Buttons["Settings"] = new Button( m_Data );

        // Set Button Properties
        m_Buttons["Exit"]->SetButtonPosition( SCREEN_WIDTH / 2.0f - BUTTON_WIDTH / 2.0f, SCREEN_HEIGHT - BUTTON_HEIGHT / 0.8f );
        m_Buttons["Exit"]->SetButtonProperties( "Button Font", "Exit" );

        m_Buttons["Settings"]->SetButtonPosition( SCREEN_WIDTH / 2.0f - BUTTON_WIDTH / 2.0f, m_Buttons["Exit"]->GetButton().getPosition().y - BUTTON_HEIGHT / 0.8f );
        m_Buttons["Settings"]->SetButtonProperties( "Button Font", "Settings" );

        m_Buttons["Play"]->SetButtonPosition( SCREEN_WIDTH / 2.0f - BUTTON_WIDTH / 2.0f, m_Buttons["Settings"]->GetButton().getPosition().y - BUTTON_HEIGHT / 0.8f );
        m_Buttons["Play"]->SetButtonProperties( "Button Font", "Play" );
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

            if ( m_Buttons["Exit"]->isPressed() )
            {
                m_Data->machine.RemoveState();
                m_Data->window.close();
            }

            if ( m_Buttons["Play"]->isPressed() )
            {
                m_Data->machine.AddState( StateRef ( new GameState( m_Data ) ), true );
            }
            if ( m_Buttons["Settings"]->isPressed() )
            {
                m_Data->machine.AddState( StateRef ( new GameSettingsState( m_Data ) ), true );
            }

            /*if ( m_Data->input.IsSpriteClicked( m_ExitButton, sf::Mouse::Left, m_Data->window ) )
            {
                m_Data->machine.RemoveState();
                m_Data->window.close();
            }*/

            /*if ( m_Data->input.IsSpriteClicked( m_PlayButton, sf::Mouse::Left, m_Data->window ) )
            {
                m_Data->machine.AddState( StateRef ( new GameState( m_Data ) ), true );
            }
            if ( m_Data->input.IsSpriteClicked( m_SettingsButton, sf::Mouse::Left, m_Data->window ) )
            {
                m_Data->machine.AddState( StateRef ( new GameSettingsState( m_Data ) ), true );
            }*/

            /*if ( sf::Keyboard::isKeyPressed(( sf::Keyboard::Key( m_KeyBinds["QUIT"] ) ) ) )
            {
                m_Data->machine.RemoveState();
                m_Data->window.close();
            }*/

        }
    }

    // @override
    void MainMenuState::Update(float dt)
    {
        m_Data->input.UpdateMousePosition( m_Data->window );

        for ( auto button : m_Buttons )
        {
            button.second->Update(m_Data->input.GetViewMousePosition());
        }
    }

    // @override
    void MainMenuState::Draw()
    {
        m_Data->window.clear();

        m_Data->window.draw( m_Background );
        /*m_Data->window.draw( m_PlayButton );
        m_Data->window.draw( m_ExitButton );
        m_Data->window.draw( m_SettingsButton );*/

        m_Hud->Draw( true );

        // m_Buttons["Settings"]->Draw();

        for ( auto button : m_Buttons )
        {
            button.second->Draw();
        }

        /* Remove later */
        /*sf::Text mouseText;
        mouseText.setPosition( m_Data->input.GetViewMousePosition().x + 5, m_Data->input.GetViewMousePosition().y );
        mouseText.setFont( m_Data->assets.GetFont( "Debug Font" ) );
        mouseText.setCharacterSize( 20 );
        std::stringstream ss;
        ss << m_Data->input.GetViewMousePosition().x << ", " << m_Data->input.GetViewMousePosition().y;
        mouseText.setString( ss.str() );
        m_Data->window.draw( mouseText );*/


        m_Data->window.display();
    }


}