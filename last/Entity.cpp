#include "Factory.h"
#include "Entity.h"
#include <string.h>

namespace Entities
{
	EntityBase::EntityBase(void)
		: parent(NULL), orientation(0), speed(0)
	{

	}

	EntityBase::~EntityBase(void)
	{
		while (listChildren.size())
		{
			delete *listChildren.begin();
			listChildren.erase(listChildren.begin());
		}
	}

	void EntityBase::Update(float elapsedTime)
	{
		EntityBase *entity;
		for (std::list<EntityBase*>::iterator it = listChildren.begin() ; it != listChildren.end() ; it++)
		{
			entity = *it;
			if (entity)
				entity->Update(elapsedTime);
		}
	}

	void EntityBase::Draw(sf::RenderWindow &window)
	{
		EntityBase *entity;
		for (std::list<EntityBase*>::iterator it = listChildren.begin() ; it != listChildren.end() ; it++)
		{
			entity = *it;
			if (entity)
				entity->Draw(window);
		}
	}

	void	EntityBase::InitWithXml(const TiXmlElement* EntityElem)
	{
		const char*	tempValue = EntityElem->Attribute("Name");
		if (tempValue)
			this->name = tempValue;

		tempValue = EntityElem->Attribute("Pos");
		if (tempValue)
			this->pos = ConvertPosition(tempValue);

		tempValue = EntityElem->Attribute("Orientation");
		if (tempValue)
			this->orientation = atoi(tempValue);

		tempValue = EntityElem->Attribute("Speed");
		if (tempValue)
			this->speed = atof(tempValue);

		const TiXmlElement*	ChildElem = EntityElem->FirstChildElement();
		while (ChildElem)
		{
			EntityBase*	newEntityChild = Factory::GetInstance()->GetObject(ChildElem->Value());

			if (newEntityChild)
			{
				newEntityChild->parent = this;
				newEntityChild->InitWithXml(ChildElem);
				listChildren.push_back(newEntityChild);
			}

			ChildElem = ChildElem->NextSiblingElement();
		}
	}

	void EntityBase::SetPosition(sf::Vector2f position)
	{
		this->pos = position;
	}

	sf::Vector2f EntityBase::GetPosition()
	{
		return this->pos;
	}

	void EntityBase::SetOrientation(int orientation)
	{
		this->orientation = orientation;
	}

	int EntityBase::GetOrientation()
	{
		return this->orientation;
	}

	//Convertie une chaine de la forme "123;663" en sf::Vector2<int>
	sf::Vector2f EntityBase::ConvertPosition(const char *position)
	{
		sf::Vector2f result;
		char positionCopy[50];
		strcpy(positionCopy, position);

		result.x = atof(strtok(positionCopy, ";"));
		result.y = atof(strtok(NULL, ";"));

		return (result);
	}

	std::string EntityBase::GetName()
	{
		return (name);
	}

	std::list<EntityBase*> & EntityBase::GetChildrenList()
	{
		return (listChildren);
	}

	void EntityBase::MovePosition(float offsetX, float offsetY)
	{
		this->pos.x += offsetX;
		this->pos.y += offsetY;
	}

	float EntityBase::GetSpeed()
	{
		return (this->speed);
	}
}
