#pragma once
#include "Scene.h"

class EditScene : public Scene
{
public:
	EditScene();
	virtual ~EditScene() override;

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

public:
	vector<pair<POINT, POINT>> _lines;


	bool _setOrigin = true;		// 맨 처음 찍을 때는 이전에 찍었던 lastPos가 없는 것 판별용
	POINT _lastPos = {};
};

