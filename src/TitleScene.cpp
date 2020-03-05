#include "TitleScene.h"
#include "Globals.h"
#include "SceneManager.h"
#include "Common.h"
#include "Game.h"
#include "Spritesheet.h"
#include "Graphics.h"
#include "Controller.h"
#include "PlayerInputComponent.h"

using namespace Scroller;

TitleScene::TitleScene()
{
	//rotation = -5;
	//acceleration = 3;
	//pos = { 100, 100 };
	GameObject GObj;
	GObj.addComponent<SpriteComponent>(EntitySprites::Treads);

	//EObj.speed = { 6, {0,0} };
	EObj.acceleration = 8;
	EObj.pos = { 100, 100 };
	EObj.addGameObject(GObj);
	EObj.addComponent<PlayerInputComponent>();
}

TitleScene::~TitleScene()
{

}

void TitleScene::update()
{
	EObj.update();
	/*
	bool moved = false;
	SDL_Point p = { 0, 0 };

	if (Controller::keyHeld(SDLK_UP) || Controller::keyHeld(SDLK_w))
	{
		p.y -= EObj.acceleration;
		moved = true;
	}
	if (Controller::keyHeld(SDLK_LEFT) || Controller::keyHeld(SDLK_a))
	{
		p.x -= EObj.acceleration;
		moved = true;
	}
	if (Controller::keyHeld(SDLK_DOWN) || Controller::keyHeld(SDLK_s))
	{
		p.y += EObj.acceleration;
		moved = true;
	}
	if (Controller::keyHeld(SDLK_RIGHT) || Controller::keyHeld(SDLK_d))
	{
		p.x += EObj.acceleration;
		moved = true;
	}
	if (Controller::keyHeld(SDLK_SPACE))
	{
		std::cout << "holding space\n";
	}
	if (moved)
	{
		EObj.stepMove(pos);
	}
	*/
}

void TitleScene::render()
{
	EObj.render();
}

void TitleScene::init()
{
	buildUI();
}

void TitleScene::mousePress(int x, int y)
{

}

void TitleScene::buildUI()
{

}
