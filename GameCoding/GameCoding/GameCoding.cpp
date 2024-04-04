#include <iostream>
using namespace std;

// 함수 템플릿
// 클래스 템플릿

// - 템플릿
// - 특수화

template<typename T>
void Print(T a)
{
	cout << a << endl;
}

void PrintInt(int a)
{
	cout << a << endl;
}

void PrintFloat(float a)
{
	cout << a << endl;
}

template<typename T1, typename T2>
void Print(T1 a, T2 b)
{
	cout << a << " " << b << endl;
}

// 템플릿을 사용하여 int나 float형을 보내는 것과
// PrintInt(), PrintFloaT() 함수는 완전히 동일한 개념이다.

template<>
void Print(int a)
// int 일 때만 다른 버전을 만들고 싶을 때 template<> 붙이면 된다
{
	cout << "int" << endl;
}

template<typename T = int, int SIZE = 100>
class RandomBox
{
public:
	T GetRandomData()
	{
		int index = rand() % SIZE;
		return data[index];
	}

public:
	T data[SIZE];
};

template<>
class RandomBox<int>
{
public:
	int GetRandomData()
	{
		int index = rand() % 100;
		return data[index];
	}
public:
	int data[100];
};

int main()
{
	Print(1);
	Print<float>(3.14f);
	Print<const char*>("Hello World");

	Print(1, "Semin");
	// == Print<int, const char*>(1, "Semin");
	
	// 클래스에 template 사용할 때는 생성 시 typename에 해당하는 것 다 넣어줘야 함
	RandomBox<int, 100> rb1;
	RandomBox<float, 200> rb2;
}

// 템플릿 함수 내용에 오류가 있어도 main 함수 내에서 실질적으로 사용되지 않으면
// 오류가 나타나지 않음. 사용하는 순간에서야 오류를 보임

// 템플릿 클래스를 만들 때는 header 파일에 그냥 구현까지 다 쓰는 게 낫다
// 안 그러면 오류가 이상하게 많이 난다.