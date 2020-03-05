#include "Camera.h"
#include "Game.h"
#include <iostream>

using namespace Scroller;

Camera::Camera() : wScale(0), hScale(0)
{
	pos = {0, 0};
	xVel = 0;
	yVel = 0;
}

Camera::Camera(int x, int y, int w, int h) : wScale(w), hScale(h)
{
	pos = {x, y};
	xVel = 0;
	yVel = 0;
}

Camera::~Camera()
{

}

void Camera::update(int px, int py)
{
	//Camera offsets to follow the player
	//int xOff = px - 32;
	//int yOff = py - 672;

	pos.x = -(int(xVel * Game::DeltaTime*2) + px - 32) + 250;
	pos.y = int(yVel * Game::DeltaTime*2) + py - 672+32;
}

void Camera::Move(int x, int y)
{
	xVel = -x;
	yVel = y;
}

void Camera::moveX(int x)
{
	xVel = x;
}

void Camera::moveY(int y)
{
	yVel = y;
}
