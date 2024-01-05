#pragma once
#include "object.h"
#include "collision.h"
class Player : public Object
{
	Texture _texture;
	Vec2 _velocityGoal = { 0.0f,0.0f };
	int _hp = 10;
	const float PLAYER_MAX_MOVESPEED = 5.0f;
	const float SENSITIVE_SPEED = 13.0 / 60.0f;
	const float PLAYER_SIZE = 32.0f;
public:
	Player();
	~Player();
	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();
	float PlayerAcceration(float goal, float cur);
	void PlayerMove();
	void Update()override;				//Updateの中にアタッククラス入れる
	void Draw()const override;
	bool IsDiscard()const override;
};
