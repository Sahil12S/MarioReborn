#include "pch.h"
#include "Engine.h"

void Engine::update()
{
	m_LM.nextLevel();
	//std::cout << "scale: " << m_Scale.x << ", " << m_Scale.y << std::endl;
	m_LM.setScale(m_Scale.x, m_Scale.y);
	m_LM.setOrigin(0, 0);
}