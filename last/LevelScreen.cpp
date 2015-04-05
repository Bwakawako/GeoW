#include "LevelScreen.h"
#include "EntitiesManager.h"
#include "GameState.h"

using namespace Entities;
using namespace MyGeometryWars;

LevelScreen::LevelScreen()
{

}

LevelScreen::~LevelScreen()
{

}

void LevelScreen::LoadContent()
{
	char levelPath[30];
	
	sprintf(levelPath, "resources\\levels\\lvl%d.xml", GameState::GetInstance()->CurrentLevel());

	GameState::GetInstance()->AreAllEnemiesDestroyed(false);
	EntitiesManager::GetInstance()->Load(levelPath);
}

void LevelScreen::UnloadContent()
{
	EntitiesManager::DestroyInstance();
	ScreenBase::UnloadContent();
}

void LevelScreen::Update(float elapsedTime)
{
	GameState &gameState(*(GameState::GetInstance()));

	EntitiesManager::GetInstance()->Update(elapsedTime);

	if (gameState.AreAllEnemiesDestroyed())
		StartNextLevel();
}

void LevelScreen::Draw(sf::RenderWindow &window)
{
	EntitiesManager::GetInstance()->Draw(window);
}

//Permet de charger le niveau suivant. Le vaisseau est conservé 
//entre deux niveaux.
void LevelScreen::StartNextLevel()
{
	GameState &gameState(*(GameState::GetInstance()));

	gameState.CurrentLevel(gameState.CurrentLevel() + 1);
	EntitiesManager::GetInstance()->Clean();
	GameState::DestroyInstance();
	LoadContent();
}

