/*===================================================================================
攻撃（attack.cpp)
Date:2024/1/6
制作者：譚偉進
====================================================================================*/
#pragma once
#include "object.h"
class Attack :public Object
{
public:
	Attack(Float2 pos);
	virtual int GetValue()const { return 1; }
	void Update()override{}
	void Draw()const override;
	bool IsDiscard()const override { return true; }
	void AttackCreation(World* world);
};

