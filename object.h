/*===================================================================================
オブジェクト基底クラス（object.h)
Date:2024/1/6
制作者：譚偉進
====================================================================================*/
#pragma once
#include "collision.h"
#include "world.h"
enum ITEM_TYPE {
	HPRECOVERY = 0,
	MAXHPUP,
	MAX_TYPE
};
class Item;
class World;			//お互い参照してる、巡回参照になるから前方宣言する
class Attack;
class Object {
private:
	World* _world = nullptr;
	std::string _tag;
protected:
	World* GetWorld()const { return _world; }		
	Collision* _collision;
	Float2 _position = { 0.0f,0.0f };
	Float2 _forward = { 1.0f,0.0f };
	Float2 _direction = { 0.0f,0.0f };
	Float2 _velocity = { 0.0f,0.0f };
public:
	Object() = default;
	Object(const std::string& tag):_tag(tag){}
	virtual ~Object() = default;					//継承して貰うやつは絶対virtualつける

	void Attach(World* world) { _world = world; }
	const std::string& GetTag()const { return _tag; }
	const Float2& GetPosition()const { return _position; }
	void SetPosition(const Float2& position) { _position = position; }
	auto GetCollision()const { return _collision; }
	virtual Attack* GetAttack() { return nullptr; }
	virtual void Damage(Attack*) {};
	virtual void Update() = 0;
	virtual void Draw()const = 0;
	virtual bool IsDiscard()const = 0;
	virtual ITEM_TYPE GetItemType()const { return MAX_TYPE; }
};
