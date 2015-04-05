#pragma once

#include <SFML/Graphics.hpp>

namespace MyGeometryWars
{
	//Cette class décrit l'état du jeu pendant un niveau.
	//Elle est instancié au début du niveau et détruite à la fin
	//de celui-ci.
	class GameState
	{
	public:
		static GameState* GetInstance();
		static void DestroyInstance();

		int CurrentLevel();
		bool AreAllEnemiesDestroyed();
		void CurrentLevel(int level);
		void AreAllEnemiesDestroyed(bool allEnemyDestroyed);
		//Temps écoulé depuis le début du niveau
		float GetElapsedTime();

	private:
		GameState();
		~GameState();
		GameState(const GameState&);
		GameState& operator=(const GameState&);

		static GameState *instance;

		int currentLevel;
		bool areAllEnemiesDestroyed;
		sf::Clock gameTime;
	};
}