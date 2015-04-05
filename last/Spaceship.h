#pragma once

#include "Entity.h"
#include "SimpleGun.h"
#include "MySprite.h"

namespace Entities
{
	class Spaceship : public EntityBase
	{
	public :
		Spaceship(void);
		~Spaceship(void);

		void Update(float elapsedTime);
		void Draw(sf::RenderWindow &window);

		void InitWithXml(const TiXmlElement* entityElem);

	private:
		int lifes;
		bool shield;
		int bomb;
		Weapon *weapon;
		int sight;
		MySprite *sprite;
	};
}