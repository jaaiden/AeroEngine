#pragma once
#include <string>
#include <Box2D\Box2D.h>
class Vector2
{
public:
	Vector2() {}
	//Vector2(float vX, float vY) { x = vX; y = vY; }
	Vector2(int vX, int vY) { x = vX; y = vY; }
	~Vector2() {}

	inline static Vector2 ConvertB2Vec2(b2Vec2 aB2Vec)
	{
		return Vector2(aB2Vec.x, aB2Vec.y);
	}

	int x, y;
};

