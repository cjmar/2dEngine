#pragma once
#ifndef WINDOW_H
#define WINDOW_H

#include "SDL2/SDL.h"
#include <string>

namespace Scroller
{
	struct Win
	{
		std::string title;
		int width, height, fWidth, fHeight;

		Win()
		{
			title = "";
			width = 0;
			height = 0;

			fWidth = 0;
			fHeight = 0;
		}
	};

	class Window
	{
	public:
		Win winStats;

		Window();
		~Window();
		void Clean();

		void init(const char*, int, int, Uint32);

		void toggleFakeFullscreen();

		Win& getWinStat();
		SDL_Window* getWindow();
		
	private:
		SDL_Window* window;
		bool fullscreen;
	};
}

#endif