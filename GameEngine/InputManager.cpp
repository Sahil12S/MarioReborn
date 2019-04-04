#include "InputManager.h"

namespace MarioEngine
{
    InputManager::InputManager()
    {
        InitKeys();
    }

    InputManager::~InputManager()
    {}

    bool InputManager::IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window)
    {
        if ( sf::Mouse::isButtonPressed( button ) )
        {
            // Draw a rectangle across sprite
            sf::IntRect buttonRect ( (int)object.getPosition().x, (int)object.getPosition().y,
                                     (int)object.getGlobalBounds().width, (int)object.getGlobalBounds().height );

            if ( buttonRect.contains( sf::Mouse::getPosition( window ) ) )
            {
                return true;
            }
        }
        return false;
    }

    void InputManager::InitKeys()
    {
        m_SupportedKeys["Escape"] = sf::Keyboard::Key ::Escape;
        m_SupportedKeys["W"] = sf::Keyboard::Key::W;
        m_SupportedKeys["A"] = sf::Keyboard::Key::A;
        m_SupportedKeys["S"] = sf::Keyboard::Key::S;
        m_SupportedKeys["D"] = sf::Keyboard::Key::D;
    }

    std::map<std::string, int>& InputManager::getSupportedKeys()
    {
        return m_SupportedKeys;
    }
}