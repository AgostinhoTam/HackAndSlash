/*===================================================================================
プレイヤー行動（player.cpp)
Date:2024/1/6
制作者：譚偉進
====================================================================================*/
#include "stdafx.h"
#include "player.h"
#include "inventory.h"
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
	//移動押すと最大速度代入、向きも変わる
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
	PlayerMove();
	_velocity.x = PlayerAcceration(_velocityGoal.x, _velocity.x);
	_velocity.y = PlayerAcceration(_velocityGoal.y, _velocity.y);
	_position += _velocity;
	_collision->SetPos(GetPosition());
	if (MouseL.up()) {
		auto attacker = new Attack(GetPosition()+_direction*32);
		GetWorld()->Accept(attacker);
	}
	PlayerAttack();
	PickItem();
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

bool Player::InventoryAdd(Item* item)
{
	//最大重量超えないように
	if (GetTotalWeight() + item->GetWeight() <= INVENTORY_MAX_WEIGHT) {
		_inventory.AddItem(*item);
		return true;
	}
	return false;
}

int Player::CountItem(ITEM_TYPE itemtype)
{
	//アイテムを数える
	int count = _inventory.CountItem(itemtype);
	return count;
	
}

float Player::GetTotalWeight()
{
	//アイテムの重量を計算
	return _inventory.GetTotalWeight();
}

void Player::HPRecovery(int hp)
{
	//HPが最大だったら使えない、最大ＨＰも越えられないように
	if(_hp != _maxhp){
	_hp = (_hp + hp > _maxhp) ? _maxhp : _hp + hp;
	_inventory.UseItem(HPRECOVERY);
	}
}

void Player::MaxHpUp()
{
	++_maxhp;
	_inventory.UseItem(MAXHPUP);
}

void Player::DropInventory(ITEM_TYPE id)
{
	//指定されたアイテムをInventoryから消す処理
	_inventory.UseItem(id);

	//ゲームオブジェクト化
	auto a = new Item(GetPosition(), id);
	GetWorld()->Accept(a);
}

void Player::PlayerAttack()
{
	//攻撃の処理
		if (MouseL.up()) {
			auto attacker = GetWorld()->GetObjectByTag("Attack");
			if (attacker != nullptr) {
				if (auto obj = GetWorld()->GetOverlapEnemy(attacker->GetCollision())) {

					auto pattacker = GetWorld()->GetObjectByTag("Attack");
					auto penemy = GetWorld()->GetObjectByTag("Enemy");
					if (penemy)obj->Damage(pattacker->GetAttack());
				}
			}
		}
}

void Player::PickItem()
{
	//アイテム拾う処理
		if (MouseR.up()) {
				if (auto obj = GetWorld()->GetOverlapItem(this->GetCollision())) {
					Item* pItem = dynamic_cast<Item*>(obj);
					if (this->InventoryAdd(pItem))pItem->PickUpItem();
				}
		}
}


