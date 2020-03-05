#include "Entity.h"
#include "Vector2D.h"

using namespace Scroller;

Entity::Entity()
{
	name = "No named Entity";
	//speed.acc = 3;
	//speed.vel = { 0,0 };
	acceleration = 3;
	pos = { 0, 0 };
}

Entity::Entity(std::string name_in)
{
	name = name_in;
	//speed.acc = 3;
	acceleration = 3;
	//speed.vel = { 0,0 };
	pos = { 0, 0 };
}

Entity::~Entity()
{

}

void Entity::update()
{
	protectedUpdate();
}

void Entity::protectedUpdate()
{
	if (hasComponent(Input))
	{
		Vector2D<float> V = getComponent<PlayerInputComponent>(Input)->getVel();
		pos.x += (V.x * acceleration);
		pos.y += (V.y * acceleration);
	}

	for (GameObject& g : gameObjects)
	{
		g.move(pos);
		g.update();
	}

	for (std::shared_ptr<EntityComponent> E : components)
	{
		E->update();
	}
}

void Entity::render()
{
	for (GameObject &g : gameObjects)
	{
		g.render();
	}
}

bool Entity::hasComponent(EntityComponentType type_in)
{
	for (std::shared_ptr<EntityComponent> C : components)
	{
		if (C->isType(type_in))
			return true;
	}

	return false;
}

void Entity::addGameObject(GameObject& g)
{
	g.move(pos);
	gameObjects.push_back(g);
}