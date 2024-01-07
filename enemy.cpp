/*===================================================================================
敵行動（enemy.cpp)
Date:2024/1/6
制作者：譚偉進
====================================================================================*/
#include "stdafx.h"
#include "enemy.h"
#include "world.h"
#include "item.h"
Enemy::Enemy() :Object("Enemy"), _texture(0xF089A_icon, 64)
{
	_collision = new CollisionCircle(_position, ENEMY_SIZE);
}

Enemy::~Enemy()
{
	//ここがポイントになる
	delete _collision;
}

void Enemy::Update()
{
	//Playerに向かって移動
	auto player = GetWorld()->GetObjectByTag("Player");
	auto v = player->GetPosition() - GetPosition();
	v.normalize();
	SetPosition(GetPosition() + v * 1.5f);
	_collision->SetPos(GetPosition());
}

void Enemy::Draw() const
{
	_texture.drawAt(GetPosition());
}

bool Enemy::IsDiscard() const
{
	if (_hp < 0) {
		auto item = new Item(GetPosition(), Random(0, (int)MAX_TYPE-1));
		GetWorld()->Accept(item);
		return true;
	}
	return false;
}

void Enemy::Damage(Attack* attack)
{
	_hp -= attack->GetValue();
}
