#pragma once
#ifndef GAME_H
#define GAME_H

#include "SDL2/SDL.h"
#include "Window.h"
#include "Camera.h"
#include "SceneManager.h"
#include "SDL2/SDL_ttf.h"
#include "Log.h"
#include "Spritesheet.h"
#include "Controller.h"

namespace Scroller
{
	class Game
	{
	public:
		Game();
		~Game();
		void init(char*, int, int);
		bool isRunning();
		void update();

		static void quit();

		void render();
		void clean();

		static SDL_Renderer* renderer;
		static float DeltaTime;
		static TTF_Font* font;

		static const char* GAME_TITLE;
		//Logical width and height of the game


		static Camera camera;
		SceneManager sceneManager;

		//Player p1;

		int backX;
		int backY;
		int speed;

	private:
		//SDL_Window* window;
		Window window;
		static bool running;
		Log logger;
		Spritesheet spritesheet;
		Text gridText;
		Controller control;
		std::vector<Text> controlText;
	};


}
#endif