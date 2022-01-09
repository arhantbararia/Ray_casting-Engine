#pragma once
#include"Vec2.h"
#include "boundry.h"

class Ray
{
	Vec2 pos;
	Vec2 dir;

	Ray(Vec2 posi, float angle)
	{
		pos = posi;
		dir = dir.FromAngle(angle);
		dir = dir.normalize();
	}

	Vec2 cast(Boundary wall)
	{
		const float x1 = wall.a.x;
		const float x2 = wall.b.x;

		const float y1 = wall.a.y;
		const float y2 = wall.b.y;


		const float x3 = pos.x;
		const float y3 = pos.y;

		const float x4 = pos.x + dir.x;
		const float y4 = pos.x + dir.x;

		const float den = (x2 - x1) * (y3 - y4) - (y1 - y2) * (x3 - x4);

		if (den != 0)
		{
			const float t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / den;
			const float u = -((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)) / den;

			if (t > 0 && t < 1 && u > 0)
			{
				Vec2 pt;
				pt.x = x1 + t * (x2 - x1);
				pt.y = y1 + t * (y2 - y1);
				return pt;
			}
		}
	}
};