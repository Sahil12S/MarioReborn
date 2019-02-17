#include "pch.h"
#include "Engine.h"

Engine::Engine()
{
	// Get screen resolution and create an SFML window and View
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	m_Window.create(VideoMode(resolution.x, resolution.y),
		"Mario Bros. REBORN", Style::Fullscreen);
	/*m_Window.create(VideoMode(1280, 720),
		"Mario Bros. REBORN", Style::Default);*/

	// Initialize the fullscreen view
	m_MainView.setSize(resolution);
	m_HudView.reset(
		FloatRect(0, 0, resolution.x, resolution.y));

	// Scale Factor
	if (resolution.y > 800) {
		m_ScaleFactor = resolution.y / 720;
	}

	// Get background
	m_BackgroundTexture = TextureHolder::GetTexture(
		"graphics/background.png");

	m_BackgroundSprite.setTexture(m_BackgroundTexture);

	// Load texture for world vertex array
	m_WorldTiles = TextureHolder::GetTexture("graphics/worldConstruct.png");
}

void Engine::run()
{
	// Timing
	Clock clock;

	while (m_Window.isOpen())
	{
		Time dt = clock.restart();

		// Update the total game time
		m_GameTimeTotal += dt;

		// Make decimal fraction from the delta tile
		float dtAsSeconds = dt.asSeconds();

		// Call each part of game loop in turn
		input();
		update(dtAsSeconds);
		draw();
	}
}

Engine::~Engine()
{
	for (int i = 0; i < m_LM.getLevelSize().y; ++i)
	{
		for (int j = 0; j < m_LM.getLevelSize().x; ++j)
		{
			delete &m_ArrayLevel[i][j];

		}
		delete[] & m_ArrayLevel[i];
	}
	delete[] & m_ArrayLevel;
}