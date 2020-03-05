#pragma once
#ifndef MAPSCENE_H
#define MAPSCENE_H

#include "Scene.h"

namespace Scroller
{

	class MapScene : public Scene
	{
	public:
		MapScene();
		~MapScene();

		void update();
		void render();
		void init();
		void mousePress(int, int);

	private:


	};

}

#endif