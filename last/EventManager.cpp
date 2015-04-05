#include "EventManager.h"

namespace MyGeometryWars
{
	EventManager::EventManager()
	{

	}

	EventManager::EventManager(const EventManager&)
	{

	}

	EventManager::~EventManager()
	{

	}

	EventManager& EventManager::operator=(const EventManager& object)
	{
		EventManager *res = new EventManager;
		return *res;
	}

	EventManager* EventManager::GetInstance()
	{
		if (instance == NULL)
		{
			instance = new EventManager;
		}
		return (instance);
	}

	void EventManager::DestroyInstance(EventManager* instance)
	{
		delete instance;
		instance = NULL;
	}

	bool EventManager::FirePressed()
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) 
			|| sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			return (true);
		else
			return (false);
	}

	bool EventManager::UseBombPressed()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)
			|| sf::Mouse::isButtonPressed(sf::Mouse::Right))
			return (true);
		else
			return (false);
	}

	bool EventManager::MoveUpPressed()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)
			|| sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			return (true);
		else
			return (false);
	}

	bool EventManager::MoveDownPressed()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)
			|| sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			return (true);
		else
			return (false);
	}

	bool EventManager::MoveLeftPressed()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)
			|| sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			return (true);
		else
			return (false);
	}

	bool EventManager::MoveRightPressed()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)
			|| sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			return (true);
		else
			return (false);
	}

	bool EventManager::PausePressed()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
			return (true);
		else
			return (false);
	}

		bool EventManager::EscapePressed()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			return (true);
		else
			return (false);
	}

	sf::Vector2i EventManager::GetMousePos()
	{
		return (sf::Mouse::getPosition(*(this->window)));
	}

	EventManager* EventManager::instance = NULL;

	void EventManager::SetWindow(sf::Window *window)
	{
		this->window = window;
	}

	bool EventManager::AnyButtonClicked()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)
			|| sf::Mouse::isButtonPressed(sf::Mouse::Left)
			|| sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			return (true);
		else
			return (false);
	}

	sf::Vector2f EventManager::GetPlayerPosition()
	{
		return (this->playerPos);
	}

	void EventManager::SetPlayerPosition(sf::Vector2f playerPos)
	{
		this->playerPos = playerPos;
	}

}
