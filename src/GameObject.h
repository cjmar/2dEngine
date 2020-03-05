#pragma once
#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "SpriteComponent.h"
#include "Common.h"
#include <vector>
#include <memory>
#include "Spritesheet.h"
#include "SDL2/SDL.h"

namespace Scroller
{
	class GameObject
	{
	public:
		GameObject();

		~GameObject();

		void move(int, int);
		void move(SDL_Point);
		void rotate(int);

		void setCenter(int, int);
		void setOffset(int, int);

		template<typename T, typename... TArgs>
		void addComponent(TArgs&&... mArgs)
		{
			T* comp(new T(std::forward<TArgs>(mArgs)...));
			std::shared_ptr<Component> p {comp};
			components.push_back(p);
		}

		template<typename T>
		T* getComponent(ComponentType type_in)
		{
			for (std::shared_ptr<Component> C : components)
			{
				if (C->isType(type_in))
					return static_cast<T*>(C.get());
			}

			return nullptr;
		}

		bool hasComponent(ComponentType type_in);

		void update();
		void render();

		//Basically init calls to specify component data
		void setGraphic(EntitySprites);

	private:
		//std::pair<bool, std::unique_ptr<SpriteComponent>> spriteComponent;
		//std::pair<bool, std::unique_ptr<BlankComponent>> blankComponent;
		SDL_Point pos;
		SDL_Point offset;
		SDL_Point center;
		int rotation;

		std::vector<std::shared_ptr<Component>> components;
	};
}

#endif