#pragma once

#include "Entity.h"

namespace Entities
{
	//Cette class charge via Load(int level) toutes les entit�es d'un niveau
	class EntitiesManager : public EntityBase
	{
	public:
		static EntitiesManager* GetInstance(void);
		static void DestroyInstance(void);

		//charge les entit�es � partir d'un fichier xml
		void Load(char * conf);
		//Supprime les entit�es charg� sauf Spaceship.
		//A utiliser entre chaque niveau.
		void Clean(void);

	private:
		EntitiesManager(void);
		virtual ~EntitiesManager(void);
		EntitiesManager(const EntitiesManager &);
		EntitiesManager& operator=(const EntitiesManager &);

		void AddObjectInFactory(void) const;

		static EntitiesManager* instance;
	};
}