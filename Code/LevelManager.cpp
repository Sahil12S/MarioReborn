#include "pch.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>
#include <fstream>
#include "LevelManager.h"

#include <iostream>

using namespace sf;
using namespace std;

pair<int, int>** LevelManager::nextLevel(VertexArray& rVaLevel)
{
	m_LevelSize.x = 0;
	m_LevelSize.y = 0;

	// Get the next level
	m_CurrentLevel++;
	//if (m_CurrentLevel > NUM_LEVELS)
	//{
	//	m_CurrentLevel = 1;
	//	m_TimeModifier -= .1f;
	//}

	// Load the appropriate level from a text file
	string levelToLoad;
	switch (m_CurrentLevel)
	{
	case 1:
		levelToLoad = "levels/level1.txt";
		m_StartPosition.x = 0;
		m_StartPosition.y = 0;
		m_BaseTimeLimit = 30.0f;
		break;

	/*case 2:
		levelToLoad = "levels/level2.txt";
		m_StartPosition.x = 100;
		m_StartPosition.y = 3600;
		m_BaseTimeLimit = 100.0f;
		break;

	case 3:
		levelToLoad = "levels/level3.txt";
		m_StartPosition.x = 1250;
		m_StartPosition.y = 0;
		m_BaseTimeLimit = 30.0f;
		break;

	case 4:
		levelToLoad = "levels/level4.txt";
		m_StartPosition.x = 50;
		m_StartPosition.y = 200;
		m_BaseTimeLimit = 50.0f;
		break;*/

	} //  End switch

	ifstream inputFile(levelToLoad);
	string s;

	// Count the number of rows in the file
	while (getline(inputFile, s))
	{
		++m_LevelSize.y;
	}

	// Store the length of the rows

	// Since its in (x,y) separated by ";", we can count number of ";"
	// to get length of row

	m_LevelSize.x = 0;

	for (char c : s)
	{
		if (c == ';')
		{
			m_LevelSize.x++;
		}
	}

	//m_LevelSize.x = s.length();
	std::cout << "our level is: ";
	std::cout << m_LevelSize.x << " by " << m_LevelSize.y << std::endl;

	// Go back to the start of the file
	inputFile.clear();
	inputFile.seekg(0, ios::beg);		// Resets stream back to before the first character.


	/* 
	This is how we are going to store coordinates of our sprite

	[ [(0,0), (1,0), (2,0)],
	[(0,1), (1,1), (2,1)],
	[(0,2), (1,2), (2,2)]]
	*/
	// Prepare the 2d array to hold the int values from the file
	//int** arrayLevel = new int*[m_LevelSize.y];
	pair<int, int>** arrayLevel = new pair<int, int>*[m_LevelSize.y];

	for (int i = 0; i < m_LevelSize.y; ++i)
	{
		// Add a new array in to each array element
		arrayLevel[i] = new pair<int, int>[m_LevelSize.x];
	}

	// Loop through the file and store all the values in the 2d array
	string row;
	int y = 0;
	while (inputFile >> row)
	{
		for (int x = 0; x < row.length(); x += 2)
		{

			char val = row[x++];
			int x_coord = atoi(&val);
			val = row[++x];
			int y_coord = atoi(&val);

			arrayLevel[y][x] = make_pair(x_coord, y_coord);		// Char to int
		}

		y++;
	}

	//cout << "height of array: " << arrayLevel << endl;

	/*cout << "Check our arrayLevel" << endl;
	for (int i = 0; i < m_LevelSize.y; i++)
	{
		for (int j = 0; j < m_LevelSize.x; j++)
		{
			cout << arrayLevel[i][j].first << "," << arrayLevel[i][j].second << "\t";
		}
		cout << endl;
	}*/

	// Close the file
	inputFile.close();
	`
	// What type of primitive are we using?
	rVaLevel.setPrimitiveType(Quads);

	// Set the size of the vertex array
	rVaLevel.resize(m_LevelSize.x * m_LevelSize.y * VERTS_IN_QUAD);

	// Start at the beginning of the vertex array
	int currentVertex = 0;

	for (int x = 0; x < m_LevelSize.x; x++)
	{
		for (int y = 0; y < m_LevelSize.y; y++)
		{
			// Position each vertex in the current quad
			rVaLevel[currentVertex + 0].position =
				Vector2f(x * TILE_SIZE, y * TILE_SIZE);

			rVaLevel[currentVertex + 1].position =
				Vector2f((x * TILE_SIZE) + TILE_SIZE, y * TILE_SIZE);

			rVaLevel[currentVertex + 2].position =
				Vector2f((x * TILE_SIZE) + TILE_SIZE,
				(y * TILE_SIZE) + TILE_SIZE);

			rVaLevel[currentVertex + 3].position =
				Vector2f(x * TILE_SIZE, (y * TILE_SIZE) + TILE_SIZE);

			// Which tile from the sprite sheet should we use
			int verticalOffset = arrayLevel[y][x].second * TILE_SIZE;
			int horizontalOffset = arrayLevel[y][x].first * TILE_SIZE;
			// int horizontalOffset = 

			rVaLevel[currentVertex + 0].texCoords =
				Vector2f(0 + horizontalOffset, 0 + verticalOffset);

			rVaLevel[currentVertex + 1].texCoords =
				Vector2f(TILE_SIZE + horizontalOffset, 0 + verticalOffset);

			rVaLevel[currentVertex + 2].texCoords =
				Vector2f(TILE_SIZE + horizontalOffset, TILE_SIZE + verticalOffset);

			rVaLevel[currentVertex + 0].texCoords =
				Vector2f(0 + horizontalOffset, TILE_SIZE + verticalOffset);

			// Position ready for the next four vertices
			currentVertex += VERTS_IN_QUAD;
		}
	}

	return arrayLevel;

} //  End of next level function

Vector2i LevelManager::getLevelSize()
{
	return m_LevelSize;
}

int LevelManager::getCurrentLevel()
{
	return m_CurrentLevel;
}

float LevelManager::getTimeLimit()
{
	return m_BaseTimeLimit;
}

Vector2f LevelManager::getStartPosition()
{
	return m_StartPosition;
}