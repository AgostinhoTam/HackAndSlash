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

bool Player::PlayerMove()
{
	if (KeyW.pressed()) {
		MoveUp();
		return true;
	}
	if (KeyA.pressed()) {
		MoveLeft();
		return true;
	}
	if (KeyS.pressed()) {
		MoveDown();
		return true;
	}
	if (KeyD.pressed()) {
		MoveRight();
		return true;
	}
	return false;
}

void Player::Update()
{
}

void Player::Draw() const
{
	_texture.drawAt(GetPosition());
}

bool Player::IsDiscard() const
{
	return false;
}
