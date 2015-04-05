#include "MySprite.h"
#include "TextureManager.h"

using namespace Util;

namespace Entities
{
	MySprite::MySprite(void)
	{
		
	}


	MySprite::~MySprite(void)
	{
	}

	MySprite &MySprite::GetInstance()
	{
		static MySprite instance;
		return instance;
	}

	void MySprite::InitWithXml(const TiXmlElement* EntityElem)
	{
		const char *tempValue;

		tempValue = EntityElem->Attribute("Texture");
		if (tempValue)	
				this->texture = tempValue;

		tempValue = EntityElem->Attribute("TexturePos");
		if (tempValue)	
			this->texturePos = (sf::Vector2<int>)ConvertPosition(tempValue);

		tempValue = EntityElem->Attribute("TextureSize");
		if (tempValue)	
			this->textureSize = (sf::Vector2<int>)ConvertPosition(tempValue);

		this->sprite.setTexture(TextureManager::GetInstance()->GetTexture(texture.c_str()));
		this->sprite.setTextureRect(sf::IntRect(this->texturePos, this->textureSize));
		this->sprite.setPosition((float)GetPosition().x, (float)GetPosition().y);

		EntityBase::InitWithXml(EntityElem);
	}

	void MySprite::Update(float ElapsedTime)
	{
		
	}

	void MySprite::Draw(sf::RenderWindow &window)
	{
		float test;
		this->sprite.setPosition(GetPosition());
		test = this->sprite.getGlobalBounds().width / 2;
		//this->sprite.setOrigin(this->sprite.getGlobalBounds().width / 2, this->sprite.getGlobalBounds().height);
		this->sprite.setRotation(GetOrientation());
		window.draw(sprite);
	}
}