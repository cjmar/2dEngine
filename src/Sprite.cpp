#include "Sprite.h"
#include "Graphics.h"
#include <iostream>

using namespace Scroller;


Sprite::Sprite()
{

	dest = { 0, 0, 0, 0};
	hitbox = { 0, 0, 0, 0 };

	frameNum = 0;
	currentIndex = 0;
	delayMilli = 0;
	frameLast = 0;
	frameCurrent = 0;
	angle = 0;
	center = {dest.w / 2, dest.h / 2 };
	flip = SDL_FLIP_NONE;
}

Sprite::Sprite(SDL_Rect src_in, int row, int col, int delay_in)
{
	delayMilli = delay_in;
	int sizeW = src_in.w / col;
	int sizeH = src_in.h / row;
	
	int tileSize = (sizeW > sizeH) ? sizeW : sizeH;

	//Cuts a spritesheet into rows and columns 
	for (int y = 0; y < row; y++)
		for (int x = 0; x < col; x++)
		{
			SDL_Rect rect = src_in;
			rect.x += x * tileSize;
			rect.y += y * tileSize;
			rect.w = sizeW;
			rect.h = sizeH;
			srcRect.push_back(rect);
			frameNum++;
		}

	hitbox = {0, 0, sizeW, sizeH};

	currentIndex = 0;
	frameLast = 0;
	frameCurrent = 0;
	angle = 0;
	flip = SDL_FLIP_NONE;

	move(0, 0);
	dest.w = srcRect.at(0).w;
	dest.h = srcRect.at(0).h;

	center = { dest.w / 2, dest.h / 2 };

	frameLast = SDL_GetTicks();
}

Sprite::~Sprite() {}

void Sprite::move(int x_in, int y_in)
{
	dest.x = x_in;
	dest.y = y_in;
}

void Sprite::update()
{
	//delayMilli is the amount of milliseconds between frames in a sprite
	if (delayMilli != 0) // if it is an animated sprite
	{
		frameCurrent = SDL_GetTicks();
		if (frameCurrent - frameLast > delayMilli)
		{
			currentIndex++;
			if (currentIndex == frameNum)
			{
				currentIndex = 0;
			}
			frameLast = frameCurrent;
		}
	}
}

int Sprite::getAngle()
{
	return angle;
}

void Sprite::setAngle(int a)
{
	angle = a;
}

void Sprite::setCenter(SDL_Point c_in)
{
	center = c_in;
}

SDL_Point &Sprite::getCenter()
{
	return center;
}
