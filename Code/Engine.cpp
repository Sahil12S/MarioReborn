#include "pch.h"
#include "Engine.h"
#include <iostream>

Engine::Engine()
{
	// Get the screen resolution and create an SFML window and View
	//sf::Vector2f resolution;
	m_Resolution.x = sf::VideoMode::getDesktopMode().width;
	m_Resolution.y = sf::VideoMode::getDesktopMode().height;

	m_Window.create(sf::VideoMode(m_Resolution.x, m_Resolution.y),
		"Mario", sf::Style::Fullscreen);

	m_MainView.setSize(m_Resolution);
	m_MainView.reset(sf::FloatRect(0, 0, m_Resolution.x, m_Resolution.y));

	m_BackgroundTexture = TextureHolder::GetTexture("graphics/background.png");

	m_BackgroundSprite.setTexture(m_BackgroundTexture);

	//m_TextureTiles = TextureHolder::GetTexture("graphics/mariotileset.png");
	m_TextureTiles = m_LM.setTexture("graphics/mariotileset.png");
}

void Engine::run()
{
	sf::Clock clock;
	setScale();

	while (m_Window.isOpen())
	{
		sf::Time dt = clock.restart();

		m_GameTimeTotal += dt;
		float dtAsSeconds = dt.asSeconds();

		input();
		update();
		drawGame();
	}
}

void Engine::setScale()
{
	//std::cout << m_Resolution.x / PREF_RESOLUTION.x << std::endl;
	m_Scale.x = m_Resolution.x / PREF_RESOLUTION.x;
	m_Scale.y = m_Resolution.y / PREF_RESOLUTION.y;
}