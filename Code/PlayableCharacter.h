#pragma once
#ifndef PLAYABLE_CHARACTER_H
#define PLAYABLE_CHARACTER_H

#include <SFML/Graphics.hpp>

class PlayableCharacter
{
protected:
	sf::Sprite m_Sprite;

	bool m_IsJumping;
	bool m_IsFalling;

	bool m_LeftPressed;
	bool m_RightPressed;

	bool m_JustJumped;
	bool m_IsDucking;

private:
	float m_Gravity;

	float m_Speed = 600;

	sf::Vector2f m_Position;

	// Character's body parts for collision detection
	sf::FloatRect m_Head;
	sf::FloatRect m_Feet;
	sf::FloatRect m_Left;
	sf::FloatRect m_Right;

	sf::Texture m_Texture;

public:
	void spawn(sf::Vector2f startPosition, float gravity);

	bool virtual handleInput() = 0;

	sf::FloatRect getPosition();

	/*sf::FloatRect getHead();
	sf::FloatRect getFeet();
	sf::FloatRect getLeft();
	sf::FloatRect getRight();*/

	sf::Sprite getSprite();

	//void stopFalling(float position);
	void stopRight(float position);
	void stopLeft(float position);
	/*void stopJump();
	void stopDuck();*/

	sf::Vector2f getCenter();

	void update(float elapsedTime);
};


#endif // !PLAYABLE_CHARACTER_H