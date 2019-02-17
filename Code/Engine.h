#pragma once
#include "TextureHolder.h"
#include "LevelManager.h"

class Engine
{
private:
	// The texture holder
	TextureHolder th;

	// Level manager
	LevelManager m_LM;

	// Constants
	const int TILE_SIZE_GROUND = 16;
	const int VERTS_IN_QUAD = 4;

	// Gravity
	const int GRAVITY = 300;

	// Scaling factor for higher resolution screen
	float m_ScaleFactor = 1;

	// A regular render window
	RenderWindow m_Window;

	// Main view
	View m_MainView;

	// Background view
	View m_BGMainView;

	// HUD View
	View m_HudView;

	// Declare a sprite and a texture for the background. (Solid light-blue color fill ?????)
	Sprite m_BackgroundSprite;
	Texture m_BackgroundTexture;

	// Is the game currently playing?
	bool m_IsPlaying = false;

	// Time remaining in current level
	float m_TimeRemaining = 10;
	Time m_GameTimeTotal;

	// Load first/new level?
	bool m_isNewLevelRequired = true;

	// The vertex array for level design
	VertexArray m_VALevel;

	// 2D array with the map for the level
	// A pointer to a pointer
	//int** m_ArrayLevel = NULL;
	pair<int, int>** m_ArrayLevel = NULL;

	// Texture for Mario world
	Texture m_WorldTiles;

	// Private functions for internal use only.

	// Handle all player inputs
	void input();

	// Update all variables and positions of objects
	void update(float dtAsSeconds);

	// Draw updated frame on screen
	void draw();

	// Load new level
	void loadLevel();

	
public:
	// The engine constructor
	Engine();

	// The destructor
	~Engine();

	// Run will call all private functions
	void run();
};