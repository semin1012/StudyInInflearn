#pragma once

class Game
{
public:
	Game();
	~Game();

public:
	// Init, Update, Render가 계속 나올 것이다. 
	// 초기화, 매 타임마다 업데이트, 렌더링
	void Init(HWND hwnd);
	void Update();
	void Render();

private:
	HWND _hwnd = {};
	HDC _hdc = {};

private:
	// Double Buffering
	RECT _rect;
	HDC _hdcBack = {};
	HBITMAP _bmpBack = {};
};

