#include "pch.h"
#include "Engine.h"
#include <iostream>

void Engine::drawGame()
{
	m_Window.clear(sf::Color::White);

	m_Window.setView(m_BGMainView);

	m_Window.draw(m_BackgroundSprite);

	m_Window.setView(m_MainView);

	//std::cout << m_VALevel.getBounds().top << std::endl;
	
	//m_Window.draw(m_VALevel, &m_TextureTiles);
	m_Window.draw(m_LM);

	m_Window.display();
}