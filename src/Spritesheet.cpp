#include "Spritesheet.h"
#include "FileLoader.h"
#include "Log.h"

using namespace Scroller;

SDL_Texture* Spritesheet::spritesheet = nullptr;
bool Spritesheet::singleton = false;

Spritesheet::Spritesheet()
{
	if (!singleton)
	{
		spritesheetFilename = "MasterSprite.png";
		singleton = true;
	}
	else
		Log::out("Tried creating another instance of Spritesheet");

}

Spritesheet::~Spritesheet() 
{
	SDL_DestroyTexture(spritesheet);
}

void Spritesheet::init()
{
	spritesheet = FileLoader::loadTexture(spritesheetFilename);
}

/*	What does a sprite need
	src rect, row, column, delay

*/
Sprite Spritesheet::getEntitySprite(EntitySprites type_in)
{
	//Oh lawd here we go
	SDL_Rect src = {0, 0, 0, 0};
	int row = 1;
	int col = 1;
	int delay = 0;

	switch (type_in)
	{
	case PlayerSub1:
		src = {0, 0, 256, 64};
		col = 4;
		delay = 200;
		break;

	case LegTest:
		src = {0, 64, 32, 64};
		break;

	case Treads:
		src = {0, 128, 224, 64};
		col = 2;
		delay = 300;
	default:

		break;
	}

	Sprite retSprite = {src, row, col, delay};
	return retSprite;
}

Sprite Spritesheet::getUISprite(UISprites type_in)
{
	SDL_Rect src = { 0, 0, 0, 0 };
	int row = 1;
	int col = 1;
	int delay = 0;

	switch (type_in)
	{
	case Button1:
		src = {0, 448, 128, 512};
		break;
	default:

		break;
	}

	Sprite retSprite = { src, row, col, delay };

	return retSprite;
}

Sprite Spritesheet::getMapSprite(MapSprites type_in)
{
	SDL_Rect src = { 0, 0, 0, 0 };
	int row = 1;
	int col = 1;
	int delay = 0;

	//switch (type_in)
	//{

	//default:

	//	break;
	//}

	Sprite retSprite = { src, row, col, delay };

	return retSprite;
}