#include "SplashScreen.h"
#include "ScreenManager.h"
#include "EntitiesManager.h"
#include "TextureManager.h"

using namespace Entities;
using namespace Util;

SplashScreen::SplashScreen(void)
{
}

SplashScreen::~SplashScreen(void)
{
}

void SplashScreen::LoadContent()
{
	EntitiesManager::GetInstance()->Load("resources\\SplashScreen.xml");
}

void SplashScreen::UnloadContent()
{
	EntitiesManager::DestroyInstance();
	TextureManager::DestroyInstance();
	ScreenBase::UnloadContent();
}
void SplashScreen::Update(float elapsedTime)
{
	EntitiesManager::GetInstance()->Update(elapsedTime);
}
void SplashScreen::Draw(sf::RenderWindow &window)
{
	EntitiesManager::GetInstance()->Draw(window);

	window.draw(sprite);
}