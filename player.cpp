#include "stdafx.h"
#include "player.h"

Player::Player() :Object("Player"), _texture(0xF0A09_icon, 64)		//Playerタグ付けて、textureを入れる
{
	
}

void Player::MoveUp()
{

	SetPosition(GetPosition() + Float2{ 0.0f,-3.0f });
}

void Player::MoveDown()
{

	SetPosition(GetPosition() + Float2{ 0.0f,3.0f });
}

void Player::MoveLeft()
{

	SetPosition(GetPosition() + Float2{ -3.0f,0.0f });
}

void Player::MoveRight()
{
	
	SetPosition(GetPosition() + Float2{ 3.0f,0.0f });
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
	}
	if (KeyA.pressed()) {
		_velocityGoal.x = -PLAYER_MAX_MOVESPEED;
	}
	if (KeyS.pressed()) {
		_velocityGoal.y = PLAYER_MAX_MOVESPEED;
	}
	if (KeyD.pressed()) {
		_velocityGoal.x = PLAYER_MAX_MOVESPEED;
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
}

void Player::Draw() const
{
	_texture.drawAt(GetPosition());
}

bool Player::IsDiscard() const
{
	return false;
}
