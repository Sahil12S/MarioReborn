#pragma once

#include <SFML/Graphics.hpp>

#include "Game.h"
#include "DEFINITIONS.h"

namespace SSEngine
{
    class Button
    {
    private:
        GameDataRef m_Data;

        // Shape of our button
        sf::RectangleShape m_Shape;

        // Text font for button
        sf::Font m_Font;

        // Text for button
        sf::Text m_Text;

        sf::Color m_IdleColor;
        sf::Color m_HoverColor;
        sf::Color m_ActiveColor;

        unsigned short m_ButtonState;

    public:
        Button( GameDataRef data );
        ~Button();

        void SetButtonPosition( int x, int y );
        void SetButtonProperties( const std::string& fontName, const std::string& text,
                                  const std::vector< sf::Color >& buttonColors = {} );

        sf::RectangleShape& GetButton();

        /*
         * Set properties of button you want to draw
         * Position x, y
         * Width and Height
         * Text, font type
         * Vector of colors ( or we can set them same for all buttons )
        */
        // void setButton( float x, float y, float width, float height,
        //         const std::string& fontName, const std::string& text,
        //         std::vector< sf::Color > buttonColors = {} );

        const bool isPressed() const;

        void Update( const sf::Vector2f& mousePosition );

        // Draw the button
        void Draw();


    };
}
