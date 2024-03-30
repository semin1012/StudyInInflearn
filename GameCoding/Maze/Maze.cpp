#include <iostream>
#include "Array.h"
#include "Vector.h"
using namespace std;

int main()
{
	//Array arr(100);

	//arr.push_back(1);
	//arr.push_back(2);
	//arr.push_back(3);
	//arr.push_back(4);

	//arr[1] = 2;

	Vector v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	for (int i = 0; i < 100; i++) {
		v.push_back(19);
	}

	int a = v[100];

	// C#에서는 동적배열(list) vs 연결리스트(linkedList)
	// 동적배열(vector) vs 연결리스트(list)

	// 배열 ㄷ 동적배열 ㄷ 연결리스트
	// - 배열: 확실하게 변할 일이 없다, 인벤토리 착용 아이템 슬롯, 외형 슬롯 등
	// - 동적배열: 배열을 대체해도 됨. 그냥 배열 = 동적배열 비슷하게 생각해도 됨. 
	//			   대부분 동적배열이 더 빠르게 움직인다. 데이터들이 한곳에 뭉쳐있기 때문에 빠르다.
	//			   때문에 동적배열을 쓰는 경우가 더 많다. 
	// - 연결리스트: 생각보다 느리다. 중간 삽입,삭제에서만 이점이 있음. 쓸 데가 생각보다 없음.
}