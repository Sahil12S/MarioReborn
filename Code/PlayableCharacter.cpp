#include "pch.h"
#include "PlayableCharacter.h"
#include <iostream>

using namespace sf;

void PlayableCharacter::spawn(Vector2f startPosition, float gravity)
{
	m_Position.x = startPosition.x;
	m_Position.y = startPosition.y;

	m_Gravity = gravity;

	m_Sprite.setPosition(m_Position);
}

void PlayableCharacter::update(float elapsedTime)
{
	if (m_RightPressed)
	{
		m_Position.x += m_Speed * elapsedTime;
		//std::cout << m_Position.x << std::endl;
	}

	if (m_LeftPressed)
	{
		m_Position.x -= m_Speed * elapsedTime;
		//std::cout << m_Position.x << std::endl;
	}
}

FloatRect PlayableCharacter::getPosition()
{
	return m_Sprite.getGlobalBounds();
}

Vector2f PlayableCharacter::getCenter()
{
	return Vector2f(
		m_Position.x + m_Sprite.getGlobalBounds().width / 2,
		m_Position.y + m_Sprite.getGlobalBounds().height / 2);
}

Sprite PlayableCharacter::getSprite()
{
	return m_Sprite;
}

void PlayableCharacter::stopRight(float position)
{
	m_Position.x = position - m_Sprite.getGlobalBounds().width;
	m_Sprite.setPosition(m_Position);
}

void PlayableCharacter::stopLeft(float position)
{
	m_Position.x = position + m_Sprite.getGlobalBounds().width;
	m_Sprite.setPosition(m_Position);
}