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
}

void World::Draw()
{
	for (auto p : _objects) {
		p->Draw();
	}
}
Object* World::GetObjectByTag(const std::string& tag)
{
	for (auto object : _objects) {							
		if (object->GetTag() == tag) { return object; }
	}
	return nullptr;
}
Object* World::GetOverlapEnemy(const Collision* collision)
{

	auto it = _objects.begin();
	while (it != _objects.end()) {
		auto tag = std::find_if(it, _objects.end(), [](const Object* obj) {return obj->GetTag() == "Enemy"; });
		if (tag == _objects.end())return nullptr;
		Object* pEnemy = *tag;
		if (pEnemy->GetCollision()->IsOverlapping(collision))return pEnemy;
		++tag;
		it = tag;
	}

	return nullptr;
}
Object* World::GetOverlapItem(const Collision* collision)
{
	auto it = _objects.begin();
	while (it != _objects.end()) {
		auto tag = std::find_if(it, _objects.end(), [](const Object* obj) {return obj->GetTag() == "Item"; });
		if (tag == _objects.end())return nullptr;
		Object* pItem = *tag;
		if (pItem->GetCollision()->IsOverlapping(collision))return pItem;
		++tag;
		it = tag;
	}
	return nullptr;
}
