#include "pch.h"
#include "Missile.h"
#include "TimeManager.h"
#include "ObjectManager.h"

Missile::Missile() : Object(ObjectType::Projectile)
{
}

Missile::~Missile()
{
}

void Missile::Init()
{
	//TODO: Data
	_stat.hp = 1;
	_stat.maxHp = 1;
	_stat.speed = 600;
}

void Missile::Update()
{
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();

	_pos.y -= deltaTime * _stat.speed;

	// 충돌
	const vector<Object*> objects = GET_SINGLE(ObjectManager)->GetObjects();
	for (Object* object : objects) 
	{
		if (object == this)
			continue;

		if (object->GetObjectType() != ObjectType::Monster)
			continue;

		Pos p1 = GetPos();
		Pos p2 = object->GetPos();

		const float dx = p1.x - p2.x;
		const float dy = p1.y - p2.y;
		float dist = sqrt(dx * dx + dy * dy);

		if (dist < 25)
		{
			GET_SINGLE(ObjectManager)->Remove(object);	// 괜찮을까...?
			GET_SINGLE(ObjectManager)->Remove(this);	// 괜찮을까...?
			return;
		}
	}


	// TODO
	if (_pos.y < -200)
	{
		GET_SINGLE(ObjectManager)->Remove(this);
		// 이렇게 Remove로 다른 녀석한테 나의 자폭을 맡겼으면
		// 바로 return을 호출해서 코드가 끝나게 해줘야 한다. 
		// 이미 자폭했는데 여기에서 _pos.x = 100; 이런 거 하면 메모리 오염 생김. 
		return;
	}
}

void Missile::Render(HDC hdc)
{
	Utils::DrawCircle(hdc, _pos, 25);
}
