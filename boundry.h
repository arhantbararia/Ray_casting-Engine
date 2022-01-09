#pragma once
#include "Vec2.h"


class Boundary
{
public:

	Vec2 a, b;
	
	short c = '*';
	Boundary(float x1, float x2, float y1, float y2)
	{
		a = Vec2(x1, y1);
		b = Vec2(x2, y2);

	}
};