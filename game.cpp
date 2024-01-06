/*===================================================================================
ゲームシステム（game.cpp)
Date:2024/1/6
制作者：譚偉進
====================================================================================*/
#include "stdafx.h"
#include "game.h"
#include "enemyspawner.h"
Game::Game():_player(new Player)
{

	_world = new World;
	_player->SetPosition(Scene::Center());
	_world->Accept(_player);
	auto es = new EnemySpawner;
	es->SetPosition({ Scene::Width() + 64.0f,0.0f });
	_world->Accept(es);
}

Game::~Game()
{
	delete _world;
}

void Game::Update()
{
	if (!_is_pause) {
		_player->PlayerMove();
		_world->Update();
		PlayerAttack();
	}
	else {
		Pause();
		if (KeyEscape.down()) {
			Resume();
		}
	}
	_world->Draw();
	//Menu();
	_world->CleanUp();
}

void Game::PlayerAttack()
{
	if (MouseL.up()) {
		auto attacker = _world->GetObjectByTag("Attack");
		if (attacker != nullptr) {
			if (auto obj = _world->GetOverlapEnemy(attacker->GetCollision())) {
					Attack* pattacker = dynamic_cast<Attack*>(attacker);
					Enemy* penemy = dynamic_cast<Enemy*>(obj);
					if (penemy)obj->Damage(pattacker);
			}
		}
	}
}

void Game::PickItem()
{
	//if (MouseR.up()) {
	//	if (_player != nullptr) {
	//		if (auto obj = _world->GetOverlapItem(_player->GetCollision())) {
	//			if (obj->GetTag() == "Enemy") {
	//				Attack* pattacker = dynamic_cast<Attack*>(attacker);
	//				Enemy* penemy = dynamic_cast<Enemy*>(obj);
	//				if (penemy)obj->Damage(pattacker);
	//			}
	//		}
	//	}
	//}
}
