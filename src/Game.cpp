#include "Game.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"
#include <iostream>
#include <sstream>
#include "Graphics.h"
#include "Globals.h"
//#include "Common.h"

using namespace Scroller;

bool DRAW_GRID = false;

SDL_Renderer* Game::renderer = nullptr;
TTF_Font* Game::font = nullptr;

bool Game::running = false;

const char* Game::GAME_TITLE = "";

Camera Game::camera = {};

float Game::DeltaTime = 0.0f;

int Global::mouseX;
int Global::mouseY;
int Global::LOGICAL_HEIGHT;
int Global::LOGICAL_WIDTH;

Game::Game() 
{
	backX = 0;
	backY = 32*20;
	speed = 10;

	gridText.msg = "Camera {x,y} = ";
	gridText.size = 0.5f;
	gridText.color = {255, 0, 0, 255};
	gridText.dest.x = 10;
	gridText.dest.y = 10;

	Text f1;
	f1.msg = "1 for fullscreen, 2 for debug grid, ESC to quit";
	f1.isStatic = true;
	f1.size = 0.5f;
	f1.color = { 0, 255, 0, 255 };
	f1.dest.x = 10;
	f1.dest.y = 25;

	Text f2;
	f2.isStatic = true;
	f2.size = 0.5f;
	f2.msg = "WASD/Arrows to move";
	f2.color = { 0, 255, 0, 255 };
	f2.dest.x = 10;
	f2.dest.y = 40;

	controlText.push_back(f1);
	controlText.push_back(f2);
}

Game::~Game() {}

void Game::init(char* title, int width, int height)
{
	Game::GAME_TITLE = title;

	//Initialize SDL2
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window.init(title, width, height, 0);

		Game::renderer = SDL_CreateRenderer(window.getWindow(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (Game::renderer)
		{
			SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 255);
		}
		Game::running = true;
	}
	if (!IMG_Init(IMG_INIT_PNG))
	{
		std::cout << "Could not initialize  SDL2_Image: " << IMG_GetError() << "\n";
	}
	if (TTF_Init() == 0)
	{
		font = TTF_OpenFont("assets/Peace.ttf", 30);
		if (font == nullptr)
		{
			std::cout << "TTF_OpenFont() says: \"" << TTF_GetError() << "\"\n";
		}
	}

	Global::LOGICAL_WIDTH = width;
	Global::LOGICAL_HEIGHT = height;

	std::cout << "Window size = {" << Global::LOGICAL_WIDTH << ", " << Global::LOGICAL_HEIGHT << "}\n\n";
	SDL_RenderSetLogicalSize(Game::renderer, width, height);

	//Window scaling
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, 0);

	camera = { 0, 0, width, height };

	sceneManager.startScene(Scroller::TitleScreenScene);
	spritesheet.init();
}

bool Game::isRunning() { return Game::running; }

void Game::quit() { Game::running = false; }

void Game::update()
{
	control.update();
	
	if (Controller::keyPress(SDLK_1))
		window.toggleFakeFullscreen();

	if (Controller::keyPress(SDLK_ESCAPE))
		quit();

	if (Controller::keyPress(SDLK_2))
		DRAW_GRID = !DRAW_GRID;
	
	std::stringstream s1;
	s1 << "Camera {x,y} = {" << Game::camera.pos.x << ", " << Game::camera.pos.y << "}";
	gridText.msg = s1.str();

	sceneManager.update();
}

void Game::render()
{
	SDL_RenderClear(Game::renderer);

	sceneManager.render();

	//p1.draw();
	//Draw grid over everything to help with debugging
	for(Text &t : controlText)
		Graphics::textDraw(t);

	if (DRAW_GRID)
	{
		//Draws a black 32x32 square grid on top

		SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 255);
		for (int x = 0; x <= Global::LOGICAL_WIDTH; x += 32)
		{
			SDL_RenderDrawLine(Game::renderer, x, 0, x, Global::LOGICAL_WIDTH);
		}
		for (int y = 0; y <= Global::LOGICAL_HEIGHT; y += 32)
		{
			SDL_RenderDrawLine(Game::renderer, 0, y, Global::LOGICAL_WIDTH, y);
		}

		Graphics::textDraw(gridText);
	}

	SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 255);
	SDL_RenderPresent(Game::renderer);
}

void Game::clean()
{
	//delete Game::font;
	//Game::font = nullptr;

	window.Clean();
	SDL_DestroyRenderer(Game::renderer);
	TTF_Quit();
	SDL_Quit();
}
