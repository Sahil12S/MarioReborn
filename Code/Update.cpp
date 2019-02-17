#include "pch.h"
#include "Engine.h"

void Engine::update(float dtAsSeconds)
{
	if (m_isNewLevelRequired)
	{
		loadLevel();
	}

	if (m_IsPlaying)
	{
		m_TimeRemaining -= dtAsSeconds;

		if (m_TimeRemaining <= 0)
		{
			m_isNewLevelRequired = true;
		}
	}

	m_MainView.setCenter(VideoMode::getDesktopMode().width / 2, VideoMode::getDesktopMode().height / 2);
}