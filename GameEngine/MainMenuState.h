#pragma once

#include "State.h"
#include "Game.h"

namespace MarioEngine
{
    class MainMenuState : public State
    {
    public:
        explicit MainMenuState( GameDataRef data );

        // @override
        void Init();

        // TODO: Initialize keys in game
        void InitKeyBinds();

        // @override
        void HandleInput();

        // @override
        void Update( float dt );

        // @override
        void Draw();

    private:
        GameDataRef m_Data;

        std::map<std::string, int> m_KeyBinds;

        sf::Sprite m_BackgroundSprite;
        sf::Sprite m_TitleSprite;
        sf::Font m_MenuFont;
    };
}