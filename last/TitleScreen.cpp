#include "TitleScreen.h"
#include "ScreenManager.h"
#include "EntitiesManager.h"

using namespace Entities;

TitleScreen::TitleScreen(void)
{
}


TitleScreen::~TitleScreen(void)
{
}

void TitleScreen::LoadContent()
{
	EntitiesManager::GetInstance()->Load("resources\\TitleScreen.xml");
}

void TitleScreen::UnloadContent()
{
	EntitiesManager::DestroyInstance();
	ScreenBase::UnloadContent();
}
void TitleScreen::Update(float elapsedTime)
{
	EntitiesManager::GetInstance()->Update(elapsedTime);
}
void TitleScreen::Draw(sf::RenderWindow &window)
{
	EntitiesManager::GetInstance()->Draw(window);
}