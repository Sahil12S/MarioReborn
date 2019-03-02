#include "pch.h"
#include "Mario.h"
#include "TextureHolder.h"
//#include "Engine.h"
#include <iostream>

using namespace sf;

Mario::Mario()
{
	m_Sprite = Sprite(TextureHolder::GetTexture(
		"graphics/mario.png", IntRect(0 ,33, 16, 16), true));

	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	Vector2f pref_reso = { 740.0, 360.0 };
	
	Vector2f scale;
	scale.x = resolution.x / pref_reso.x;
	scale.y = resolution.y / pref_reso.y;

	m_Sprite.setScale(scale.x, scale.y);
}

bool Mario::handleInput()
{
	m_JustJumped = false;

	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		if (!m_IsJumping && !m_IsFalling)
		{
			m_IsJumping = true;
			m_JustJumped = true;
		}
	}
	else
	{
		m_IsJumping = false;
		m_IsFalling = true;
	}

	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		m_LeftPressed = true;
	}
	else
	{
		m_LeftPressed = false;
	}

	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		//std::cout << "Right" << std::endl;
		m_RightPressed = true;
	}
	else
	{
		m_RightPressed = false;
	}

	return m_JustJumped;
}