#pragma once
#include <list>
#include "object.h"
#include "collision.h"
class Object;
class World {
private:
	std::list<Object*> _objects;
public:
	World() = default;
	~World();

	void Accept(Object* object);
	void CleanUp();
	void Update();
	void Draw();

	Object* GetObjectByTag(const std::string& tag);
	Object* GetOverlapObject(const Collision* collision);
};
