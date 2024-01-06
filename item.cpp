#include "stdafx.h"
#include "item.h"

Item::Item(Float2 pos):Object("Item"), _texture(0xF1B14_icon, 64)
{
	_collision = new CollisionCircle(pos, 32.0f);
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
