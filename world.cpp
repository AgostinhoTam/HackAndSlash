/*===================================================================================
ゲームステージ（world.cpp)
Date:2024/1/6
制作者：譚偉進
====================================================================================*/
#include "stdafx.h"
#include "world.h"
#include "attack.h"
#include "enemy.h"
World::~World()
{
	for (auto p : _objects) {
		delete p;
		p = nullptr;
	}
}

void World::Accept(Object* object)
{
	object->Attach(this);
	_objects.push_back(object);
}

void World::CleanUp()
{
	_objects.remove_if([](const Object* p) {
		if (p->IsDiscard()) {
			delete p;
			p = nullptr;
			return true;
		}
		return false;
	});
}

void World::Update()
{
	for (auto p : _objects) {
		p->Update();
	}
	auto attacker = GetObjectByTag("Attack");
	if(attacker != nullptr){
		if (auto obj = GetOverlapObject(attacker->GetCollision())) {
			if (obj->GetTag() == "Enemy") {
				Attack* pattacker = dynamic_cast<Attack*>(attacker);
				Enemy* penemy = dynamic_cast<Enemy*>(obj);
				if(penemy)obj->Damage(pattacker);
			}
		}
	}
}

void World::Draw()
{
	for (auto p : _objects) {
		p->Draw();
	}
}
Object* World::GetObjectByTag(const std::string& tag)
{
	for (auto object : _objects) {							//複数が返るように改造する
		if (object->GetTag() == tag) { return object; }
	}
	//std::find(_objects.begin(), _objects.end(), tag);
	return nullptr;
}
Object* World::GetOverlapObject(const Collision* collision)
{
	for (auto object : _objects) {
		auto dist_collision = object->GetCollision();
		if (object->GetTag() == "Player" || dist_collision == collision)continue;
		if (dist_collision) {
			if (dist_collision->IsOverlapping(collision)) {
				return object;
			}
		}
	}
	return nullptr;
}
//ClearUpの中身は正直普通にdrawの後に入れていいらしい
