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
public:
	Item(Float2 pos);
	void Update()override{}
	void Draw()const override;
	bool IsDiscard()const override;
	void PickUpItem() { _flag = true; }
};
