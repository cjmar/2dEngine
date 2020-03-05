#pragma once
#ifndef VECTOR_2D
#define VECTOR_2D

template<typename T>
class Vector2D
{
public:
	Vector2D() : x(0), y(0) {};
	Vector2D(T x_in, T y_in) : x(x_in), y(y_in) {}

	T length() { return sqrt(x * x + y * y); }

	void normalize() 
	{ 
		if (length() > 0) 
		{ 
			(*this) *= (1 / length()); 
		} 
	}

	Vector2D& operator+=(const Vector2D& rhs)
	{
		x += rhs.y;
		y += rhs.y;
		return *this;
	}

	Vector2D& operator*=(float scale)
	{
		x *= scale;
		y *= scale;
		return *this;
	}

	T x;
	T y;
};

#endif