#pragma once
#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include "Scene.h"

namespace Scroller
{

	class GameScene : public Scene
	{
		GameScene();
		~GameScene();

		void update();
		void render();
		void init();
		void mousePress(int, int);
	};

}
#endif