#include "State.h"
#include "Game.h"
#include "Entity.h"

namespace MarioEngine
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

        Entity* m_Player;

        sf::Sprite m_BackgroundSprite;
    };
}