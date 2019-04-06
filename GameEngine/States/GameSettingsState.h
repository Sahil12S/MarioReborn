#include "../Game.h"
#include "State.h"
#include "../Game_Components/HUD.h"
#include "../Game_Components/Button.h"

namespace SSEngine
{
    class GameSettingsState : public State
    {
    public:
        GameSettingsState( GameDataRef data );
        ~GameSettingsState();

        // Initializes the state
        void Init();

        void HandleInput();
        void Update( float dt );
        void Draw();

    private:
        /* Variables */
        GameDataRef m_Data;

        HUD* m_Hud;

        std::map<std::string, int> m_KeyBinds;

        sf::RectangleShape m_Background;

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