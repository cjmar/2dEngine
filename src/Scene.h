#pragma once
#ifndef SCENE_H
#define SCENE_H

namespace Scroller
{
	class Scene
	{
	public:
		virtual void update() = 0;
		virtual void render() = 0;
		virtual void init() = 0;
		virtual void mousePress(int, int) = 0;
	};
}

#endif