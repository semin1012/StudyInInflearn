#include <iostream>
#include "List.h"

int main()
{
	List li;
	
	li.AddAtTail(1);
	// 이렇게 특정 데이터를 기억해 뒀다가 삭제하는 건 굉장히 빠르다.
	Node* node = li.AddAtTail(2);
	li.AddAtTail(3);

	li.Print();

	li.Remove(node);

	// 하지만 이렇게 GetNode로 위치를 찾은 뒤에 삭제하는 것은 느리다.
	// 연결 리스트의 검색 자체가 느리기 때문.
	li.Remove(li.GetNode(0));

	// 위치를 기억하지 않고는 중간 삽입/삭제가 빠르다.
	// 서치를 따로 해야 하는 경우에는 삽입/삭제가 빠르지 않다. 
	// 중간에 임의 접근을 해야 하는 경우는 전혀 빠르지 않다. 임의접근 안 됨.

	li.Print();
}
