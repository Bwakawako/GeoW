#pragma once
#include <string>
#include <list>
#include <SFML/Graphics.hpp>
#include "tinyxml.h"

namespace Entities
{

	//TODO Cr�er une interface EntityBase avec les m�thode :
	/*
		virtual void InitWithXml(const TiXmlElement* EntityElem);
		virtual void Update(float elapsedTime);
		virtual void Draw(sf::RenderWindow &window);
	*/

	//Class � la base de toutes entit�es du jeu (vaisseau, �nemies, d�cor...)
	class EntityBase
	{
	public:
		EntityBase(void);
		virtual ~EntityBase(void);

		virtual void InitWithXml(const TiXmlElement* EntityElem);

		virtual void Update(float elapsedTime);
		virtual void Draw(sf::RenderWindow &window);
		
		//TODO � mettre en protected
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