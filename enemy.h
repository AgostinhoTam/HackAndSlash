#pragma once
#include "object.h"
class Enemy :public Object
{
private:
	Texture _texture;					//テキスチャーアセット作った方がいい
	int _hp=3;
	const float ENEMY_SIZE = 32.0f;
public:
	Enemy();
	~Enemy()override;
	void Update()override;				//Updateの中にアタッククラス入れる
	void Draw()const override;
	bool IsDiscard()const override;

};

