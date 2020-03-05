#pragma once
#ifndef CAMERA_H
#define CAMERA_H

#include "SDL2/SDL.h"

namespace Scroller
{
	class Camera
	{
	public:
		//World position
		SDL_Point pos;
		
		//View
		int hScale;
		int wScale;

		//Movement
		int xVel;
		int yVel;

		void Move(int, int);
		void moveX(int);
		void moveY(int);

		Camera();
		Camera(int, int, int, int);
		~Camera();

		void update(int, int);
	};
}

#endif