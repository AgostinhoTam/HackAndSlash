/*===================================================================================
当たり判定（collision.h)
Date:2024/1/6
制作者：譚偉進
====================================================================================*/
#pragma once
class Collision {
public:
	virtual ~Collision(){}
	virtual void SetPos(Float2 pos){}
	virtual Circle GetCircle()const { return Circle(Float2(0.0f, 0.0f), 0.0f); }
	virtual bool IsOverlapping(const Collision* collision)const = 0;
};
class CollisionCircle :public Collision {
private:
	Circle _circle;
public:
	CollisionCircle(Float2 pos,float size);
	Circle GetCircle()const override{ return _circle; }
	Vec2 GetPos()const { return _circle.center; }
	float GetRadius()const { return _circle.r; }
	void SetPos(Float2 pos) override{ _circle.setPos(pos); }
	bool IsOverlapping(const Collision* collision)const override{
		return this->isOverlappingCircle(collision);
	}
	bool isOverlappingCircle(const Collision* collision)const{
		auto ob1 = this->GetCircle();
		auto ob2 = collision->GetCircle();
		if (ob1.intersects(ob2))return true;
		return false;
	}
};



