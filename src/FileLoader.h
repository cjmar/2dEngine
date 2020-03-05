#pragma once
#ifndef FILE_LOADER_H
#define FILE_LOADER_H

#include "SDL2/SDL_image.h"
#include <string>

namespace Scroller
{
	namespace FileLoader
	{
		SDL_Texture* loadTexture(std::string);
	}
}

#endif