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

        sf::RectangleShape m_Background;

        /*sf::Sprite m_PlayButton;
        sf::Sprite m_ExitButton;
        sf::Sprite m_SettingsButton;*/

        HUD* m_Hud;

        std::map<std::string, Button*> m_Buttons;

        // Button* m_PlayButton;
        // Button* m_ExitButton;
        // Button* m_SettingsButton;


        /*sf::Sprite m_BackgroundSprite;
        sf::Sprite m_TitleSprite;
        sf::Font m_MenuFont;*/
    };
}