#include "Game.h"
#include "EventManager.h"
#include "LevelScreen.h"
#include "Logger.h"

using namespace MyGeometryWars;

Game::Game()
{
}

Game::~Game()
{
}

Game &Game::GetInstance()
{
	static Game instance;
	return instance;
}

void Game::Start(void)
{
	_mainWindow.create(sf::VideoMode(ScreenWidth,ScreenHeight,32),"Game");
	sf::Clock clock;
	sf::Time elapsedTime;
	sf::Event event;
	EventManager::GetInstance()->SetWindow(&_mainWindow);

	if(_gameState != Uninitialized)
		return;
	_gameState = Game::ShowingSplash;

	Logger log("resources\\log.txt");
	log.write("poney", Logger::ERROR);

	while(!IsExiting())
	{
		sf::sleep(sf::milliseconds(20));
		elapsedTime = clock.restart();
		GameCycle(elapsedTime.asSeconds());

		//TODO : il faut cliquer plein de fois pour pouvoir quitter...
		while (_mainWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				_gameState = Game::Exiting;
		}
	}

	_mainWindow.close();
}


bool Game::IsExiting()
{
	if(_gameState == Game::Exiting) 
		return true;
	else 
		return false;	
}

 void Game::GameCycle(float elapsedTime)
 {
	 sf::Event currentEvent;
	_mainWindow.pollEvent(currentEvent);
 

	switch(_gameState)
	{
		
		case Game::ShowingSplash:
			{
				ShowSplashScreen(elapsedTime);
				break;
			}
		case Game::ShowingMenu:
			{
				ShowMenu(elapsedTime);
				break;
			}
		case Game::Playing:
			{
				ShowGame(elapsedTime);
				break;
			}
	}
 }

 void Game::ShowSplashScreen(float elapsedTime)
{
	static bool loaded = false;

	if (loaded == false)
	{
		ScreenManager::GetInstance().Initialize();
		ScreenManager::GetInstance().LoadContent();
		loaded = true;
	}
	ScreenManager::GetInstance().Update(elapsedTime);
	ScreenManager::GetInstance().Draw(_mainWindow);

	_mainWindow.display();

	if (EventManager::GetInstance()->AnyButtonClicked())
	{
		_gameState = Game::ShowingMenu;
		loaded = false;
		return;
	}
 }

 void Game::ShowMenu(float elapsedTime)
{
	static bool loaded = false;
	MainMenuGame mainMenu;

	if (loaded == false)
	{
		ScreenManager::GetInstance().AddScreen(new TitleScreen);
		loaded = true;
	}

	ScreenManager::GetInstance().Update(elapsedTime);

	_mainWindow.clear(sf::Color(0,0,0));
	ScreenManager::GetInstance().Draw(_mainWindow);
	_mainWindow.display();

	MainMenuGame::MenuResult result = mainMenu.Show(_mainWindow);

	switch(result)
	{
		case MainMenuGame::Exit:
			_gameState = Exiting;
			break;
		case MainMenuGame::Play:
			_gameState = Playing;
			loaded = false;
			break;
	}
}

 void Game::ShowGame(float elapsedTime)
 {
	 static bool loaded = false;

	 if (loaded == false)
	 {
		ScreenManager::GetInstance().AddScreen(new LevelScreen);
		loaded = true;
	 }

	 ScreenManager::GetInstance().Update(elapsedTime);

	 _mainWindow.clear(sf::Color(0,0,0));
	 ScreenManager::GetInstance().Draw(_mainWindow);
	 _mainWindow.display();
 
	 //TODO à tester
	 if(EventManager::GetInstance()->PausePressed() || EventManager::GetInstance()->EscapePressed())
	 {
		 Game::_gameState = ShowingMenu;
		 loaded = false;
	 }
 }

 Game::GameState Game::_gameState = Uninitialized;
 sf::RenderWindow Game::_mainWindow;