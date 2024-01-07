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
	const Font font{ FontMethod::MSDF, 48, Typeface::Bold };
	Texture _hprecovery;
	Texture _attackup;
public:
	Game();
	~Game();
	void Update();
	void Pause() { _is_pause = true; }
	void Resume() { _is_pause = false; }
	void Menu();
	void PlayerAttack();
	void PickItem();
	bool Button(const Rect& rect, const Texture& texture, const Font& font, const String& name, const String& desc, int32 count, bool enabled);
	//void Menu();
};
