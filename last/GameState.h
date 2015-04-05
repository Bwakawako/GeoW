#pragma once

#include <SFML/Graphics.hpp>

namespace MyGeometryWars
{
	//Cette class d�crit l'�tat du jeu pendant un niveau.
	//Elle est instanci� au d�but du niveau et d�truite � la fin
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
		//Temps �coul� depuis le d�but du niveau
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