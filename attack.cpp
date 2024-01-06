/*===================================================================================
攻撃判定（attack.cpp)
Date:2024/1/6
制作者：譚偉進
====================================================================================*/
#include "stdafx.h"
#include "attack.h"

Attack::Attack(Float2 pos):Object("Attack"), _texture(0xF04E5_icon, 64)
{
	SetPosition(pos);
	_collision = new CollisionCircle(GetPosition(), 32.0f);
}

void Attack::Draw() const
{
	_texture.drawAt(GetPosition());
}

void Attack::AttackCreation(World* world)
{
	
}
