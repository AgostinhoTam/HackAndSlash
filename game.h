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
