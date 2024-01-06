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
