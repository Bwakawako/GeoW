#include "FontManager.h"
#include "Logger.h"

using namespace Util;

FontManager *FontManager::GetInstance()
{
	if (instance == NULL)
	{
		instance = new FontManager;
	}
	return instance;
}

void FontManager::DestroyInstance()
{
	delete instance;
	instance = NULL;
}

sf::Font FontManager::GetFont(const char* name)
{
	//Si la police n'a pas été chargé, on la charge
	if (loadedFonts.count(name) == 0)
	{
		sf::Font font;
		if (font.loadFromFile(name))
			loadedFonts[name] = font;
		else
		{
			Logger log("resources\\log.txt");
			log.write("La police n'a pas pu etre charge", Logger::ERROR);
		}
	}
	return loadedFonts[name];
}

FontManager::FontManager()
{

}

FontManager::FontManager(const FontManager&)
{

}

FontManager::~FontManager()
{

}

FontManager& FontManager::operator=(const FontManager&)
{
	FontManager *res = new FontManager;
	return *res;
}

FontManager * FontManager::instance = NULL;
