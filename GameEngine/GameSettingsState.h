#include "Game.h"
#include "State.h"

namespace MarioEngine
{
    class GameSettingsState : public State
    {
    public:
        GameSettingsState( GameDataRef data );

        void Init();
        // TODO: Initialize key binds in game
        void InitKeyBinds();
        void HandleInput();
        void Update( float dt );
        void Draw();

    private:
        GameDataRef m_Data;

        std::map<std::string, int> m_KeyBinds;

        sf::Sprite m_BackgroundSprite;
    };
}