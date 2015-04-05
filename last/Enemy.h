#pragma once

#include "Entity.h"
#include "MySprite.h"

namespace Entities
{
	class Enemy : public EntityBase
	{
	public:
		Enemy(void);
		virtual ~Enemy(void);

		void InitWithXml(const TiXmlElement* EntityElem);

		void Update(float elapsedTime);
		void Draw(sf::RenderWindow &window);

	private:
		float spawnDelay;
		bool isSpawn;
		int HP;
		MySprite *sprite;
	};
}