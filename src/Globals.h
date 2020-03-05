#pragma once
#ifndef GLOBALS_H
#define GLOBALS_H

#include "SDL2/SDL_ttf.h"

namespace Global
{
	extern int LOGICAL_WIDTH;
	extern int LOGICAL_HEIGHT;

	extern int mouseX;
	extern int mouseY;

	extern TTF_Font* gameFont;
}

#endif