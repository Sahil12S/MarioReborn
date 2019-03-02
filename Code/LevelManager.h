#pragma once
#ifndef LEVEL_MANAGER_H
#define LEVEL_MANAGER_H

#include <SFML/Graphics.hpp>
#include "TextureHolder.h"

class LevelManager : public sf::Drawable, public sf::Transformable
{
private:
	sf::Texture m_LevelTexture;

	sf::VertexArray m_rVALevel;

	sf::Vector2i m_LevelSize;

	void readLevel(const std::string filename, std::vector< std::pair<int, int>>& level, sf::Vector2i& levelSize);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform *= getTransform();
		states.texture = &m_LevelTexture;
		target.draw(m_rVALevel, states);
	}

public:
	// 16px tiles in our sprite sheet
	const int TILE_SIZE = 16;
	const int VERTS_IN_QUAD = 4;

	//LevelManager(std::string filename);

	sf::Texture& setTexture(std::string filename);

	sf::Vector2i getLevelSize();
	
	//void nextLevel(sf::VertexArray& rVALevel);
	void nextLevel();
};

#endif // !LEVEL_MANAGER_H