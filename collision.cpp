#include "stdafx.h"
#include "collision.h"

CollisionCircle::CollisionCircle(Float2 pos, float size)
{
	_circle.setPos(pos);
	_circle.setR(size);
}
