#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <unordered_map>
#include <algorithm>

// 가장 기본적인 정렬에 대해 알아볼 것

// 1 5 3 4 2
// 1 5 3 4 2
// 1 3 5 4 2
// 1 3 4 5 2
// 1 3 4 2 5
// 2개씩 비교해서 하나씩 뒤로 가는 것
// 가장 큰 숫자가 오른쪽으로 간다. 
// 이걸 반복
void BubbleSort(vector<int>& v)
{
	const int n = v.size();

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (v[j] > v[j + 1])
			{
				int temp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = temp;
				//swap(v[j], v[j + 1]);
			}
		}
	}
}


// 1 5 3 4 2
// 제일 작은 애를 하나씩 스캔해서 위치 선택함
// 1 ?
// 1 2 ?
// 1 2 3 ?
void SelectionSort(vector<int>& v)
{
	const int n = v.size();

	for (int i = 0; i < n - 1; i++)
	{
		int bestIdx = i; 
		
		for (int j = i + 1; j < n; j++)
		{
			if (v[j] < v[bestIdx])
				bestIdx = j;
		}

		if ( i != bestIdx )
			swap(v[i], v[bestIdx]);
	}
}

// O(NlogN), 데이터가 많을수록 얘가 더 빨라진다. 보통 괜찮은 소트가 다 NlogN이다.
void HeapSort(vector<int>& v)
// 우선순위 큐의 힙과 같다, 부모가 나보다 더 크면 도장깨기
{
	priority_queue<int, vector<int>, greater<int>> pq;

	// O(NlogN), logN을 N번 한다
	for (int num : v)
		pq.push(num);	// 우선순위 큐에 다 넣어주기, LogN

	// O(NlogN), N개의 데이터마다 logN이 걸려서
	while (pq.empty() == false)
	{
		v.push_back(pq.top()); // O(1)
		pq.pop();	// O(logN)
	}	// 데이터가 있는 동안 작은 순서로 꺼내오게 될 테니까 하나씩 꺼내기
}



int main()
{
	vector<int> v{ 1, 5, 3, 4, 2 };

	//std::sort(v.begin(), v.end());
	// 이것만 알면 되긴 하는데 면접에서 많이 나온다.
	// 간단하게 테스트할 수 있기 때문에...

	BubbleSort(v);
	// 시간복잡도: O(N^2) 굉장히 느리다! 현실성이 없을 정도

	SelectionSort(v);
	// 시간복잡도: O(N^2) 얘도 느리다 
	// 이제부터 현실적인 애들 보자

	HeapSort(v);
	// 시간복잡도: O(logN)
	// 
}