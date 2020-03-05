#pragma once
#ifndef PLAYERINPUT_COMPONENT_H
#define PLAYERINPUT_COMPONENT_H


#include "InputComponent.h"
#include "SDL2/SDL.h"

namespace Scroller
{

	class PlayerInputComponent : public InputComponent
	{
	public:
		PlayerInputComponent();

		void update();

	private:

	};
}

#endif