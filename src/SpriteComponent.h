#pragma once
#ifndef SPRITE_COMPONENT_H
#define SPRITE_COMPONENT_H

#include "Component.h"
#include "Sprite.h"
#include "Spritesheet.h"

/*
	Basically just a wrapper object for holding a sprite without forcing every GameObject to have one
*/

namespace Scroller
{
	class SpriteComponent : public Component
	{
	public:
		SpriteComponent();
		SpriteComponent(EntitySprites);

		~SpriteComponent();

		void setSprite(EntitySprites);

		void update();
		void render();
		bool isType(ComponentType);

		void move(int, int);
		void scale(float);
		void rotate(int);

		Sprite spriteCurrent;

	private:
		//Sprite spriteCurrent;
	};
}

#endif