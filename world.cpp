/*===================================================================================
ゲームステージ（world.cpp)
Date:2024/1/6
制作者：譚偉進
====================================================================================*/
#include "stdafx.h"
#include "world.h"

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
	auto pPlayer = GetObjectByTag("Player");
	if (auto obj = GetOverlapObject(pPlayer->GetCollision())) {
		if (obj->GetTag() == "Enemy") {
			obj->Damage(pPlayer->GetAttack());
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
		if (dist_collision == collision)continue;
		if (dist_collision) {
			if (dist_collision->IsOverlapping(collision)) {
				return object;
			}
		}
	}
	return nullptr;
}
//ClearUpの中身は正直普通にdrawの後に入れていいらしい
