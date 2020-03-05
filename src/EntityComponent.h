#pragma once
#ifndef ENTITY_COMPONENT
#define ENTITY_COMPONENT

/*
	
*/

namespace Scroller
{
	enum EntityComponentType
	{
		Input,

	};

	class EntityComponent
	{


	public:
		EntityComponent(EntityComponentType type_in) : compType(type_in)
		{};

		virtual ~EntityComponent() {};
		virtual void update() = 0;

		virtual bool isType(EntityComponentType type_in) = 0;

	protected:
		EntityComponentType compType;
	};
}

#endif