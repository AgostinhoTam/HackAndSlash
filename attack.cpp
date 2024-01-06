/*===================================================================================
攻撃判定（attack.cpp)
Date:2024/1/6
制作者：譚偉進
====================================================================================*/
#include "stdafx.h"
#include "attack.h"

Attack::Attack(Float2 pos):Object("Attack")
{
	SetPosition(pos);
	_collision = new CollisionCircle(GetPosition(), 10.0f);
}

void Attack::Draw() const
{
}

void Attack::AttackCreation(World* world)
{
	
}
