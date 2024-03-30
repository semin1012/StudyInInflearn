#include <iostream>
#include "Array.h"
#include "Vector.h"
using namespace std;

int main()
{
	// Vector
	// 삽입/삭제
		// - 시작	O(N)
		// - 중간	O(N)
		// - 끝		O(1)
		// 끝 말고는 모두 느리다. 
	// 임의 접근?
		// 0(1)


	// List
	// 삽입/삭제
		// - 시작	O(1)
		// - 중간	O(1)
		//	 중간의 위치를 기억하고 있을 때만 빠르다!!
		// - 끝		O(1)
	// 임의의 index 접근?
		// O(N)
}