#pragma once
#ifndef INPUT_COMPONENT_H
#define INPUT_COMPONENT_H

#include "EntityComponent.h"
#include "SDL2/SDL.h"
#include "Vector2D.h"

namespace Scroller
{
	/*
	struct Speed
	{
		int acc = 0;
		SDL_Point vel = { 0,0 };

		Speed() : acc(0), vel({ 0,0 }) {}
		Speed(int a, SDL_Point v) : acc(a), vel(v) {}
	};
	*/
	class InputComponent : public EntityComponent
	{
	public:
		InputComponent();

		Vector2D<float> getVel() { return velocity; }

		virtual void update() = 0;
		
		bool isType(EntityComponentType);

	protected:
		Vector2D<float> velocity;
	};
}

#endif