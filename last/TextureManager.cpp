#include "TextureManager.h"
#include "Logger.h"

using namespace Util;

TextureManager * TextureManager::GetInstance()
{
	if (instance == NULL)
	{
		instance = new TextureManager;
	}
	return instance;
}

void TextureManager::DestroyInstance()
{
	delete instance;
	instance = NULL;
}

sf::Texture & TextureManager::GetTexture(const char* name)
{
	//Si la texture n'a pas été chargé, on la charge
	if (loadedTextures.count(name) == 0)
	{
		sf::Texture texture;
		if (texture.loadFromFile(name))
			loadedTextures[name] = texture;
		else
		{
			Logger log("resources\\log.txt");
			log.write("La police n'a pas pu etre charge", Logger::ERROR);
		}
	}
	return loadedTextures[name];
}

TextureManager::TextureManager()
{

}

TextureManager::TextureManager(const TextureManager&)
{

}

TextureManager::~TextureManager()
{

}

TextureManager& TextureManager::operator=(const TextureManager&)
{
	TextureManager *res = new TextureManager;
	return *res;
}

TextureManager * TextureManager::instance = NULL;
