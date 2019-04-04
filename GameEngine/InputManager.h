#pragma once

#include <map>
#include <SFML/Graphics.hpp>

namespace MarioEngine
{
    class InputManager
    {
    public:
        InputManager();
        ~InputManager();

        bool IsSpriteClicked( sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow& window );

        void InitKeys();

        std::map<std::string, int>& getSupportedKeys();

    private:
        /*
         * Key map so that player can change key bindings
         */
        std::map<std::string, int> m_SupportedKeys;
    };
}