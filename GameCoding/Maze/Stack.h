#pragma once
#include "Vector.h"

// ���Լ����� ����
template<typename T>
class Stack
{
public:
	void push(const T& value)
	{
		_container.push_back(value);
	}

	void pop()
	{
		_container.pop_back();
	}

	T& top()
	{
		return _container.back();	
		// �� ���� ������ ������ �ڿ� pop()�� ȣ���ϴ� ���, top() -> pop()
	}

	bool empty() { return size() > 0; }
	int size() { return _container.size(); }

private:
	Vector<T> _container;
};

