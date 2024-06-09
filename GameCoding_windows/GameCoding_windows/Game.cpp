#include "pch.h"
#include "Game.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "SceneManager.h"

Game::Game()
{
	// 메모리 릭 체크
	//new
	//delete
}

Game::~Game()
{
	GET_SINGLE(SceneManager)->Clear();

	_CrtDumpMemoryLeaks();
	// 마지막에 메모리 해제되지 않은 애들을 출력창에 나오게 해 줌
}

void Game::Init(HWND hwnd)
{
	_hwnd = hwnd;			// 윈도우 번호
	_hdc = ::GetDC(hwnd);	// 도화지 번호

	::GetClientRect(hwnd, &_rect);


	// 더블 버퍼링에 대해서 면접에서 묻는 경우 있다. 알아둘 것.
	_hdcBack = ::CreateCompatibleDC(_hdc);		// _hdc와 호환되는 DC를 생성
	_bmpBack = ::CreateCompatibleBitmap(_hdc, _rect.right, _rect.bottom);	// _hdc와 호환되는 비트맵 생성
	HBITMAP prev = (HBITMAP)::SelectObject(_hdcBack, _bmpBack);	// DC와 BMP를 연결
	::DeleteObject(prev);
	// 도화지 -> 비트맵으로 연결 -> 이전 것은 필요 없으니 날려준다, 더블 버퍼링



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
		// WCHAR  buffer[100]; // 이건 옛날 방식이다.
		wstring str = std::format(L"FPS({0}), DT({1} ms)", fps, static_cast<int32>(deltaTime * 1000));
		::TextOutW(_hdcBack, 650, 10, str.c_str(), static_cast<int32>(str.size()));
	}
	
	GET_SINGLE(SceneManager)->Render(_hdcBack);

	// Double Buffering
	::BitBlt(_hdc, 0, 0, _rect.right, _rect.bottom, _hdcBack, 0, 0, SRCCOPY);	
	// 비트블릿: 고속 복사, 메모리 DC의 비트맵을 현재 DC에 고속복사하는 함수
	// _hdcBack 내용을 hdc에 복사
	::PatBlt(_hdcBack, 0, 0, _rect.right, _rect.bottom, WHITENESS);
	// 패트블릿: 초기화하는 것. 화이트로 초기화를 했다.
	// 패트블릿으로 초기화를 하고 비트블릿으로 백버퍼에 저장.

	// 더블 버퍼링은 출력하는 것과 지우는 것을 따로 분리한 것이다. 
	// 하나는 출력만 하고, 하나는 지우기만 한다. 
}
