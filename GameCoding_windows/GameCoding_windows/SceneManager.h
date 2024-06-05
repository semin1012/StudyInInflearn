#pragma once

class SceneManager
{
	// 씬과 씬 매니저를 두는 이유는?
	// 게임의 씬마다 아예 느낌이 달라질 수 있다.
	// 씬이 없다면 씬 매니저에 그 객체들을 하드코딩할 수밖에 없지만
	// 씬을 따로 둔다면 하드코딩 없이 게임에서 플레이어, 몬스터를 배치하듯 깔끔
	// 하게 코딩이 가능하다. 

	DECLARE_SINGLE(SceneManager);

public:
	void Init();
	void Update();
	void Render(HDC hdc);

	void Clear();

public:
	void ChangeScene(SceneType sceneType);

private:
	class Scene* _scene;
	SceneType _sceneType = SceneType::None;
};