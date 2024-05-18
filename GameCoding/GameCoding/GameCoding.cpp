#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <queue>

int main()
{
	// size (resize)
	// capacity (reserve) - X
		// * list의 개념엔 capacity가 없음
		// * 사이즈의 개념은 있지만 별도의 capacity는 없음
	// 삽입/삭제?
	// - 시작		O(1)
	// - 중간		O(1) << 이 위치를 기억하고 있으면 O(1)이다.
	// - 끝			O(1)
	// front		O(1)
	// back			O(1)
	// push_front	O(1)
	// push_back	O(1)
	// 이론적으론 좋지만 노드 타고 가는 연산이 갉아먹기 때문에 벡터보다 느린 경우가 많다
	// remove(value)
	// 임의 접근 li[2]	X

	list<int> li;

	li.insert(li.end(), 1);
	li.insert(li.end(), 2);
	list<int>::iterator it = li.insert(li.end(), 3);
	li.insert(li.end(), 4);
	li.insert(li.end(), 5);
	// insert - 원하는 위치에 넣을 수 있다. 이터레이터임
	li.remove(5);
	li.erase(it);
	// erase - 원하는 위치를 삭제할 수 있다. 이터레이터임

	// 순회, 벡터와 같다 
	for (list<int>::iterator it = li.begin(); it != li.end(); )
	{
		int value = *it;
		if (value % 2 == 0)
			it = li.erase(it);
		else it++;
	}
	
	//if (it != li.end())
	//{
	//	// 끝까지 다 왔다면 그것에 대한 처리
	//}


}