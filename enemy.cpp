#include "stdafx.h"
#include "enemy.h"
#include "world.h"
Enemy::Enemy() :Object("Enemy"), _texture(0xF089A_icon, 64)
{
}

Enemy::~Enemy()
{
	//ここがポイントになる
}

void Enemy::Update()
{
	//Playerに向かって移動
	auto player = GetWorld()->GetObjectByTag("Player");
	auto v = player->GetPosition() - GetPosition();
	v.normalize();
	SetPosition(GetPosition() + v * 1.5f);
}

void Enemy::Draw() const
{
	_texture.drawAt(GetPosition());
}

bool Enemy::IsDiscard() const
{
	if (_hp < 0)return true;
	return false;
}
