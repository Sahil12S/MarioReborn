#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

#include "AssetManager.h"
#include "InputManager.h"
#include "StateMachine.h"

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