#include <iostream>
#include "AssetManager.h"

namespace SSEngine
{
    AssetManager::AssetManager()
    {}

    AssetManager::~AssetManager()
    {}

    void AssetManager::LoadTexture(std::string name, std::string fileName)
    {
        sf::Texture tex;

        // TODO: Add try-catch block
        if ( tex.loadFromFile( fileName ) )
        {

            m_Textures[name] = tex;
        }
    }

    sf::Texture& AssetManager::GetTexture(std::string name)
    {
        // TODO: Handle key not found exception
        try
        {
            return m_Textures.at( name );
        }
        catch ( std::exception& e)
        {
            std::cerr << e.what() << std::endl;
            exit(-1);
        }

        // return m_Textures.at( name );
    }

    void AssetManager::LoadFont(std::string name, std::string fileName)
    {
        sf::Font font;

        // TODO: Add try-catch
        if ( font.loadFromFile( fileName ) )
        {
            m_Fonts[name] = font;
        }
    }

    sf::Font& AssetManager::GetFont(std::string name)
    {
        return m_Fonts.at( name );
    }

    void AssetManager::LoadAudio(std::string name, std::string fileName)
    {
        sf::SoundBuffer sb;

        if ( sb.loadFromFile( fileName ))
        {
            m_Audios[name] = sb;
        }
    }

    sf::SoundBuffer& AssetManager::GetAudio(std::string name)
    {
        return m_Audios.at( name );
    }
}