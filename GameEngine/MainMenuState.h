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

        // @override
        void HandleInput();

        // @override
        void Update( float dt );

        // @override
        void Draw();

    private:
        /* Variables */
        GameDataRef m_Data;

        std::map<std::string, int> m_KeyBinds;

        sf::RectangleShape m_Background;

        HUD* m_Hud;

        std::map<std::string, Button*> m_Buttons;

        /* Functions */
        // Initializers
        void InitKeyBinds();
        void InitTextures();
        void InitFonts();
        void InitSounds();
        void InitButtons();

        void InitVariables();

    };
}