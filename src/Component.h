#pragma once
#ifndef COMPONENT_H
#define COMPONENT_H

namespace Scroller
{
	enum ComponentType
	{
		Graphic2d,
		ParticleEffect,
		Collider,
		Physics,
	};


	class Component
	{
	public:
		Component(ComponentType type_in) : compType(type_in)
		{}; 
		
		virtual ~Component() {};
		virtual void update() = 0;

		virtual bool isType(ComponentType type_in) = 0;


		//static ComponentType staticType;

	protected:
		ComponentType compType;
		
	};

	/*
	class BlankComponent : public Component
	{
	public:
		BlankComponent() {};
		void update() {};
	};
	*/
}

#endif