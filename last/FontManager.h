#pragma once
#include "Entity.h"
#include <iostream>

namespace Util
{
	class FontManager
	{
	public:
		static FontManager *GetInstance();
		static void DestroyInstance();

		sf::Font GetFont(const char* name);

	private:
		FontManager();
		~FontManager();
		FontManager(const FontManager&);
		FontManager& operator=(const FontManager&);

		static FontManager *instance;
		std::map<std::string, sf::Font> loadedFonts;

	};
}