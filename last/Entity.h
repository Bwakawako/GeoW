#pragma once
#include <string>
#include <list>
#include <SFML/Graphics.hpp>
#include "tinyxml.h"

namespace Entities
{

	//TODO Créer une interface EntityBase avec les méthode :
	/*
		virtual void InitWithXml(const TiXmlElement* EntityElem);
		virtual void Update(float elapsedTime);
		virtual void Draw(sf::RenderWindow &window);
	*/

	//Class à la base de toutes entitées du jeu (vaisseau, énemies, décor...)
	class EntityBase
	{
	public:
		EntityBase(void);
		virtual ~EntityBase(void);

		virtual void InitWithXml(const TiXmlElement* EntityElem);

		virtual void Update(float elapsedTime);
		virtual void Draw(sf::RenderWindow &window);
		
		//TODO à mettre en protected
		void SetPosition(sf::Vector2f pos);
		sf::Vector2f GetPosition();
		void MovePosition(float offsetX, float offsetY);
		void SetOrientation(int orientation);
		int GetOrientation();
		std::string GetName();
		std::list<EntityBase*> &GetChildrenList();
		float GetSpeed();

	protected:
		//Convertie une chaine de la forme "123;663" en sf::Vector2<int>
		sf::Vector2f ConvertPosition(const char *position);

	private:
		EntityBase *parent;
		std::list<EntityBase*> listChildren;
		std::string name;
		sf::Vector2f pos;
		int orientation;
		float speed;
	};
}