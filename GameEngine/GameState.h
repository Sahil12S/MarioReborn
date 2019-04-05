#include "State.h"
#include "Game.h"
#include "Player.h"

namespace SSEngine
{
    class GameState : public State
    {
    public:
        GameState( GameDataRef data );

        void Init();
        void InitKeyBinds();
        void HandleInput();
        void Update( float dt );
        void Draw();

    private:
        GameDataRef m_Data;

        std::map<std::string, int> m_KeyBinds;

        Player* m_Player;

        sf::Sprite m_BackgroundSprite;
    };
}