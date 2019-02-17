#pragma once
#ifndef TEXTURE_HOLDER_H
#define TEXTURE_HOLDER_H

#include <SFML/Graphics.hpp>
#include <map>


using namespace sf;
using namespace std;

class TextureHolder
{
private:
	// Map to hold relative pair of string and texture
	map<string, Texture> m_Textures;

	// A pointer of the same type as the class itself
	// The one and only instance
	static TextureHolder* m_s_Instance;

public:
	TextureHolder();
	static Texture& GetTexture(string const& filename);
};

#endif // !TEXTURE_HOLDER_H
