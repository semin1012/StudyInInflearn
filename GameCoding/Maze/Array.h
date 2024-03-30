#pragma once
#include "assert.h"

class Array
{
	using T = int;
public:
	// 다른 클래스에서 간접적 변환이 되는 것을 막는 것 explicit
	explicit Array(int capacity = 100) : _capacity(capacity)
	{
		_buffer = new T[capacity];
	}

	~Array()
	{
		delete[] _buffer;
	}

	void push_back(const T& data)
	{
		// TODO
		if (_size == _capacity)
			return;

		_buffer[_size] = data;
		_size++; 
	}

	T& operator[] (int index)
	{
		// TODO
		assert(index >= 0 && index <= _size);
		return _buffer[index];
	}

	int size() { return _size; }
	int capacity() { return _capacity; }

private:
	T*		_buffer = nullptr;
	int		_size = 0;
	int		_capacity = 0;
};

