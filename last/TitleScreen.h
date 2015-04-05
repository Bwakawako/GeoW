#ifndef TITLESCREEN_H
#define TITLESCREEN_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameScreen.h"


class TitleScreen : public ScreenBase
{
public:
	TitleScreen(void);
	~TitleScreen(void);

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

#endif