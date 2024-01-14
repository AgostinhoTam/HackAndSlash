/*===================================================================================
アイテム管理（item.cpp)
Date:2024/1/7
制作者：譚偉進
====================================================================================*/
#include "stdafx.h"
#include "item.h"

Item::Item(Float2 pos, int itemtype):Object("Item")
{
	SetPosition(pos);
	switch (itemtype) {
		case HPRECOVERY:{
			_itemtype = HPRECOVERY;
			const Texture recoveryText(0xF1B14_icon, 64);
			_texture = recoveryText;
			_weight = 1.0f;
			break;
		}
		case MAXHPUP:{
			_itemtype = MAXHPUP;
			const Texture attackupText(0xF0737_icon, 64);
			_texture = attackupText;
			_weight = 2.0f;
			break;
		}
	}
	_collision = new CollisionCircle(GetPosition(), 32.0f);
}

void Item::Draw() const
{
	_texture.drawAt(GetPosition());
}

bool Item::IsDiscard() const
{
	if (_flag)return true;
    return false;
}
