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

	GET_SINGLE(SceneManager)->Render(_hdc);
	
	{
		// WCHAR  buffer[100]; // �̰� ���� ����̴�.
		wstring str = std::format(L"FPS({0}), DT({1} ms)", fps, static_cast<int32>(deltaTime * 1000));
		::TextOutW(_hdc, 650, 10, str.c_str(), static_cast<int32>(str.size()));
	}
		
	// ���� ���۸��� ���ؼ� �������� ���� ��� �ִ�. �˾Ƶ� ��.
}
