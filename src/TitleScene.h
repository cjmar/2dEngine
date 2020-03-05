#pragma once
#ifndef TITLESCENE_H
#define TITLESCENE_H

#include "Scene.h"
#include "Entity.h"
#include "Sprite.h"

namespace Scroller
{

	class TitleScene : public Scene
	{
	public:
		TitleScene();
		~TitleScene();

		void update();
		void render();
		void init();
		void mousePress(int, int);

		Entity EObj;
		//int acceleration;
		//SDL_Point pos;
		//int rotation;
		//PlayerInputComponent p;

	private:

		void buildUI();
	};

}

#endif