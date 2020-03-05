#pragma once
#ifndef COMMON_ITEMS_H
#define COMMON_ITEMS_H

#include "SDL2/SDL.h"
#include <iostream>

namespace Scroller
{
	//Scene types
	enum SceneType
	{
		MappingScreenScene,
		GameScreenScene,
		TitleScreenScene,

		None
	};

	struct Text
	{
		std::string msg = "";
		SDL_Color color = { 0, 0, 0, 0 };
		float size = 1.0f;
		float angle = 0.0f;
		bool isStatic = false;

		SDL_Texture* tex = nullptr;
		SDL_Rect dest = { 0, 0, 0, 0 };

		~Text()
		{
			SDL_DestroyTexture(tex);
		}
	};

	struct SDL_Deleter
	{
		void operator()(SDL_Window* p) const { SDL_DestroyWindow(p); };
		void operator()(SDL_Renderer* p) const { SDL_DestroyRenderer(p); };
		void operator()(SDL_Texture* p) const { SDL_DestroyTexture(p); };
	};

	namespace 
	{

		//Common Colors
		SDL_Color RED = { 255, 0, 0, 0 };
		SDL_Color MANGO = { 240, 50, 50 };	//I just like this color for some reason
		SDL_Color BLACK = { 0, 0, 0 };
		SDL_Color WHITE = { 255, 255, 255 };



		//###############################################################
		//Simple axis aligned box collider and circle collider

		//Box: SDL_Rect = int{x coord, y coord, width, height}
		//Do not use with rotatable rects
		bool boxCollide(SDL_Rect &r1, SDL_Rect &r2)
		{
			if (r1.x < r2.x + r2.w &&
				r1.x + r1.w > r2.x &&
				r1.y < r2.y + r2.h &&
				r1.y + r1.h > r2.y) {
				
				return true;
			}
			else
			{
				return false;
			}
		}

		//Circle: SDL_Rect = int{x coord, y coord, radius, not used}
		bool circleCollde(SDL_Rect &c1, SDL_Rect &c2)
		{
			float dx = (float)c1.x - (float)c2.x;
			float dy = (float)c1.y - (float)c2.y;
			float distance = sqrt(float(dx * dx) + float(dy * dy));

			if (distance < c1.w + c2.w)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		//###############################################################
		//Returns if {x, y} is inside of shape or rect passed

		bool rectClick(int x, int y, SDL_Rect &r)
		{
			bool isxHit = false;
			bool isyHit = false;

			if (x >= r.x && x < r.x + r.w) isxHit = true;
			if (y >= r.y && y < r.y + r.h) isyHit = true;

			return (isxHit && isyHit);
		}

		/*	SINE/COSINE TAKES RADIANS AND NOT DEGREES
			
		
		*/
		bool rotatedRectClick(int x, int y, SDL_Rect &r, double a, SDL_Point c)
		{
			double an = a * 3.14159 / 180.0f;
			double S = sin(-an);
			double C = cos(-an);

			int dx = x - c.x;
			int dy = y - c.y;
			double nx = dx * C - dy * S;
			double ny = dx * S + dy * C;

			return (abs(nx) < r.w / 2) && (abs(ny) < r.h / 2);
		}

		void printRect(SDL_Rect a)
		{
			std::cout << "{" << a.x << ", " << a.y << ", " << a.w << ", " << a.h << "}\n";
		}

	}
}

#endif