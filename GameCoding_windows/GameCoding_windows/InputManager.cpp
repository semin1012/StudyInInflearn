#include "pch.h"
#include "InputManager.h"

void InputManager::Init(HWND hwnd)
{
	_hwnd = hwnd;
	_states.resize(KEY_TYPE_COUNT, KeyState::None);
}

void InputManager::Update()
{
	// ::GetAsyncKeyState();	// 여러번 호출하면 속도가 느려짐. 보통 학원에서 씀.

	BYTE asciiKeys[KEY_TYPE_COUNT] = {};
	if (::GetKeyboardState(asciiKeys) == false)	// 키보드 256개의 상태를 모두 긁어오는 것을 매 프레임마다 한다.
		return;

	for (uint32 key = 0; key < KEY_TYPE_COUNT; key++)
	{
		// 키가 눌려 있으면 true
		if (asciiKeys[key] & 0x80)	// 0x80이랑 체크하면 눌려있을 때 1이 나온다.
		{
			KeyState& state = _states[key];

			// 이전 프레임에 키를 누른(Down) 상태라면 PRESS
			if (state == KeyState::Press || state == KeyState::Down)
				state = KeyState::Press;
			else
				state = KeyState::Down;
		}
		else
		// 키가 눌려 있지 않으면 이것
		{
			KeyState& state = _states[key];

			// 이전 프레임에 키를 누른 상태(Down)였다면 Up
			if (state == KeyState::Down || state == KeyState::Press)
				state = KeyState::Up;
			else
				state = KeyState::None;
		}
	}

	// Mouse
	::GetCursorPos(&_mousePos);				// 커서의 좌표를 얻어온다
	::ScreenToClient(_hwnd, &_mousePos);	// 우리 창을 기준으로 한 mousePos를 구하는 함수
}
