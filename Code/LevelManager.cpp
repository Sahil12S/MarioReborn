#include "pch.h"
#include "LevelManager.h"
#include <fstream>
#include <iostream>

using namespace sf;

Texture& LevelManager::setTexture(std::string filename)
{
	m_LevelTexture = TextureHolder::GetTexture("graphics/mariotileset.png");
	return m_LevelTexture;
}

//void LevelManager::nextLevel(VertexArray& rVALevel)
void LevelManager::nextLevel()
{
	std::vector< std::pair< int, int>> level;
	//Vector2i levelSize;
	readLevel("levels/level1.txt", level, m_LevelSize);

	m_rVALevel.setPrimitiveType(Quads);
	m_rVALevel.resize(m_LevelSize.x * m_LevelSize.y * VERTS_IN_QUAD);

	for (unsigned int i = 0; i < m_LevelSize.x; ++i)
	{
		for (unsigned int j = 0; j < m_LevelSize.y; ++j)
		{
			// get the current tile number
			std::pair<int, int> tileNumber = level[i + j * m_LevelSize.x];

			// find its position in the tileset texture
			int tu = tileNumber.first % (m_LevelTexture.getSize().x / TILE_SIZE);
			int tv = tileNumber.second % (m_LevelTexture.getSize().y / TILE_SIZE);

			// get a pointer to the current tile's quad
			sf::Vertex* quad = &m_rVALevel[(i + j * m_LevelSize.x) * 4];

			// define its 4 corners
			quad[0].position = sf::Vector2f(i * TILE_SIZE, j * TILE_SIZE);
			quad[1].position = sf::Vector2f((i + 1) * TILE_SIZE, j * TILE_SIZE);
			quad[2].position = sf::Vector2f((i + 1) * TILE_SIZE, (j + 1) * TILE_SIZE);
			quad[3].position = sf::Vector2f(i * TILE_SIZE, (j + 1) * TILE_SIZE);

			// define its 4 texture coordinates
			quad[0].texCoords = sf::Vector2f(tu * TILE_SIZE, tv * TILE_SIZE);
			quad[1].texCoords = sf::Vector2f((tu + 1) * TILE_SIZE, tv * TILE_SIZE);
			quad[2].texCoords = sf::Vector2f((tu + 1) * TILE_SIZE, (tv + 1) * TILE_SIZE);
			quad[3].texCoords = sf::Vector2f(tu * TILE_SIZE, (tv + 1) * TILE_SIZE);
		}
	}
	//std::cout << level.size() << std::endl;
	//std::cout << "LM: " << rVALevel[1].position.x << std::endl;

}

void LevelManager::readLevel(const std::string filename, std::vector< std::pair<int, int>>& level, Vector2i& levelSize)
{
	std::ifstream inputfile(filename);
	std::string s;

	levelSize.y = 0;

	std::string num = "";
	while (getline(inputfile, s))
	{
		levelSize.x = 0;
		std::string str = "";
		for (int j = 0; j <= s.length(); j++)
		{
			if (j != s.length() && s[j] != '\t')
			{
				str += s[j];
			}
			else
			{
				num = "";
				std::pair<int, int> coords;
				for (int i = 1; i < str.length() - 1; i++)
				{
					if (str[i] != ',')
					{
						num += str[i];
					}
					else
					{
						coords.first = stoi(num);
						num = "";
					}
				}
				coords.second = stoi(num);
				level.emplace_back(coords);
				++levelSize.x;
				str = "";
			}
		}
		++levelSize.y;
	}
}

Vector2i LevelManager::getLevelSize()
{
	return m_LevelSize;
}