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

	//TimeManager::GetInstance()->Init();
	GET_SINGLE(TimeManager)->Init();
	GET_SINGLE(InputManager)->Init(hwnd);
	GET_SINGLE(SceneManager)->Init();

	GET_SINGLE(SceneManager)->ChangeScene(SceneType::DevScene);
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
		::TextOut(_hdc, 20, 10, str.c_str(), static_cast<int32>(str.size()));
		::Rectangle(_hdc, mousePos.x - 100, mousePos.y-100, mousePos.x + 100, mousePos.y+100);
	}
	
	{
		// WCHAR  buffer[100]; // 이건 옛날 방식이다.
		wstring str = std::format(L"FPS({0}), DT({1} ms)", fps, static_cast<int32>(deltaTime * 1000));
		::TextOut(_hdc, 650, 10, str.c_str(), static_cast<int32>(str.size()));
	}


	GET_SINGLE(SceneManager)->Render(_hdc);
	
	// 더블 버퍼링에 대해서 면접에서 묻는 경우 있다. 알아둘 것.
}
