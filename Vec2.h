#pragma once
#include<math.h>

class Vec2
{
public:
	float x, y;

	Vec2()
	{
		x = 0;
		y = 0;

	}

	Vec2(float a, float b)
	{
		x = a;
		y = b;

	}


	friend Vec2 operator+ (Vec2 a, Vec2 b)
	{
		return { a.x + b.x , a.y + b.y };

	}

	friend Vec2 operator- (Vec2 a, Vec2 b)
	{
		return { a.x - b.x , a.y - b.y };
	}

	friend Vec2 operator* (Vec2 a, Vec2 b)
	{
		return { a.x * b.x , a.y * b.y };
	}

	friend Vec2 operator/ (Vec2 a, Vec2 b)
	{
		return { a.x / b.x , a.y / b.y };
	}


	Vec2 normalize()
	{
		float mag = x * x + y * y;

		if (mag != 0)
		{
			x /= mag;
			y /= mag;
		}

		return { x, y };
	}

	Vec2 FromAngle(float angle)
	{
		return { cosf(angle) , sinf(angle) };
	}


	
};