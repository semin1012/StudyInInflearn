#include "pch.h"
#include "Game.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "SceneManager.h"

Game::Game()
{
	// �޸� �� üũ
	//new
	//delete
}

Game::~Game()
{
	GET_SINGLE(SceneManager)->Clear();

	_CrtDumpMemoryLeaks();
	// �������� �޸� �������� ���� �ֵ��� ���â�� ������ �� ��
}

void Game::Init(HWND hwnd)
{
	_hwnd = hwnd;			// ������ ��ȣ
	_hdc = ::GetDC(hwnd);	// ��ȭ�� ��ȣ

	::GetClientRect(hwnd, &_rect);


	// ���� ���۸��� ���ؼ� �������� ���� ��� �ִ�. �˾Ƶ� ��.
	_hdcBack = ::CreateCompatibleDC(_hdc);		// _hdc�� ȣȯ�Ǵ� DC�� ����
	_bmpBack = ::CreateCompatibleBitmap(_hdc, _rect.right, _rect.bottom);	// _hdc�� ȣȯ�Ǵ� ��Ʈ�� ����
	HBITMAP prev = (HBITMAP)::SelectObject(_hdcBack, _bmpBack);	// DC�� BMP�� ����
	::DeleteObject(prev);
	// ��ȭ�� -> ��Ʈ������ ���� -> ���� ���� �ʿ� ������ �����ش�, ���� ���۸�



	//TimeManager::GetInstance()->Init();
	GET_SINGLE(TimeManager)->Init();
	GET_SINGLE(InputManager)->Init(hwnd);
	GET_SINGLE(SceneManager)->Init();

	GET_SINGLE(SceneManager)->ChangeScene(SceneType::EditScene);
}

void Game::Update()
{
	GET_SINGLE(TimeManager)->Update();
	GET_SINGLE(InputManager)->Update();
	GET_SINGLE(SceneManager)->Update();
}

void Game::Render()
{
	uint32 fps = GET_SINGLE(TimeManager)->GetFps();
	float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();
	
	{
		POINT mousePos = GET_SINGLE(InputManager)->GetMousePos();
		wstring str = std::format(L"Mouse({0}, {1})", mousePos.x, mousePos.y);
		::TextOutW(_hdcBack, 20, 10, str.c_str(), static_cast<int32>(str.size()));
	}


	{
		// WCHAR  buffer[100]; // �̰� ���� ����̴�.
		wstring str = std::format(L"FPS({0}), DT({1} ms)", fps, static_cast<int32>(deltaTime * 1000));
		::TextOutW(_hdcBack, 650, 10, str.c_str(), static_cast<int32>(str.size()));
	}
	
	GET_SINGLE(SceneManager)->Render(_hdcBack);

	// Double Buffering
	::BitBlt(_hdc, 0, 0, _rect.right, _rect.bottom, _hdcBack, 0, 0, SRCCOPY);	
	// ��Ʈ��: ��� ����, �޸� DC�� ��Ʈ���� ���� DC�� ��Ӻ����ϴ� �Լ�
	// _hdcBack ������ hdc�� ����
	::PatBlt(_hdcBack, 0, 0, _rect.right, _rect.bottom, WHITENESS);
	// ��Ʈ��: �ʱ�ȭ�ϴ� ��. ȭ��Ʈ�� �ʱ�ȭ�� �ߴ�.
	// ��Ʈ������ �ʱ�ȭ�� �ϰ� ��Ʈ������ ����ۿ� ����.

	// ���� ���۸��� ����ϴ� �Ͱ� ����� ���� ���� �и��� ���̴�. 
	// �ϳ��� ��¸� �ϰ�, �ϳ��� ����⸸ �Ѵ�. 
}
