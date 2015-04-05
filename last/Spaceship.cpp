#include "Spaceship.h"
#include "Factory.h"
#include "EventManager.h"

using namespace MyGeometryWars;

namespace Entities
{
	Spaceship::Spaceship(void) : sight(0)
	{

	}

	Spaceship::~Spaceship(void)
	{

	}

	void Spaceship::InitWithXml(const TiXmlElement* EntityElem)
	{
		const char *tempValue;

		tempValue = EntityElem->Attribute("Lifes");
		if (tempValue)
			this->lifes = atoi(tempValue);

		tempValue = EntityElem->Attribute("Bomb");
		if (tempValue)
			this->bomb = atoi(tempValue);

		tempValue = EntityElem->Attribute("MySprite");
		if (tempValue)
		{
			TiXmlDocument doc(tempValue);

			if (doc.LoadFile())
			{
				TiXmlElement* spriteElement = doc.FirstChildElement("MySprite");

				EntityBase*	newEntity = Factory::GetInstance()->GetObject("MySprite");

				this->sprite = (MySprite*)newEntity;
				this->sprite->InitWithXml(spriteElement);
			}
		}

		const TiXmlElement*	ChildElem = EntityElem->FirstChildElement();
		if (ChildElem)
		{
			Weapon*	newEntityChild = (Weapon*)Factory::GetInstance()->GetObject(ChildElem->Value());

			if (newEntityChild)
			{
				newEntityChild->InitWithXml(ChildElem);
				this->weapon = newEntityChild;
			}
		}
		EntityBase::InitWithXml(EntityElem);
	}

	void Spaceship::Update(float elapsedTime)
	{
		EventManager &event(*(EventManager::GetInstance()));

		if (event.MoveUpPressed())
		{
			MovePosition(0, -elapsedTime * GetSpeed());
			SetOrientation(0);
		}

		if (event.MoveDownPressed())
		{	
			MovePosition(0, elapsedTime * GetSpeed());
			SetOrientation(180);
		}

		if (event.MoveLeftPressed())
		{	
			MovePosition(-elapsedTime * GetSpeed(), 0);
			SetOrientation(270);
		}

		if (event.MoveRightPressed())
		{	
			MovePosition(elapsedTime * GetSpeed(), 0);
			SetOrientation(90);
		}

		event.SetPlayerPosition(GetPosition());
	}

	void Spaceship::Draw(sf::RenderWindow &window)
	{
		sprite->SetPosition(this->GetPosition());
		sprite->SetOrientation(this->GetOrientation());
		sprite->Draw(window);
	}
}