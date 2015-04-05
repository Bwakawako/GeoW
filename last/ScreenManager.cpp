#include "ScreenManager.h"
#include<SFML/Graphics.hpp>

ScreenBase *currentScreen, *newScreen;

ScreenManager::ScreenManager()
{	
}
ScreenManager::~ScreenManager()
{
}

ScreenManager &ScreenManager::GetInstance()
{
	static ScreenManager instance;
	return instance;
}

void ScreenManager::AddScreen(ScreenBase *screen)
{
	if (currentScreen != NULL)
	{
		currentScreen->UnloadContent();
		delete currentScreen;
	}
	currentScreen = screen;
	currentScreen->LoadContent();
}

void ScreenManager::Initialize()
{
	currentScreen = new SplashScreen();
}
void ScreenManager::LoadContent()
{
	currentScreen->LoadContent();
}
void ScreenManager::Update(float elapsedTime)
{
	currentScreen->Update(elapsedTime);
}
void ScreenManager::Draw(sf::RenderWindow &window)
{
	currentScreen->Draw(window);
}
