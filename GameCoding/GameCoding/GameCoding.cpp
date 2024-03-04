#include <iostream>
using namespace std;

int Add(int a, int b);
float Add(float a, float b);

int main()
{
	cout << Add(10, 20) << endl;
}

int Add(int a, int b)
// 게임계에서 함수는 보통 대문자로 시작한다 
{
	return (a + b);
}

float Add(float a, float b)
{
	
}