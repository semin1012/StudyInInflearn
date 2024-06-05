#include "pch.h"
#include "InputManager.h"

void InputManager::Init(HWND hwnd)
{
	_hwnd = hwnd;
	_states.resize(KEY_TYPE_COUNT, KeyState::None);
}

void InputManager::Update()
{
	// ::GetAsyncKeyState();	// ������ ȣ���ϸ� �ӵ��� ������. ���� �п����� ��.

	BYTE asciiKeys[KEY_TYPE_COUNT] = {};
	if (::GetKeyboardState(asciiKeys) == false)	// Ű���� 256���� ���¸� ��� �ܾ���� ���� �� �����Ӹ��� �Ѵ�.
		return;

	for (uint32 key = 0; key < KEY_TYPE_COUNT; key++)
	{
		// Ű�� ���� ������ true
		if (asciiKeys[key] & 0x80)	// 0x80�̶� üũ�ϸ� �������� �� 1�� ���´�.
		{
			KeyState& state = _states[key];

			// ���� �����ӿ� Ű�� ����(Down) ���¶�� PRESS
			if (state == KeyState::Press || state == KeyState::Down)
				state = KeyState::Press;
			else
				state = KeyState::Down;
		}
		else
		// Ű�� ���� ���� ������ �̰�
		{
			KeyState& state = _states[key];

			// ���� �����ӿ� Ű�� ���� ����(Down)���ٸ� Up
			if (state == KeyState::Down || state == KeyState::Press)
				state = KeyState::Up;
			else
				state = KeyState::None;
		}
	}

	// Mouse
	::GetCursorPos(&_mousePos);				// Ŀ���� ��ǥ�� ���´�
	::ScreenToClient(_hwnd, &_mousePos);	// �츮 â�� �������� �� mousePos�� ���ϴ� �Լ�
}
