#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Entity.h"
#include "EntitiesManager.h"

namespace Entities
{
	class MySprite : public EntityBase
	{
	public:
		MySprite(void);
		~MySprite(void);
		static MySprite &GetInstance();

		void Update(float ElapsedTime);
		void Draw(sf::RenderWindow &window);
		void InitWithXml(const TiXmlElement* EntityElem);

	private:
		sf::Sprite sprite;
		std::string texture;
		sf::Vector2<int> texturePos;
		sf::Vector2<int> textureSize;
	};
}