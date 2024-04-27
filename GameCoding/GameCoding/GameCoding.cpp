#include <iostream>
using namespace std;

// Vector/List -> Tree -> Gragh -> BFS -> Dijikstra -> A* (PQ)
// 모든 애들이 엮어 있다. 순차적으로 알아볼 것.

void Func(int a)
{
	if ( a == 0 )
		return;

	cout << a << endl;

	Func(a-1);
	// 이렇게 되면 스택 오버플로우, 할당된 스택 프레임을 초과해서 사용하기 때문에 스택 오버플로우 발생.
	// for문 사용하면 되는 것을 왜 이렇게 하냐?
	//  - Tree의 경우 똑같은 함수를 재사용하면 상황을 재현하기가 좋을 때가 있다. 이럴 때 사용함.
}

// 5! (팩토리얼) = 5*4*3*2*1 = 120
// n! = n * (n-1)!

int Factorial(int n)
{
	if ( n <= 1 )
		return 1;
	return n * Factorial(n-1);
}

// 유클리드 알고리즘
// a > b
// GCD(1071, 1029)
// = GCD(1029, 1071%1029=42)
// = GCD(42, 1029%42=21)
// = GCD(21, 0) = 21

int Gcd(int a, int b)
{
	if ( b == 0 )
		return a;
	return Gcd(b, a%b);
}

int main()
{
	cout << Gcd(1071, 1029) << endl;
}