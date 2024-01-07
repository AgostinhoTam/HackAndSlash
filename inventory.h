/*===================================================================================
インベントリ（inventory.cpp)
Date:2024/1/6
制作者：譚偉進
====================================================================================*/
#pragma once
#include "item.h"
class Inventory {
private:
	bool _flag=true;
	ITEM_TYPE _itemtype;
	float _weight;
public:
	Inventory(Item* item);
	void UseItem() { _flag = false; }
	ITEM_TYPE GetItemType() const{ return _itemtype; }
	float GetWeight() const{ return _weight; }
	bool GetUse() const{ return _flag; }
};
