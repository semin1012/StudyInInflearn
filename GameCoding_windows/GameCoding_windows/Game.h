#pragma once

class Game
{
public:
	Game();
	~Game();

public:
	// Init, Update, Render�� ��� ���� ���̴�. 
	// �ʱ�ȭ, �� Ÿ�Ӹ��� ������Ʈ, ������
	void Init(HWND hwnd);
	void Update();
	void Render();

private:
	HWND _hwnd = {};
	HDC _hdc = {};
};

