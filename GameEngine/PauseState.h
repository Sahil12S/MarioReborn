#include "State.h"
#include "Game.h"

namespace SSEngine
{
    class PauseState : public  State
    {
    public:
        explicit PauseState( GameDataRef data );

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
        sf::Sprite m_PauseScreenMenu;
    };
}