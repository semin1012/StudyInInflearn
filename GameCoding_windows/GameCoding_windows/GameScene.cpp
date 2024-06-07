#include "pch.h"
#include "GameScene.h"
#include "Player.h"
#include "Monster.h"
#include "Missile.h"
#include "ObjectManager.h"

GameScene::GameScene()
{

}

GameScene::~GameScene()
{

}

void GameScene::Init()
{
	{
		Player* player = GET_SINGLE(ObjectManager)->CreateObject<Player>();
		player->SetPos(Pos{ 400, 400 });
		GET_SINGLE(ObjectManager)->Add(player);
	}

	for ( int i = 0 ; i < 5; i++ ) 
	{
		Monster* monster = GET_SINGLE(ObjectManager)->CreateObject<Monster>();
		monster->SetPos(Pos{ static_cast<float>(i+1) * 100, 100 });
		GET_SINGLE(ObjectManager)->Add(monster);
	}
}

void GameScene::Update()
{
	// 플레이어에서 Add를 하는 동시에 Update를 호출하고 있어서 문제가 생긴다.
	// 바로 생성하는 게 아니라 예약을 해 두는 방법이 있을 수 있다.
	// 아니면 애당초 복사로 작업을 하는 것도 방식이 될 수 있다. 
	// &를 지우면(복사 방식 채택) 문제가 없어지지만 소멸에서 신경을 써야 한다. 
	const vector<Object*> objects = GET_SINGLE(ObjectManager)->GetObjects();
	for (Object* object : objects)
	{
		object->Update();
	}
}

void GameScene::Render(HDC hdc)
{
	const vector<Object*>& objects = GET_SINGLE(ObjectManager)->GetObjects();

	for (Object* object : objects)
	{
		object->Render(hdc);
	}
}
