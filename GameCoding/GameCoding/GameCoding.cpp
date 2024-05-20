#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <queue>
#include <map>
#include "BinarySearchTree.h"

int main()
{
	BinarySearchTree bst;

	bst.Insert(20);
	bst.Insert(30);
	bst.Insert(10);

	bst.Insert(25);
	bst.Insert(26);
	bst.Insert(40);
	bst.Insert(50);
	
	bst.Delete(30);
	bst.Print(bst.GetRootNode(), 10, 0);
}

// 이진 탐색은 벡터 기반이라 중간 삽입/삭제가 어렵다.
// 삽입/삭제 용이하게 만든 것이 tree 구조다.

// 이진 탐색 -> O(logN)이지만 정렬을 유지해야 하고 데이터 추가/삭제에 무리가 있다.
// 이진 탐색 트리 
//   - 추가/삭제 = O(logN) = 트리의 높이에 의존적. 빠르다.
//	 - 그렇지만 치명적인 단점은?
//	 - 균형이 안 맞는다. tree의 부모에 따라 한쪽으로만 값이 늘어난다.
//	 - 트리의 높이에 의존적이기 때문에 한쪽으로만 쏠려서 높이가 높아질수록 느려질 수밖에 없음.
//	 - 한쪽에만 쏠릴수록 결국 그냥 리스트에 불과하게 됨. = O(N)

// 개선하고 싶으면?
// - red-black tree 같은 것 
// - 레드블랙은 힘드니까 random하게 만드는 것으로 가볍게 구현하기도 함 (프로그래밍 대회에 나갈 정도의 주제)
// - 균형을 맞주는 게 red-black tree. 레드블랙의 표준방식이 map이다.
// - 레드블랙은 구현하기 너무 힘들어서 이론적으로만 보고 지나갈 것이다. 