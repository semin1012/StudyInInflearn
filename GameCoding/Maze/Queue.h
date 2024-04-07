#pragma once
#include "Vector.h"

// 선입선출인 큐
// 큐가 원형 모양이라고 보면 된다. back이 맨 뒤까지 차면 맨 첫번째 자리로 돌아간다. 
template<typename T>
class Queue
{
public:
	Queue()
	{
		_container.resize(100);
	}

	void push(const T& value)
	{
		// TODO: 다 찼는지 체크
		if (_size == _container.size())
		{

		}

		_container[_back] = value;
		_back = (_back + 1) % _container.size();
		_size++;
	}

	void pop()
	{
		_front = (_front + 1) % _container.size();
		_size--;
	}

	T& front()
	{
		return _container[_front];
	}

	bool empty() { return _size == 0; }
	int size() { return _size; }

private:
	Vector<T> _container;

	int _front = 0;
	int _back = 0;
	int _size = 0;
};