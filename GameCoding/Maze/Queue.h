#pragma once
#include "Vector.h"

// 선입선출인 큐 
template<typename T>
class Queue
{
public:
	Queue()
	{
		_container.resize(100);
	}

private:
	Vector<T> _container;

	int _front = 0;
	int _back = 0;
	int _size = 0;
};