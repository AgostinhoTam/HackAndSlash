/*===================================================================================
当たり判定（collision.cpp)
Date:2024/1/6
制作者：譚偉進
====================================================================================*/
#include "stdafx.h"
#include "collision.h"

CollisionCircle::CollisionCircle(Float2 pos, float size)
{
	_circle.setPos(pos);
	_circle.setR(size);
}

