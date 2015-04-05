#include <iostream>
#include <SFML/Graphics.hpp>
#include "ScreenManager.h"
#include "GameState.h"
#include "EventManager.h"

using namespace std;
using namespace MyGeometryWars;
#include "Game.h"

int main()
{
	Game::GetInstance().Start();
	return (0);
}