#pragma once
#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "LevelManager.h"

class Engine
{
private:
	const sf::Vector2i PREF_RESOLUTION = { 740.0, 360.0 };

	TextureHolder th;
	LevelManager m_LM;

	sf::RenderWindow m_Window;

	sf::View m_MainView;
	sf::View m_BGMainView;
	
	sf::Sprite m_BackgroundSprite;
	sf::Texture m_BackgroundTexture;

	sf::Vector2f m_Resolution;
	sf::Vector2f m_Scale;

	sf::Texture m_TextureTiles;



	sf::Time m_GameTimeTotal;


	//sf::VertexArray m_VALevel;

	void input();
	void update();
	void drawGame();
	void setScale();
	

public:
	Engine();

	void run();
};

#endif // !ENGINE_H
