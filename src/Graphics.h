#pragma once
#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "SDL2/SDL_image.h"
#include <string>
#include <unordered_map>
#include "Sprite.h"
#include "Common.h"

namespace Scroller
{
	namespace Graphics
	{
		//void Draw(SDL_Rect&, SDL_Rect&, SDL_Texture*);
		//void staticDraw(SDL_Rect&, SDL_Rect&, SDL_Texture*);

		void Draw(Sprite &);
		void Draw(Sprite &, SDL_Texture*);
		void staticDraw(Sprite &);
		void textDraw(Scroller::Text& textStruct);
	}
}

#endif