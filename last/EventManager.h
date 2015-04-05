#pragma once

#include <SFML/Graphics.hpp>

namespace MyGeometryWars
{
	class EventManager
	{
	public:
		static EventManager* GetInstance();
		static void DestroyInstance(EventManager* instance);

		//Défini la fênetre que l'on va observer
		void SetWindow(sf::Window *window);

		//Commande du joueur
		bool FirePressed();
		bool UseBombPressed();
		bool MoveUpPressed();
		bool MoveDownPressed();
		bool MoveLeftPressed();
		bool MoveRightPressed();
		bool PausePressed();
		bool EscapePressed();

		bool AnyButtonClicked();

		sf::Vector2i GetMousePos();
		sf::Vector2f GetPlayerPosition();
		void SetPlayerPosition(sf::Vector2f playerPos);

	private:
		EventManager();
		~EventManager();
		EventManager(const EventManager&);
		EventManager& operator=(const EventManager&);

		sf::Window *window;
		sf::Vector2f playerPos;
		static EventManager* instance;
	};
}