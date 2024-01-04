#pragma once

class World;			//お互い参照してる、巡回参照になるから前方宣言する
class Object {
private:
	World* _world = nullptr;
	Float2 _position = { 0.0f,0.0f };
	Float2 _forward = { 1.0f,0.0f };
	Float2 _direction = { 0.0f,0.0f };
	Float2 _velocity = { 0.0f,0.0f };
	std::string _tag;
protected:
	World* GetWorld()const { return _world; }		//
public:
	Object() = default;
	Object(const std::string& tag):_tag(tag){}
	virtual ~Object() = default;					//継承して貰うやつは絶対virtualつける

	void Attach(World* world) { _world = world; }
	const std::string& GetTag()const { return _tag; }
	const Float2& GetPosition()const { return _position; }
	void SetPosition(const Float2& position) { _position = position; }

	virtual void Update() = 0;
	virtual void Draw()const = 0;
	virtual bool IsDiscard()const = 0;
};
