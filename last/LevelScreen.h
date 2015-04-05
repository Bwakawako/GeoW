#pragma once

#include "GameScreen.h"
#include <iostream>
#include <SFML/Graphics.hpp>

class LevelScreen : public ScreenBase
{
public:
	LevelScreen();
	~LevelScreen();

	void LoadContent();
	void UnloadContent();
	void Update(float elapsedTime);
	void Draw(sf::RenderWindow &window);
private:
	void StartNextLevel();
};