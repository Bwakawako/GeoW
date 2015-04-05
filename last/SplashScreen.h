#pragma once

#include "GameScreen.h"
#include <iostream>
#include <SFML/Graphics.hpp>

class SplashScreen : public ScreenBase
{
public:
	SplashScreen();
	~SplashScreen();

	void LoadContent(); 
	void UnloadContent();
	void Update(float elapsedTime);
	void Draw(sf::RenderWindow &window);
private:
	sf::Text text;
	sf::Font font;
	sf::Texture texture;
	sf::Sprite sprite;

};
