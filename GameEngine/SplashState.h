#include "State.h"
#include "Game.h"
#include "MainMenuState.h"

namespace MarioEngine
{
    class SplashState : public State
    {
    public:
        /*
         * Splash State doesn't need any key bindings
         */
        SplashState( GameDataRef data );

        void Init();

        void HandleInput();
        void Update( float dt );
        void Draw();

        // TODO: Initialize keys in game
        void InitKeyBinds();

    private:
        GameDataRef m_Data;
        sf::Clock m_Clock;
        sf::Sprite m_BackgroundSprite;

        std::map<std::string, int> m_KeyBinds;
    };
}