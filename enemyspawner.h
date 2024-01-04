#pragma once
#include "object.h"
class EnemySpawner:public Object {
	int _frame_counter = 0;
public:
	void Update()override;				
	void Draw()const override{}
	bool IsDiscard()const override { return false; }
};
