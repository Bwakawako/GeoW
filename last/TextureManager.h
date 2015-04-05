#pragma once
#include "Entity.h"
#include <iostream>

namespace Util
{
	//Gestionnaire de texture
	class TextureManager
	{
	public:
		static TextureManager *GetInstance();
		static void DestroyInstance();

		sf::Texture &GetTexture(const char* name);

	private:
		TextureManager();
		~TextureManager();
		TextureManager(const TextureManager&);
		TextureManager& operator=(const TextureManager&);

		static TextureManager *instance;
		std::map<std::string, sf::Texture> loadedTextures;
	};
}