/*===================================================================================
プレイヤー行動（player.h)
Date:2024/1/6
制作者：譚偉進
====================================================================================*/
#pragma once
#include "object.h"
#include "collision.h"
#include "attack.h"
#include "inventory.h"
#include "item.h"
class Player : public Object
{
	Texture _texture;
	Vec2 _velocityGoal = { 0.0f,0.0f };
	std::list<Inventory*> _inventory;
	int _hp = 10;
	int _maxhp = 10;
	const float PLAYER_MAX_MOVESPEED = 5.0f;
	const float SENSITIVE_SPEED = 13.0 / 60.0f;
	const float PLAYER_SIZE = 32.0f;
	const float INVENTORY_MAX_WEIGHT = 20.0f;
	float _weight = 0.0f;
public:
	Player();
	~Player();
	float PlayerAcceration(float goal, float cur);
	void PlayerMove();
	void Update()override;				//Updateの中にアタッククラス入れる
	void Draw()const override;
	bool IsDiscard()const override;
	bool InventoryAdd(Item* item);
	int  CountItem(ITEM_TYPE itemtype);
	float GetTotalWeight();
	void HPRecovery(int hp);
	void MaxHpUp();
};
