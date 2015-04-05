#include "MainMenuGame.h"


MainMenuGame::MainMenuGame(void)
{
}	

MainMenuGame::~MainMenuGame(void)
{
}

MainMenuGame::MenuResult MainMenuGame::Show(sf::RenderWindow& window)
{
	//Play menu item coordinates
	MenuItem playButton;
	playButton.rect.top= 145;
	playButton.rect.width = 380;
	playButton.rect.left = 0;
	playButton.rect.height = 1023;
	playButton.action = Play;

	//Exit menu item coordinates
	MenuItem exitButton;
	exitButton.rect.left = 0;
	exitButton.rect.height = 1023;
	exitButton.rect.top = 383;
	exitButton.rect.width = 560;
	exitButton.action = Exit;

	_menuItems.push_back(playButton);
	_menuItems.push_back(exitButton);

	return GetMenuResponse(window);
}

MainMenuGame::MenuResult MainMenuGame::HandleClick(int x, int y)
{
	std::list<MenuItem>::iterator it;

	for ( it = _menuItems.begin(); it != _menuItems.end(); it++)
	{
		sf::Rect<int> menuItemRect = (*it).rect;
		if( menuItemRect.width > y 
			&& menuItemRect.top < y 
			&& menuItemRect.left < x 
			&& menuItemRect.height > x)
			{
				return (*it).action;
			}
	}

	return Nothing;
}

MainMenuGame::MenuResult  MainMenuGame::GetMenuResponse(sf::RenderWindow& window)
{
	sf::Event menuEvent;

	while(42 != 43)
	{

		while(window.pollEvent(menuEvent))
		{
			if(menuEvent.type == sf::Event::MouseButtonPressed)
			{

				return HandleClick(menuEvent.mouseButton.x,menuEvent.mouseButton.y);
			}
			if(menuEvent.type == sf::Event::Closed)
			{
				return Exit;
			}
		}
	}
}