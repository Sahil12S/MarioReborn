#include "Game.h"
#include "State.h"
#include "HUD.h"
#include "Button.h"

namespace SSEngine
{
    class GameSettingsState : public State
    {
    public:
        GameSettingsState( GameDataRef data );
        ~GameSettingsState();

        void Init();
        // TODO: Initialize key binds in game
        void InitKeyBinds();
        void HandleInput();
        void Update( float dt );
        void Draw();

    private:
        GameDataRef m_Data;

        HUD* m_Hud;

        std::map<std::string, int> m_KeyBinds;

        sf::RectangleShape m_Background;

        /*sf::Sprite m_ExitButton;
        sf::Sprite m_HomeButton;*/

        std::map<std::string, Button*> m_Buttons;

        // sf::Sprite m_BackgroundSprite;
    };
}