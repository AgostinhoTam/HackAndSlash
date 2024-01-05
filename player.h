#pragma once
#include "object.h"
class Player : public Object
{
	Texture _texture;
	const float PLAYER_MAX_MOVESPEED = 5.0f;
	Vec2 _velocityGoal = { 0.0f,0.0f };
	const float SENSITIVE_SPEED = 13.0 / 60.0f;
public:
	Player();
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
