#ifndef MAINMENUGAME_H
#define MAINMENUGAME_H

#include "MySprite.h"
#include "SFML/Window.hpp"
#include <SFML/Graphics.hpp>
#include <list>
#include "ScreenManager.h"
#include "TextureManager.h"
#include "FontManager.h"

/*TODO
Class à supprimer quand les boutons auront été intégrer au entitées*/
class MainMenuGame
{
public:
	MainMenuGame(void);
	~MainMenuGame(void);


	enum MenuResult { Nothing, Exit, Play };	
	
	struct MenuItem
		{
		public:
			sf::Rect<int> rect;
			MenuResult action;
		};
	
	MenuResult Show(sf::RenderWindow& window);

private:
	MenuResult GetMenuResponse(sf::RenderWindow& window);
	MenuResult HandleClick(int x, int y);
	std::list<MenuItem> _menuItems;
	//sf::Texture image;
};

#endif