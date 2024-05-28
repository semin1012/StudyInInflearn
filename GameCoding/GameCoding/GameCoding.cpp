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


// 병합정렬(분할 정복 사용 (Divide and Conquer)
// - 분할(Divide)		문제를 더 단순하게 분할한다
// - 정복(Conquer)		분할된 문제를 해결한다
// - 결합(Combine)		결과를 취합하여 마무리한다

// [3][k][7][2][j][4][8][9]					<< 8개*1
// [3][k][7][2] | [j][4][8][9]				<< 4개*2
// [3][k] | [7][2] | [j][4] | [8][9]		<< 2개*4
// [3] | [k] | [7] | [2] | [j] | [4] | [8] | [9] << 1개*8
// [3][k]  [2][7]  [4][j]  [8][9]			<< 2개*4
// [2][3][7][k]  [4][8][9][j]
// 정렬된 애들끼리 합치는 건 쉽다는 아이디어에서 출발한다.
// 정렬 뿐만 아니라 다양한 상황에서 사용할 수 있다. 

void MergeResult(vector<int>& v, int left, int mid, int right)
{
	int leftIdx = left;
	int rightIdx = mid + 1;	// right 인덱스의 시작은 mid+1부터 시작

	vector<int> temp;
	
	while (leftIdx <= mid && rightIdx <= right)
	{	// 둘 다 아직 끝나지 않고 데이터가 남아있을 때까지
		if (v[leftIdx] <= v[rightIdx])
		{	// 승리한 숫자 넣어주기
			temp.push_back(v[leftIdx]);
			leftIdx++;
		}
		else
		{
			temp.push_back(v[rightIdx]);
			rightIdx++;
		}
	}

	if (leftIdx > mid)
	{	// leftIdx가 mid보다 커졌다면 left쪽에 있는 애들이 다 이겼다는 말
		while (rightIdx <= right)
		{
			temp.push_back(v[rightIdx]);
			rightIdx++;
			// 나머지 right 애들 넣어준다
		}
	}
	else
	{
		temp.push_back(v[leftIdx]);
		leftIdx++;
	}

	for (int i = 0; i < temp.size(); i++)
	{
		v[left + i] = temp[i];
		// temp의 내용을 원본 벡터에 덮어씌워 주기
	}
}

// 반반씩 나누어 계속 계산하는 시간복잡도 = O(logN)
// MergeResult 시간복잡도 = O(N)
// 결론 - O(logN) + O(N) = O(NlogN)
// 분할정복은 반반씩 나누어서 다른 cpu가 처리해도 결과는 똑같음
// 병렬 처리가 가능하기 때문에 분할정복이 더 유용할 때가 많다. 
void MergeSort(vector<int>& v, int left, int right)
{// left, right 까지의 범위까지 담당한다는 의미
	
	if (left >= right)
		return;

	int mid = (left + right) / 2;
	MergeSort(v, left, mid);
	MergeSort(v, mid + 1, right);
	
	MergeResult(v, left, mid, right);
}

int Partition(vector<int>& v, int left, int right)
{
	int pivot = v[left];	// 숫자
	int low = left + 1;		// index
	int high = right;		// index

	while (low <= high)
	{
		while (low <= right && pivot >= v[low])
			low++;

		while (high >= left + 1 && pivot <= v[high])
			high--;

		if (low < high)
			swap(v[low], v[high]); 
	}

	swap(v[left], v[high]);
	return high;
}

// Partition의 시간복잡도: O(N)
// 평균적으로 QuickSort 시간복잡도: O(NlogN)
// 그러나 계속 극단적으로 피벗 값이 잘리는 경우 O(N^2)인데 평균은 NlogN이라고 보면 됨.
// 평균의 경우 나머지 애들보다 빠르다. 
void QuickSort(vector<int>& v, int left, int right)
{	// 얘가 제일 빠르다. 얘만 알고 있어도 된다.
	if (left > right)
		return;

	int pivot = Partition(v, left, right);
	QuickSort(v, left, pivot - 1);
	QuickSort(v, pivot + 1, right);
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
	// 시간복잡도: O(NlogN)
	
	MergeSort(v, 0, v.size()-1);
	// 시간복잡도: O(NlogN)

	QuickSort(v, 0, v.size() - 1);
	// 시간복잡도: O(logN)
	// 정렬을 하면서 나누는 느낌이다 

	// Sorting의 시간복잡도는? - 보통 애들의 시간복잡도는 다 O(NlogN)이다.
	// O(logN) > O(NlogN) > O(N^2)
	// sorting은 남발하지 않는 게 좋지만 한 번쯤 쓰는 건 괜춘
	// 게임 만들 때 소팅을 쓸 일이 있을까?
	// ex) 인벤토리 정렬.
	// 코드까지 완벽하게 소팅을 구현할 필요는 없지만
	// 대략적으로 어떻게 돌아가는지 정도는 알아두는 게 좋다. 
}