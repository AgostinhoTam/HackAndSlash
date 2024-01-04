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
//ClearUpの中身は正直普通にdrawの後に入れていいらしい
