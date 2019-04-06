#pragma once

#include "State.h"
#include "Game.h"
#include "HUD.h"
#include "Button.h"

namespace SSEngine
{
    class MainMenuState : public State
    {
    public:
        explicit MainMenuState( GameDataRef data );
        ~MainMenuState();

        // @override
        void Init();

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

        sf::RectangleShape m_Background;

        HUD* m_Hud;

        std::map<std::string, Button*> m_Buttons;

    };
}