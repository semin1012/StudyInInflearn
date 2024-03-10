#include <iostream>
using namespace std;

void Swap(int* a, int* b) // 주소값을 담은 변수라는 뜻
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	void* ptr = nullptr; // 빈 주소라는 뜻
	// 64bit 컴퓨터에서는 8바이트의 주소를 담을 수 있다.

	int a = 10;
	int b = 20;

	Swap(&a, &b);	// 주소값을 넘긴다
	
	cout << a << endl;
	cout << b << endl;
}