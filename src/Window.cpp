#include "Window.h"
#include <iostream>
#include "Game.h"

using namespace Scroller;

Window::Window()
{
	window = nullptr;
	fullscreen = false;
}

Window::~Window()
{

}

void Window::init(const char* title, int width, int height, Uint32 Flag = 0)
{
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, Flag);

	SDL_DisplayMode dm;

	if (SDL_GetDesktopDisplayMode(0, &dm) != 0)
	{
		SDL_Log("SDL_GetDesktopDisplayMode failed: %s", SDL_GetError());
	}

	winStats.title = title;

	//Starting width/height
	winStats.width = width;
	winStats.height = height;

	//Fullscreen width/height from monitor
	winStats.fWidth = dm.w;
	winStats.fHeight = dm.h;

	std::cout << "Display screen size = {" << winStats.fWidth << ", " << winStats.fHeight << "}\n";
}

void Window::toggleFakeFullscreen()
{
	if (!fullscreen)
	{
		SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
		fullscreen = true;
	}
	else
	{
		SDL_SetWindowFullscreen(window, 0);
		fullscreen = false;
	}
}

void Window::Clean()
{

	SDL_DestroyWindow(window);
}

Win& Window::getWinStat()
{
	return winStats;
}

SDL_Window* Window::getWindow()
{
	return window;
}