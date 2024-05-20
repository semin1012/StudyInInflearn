#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <queue>
#include <map>

// 이진 탐색 (binary search)

vector<int> numbers;

void BinarySearch(int N)
{
	int left = 0;
	int right = numbers.size() - 1;

	while (left <= right)
	{
		cout << "탐색 범위: " << left << " ~ " << right << endl;

		int mid = (left + right) / 2;

		if (N < numbers[mid])
		{
			cout << N << " < " << numbers[mid] << endl;
			right = mid - 1;
		}
		else if (N > numbers[mid])
		{
			cout << N << " > " << numbers[mid] << endl;
			left = mid + 1;
		}
		else
		{
			cout << "찾았음!" << N << " = " << numbers[mid] << endl;
			break;
		}
	}
}

int main()
{
	// [1][8][15][23][32][44][56][63][81][91]
	// 위의 데이터가 vector 형식일 때 원하는 값이 있는지 찾는 법?
	// Q) 82?
	// 하나하나씩 확인할 경우 -> O(N)
	// 만약 정렬이 되어있다는 것을 안다면?
	// 중간 값이 찾는 값보다 작은지, 큰지를 파악해서 업앤다운으로 "이진 탐색" 할 수 있음
	// 이진 탐색: 반반씩 나누어서 서칭을 하는 느낌이다
	//			  = O(logN)
	// 정렬만 되어 있다면 아름다운 방식이다. 코테에 자주 나온다.

	// left와 right가 존재, mid 값이 큰지 작은지 파악한다.
	// mid보다 크다면 left = mid 로 변경하는 식으로 진행한다. 

	numbers = { 1, 8, 15, 23, 32, 44, 56, 63, 81, 91 };
	BinarySearch(81);

	// Q1. 이것을 리스트로 한다면?
	//  - vector는 임의 접근이 가능했기 때문에 이게 가능했음
	//  - 리스트는 임의 접근이 불가능하기 때문에 바이너리 서치 불가능. 배열 특화적인 기법임.
	// Q2. O(logN) 굉장히 빠른 것이다. 근데 왜 게임에서 한계가 있을까?
	//  - 중간에 삽입/삭제가 너무나 힘들다(느리다). 벡터는 중간 삽입 삭제 어려움.
	//  - 리스트는 삽입/삭제가 쉽지만 바이너리 서치가 안 됨. 
	//  - 서칭하는 용도로만 사용하면 좋다. 그렇지만 대부분 상황에서는 삽입/삭제 필수적.
	
}