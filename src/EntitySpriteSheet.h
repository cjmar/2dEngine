#pragma once
#ifndef SPRITESHEET_H
#define SPRITESHEET_H

#include "SDL2/SDL.h"
#include "Sprite.h"
#include <string>

/*	Idea:
		3 seperate spritesheets 

*/

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
	};

	enum UISprites
	{

	};

	enum MapSprites
	{

	};

	class EntitySpritesheet
	{
	public:
		EntitySpritesheet();
		~EntitySpritesheet();

		Sprite getEntitySprite(EntitySprites);
		Sprite getUISprite(UISprites);
		Sprite getMapSprite(MapSprites);

		static SDL_Texture* spritesheet;

	private:
		std::string spritesheetFilename;
	};
}

#endif