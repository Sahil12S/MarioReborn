#include "Button.h"

namespace SSEngine
{
    Button::Button(SSEngine::GameDataRef data) : m_Data( std::move ( data ) )
    {
        m_ButtonState = eIdle;
    }

    Button::~Button()
    {

    }

    const bool Button::isPressed() const
    {
        if ( m_ButtonState == eActive )
        {
            return true;
        }
        return false;
    }

    void Button::SetButtonPosition( int x, int y )
    {
        m_Shape.setSize( sf::Vector2f( BUTTON_WIDTH, BUTTON_HEIGHT ) );
        m_Shape.setPosition( sf::Vector2f( x, y ) );
    }

    void Button::SetButtonProperties(const std::string &fontName, const std::string &text,
                                     const std::vector<sf::Color>& buttonColors)
    {
        m_Font = m_Data->assets.GetFont( fontName );
        m_Text.setFont( m_Font );
        m_Text.setString( text );
        //( 97, 143, 216 )
        m_Text.setFillColor( sf::Color::White );
        m_Text.setCharacterSize( 50 );

        // Set in the middle of button
        // m_Text.setPosition(
        //         m_Shape.getPosition().x ,
        //         m_Shape.getPosition().y  );


        m_Text.setPosition(
                m_Shape.getPosition().x +
                m_Shape.getGlobalBounds().width / 2.0f -
                m_Text.getGlobalBounds().width / 2.0f,
                m_Shape.getPosition().y +
                m_Shape.getGlobalBounds().height / 2.0f -
                m_Text.getGlobalBounds().height / 2.0f );

        m_IdleColor = sf::Color::Transparent;
        m_HoverColor = sf::Color::Magenta;
        m_ActiveColor = sf::Color::Green;

        m_Shape.setFillColor( m_IdleColor );
    }

    void Button::Update(const sf::Vector2f& mousePosition)
    {
        // Update button hover with mouse position
        m_ButtonState = eIdle;

        // Hover
        if( m_Shape.getGlobalBounds().contains( mousePosition ) )
        {
            m_ButtonState = eHover;

            // Active
            if ( sf::Mouse::isButtonPressed( sf::Mouse::Left ) )
            {
                m_ButtonState = eActive;
            }
        }

        // Set the button color
        switch ( m_ButtonState )
        {
            case eIdle:
                m_Shape.setFillColor( m_IdleColor );
                break;
            case eHover:
                m_Shape.setFillColor( m_HoverColor );
                break;
            case eActive:
                m_Shape.setFillColor( m_ActiveColor );
                break;

            default:
                m_Shape.setFillColor( sf::Color::Red );
                break;
        }

    }

    void Button::Draw()
    {
        m_Data->window.draw( m_Shape );
        m_Data->window.draw( m_Text );
    }

    sf::RectangleShape &Button::GetButton()
    {
        return m_Shape;
    }

}