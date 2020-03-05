#pragma once
#ifndef SPRITE_H
#define SPRITE_H

#include "SDL2/SDL.h"
#include <vector>
#include <string>

namespace Scroller
{


	class Sprite
	{
	public:
		Sprite();
		Sprite(SDL_Rect, int, int, int);
		~Sprite();

		void move(int, int);

		int getAngle();
		void setAngle(int);
		SDL_Point &getCenter();
		void setCenter(SDL_Point);
		SDL_RendererFlip flip;

		std::vector<SDL_Rect> srcRect;	//List of each sprite in a texture
		SDL_Rect dest;
		SDL_Rect hitbox;				//Approximate hitbox based on visual

		int currentIndex;				//Current index in srcRect

		void update();					//Updates animations

	private:

		//Translation/angles
		int angle;
		SDL_Point center;

		//Animation
		int frameNum;					//Number of frames
		unsigned int delayMilli;		//Delay in milliseconds between each frame in an animation
		Uint32 frameLast;				//Time measurement for the previous frame
		Uint32 frameCurrent;			//Time measurement for current frame

	};

}

#endif