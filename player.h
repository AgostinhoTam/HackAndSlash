#pragma once
#include "object.h"
class Player : public Object
{
	Texture _texture;
	Vec2 _velocityGoal = { 0.0f,0.0f };
public:
	Player();
	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();
	bool PlayerMove();
	void Update()override;				//Updateの中にアタッククラス入れる
	void Draw()const override;
	bool IsDiscard()const override;
};

