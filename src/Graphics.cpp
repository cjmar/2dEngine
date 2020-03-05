#include "Graphics.h"
#include "SDL2/SDL.h"
#include "Game.h"
#include <iostream>
#include "SDL2/SDL_ttf.h"
#include "Spritesheet.h"

using namespace Scroller;


/*	Unscaled drawing for UI and other non moving elements

*/
void Graphics::staticDraw(Sprite &s)
//void Textures::staticDraw(SDL_Rect& src, SDL_Rect& dest, SDL_Texture* tex)
{
	//SDL_RenderCopy(Game::renderer, tex, &src, &dest);
	//SDL_RenderCopy(Game::renderer, s.tex, &s.srcRect.at(s.currentIndex), &s.destRect);
	//SDL_RenderCopyEx(Game::renderer, s.tex, &s.srcRect.at(s.currentIndex), &s.destRect, s.getAngle(), /*&s.getCenter()*/NULL, s.flip);
	SDL_RenderCopyEx(Game::renderer, Spritesheet::spritesheet, &s.srcRect.at(s.currentIndex), &s.dest, s.getAngle(), &s.getCenter(), s.flip);
}

/*	Scaled drawing based on camera location
	
*/
void Graphics::Draw(Sprite &s)
//void Textures::Draw(SDL_Rect& src, SDL_Rect& dest, SDL_Texture* tex)
{
	SDL_Rect scaledDest = {s.dest.x + Game::camera.pos.x, s.dest.y + Game::camera.pos.y, s.dest.w, s.dest.h};
	//SDL_RenderCopy(Game::renderer, tex, &src, &scaledDest);

	//SDL_RenderCopy(Game::renderer, s.tex, &s.srcRect.at(s.currentIndex), &scaledDest);
	SDL_RenderCopyEx(Game::renderer, Spritesheet::spritesheet, &s.srcRect.at(s.currentIndex), &scaledDest, s.getAngle(), &s.getCenter(), s.flip);
}

/*
	For the moment testing purposes which takes a custom texture
		ie: the large 3k background
*/
void Graphics::Draw(Sprite &s, SDL_Texture *tex)
{
	SDL_Rect scaledDest = { s.dest.x + Game::camera.pos.x, s.dest.y + Game::camera.pos.y, s.dest.w, s.dest.h };
	//SDL_Rect scaledDest = { s.dest.x, s.dest.y, s.dest.w, s.dest.h };

	SDL_RenderCopyEx(Game::renderer, tex, &s.srcRect.at(s.currentIndex), &scaledDest, s.getAngle(), &s.getCenter(), s.flip);
}

/*
	A "for now" text renderer

	TODO: Angles and a message or text struct to pass to this instead
*/
void Graphics::textDraw(Scroller::Text& text)
{
	
	if (!text.isStatic || text.tex == nullptr)
	{
		if(!text.isStatic)
			SDL_DestroyTexture(text.tex);

		SDL_Surface* tSurface = TTF_RenderText_Solid(Game::font, text.msg.c_str(), text.color);
		//SDL_Texture* tTexture = SDL_CreateTextureFromSurface(Game::renderer, tSurface);

		text.tex = SDL_CreateTextureFromSurface(Game::renderer, tSurface);
		text.dest = { text.dest.x, text.dest.y, tSurface->w, tSurface->h };
		//text.dest.w = tSurface->w;
		//text.dest.h = tSurface->h;

		SDL_FreeSurface(tSurface);
	}
	
	SDL_Rect scaledDest = {text.dest.x, text.dest.y, int(text.dest.w * text.size), int(text.dest.h * text.size)};

	//SDL_RenderCopy(Game::renderer, text.tex, NULL, &text.dest);
	SDL_RenderCopyEx(Game::renderer, text.tex, NULL, &scaledDest, text.angle, NULL, SDL_FLIP_NONE);

}
