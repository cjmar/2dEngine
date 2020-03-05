#include "SceneManager.h"
#include <iostream>
#include "MapScene.h"
#include "TitleScene.h"
//#include "Game.h"
#include "Globals.h"

/*
	Handler and container for the scene currently being used in game
	Also owns the camera
*/

using namespace Scroller;

SceneManager* SceneManager::instance = nullptr;
Camera SceneManager::camera = {};
bool SceneManager::singleton = false;

//extern int Global::LOGICAL_HEIGHT;
//extern int Global::LOGICAL_WIDTH;

/* ###########################################################################


*/
SceneManager::SceneManager()
{
	currentScene = nullptr;
	sceneType = SceneType::None;

	if (!SceneManager::singleton) //If not created, then create
	{
		SceneManager::instance = this;
		SceneManager::singleton = true;
	}
	else //Problem, log it
	{
		std::cout << "Tried creating SceneManger which already exists";
	}
}

/* ###########################################################################


*/
SceneManager::~SceneManager()
{
	SceneManager::instance = NULL;

	delete currentScene;
	currentScene = nullptr;
}

/* ###########################################################################


*/
void SceneManager::update()
{
	currentScene->update();
}

/* ###########################################################################


*/
void SceneManager::render()
{
	currentScene->render();
	//ui.render();
}


/* ###########################################################################


*/
void SceneManager::startScene(SceneType type_in)
{
	sceneType = type_in;

	delete currentScene;
	currentScene = nullptr;

	//ui.changeScene(sceneType);

	switch (sceneType)
	{
	case SceneType::TitleScreenScene:
		currentScene = new TitleScene();
		break;

	case SceneType::MappingScreenScene:
		currentScene = new MapScene();
		//std::cout << "Starting Map Scene\n";
		break;

	case SceneType::GameScreenScene:
		//currentScene = new GameScene();
		std::cout << "Starting Title Scene\n";
		break;
	}
	currentScene->init();
}

/* ###########################################################################
					Mouse button events

*/
void SceneManager::mouseDownEvent(int x_in, int y_in)
{

}

void SceneManager::mouseUpEvent(int x_in, int y_in)
{
	//ui.eventCheck(x_in, y_in);
	currentScene->mousePress(x_in, y_in);
}

/* ###########################################################################


*/
SceneManager& SceneManager::getInstance()
{
	return *SceneManager::instance;
}
