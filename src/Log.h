#pragma once
#ifndef LOG_H
#define LOG_H

#include <iostream>

namespace Scroller
{
	class Log
	{
	public:
		Log()
		{

		}
		~Log()
		{

		}

		template<typename T>
		static void out(T text)
		{
			std::cout << text << "\n";
		}

	private:
	};
}

#endif