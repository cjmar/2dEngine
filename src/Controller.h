#pragma once
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <map>
#include "SDL2/SDL.h"

/*
	https://stackoverflow.com/questions/30815857/sdl-keycodes-are-too-big-for-storage
*/

namespace Scroller
{
	class Controller
	{
	public:
		Controller();
		~Controller();

		void update();

		static bool keyPress(SDL_Keycode);
		static bool keyHeld(SDL_Keycode);

		static bool mousePress();
		static bool mouseHeld();

		static int mouseX;
		static int mouseY;

	private:
		//static std::unique_ptr<std::unordered_map<SDL_Keycode, bool>> keys;
		static std::map<SDL_Keycode, bool> keys;
		static std::map<SDL_Keycode, bool> keysHeld;
	};
}

#endif