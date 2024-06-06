#include "pch.h"
#include "Player.h"
#include "InputManager.h"
#include "TimeManager.h"
#include "ObjectManager.h"
#include "Missile.h"

Player::Player() : Object(ObjectType::Player)
{
}

Player::~Player()
{
}

void Player::Init()
{
	// 데이트시트: Excel, Json 등 게임 프로젝트 안에 있는 파일
	// 데이터베이스: Oracale, MSSQL 등 큰 데이터
	
	// TODO: DATA SHEET에 정보가 들어가있을 것이다 
	_stat.hp = 100;
	_stat.maxHp = 100;
	_stat.speed = 500;

	_pos.x = 400;
	_pos.y = 500;
}

void Player::Update()
{
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();
	// 거리 = 시간 * 속도


	// 문제 발생! 
	// 대각선 이동 시 거리가 두 번씩 계산되기 때문에(상하, 좌우로) 
	// 속도가 빨라지는 부분이 생긴다.
	if (GET_SINGLE(InputManager)->GetButton(KeyType::A))
	{
		_pos.x -= _stat.speed * deltaTime;
	}

	if (GET_SINGLE(InputManager)->GetButton(KeyType::D))
	{
		_pos.x += _stat.speed * deltaTime;
	}

	if (GET_SINGLE(InputManager)->GetButton(KeyType::W))
	{
		_pos.y -= _stat.speed * deltaTime;
	}

	if (GET_SINGLE(InputManager)->GetButton(KeyType::S))
	{
		_pos.y += _stat.speed * deltaTime;
	}

	if (GET_SINGLE(InputManager)->GetButtonDown(KeyType::SpaceBar))
	{
		// TODO: 미사일 발사
		Missile* missile = GET_SINGLE(ObjectManager)->CreateObject<Missile>();
		missile->SetPos(_pos);
		GET_SINGLE(ObjectManager)->Add(missile);
	}
}

void Player::Render(HDC hdc)
{
	Utils::DrawCircle(hdc, _pos, 50);
}