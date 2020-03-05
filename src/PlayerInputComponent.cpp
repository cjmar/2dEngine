#include "PlayerInputComponent.h"
#include "Controller.h"
#include <iostream>

using namespace Scroller;

PlayerInputComponent::PlayerInputComponent() : InputComponent()
{
	
}

void PlayerInputComponent::update()
{
	bool xMove = false;
	bool yMove = false;
	velocity = { 0, 0 };

	if (Controller::keyHeld(SDLK_UP) || Controller::keyHeld(SDLK_w))
	{
		velocity.y -= 1;
		yMove = true;
	}
	if (Controller::keyHeld(SDLK_LEFT) || Controller::keyHeld(SDLK_a))
	{
		velocity.x -= 1;
		xMove = true;
	}
	if (Controller::keyHeld(SDLK_DOWN) || Controller::keyHeld(SDLK_s))
	{
		velocity.y += 1;
		yMove = true;
	}
	if (Controller::keyHeld(SDLK_RIGHT) || Controller::keyHeld(SDLK_d))
	{
		velocity.x += 1;
		xMove = true;
	}
	if (xMove && yMove)
	{
		velocity.normalize();
	}
}
