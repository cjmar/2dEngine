#include "SpriteComponent.h"
#include <iostream>
#include "Graphics.h"

using namespace Scroller;

SpriteComponent::SpriteComponent() : Component(Graphic2d)
{
}

SpriteComponent::SpriteComponent(EntitySprites sprite_in) : Component(Graphic2d)
{
	setSprite(sprite_in);
}

SpriteComponent::~SpriteComponent()
{

}

void SpriteComponent::update()
{
	spriteCurrent.update();
}

void SpriteComponent::render()
{
	Graphics::Draw(spriteCurrent);
}

bool SpriteComponent::isType(ComponentType type_in)
{
	return compType == type_in;
}

void SpriteComponent::move(int x_in, int y_in)
{
	spriteCurrent.dest.x = x_in;
	spriteCurrent.dest.y = y_in;
}

void SpriteComponent::scale(float size)
{
	spriteCurrent.dest.w = int(spriteCurrent.dest.w * size);
	spriteCurrent.dest.h = int(spriteCurrent.dest.h * size);

	SDL_Point c = { spriteCurrent.dest.w / 2, spriteCurrent.dest.h / 2 };
	spriteCurrent.setCenter(c);
}

void SpriteComponent::rotate(int r_in)
{
	spriteCurrent.setAngle(r_in);
}

void SpriteComponent::setSprite(EntitySprites type_in)
{
	spriteCurrent = Spritesheet::getEntitySprite(type_in);
}