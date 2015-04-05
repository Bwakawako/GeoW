#include "Factory.h"

namespace Entities
{
	Factory* Factory::instance = NULL;

	Entities::EntityBase* Factory::GetObject(std::string entityName)
	{
		if (resgistredObject.count(entityName))
			return resgistredObject[entityName]->GetNewInstance();
		else
			return NULL;
	}

	Factory* Factory::GetInstance()
	{
		if (instance == NULL)
		{
			instance = new Factory;
		}
		return instance;
	}

	void Factory::DestroyInstance()
	{
		delete instance;
		instance = NULL;
	}

	Factory::Factory()
	{

	}

	Factory::Factory(const Factory&)
	{

	}

	Factory::~Factory()
	{

	}

	Factory& Factory::operator=(const Factory& object)
	{
		Factory *res = new Factory;
		return *res;
	}
}