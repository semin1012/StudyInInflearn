#include <iostream>
using namespace std;
#include <vector>
#include <queue>

// 함수 포인터의 단점
// - 시그니처가 안 맞으면 사용 X (함수의 return, 변수 타입이 다르면 할당할 수 없음)
// - 상태를 가질 수 없음 (데이터를 바인딩해서 가질 수 없음)

// 함수를 호출하는 용도로 사용하는 것을 함수 객체라고 한다.

class Functor
{
public:
	// 오버로딩 -> 같은 함수가 여러 의미를 갖는 것
	// 오버라이딩 -> 상속받은 부모의 함수에 자식이 새로운 의미를 갖는 것
	void operator()()	// 괄호에 대해서 오버로딩을 하는 것이다
	{
		cout << "Functor Test" << endl;
		cout << _value << endl;
	}

	void operator()(int n)
	{
		cout << "Functor Test" << endl;
		_value += n;
		cout << _value << endl;
	}

public:
	int _value = 0;
};

struct AddStruct
{
public:
	int operator()(int a, int b)
	{
		return a + b;
	}
};

template<typename T>
//using FuncType = int(*)(int, int);
// T를 위처럼 하면 함수의 '포인터'만 들어갈 수가 있어서
// main의 함수 객체인 func를 쓸 수가 없음
int DoSomething(int a, int b, T func)
{
	return func(a, b);
}

template<class T>
struct Greater	// 공식 문서 greater와 동일한 코드 
{
	bool operator()(const T& left, const T& right) const
	{
		return left > right;
	}
};

int main()
{
	// 아래처럼 Functor를 사용할 때는 템플릿이랑 궁합이 잘 맞는다.
	// 별다른 위험 없이 아다리가 잘 맞는다면 실행이 된다. 
	AddStruct func;
	DoSomething(10, 20, func);

	priority_queue<int, vector<int>, Greater<int>> pq;
}