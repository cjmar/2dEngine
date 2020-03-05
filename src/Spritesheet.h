#pragma once
#ifndef SPRITESHEET_H
#define SPRITESHEET_H

#include "SDL2/SDL.h"
#include "Sprite.h"
#include <string>
#include <memory>
#include "Common.h"

namespace Scroller
{
	/*


		NoSprite,
		SpriteLibrarySize
	*/

	enum EntitySprites
	{
		//Player elements
		PlayerSub1,
		LegTest,
		Treads,
	};

	enum UISprites
	{
		Button1,

	};

	enum MapSprites
	{

	};

	class Spritesheet
	{
	public:
		Spritesheet();
		~Spritesheet();

		void init();

		static Sprite getEntitySprite(EntitySprites);
		static Sprite getUISprite(UISprites);
		static Sprite getMapSprite(MapSprites);

		static SDL_Texture* spritesheet;

	private:
		std::string spritesheetFilename;
		static bool singleton;
	};
}

#endif