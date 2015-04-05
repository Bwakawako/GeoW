#ifndef GAME_H
#define GAME_H
#include <string>
#include <iostream>
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "GameScreen.h"
#include "MySprite.h"
#include "MyText.h"
#include "Entity.h"
#include "MainMenuGame.h"
#include "SplashScreen.h"
#include "ScreenManager.h"


#define ScreenWidth 1024
#define ScreenHeight 768

class Game
{
public:
	Game();
	~Game();
	static Game &GetInstance();
	static void Start();

private:
		//Game();
		static bool IsExiting();
		static void GameCycle(float elapsedTime);
		
		static void ShowSplashScreen(float elapsedTime);
		static void ShowMenu(float elapsedTime);
		static void ShowGame(float elapsedTime);
		
		enum GameState { Uninitialized, ShowingSplash, Paused, ShowingMenu, Playing, Exiting };

		static GameState _gameState;
		static sf::RenderWindow _mainWindow;

};

#endif
