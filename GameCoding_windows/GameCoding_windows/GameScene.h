#pragma once
#include "Scene.h"

class GameScene : public Scene
{
public:
	GameScene();
	virtual ~GameScene() override;

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

public:
	//class Player* _player = nullptr;
	
	// Q1) 오브젝트를 리스트로 관리할 거냐, 벡터로 관리할 거냐? 고민 필요
	// Q2) 오브젝트들 관리를 어디서 할 것이냐? - 씬마다 관리하는 객체가 다를 테니 씬마다 관리하는 게 낫나?
	//	   온라인에서는 서버에서 명령을 내림. 씬에 있는 유저를 찾으려면 씬까지 가야 되는 게 번거로움.

};

