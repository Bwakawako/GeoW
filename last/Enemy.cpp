#include "Enemy.h"
#include "Factory.h"
#include "GameState.h"
#include "EventManager.h"

using namespace Entities;
using namespace MyGeometryWars;

Enemy::Enemy(void) : HP(10), isSpawn(false)
{

}

Enemy::~Enemy(void)
{

}

void Enemy::InitWithXml(const TiXmlElement* EntityElem)
{
	const char *tempValue = EntityElem->Attribute("SpawnDelay");
	if (tempValue)
		this->spawnDelay = atof(tempValue);

	tempValue = EntityElem->Attribute("HP");
	if (tempValue)
		this->HP = atoi(tempValue);

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

	EntityBase::InitWithXml(EntityElem);
}

void Enemy::Update(float elapsedTime)
{
	if (isSpawn == false && GameState::GetInstance()->GetElapsedTime() > spawnDelay)
		isSpawn = true;
	else
	{
		//TODO faire fonctionné
		//EventManager &event(*(EventManager::GetInstance()));
		////Go up
		//if (event.GetPlayerPosition().y > GetPosition().y)//GetPlayerPosition
		//	MovePosition(0, -elapsedTime * GetSpeed());
		////Go down
		//if (event.GetPlayerPosition().y < GetPosition().y)
		//	MovePosition(0, elapsedTime * GetSpeed());
		////Go left
		//if (event.GetPlayerPosition().x < GetPosition().x)
		//	MovePosition(-elapsedTime * GetSpeed(), 0);
		////Go right
		//if (event.GetPlayerPosition().x > GetPosition().x)
		//	MovePosition(elapsedTime * GetSpeed(), 0);
	}
}

void Enemy::Draw(sf::RenderWindow &window)
{
	if (isSpawn)
	{
		sprite->SetPosition(this->GetPosition());
		this->sprite->Draw(window);
	}
}

