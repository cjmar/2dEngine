#pragma once
#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include "GameObject.h"
#include <string>
#include <memory>
#include "EntityComponent.h"
#include "PlayerInputComponent.h"

namespace Scroller
{

	class Entity
	{
	public:
		Entity();
		Entity(std::string);
		~Entity();

		void render();
		void update(); //needs to call protectedUpdate();
		void addGameObject(GameObject &);

		template<typename T, typename... TArgs>
		void addComponent(TArgs&& ... mArgs)
		{
			T* comp(new T(std::forward<TArgs>(mArgs)...));
			std::shared_ptr<EntityComponent> p { comp };
			components.push_back(p);
		}

		template<typename T>
		T* getComponent(EntityComponentType type_in)
		{
			for (std::shared_ptr<EntityComponent> C : components)
			{
				if (C->isType(type_in))
				{
					return static_cast<T*>(C.get());
				}
			}
			return nullptr;
		}

		bool hasComponent(EntityComponentType);

		//int acceleration;		//Speed it moves
		//SDL_Point velocity;		//Current movement speed
		//SDL_Point pos;			//Current position

		//Speed speed;
		int acceleration;
		SDL_Point pos;

	protected:

		std::string name;
		void protectedUpdate();
		std::vector<std::shared_ptr<EntityComponent>> components;
		std::vector<GameObject> gameObjects;

	};
}

#endif