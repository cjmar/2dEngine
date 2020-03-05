#include "InputComponent.h"

using namespace Scroller;

InputComponent::InputComponent() : EntityComponent(Input)
{
	velocity = { 0, 0 };
}

bool InputComponent::isType(EntityComponentType type_in)
{
	if (compType == Input)
		return true;
	else
		return false;
}