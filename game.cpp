/*===================================================================================
ゲームシステム（game.cpp)
Date:2024/1/6
制作者：譚偉進
====================================================================================*/
#include "stdafx.h"
#include "game.h"
#include "item.h"
#include "enemyspawner.h"

Game::Game():_player(new Player)
{
	_world = new World;
	_player->SetPosition(Scene::Center());
	_world->Accept(_player);
	auto es = new EnemySpawner;
	es->SetPosition({ Scene::Width() + 64.0f,0.0f });
	_world->Accept(es);
	const Texture recoveryText(0xF1B14_icon, 64);
	const Texture attackupText(0xF0737_icon, 64);
	_hprecovery = recoveryText;
	_attackup = attackupText;
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
		PickItem();
		if(KeyE.down())Pause();
	}
	else {
		Menu();
		if (KeySpace.down()) {
			Resume();
		}
	}
	if(!_is_pause)_world->Draw();
	_world->CleanUp();
}

void Game::Menu()
{
	Rect{0,0,800,800}.draw(Arg::top = ColorF{ 0.6, 0.5, 0.3 }, Arg::bottom = ColorF{ 0.2, 0.5, 0.3 });
	if (Button(Rect{ 340,40,420,100 }, _hprecovery, font, U"回復アイテム", U"10HP回復しまう", _player->CountItem(HPRECOVERY), _player->CountItem(HPRECOVERY) > 0)) {
		_player->HPRecovery(5);
		; }
	if (Button(Rect{ 340,160,420,100 }, _attackup, font, U"攻撃アップ", U"30秒攻撃上がります", _player->CountItem(MAXHPUP), _player->CountItem(MAXHPUP) > 0)) {
		_player->MaxHpUp();
	}
	font(U"重量").draw(30, 400, 400, Palette::White);
	font(_player->GetTotalWeight()).draw(30, 500, 400, Palette::White);
	font(U" / ").draw(30, 550, 400, Palette::White);
	font(U"20").draw(30, 600, 400, Palette::White);
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
	if (MouseR.pressed()) {
		if (_player != nullptr) {
			if (auto obj = _world->GetOverlapItem(_player->GetCollision())) {
				Item* pItem = dynamic_cast<Item*>(obj);
				if(_player->InventoryAdd(pItem))pItem->PickUpItem();
			}
		}
	}
}

bool Game::Button(const Rect& rect, const Texture& texture,const Font& font,const String& name,const String& desc,int32 count, bool enabled)
{
	if (enabled)
	{
		rect.draw(ColorF{ 0.3, 0.5, 0.6, 0.8 });

		rect.drawFrame(2, 2, ColorF{ 0.5, 0.7, 1.0 });

		if (rect.mouseOver())
		{
			Cursor::RequestStyle(CursorStyle::Hand);
			rect.draw(ColorF{ 0.3, 0.5, 0.9, 0.8 });

			rect.drawFrame(2, 2, ColorF{ 0.5, 0.7, 1.0 });
		}
	}
	else
	{
		rect.draw(ColorF{ 0.0, 0.4 });

		rect.drawFrame(2, 2, ColorF{ 0.5 });
	}

	texture.scaled(0.5).drawAt(rect.x + 50, rect.y + 50);

	font(name).draw(30, rect.x + 100, rect.y + 16, Palette::White);
	font(desc).draw(18, rect.x + 102, rect.y + 60, Palette::White);
	font(count).draw(50, Arg::rightCenter((rect.x + rect.w - 20), (rect.y + 50)), Palette::White);
	return (enabled && rect.leftClicked());
}
