#include "MyText.h"
#include "FontManager.h"

using namespace Util;

namespace Entities
{
	TextBlock::TextBlock(void)
	{
	}

	TextBlock::~TextBlock(void)
	{

	}

	void TextBlock::InitWithXml(const TiXmlElement* EntityElem)
	{
		const char *tempValue;

		//TODO la font se charge mais fais planté l'appli au prochain appel à text
/*		tempValue = EntityElem->Attribute("Font");
		if (tempValue)
		{
			text.setFont(FontManager::GetInstance()->GetFont(tempValue));
		}	*/	

		tempValue = EntityElem->Attribute("String");
		if (tempValue)
			this->text.setString(tempValue);
		
		tempValue = EntityElem->Attribute("TextSize");
		if (tempValue)
			this->text.setCharacterSize(atoi(tempValue));

		tempValue = EntityElem->Attribute("Color");
		if (tempValue)
			this->text.setColor(sf::Color::White/*TODO convertColor(tempValue)*/);

		EntityBase::InitWithXml(EntityElem);
	}

	void TextBlock::Draw(sf::RenderWindow &window)
	{
		text.setPosition(this->GetPosition());
		window.draw(text);
	}

	void TextBlock::Update( float elapsedTime )
	{

	}
}