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
	
	// Q1) ������Ʈ�� ����Ʈ�� ������ �ų�, ���ͷ� ������ �ų�? ��� �ʿ�
	// Q2) ������Ʈ�� ������ ��� �� ���̳�? - ������ �����ϴ� ��ü�� �ٸ� �״� ������ �����ϴ� �� ����?
	//	   �¶��ο����� �������� ����� ����. ���� �ִ� ������ ã������ ������ ���� �Ǵ� �� ���ŷο�.

};

