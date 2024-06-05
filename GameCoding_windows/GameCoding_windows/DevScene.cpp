#include "pch.h"
#include "DevScene.h"
#include "InputManager.h"
#include "TimeManager.h"

DevScene::DevScene()
{

}

DevScene::~DevScene()
{

}

void DevScene::Init()
{

}

void DevScene::Update()
{
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();
	// 거리 = 시간 * 속도


	// 문제 발생! 
	// 대각선 이동 시 거리가 두 번씩 계산되기 때문에(상하, 좌우로) 
	// 속도가 빨라지는 부분이 생긴다.
	if (GET_SINGLE(InputManager)->GetButton(KeyType::A))
	{
		_playerPos.x -= _speed * deltaTime;
	}
	
	if (GET_SINGLE(InputManager)->GetButton(KeyType::D))
	{
		_playerPos.x += _speed * deltaTime;
	}

	if (GET_SINGLE(InputManager)->GetButton(KeyType::W))
	{
		_playerPos.y -= _speed * deltaTime;
	}

	if (GET_SINGLE(InputManager)->GetButton(KeyType::S))
	{
		_playerPos.y += _speed * deltaTime;
	}
}

void DevScene::Render(HDC hdc)
{
	Utils::DrawCircle(hdc, _playerPos, 50);
}