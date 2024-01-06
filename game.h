/*===================================================================================
ゲームシステム（game.cpp)
Date:2024/1/6
制作者：譚偉進
====================================================================================*/
#pragma once
#include "world.h"
#include "player.h"
#include "enemy.h"
class Game {
private:
	World* _world;
	bool _is_pause = false;
	Player* _player = nullptr;
public:
	Game();
	~Game();
	void Update();
	void Pause() { _is_pause = true; }
	void Resume() { _is_pause = false; }
	//void Menu();
};
