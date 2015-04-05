#include <stdlib.h>
#include "EntitiesManager.h"
#include "Factory.h"
#include "tinyxml.h"
#include "Spaceship.h"
#include "Enemy.h"
#include "MySprite.h"
#include "MyText.h"

namespace Entities
{
	EntitiesManager* EntitiesManager::instance = NULL;

	EntitiesManager::EntitiesManager(void)
	{
		this->AddObjectInFactory();
	}

	EntitiesManager::~EntitiesManager(void)
	{
		
	}

	EntitiesManager*	EntitiesManager::GetInstance(void)
	{
		if (instance == NULL)
			instance = new EntitiesManager;
		return instance;
	}

	void EntitiesManager::DestroyInstance(void)
	{
		delete instance;
		instance = NULL;
	}

	//conf: chemin relatif vers le .xml de l'écran à charger
	void EntitiesManager::Load(char * conf)
	{
		TiXmlDocument doc(conf);

		if (doc.LoadFile())
		{
			TiXmlElement* allEntitiesElem = doc.FirstChildElement("Entities");

			this->InitWithXml(allEntitiesElem);
		}
	}

	void EntitiesManager::AddObjectInFactory(void) const
	{

		Factory* factoryInstance = Factory::GetInstance();

		factoryInstance->RegisterObject<EntityBase>("Entity");
		factoryInstance->RegisterObject<Spaceship>("Spaceship");
		factoryInstance->RegisterObject<Enemy>("Enemy");
		factoryInstance->RegisterObject<SimpleGun>("SimpleGun");
		factoryInstance->RegisterObject<MySprite>("MySprite");
		factoryInstance->RegisterObject<TextBlock>("MyText");
	}


	void EntitiesManager::Clean(void)
	{
		EntityBase *entity;
		std::list<EntityBase*> &childrenList(GetChildrenList());
		for (std::list<EntityBase*>::iterator it = childrenList.begin() ; childrenList.size() != 1 ;)
		{
			entity = *it;
			if (entity !=NULL 
				&& entity->GetName() != "spaceship" 
				&& entity->GetName() != "score")//TODO : trouver mieu. En effet le name est défini dans le xml... Se baser sur le type serait plus sur.
				it = childrenList.erase(it);
			else
				it++;
		}
	}
}