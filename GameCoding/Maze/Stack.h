#pragma once
#include "Vector.h"

// 후입선출인 스택
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
		// 맨 뒤의 데이터 가져온 뒤에 pop()을 호출하는 방식, top() -> pop()
	}

	bool empty() { return size() > 0; }
	int size() { return _container.size(); }

private:
	Vector<T> _container;
};

