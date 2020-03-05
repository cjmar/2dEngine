#include "Controller.h"
#include "Game.h"
#include <iostream>

using namespace Scroller;

std::map<SDL_Keycode, bool> Controller::keys = {};
std::map<SDL_Keycode, bool> Controller::keysHeld = {};

Controller::Controller()
{

}

Controller::~Controller()
{

}

/*
	
	it->second && !keysHeld[k]			pressed since last frame
	!it->second && keysHeld[k]			released since last frame
	it->second && keysHeld[k]		held since last frame
*/
bool Controller::keyPress(SDL_Keycode k)
{
	std::map<SDL_Keycode, bool>::iterator it = keys.find(k);

	if (it == keys.end())
		return false;

	return it->second && !keysHeld[k];
}

bool Controller::keyHeld(SDL_Keycode k)
{
	std::map<SDL_Keycode, bool>::iterator it = keys.find(k);

	if (it == keys.end())
		return false;

	return it->second;
}

bool Controller::mousePress()
{
	return false;
}

bool Controller::mouseHeld()
{
	return false;
}

void Controller::update()
{
	keysHeld = keys;

	SDL_Event E;
	while (SDL_PollEvent(&E))
	{
		switch (E.type)
		{
		case SDL_QUIT:
			Game::quit();
			break;

		case SDL_KEYDOWN:
			keys[E.key.keysym.sym] = true;
			break;

		case SDL_KEYUP:
			keys[E.key.keysym.sym] = false;
			break;

			case SDL_MOUSEBUTTONDOWN:
				E.button.button;
			break;

		default:
			break;
		}
	}
}