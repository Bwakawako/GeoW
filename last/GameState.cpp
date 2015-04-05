#include "GameState.h"
#include <iostream>

namespace MyGeometryWars
{
	int GameState::CurrentLevel()
	{
		return currentLevel;
	}

	void GameState::CurrentLevel(int level)
	{
		if (level > 0)
			currentLevel = level;
	}

	bool GameState::AreAllEnemiesDestroyed()
	{
		return areAllEnemiesDestroyed;
	}

	void GameState::AreAllEnemiesDestroyed(bool allEnemyDestroyed)
	{
		areAllEnemiesDestroyed = allEnemyDestroyed;
	}

	GameState* GameState::GetInstance()
	{
		if (instance == NULL)
		{
			instance = new GameState;
		}
		return instance;
	}

	void GameState::DestroyInstance()
	{
		delete instance;
		instance = NULL;
	}

	GameState::GameState() : currentLevel(1)
	{

	}

	GameState::GameState(const GameState&)
	{

	}

	GameState::~GameState()
	{

	}

	GameState& GameState::operator=(const GameState&)
	{
		GameState *res = new GameState;
		return *res;
	}

	float GameState::GetElapsedTime()
	{
		sf::Time elapsedTime(gameTime.getElapsedTime());
		return (elapsedTime.asSeconds());
	}

	GameState* GameState::instance = NULL;
}