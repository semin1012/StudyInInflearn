#pragma once
#include "assert.h"

class Vector
{
	using T = int;

public:
	// 다른 클래스에서 간접적 변환이 되는 것을 막는 것 explicit
	explicit Vector(int capacity = 100) : _capacity(capacity)
	{
		_buffer = new T[capacity];
	}

	~Vector()
	{
		delete[] _buffer;
	}

	void clear()
	{
		// TODO
		if (_buffer)
		{
			delete[] _buffer;
			_buffer = new T[_capacity];
		}

		_size = 0;
	}

	void push_back(const T& data)
	{
		// 만약 데이터의 양이 허용 용량과 같다면 (추가 불가능, 용량 추가 필요)
		// 코드 안정화가 되면 더이상 호출이 안 될 코드기 때문에 밑에 if문은 시간복잡도 계산하지 않는다.
		if (_size == _capacity)
		{
			// 증설 작업
			int newCapacity = static_cast<int>(_capacity * 1.5);
			if (newCapacity == _capacity)
				newCapacity++;

			reserve(newCapacity);
		}

		// 데이터 저장
		_buffer[_size] = data;
		
		// 데이터 개수 증가
		_size++;
	}
	
	void pop_back()
	{
		// TODO : 소멸 
		_size--;
	}

	T& back()
	{
		return _buffer[_size-1];
	}

	void reserve(int capacity)
	{
		if (_capacity >= capacity)
			return;

		_capacity = capacity;

		T* newData = new T[_capacity];

		// 데이터 복사
		for (int i = 0; i < _size; i++)
			newData[i] = _buffer[i];

		if (_buffer)
			delete[] _buffer;

		_buffer = newData;
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
	T* _buffer = nullptr;
	int		_size = 0;
	int		_capacity = 0;
};

