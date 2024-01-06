/*===================================================================================
プレイヤー行動（player.cpp)
Date:2024/1/6
制作者：譚偉進
====================================================================================*/
#include "stdafx.h"
#include "player.h"

Player::Player() :Object("Player"), _texture(0xF0A09_icon, 64)		//Playerタグ付けて、textureを入れる
{
	_collision = new CollisionCircle(_position, PLAYER_SIZE);
}

Player::~Player()
{
	delete _collision;
}

float Player::PlayerAcceration(float goal, float cur)
{
	//スムーズになるための移動処理
	float difference = goal - cur;
	if (difference > SENSITIVE_SPEED)return cur + SENSITIVE_SPEED;			//目標値まで加速
	if (difference < -SENSITIVE_SPEED)return cur - SENSITIVE_SPEED;			//目標値がスピード＋フレーム値越えたら減速
	return goal;		//最大速度									//以外の条件は最大速度で返す
}

void Player::PlayerMove()
{
	if (KeyW.pressed()) {
		_velocityGoal.y = -PLAYER_MAX_MOVESPEED;
		_direction = { 0.0f,-1.0f };
	}
	if (KeyA.pressed()) {
		_velocityGoal.x = -PLAYER_MAX_MOVESPEED;
		_direction = { -1.0f,0.0f };
	}
	if (KeyS.pressed()) {
		_velocityGoal.y = PLAYER_MAX_MOVESPEED;
		_direction = { 0.0f,1.0f };
	}
	if (KeyD.pressed()) {
		_velocityGoal.x = PLAYER_MAX_MOVESPEED;
		_direction = { 1.0f,0.0f };
	}
	if (KeyW.up()) {
		_velocityGoal.y = 0;
	}
	if (KeyA.up()) {
		_velocityGoal.x = 0;
	}
	if (KeyS.up()) {
		_velocityGoal.y = 0;
	}
	if (KeyD.up()) {
		_velocityGoal.x = 0;
	}
}

void Player::Update()
{
	_velocity.x = PlayerAcceration(_velocityGoal.x, _velocity.x);
	_velocity.y = PlayerAcceration(_velocityGoal.y, _velocity.y);
	_position += _velocity;
	_collision->SetPos(GetPosition());
	if (MouseL.up()) {
		auto attacker = new Attack(GetPosition()+_direction*32);
		GetWorld()->Accept(attacker);
	}
}

void Player::Draw() const
{
	_texture.drawAt(GetPosition());
}

bool Player::IsDiscard() const
{
	if (_hp < 0)return true;
	return false;
}


