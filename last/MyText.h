#ifndef MYTEXT_H
#define MYTEXT_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Entity.h"

namespace Entities
{
	class TextBlock : public EntityBase
	{
	public:
		TextBlock(void);
		~TextBlock(void);


		void InitWithXml(const TiXmlElement* EntityElem);
		void Draw(sf::RenderWindow &window);
		void Update(float elapsedTime);

	private:
		sf::Text text;
	};
}
#endif