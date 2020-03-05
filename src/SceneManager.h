#pragma once
#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "Scene.h"
#include "Camera.h"
#include "Common.h"

namespace Scroller
{

	class SceneManager
	{
	public:

		SceneManager();
		~SceneManager();

		void update();
		void render();
		void startScene(SceneType);

		void mouseDownEvent(int, int);
		void mouseUpEvent(int, int);

		static SceneManager& getInstance();
		static Camera camera;

	private:
		static SceneManager* instance;
		Scene* currentScene;
		static bool singleton;
		SceneType sceneType;
	};

}

#endif