#pragma once

class SceneManager
{
	// ���� �� �Ŵ����� �δ� ������?
	// ������ ������ �ƿ� ������ �޶��� �� �ִ�.
	// ���� ���ٸ� �� �Ŵ����� �� ��ü���� �ϵ��ڵ��� ���ۿ� ������
	// ���� ���� �дٸ� �ϵ��ڵ� ���� ���ӿ��� �÷��̾�, ���͸� ��ġ�ϵ� ���
	// �ϰ� �ڵ��� �����ϴ�. 

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