/*===================================================================================
アイテム（item.cpp)
Date:2024/1/6
制作者：譚偉進
====================================================================================*/
#pragma once
#include "object.h"

class Item :public Object {
private:
	Texture _texture;
	bool _flag=false;
	ITEM_TYPE _itemtype;
	float _weight=0;
public:
	Item(Float2 pos,int itemtype);
	void Update()override{}
	void Draw()const override;
	bool IsDiscard()const override;
	void PickUpItem() { _flag = true; }
	ITEM_TYPE GetItemType()const override { return _itemtype; }
	float GetWeight() { return _weight; }
};
