#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

#include "Engine_Managers/AssetManager.h"
#include "Engine_Managers/InputManager.h"
#include "Engine_Managers/StateMachine.h"
#include "Entities/Entity.h"

namespace SSEngine
{
    struct GameData
    {
        StateMachine machine;
        AssetManager assets;
        InputManager input;
        sf::RenderWindow window;
    };

    typedef std::shared_ptr<GameData> GameDataRef;

    class Game
    {
    public:
        Game( unsigned int width, unsigned int height, std::string title );


    private:
        float dt;
        // const float dt = 1.0f / 60.0f;

        sf::Clock m_Clock;

        GameDataRef m_Data = std::make_shared<GameData>();

        void UpdateDt();
        void Run();

    };
}