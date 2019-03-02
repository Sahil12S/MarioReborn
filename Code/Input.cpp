#include "pch.h"
#include "Engine.h"

void Engine::input()
{
	sf::Event event;

	while (m_Window.pollEvent(event))
	{
		if (event.type == sf::Event::KeyPressed)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				m_Window.close();
			}
		}
	}
}