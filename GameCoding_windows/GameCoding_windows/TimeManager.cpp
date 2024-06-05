#include "pch.h"
#include "TimeManager.h"

void TimeManager::Init()
{
	// ms
	//::GetTickCount64();	// 정밀도가 살짝 떨어진다.
	//::GetTickCount64();

	::QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER*>( & _frequency));
	::QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&_prevCount));	// 이거 더 정밀하다.
	// 이 이상 알아볼 필요는 없다. 
}

void TimeManager::Update()
{	
	uint64 currentCount;
	::QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&currentCount));

	_deltaTime = (currentCount - _prevCount) / static_cast<float>(_frequency);
	_prevCount = currentCount;
	// 그냥 이렇게 계산된다고 하니까 이렇게 넣어준다. 

	_frameCount++;
	_frameTime += _deltaTime;

	if (_frameTime >= 1.f)
	{
		_fps = static_cast<uint32>(_frameCount / _frameTime);

		_frameTime = 0.f;
		_frameCount = 0;
	}
}
