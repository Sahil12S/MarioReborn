#include "State.h"
#include "../Game.h"
#include "../Entities/Player.h"

namespace SSEngine
{
    class GameState : public State
    {
    public:
        GameState( GameDataRef data );
        ~GameState();

        void Init() override;

        void HandleInput() override;
        void Update( float dt ) override;
        void Draw() override;


    private:
        /* Variables */
        GameDataRef m_Data;

        std::map<std::string, int> m_KeyBinds;

        Player* m_Player;

        sf::Sprite m_BackgroundSprite;

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