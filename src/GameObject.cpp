#include "GameObject.h"
#include "Log.h"

using namespace Scroller;

GameObject::GameObject()
{
	pos = {0, 0};
	offset = {0, 0};
	center = {0, 0};
	rotation = 0;
}

GameObject::~GameObject()
{
	
}

void GameObject::update()
{
	for (std::shared_ptr<Component> C : components)
	{
		C->update();
	}
}

bool GameObject::hasComponent(ComponentType type_in)
{
	for (std::shared_ptr<Component> C : components)
	{
		if (C->isType(type_in))
			return true;
	}

	return false;
}

void GameObject::render()
{
	if (hasComponent(Graphic2d))
	{
		getComponent<SpriteComponent>(Graphic2d)->render();
	}
}

void GameObject::setGraphic(EntitySprites type_in)
{

	if (!hasComponent(Graphic2d))
		addComponent<SpriteComponent>();

	//spriteComponent.second->setSprite(type_in);
	getComponent<SpriteComponent>(Graphic2d)->setSprite(type_in);

}

void GameObject::move(SDL_Point pos_in)
{
	move(pos_in.x, pos_in.y);
}

void GameObject::move(int x_in, int y_in)
{
	pos.x = x_in;
	pos.y = y_in;

	if (hasComponent(Graphic2d))
		getComponent<SpriteComponent>(Graphic2d)->move(x_in, y_in);
}

void GameObject::setOffset(int x_in, int y_in)
{
	offset = {x_in, y_in};
}

/*
	Take in degrees, positive to rotate right, negative for left
*/
void GameObject::rotate(int r_in)
{
	if (r_in > 360 || r_in < -360)
		rotation = r_in % 360;

	else rotation += r_in;

	if (rotation > 360 || rotation < 360)
		rotation = rotation % 360;

	if (hasComponent(Graphic2d))
		getComponent<SpriteComponent>(Graphic2d)->rotate(rotation);

}

void GameObject::setCenter(int x_in, int y_in)
{
	center = { center.x + x_in, center.y + y_in };

	if (hasComponent(Graphic2d))
	{
		SDL_Point c = getComponent<SpriteComponent>(Graphic2d)->spriteCurrent.getCenter();
		c.x += x_in;
		c.y += y_in;

		getComponent<SpriteComponent>(Graphic2d)->spriteCurrent.setCenter(c);
		std::cout << "C = {" << c.x << ", " << c.y << "}\n";
	}
}