#pragma once

#include <string>
#include <map>
#include "Entity.h"

namespace Entities
{
	//Class qui permet d'utiliser un SpecificType sans s'occuper son type T
	class BaseType
	{
	public:
		virtual Entities::EntityBase* GetNewInstance(void) = 0;
	};

	//Cette class sert à instancier un type T
	template<class T>
	class SpecificType : public BaseType
	{
	public:
		virtual Entities::EntityBase* GetNewInstance(void) { return new T; }

	};

	//Cette class enregistre des objets dérivant de Entity afin de pouvoir
	//les instancier par la suite gâce à GetObject(std::string)
	class Factory : public EntityBase//TODO Normalement il n'y a aps besoin d'hérité d'entity !!!
	{
	public:
		static Factory* GetInstance();
		static void DestroyInstance();

		template <typename T>
		void RegisterObject(std::string);
		Entities::EntityBase* GetObject(std::string);

	private:
		Factory();
		~Factory();
		Factory(const Factory&);
		Factory& operator=(const Factory&);

		static Factory* instance;
		std::map<std::string, BaseType*> resgistredObject;
	};

	template <typename T>
	void Factory::RegisterObject(std::string entityName)
	{
		resgistredObject[entityName] = new SpecificType<T>;
	}
}