#include "stdafx.h"
#include "enemyspawner.h"
#include "enemy.h"
#include "world.h"
void EnemySpawner::Update()
{
	if (_frame_counter % (60*5)==0) {
		auto e = new Enemy;
		e->SetPosition(GetPosition());
		GetWorld()->Accept(e);
	}
	++_frame_counter;
}
