#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include <string>
#include <iostream>
#include "GameScreen.h"
#include "SplashScreen.h"
#include "TitleScreen.h"

#define ScreenWidth 1024
#define ScreenHeight 768

class ScreenManager
{
public:
	~ScreenManager();
	static ScreenManager &GetInstance();

	void Initialize();
	void LoadContent();
	void Update(float elapsedTime);
	void Draw(sf::RenderWindow &window);

	void AddScreen(ScreenBase *screen);

protected:
private:
	//GameScreen *currentScreen, *newScreen;

	ScreenManager();
	ScreenManager(ScreenManager const&);
	void operator=(ScreenManager const&);

	std::string text;
};

#endif