#pragma once
class Collision {
public:
	virtual ~Collision(){}
	virtual void SetPos(Float2 pos){}
	virtual bool IsOverlapping(const Collision* collision)const = 0;
};

class CollisionCircle :public Collision {
private:
	Circle _circle;
public:
	CollisionCircle(Float2 pos,float size);
	Circle GetCircle()const { return _circle; }
	Vec2 GetPos()const { return _circle.center; }
	float GetRadius()const { return _circle.r; }
	void SetPos(Float2 pos) override{ _circle.setPos(pos); }
	bool IsOverlapping(const Collision* collision)const override{
		const CollisionCircle* ob1 = dynamic_cast<const CollisionCircle*>(collision);
		return this->isOverlappingCircle(ob1);
	}
	bool isOverlappingCircle(const CollisionCircle* collision)const{
		auto ob1 = this->GetCircle();
		auto ob2 = collision->GetCircle();
		if (ob1.intersects(ob2))return true;
		return false;
	}
};
