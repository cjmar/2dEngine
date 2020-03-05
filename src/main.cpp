/*
	Mario clone for now

*/
#if _DEBUG
#define SDL_MAIN_HANDLED
#endif

#include "SDL2/SDL.h"
#include "Game.h"
#include <iostream>

using namespace Scroller;

#if _DEBUG
	int main(int argc, char** argv)

#else
#include <Windows.h>
int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nCmdShow)
#endif
{
	Game game;
	/* 16:9 screen ratios
		
		1920×1080 (1080p Full-HD)
		1600×900
		1366×768 1344x768 divisable by 32
		1280×720 (720p HD)
	*/

	char title[] = "Scroller Test";
	const int WINDOW_WIDTH = 1280;
	//const int WINDOW_HEIGHT = 720;
	const int WINDOW_HEIGHT = 704;

	game.init(title, WINDOW_WIDTH, WINDOW_HEIGHT);

	Uint64 NOW = SDL_GetPerformanceCounter();
	Uint64 LAST = 0;

	int frame = 0;
	while (game.isRunning())
	{
		game.update();

		LAST = NOW;
		NOW = SDL_GetPerformanceCounter();
		Game::DeltaTime = ((float)(NOW - LAST) / (float)SDL_GetPerformanceFrequency());

		game.render();

		if (frame >= 60)
		{
			//std::printf("DT:%.2f\n", Game::DeltaTime);
			frame = 0;
		}
		frame++;
	}

	game.clean();

	return 0;
}