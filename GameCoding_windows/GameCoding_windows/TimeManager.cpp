#include "pch.h"
#include "TimeManager.h"

void TimeManager::Init()
{
	// ms
	//::GetTickCount64();	// ���е��� ��¦ ��������.
	//::GetTickCount64();

	::QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER*>( & _frequency));
	::QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&_prevCount));	// �̰� �� �����ϴ�.
	// �� �̻� �˾ƺ� �ʿ�� ����. 
}

void TimeManager::Update()
{	
	uint64 currentCount;
	::QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&currentCount));

	_deltaTime = (currentCount - _prevCount) / static_cast<float>(_frequency);
	_prevCount = currentCount;
	// �׳� �̷��� ���ȴٰ� �ϴϱ� �̷��� �־��ش�. 

	_frameCount++;
	_frameTime += _deltaTime;

	if (_frameTime >= 1.f)
	{
		_fps = static_cast<uint32>(_frameCount / _frameTime);

		_frameTime = 0.f;
		_frameCount = 0;
	}
}
