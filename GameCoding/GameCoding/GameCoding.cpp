#include <iostream>
using namespace std;
#include <vector>
#include <queue>

// STL - 컨테이너, 자료구조를 구현한 상태로 공급해 준다.
// 자료를 관리할 목적으로 구현한 클래스를 컨테이너라고 한다고 볼 수 있지만
// 자료구조와 컨테이너를 혼용해서 사용하긴 한다.
// vector는 자료구조가 아니라 컨테이너긴 하다. 

// 시퀀스 컨테이너: 일렬로 연결된 애들 (벡터, 리스트)
// 연관 컨테이너: 저장되는 순서가 추가한 순서랑 다른 애들 (맵, 해시맵, 셋)
//				  즉, 특정 기준에 따라 자동 정렬되는 애들

void Test(vector<int> v)
{

}

// 복사가 안 일어나게 하려면 밑에처럼 "참조"값을 넘기는 게 유리하다.
void TestBetter(vector<int>& v)
{

}

int main()
{
	vector<int> v{ 1,2,3,4,5 };
	// size (resize) : 실제 데이터 크기
	// capacity (reserve) : 실제 할당된 공간 
	// 삽입/삭제
	// - 시작	O(n)
	// - 중간	O(n)
	// - 끝		O(1)
	// push_back, front, back
	// 임의 접근 v[i] = O(1)
	// v.remove(10)?	O(n)

	v.reserve(10); // 공간을 할당
	v.resize(10);  // 데이터 크기 넣기
	// 그래서 reserve를 먼저 한 뒤에 데이터를 넣는 사람도 있다.
	// 이유: 이사 비용을 아낄 수 있고 메모리 파편을 아낄 수 있다.

	v.push_back(10);	// O(1)
	v.push_back(20);	// O(1)
	v.push_back(30);	// O(1)
	// 맨 뒤에 추가하는 것은 O(1)이라 vector 컨테이너 자체에서 제공함.
	v.pop_back();		// 이것도 O(1)이라 당연히 제공함.

	int a = v.front();	// O(1)
	int b = v.back();	// O(1)

	// 여기까지 이전 내용
	// ========================================================================
	// 여기부터 오늘 내용 
	
	// 추가
	// 삭제
		// erase 사용할 때 주의해야 한다!!!
	// 순회
	// 검색


	// 순회
	const int size = v.size();
	// 위처럼 쓰면 밑에처럼 v.size()를 for문에서 쓸 때 반복계산을 안 할 것.
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
	cout << endl;


	// vector 초기화 방법은 밑에 세 가지
	//vector<int> v(3);
	//vector<int> v(5, -1);
	//vector<int> v{ 1,2,3,4,5 };


	// vector는 동적 배열이다. v는 스택 영역이지만 안에 들어간 데이터는 heap 영역.
	//vector<int> v2 = v;	// 애초에 안 되는 코드
	//v2[0] = 100;
	// 그렇다면 v2를 바꿀 때 v도 바뀔까? no no. 얕은 복사임.
	// 별도의 공간에 똑같은 데이터를 갖게 될 뿐이다. 
	Test(v);
	// 위의 코드를 계속 호출한다면 v가 계속해서 복사된다는 뜻이다. 
	TestBetter(v);
	// 위처럼 쓰면 복사 안 일어나서 이점이 있음.


	v.clear();
	// size -> 데이터는 사라짐, 0
	// capacity -> 영역은 그대로, 15
	// 벡터가 한 번 만들어졌으면 공간은 안 사라지고 그대로 간다고 생각해야 함
	cout << v.size() << endl;
	cout << v.capacity() << endl << endl;

	{
		// iterator ? 반복자 포인터 ?
		vector<int> v{ 1,2,3,4,5 };

		int* ptr = &v[0];
		int* ptrEnd = &v[4];
		int value = *ptr;
		
		while (ptr != ptrEnd) 
		{
			// 하나씩 뒤로 가기 가능
			ptr++;
			cout << *ptr << endl;
		}

		cout << endl;
	}

	{	// 위의 코드를 iterator로 구현할 수 있다.
		// 이렇게 코드를 짜면 vector를 list로 바꿔서도 구현 가능하다. 인터페이스가 같음.
		// 코드가 유지 가능하다는 것이 굉장한 장점이다. 
		vector<int> v{ 1,2,3,4,5 };
		vector<int>::iterator it = v.begin();
		vector<int>::iterator itEnd = v.end();

		while (it != itEnd) 
		{
			cout << *it << endl;
			it++;
		}
		cout << endl;
	}

	{	// 보통은 이터레이터로 탐색할 때 아래처럼 사용한다. 
		vector<int> v{ 1,2,3,4,5 };
		bool found = false;
		vector<int>::iterator it;

		for ( it = v.begin(); it != v.end(); it++)
		{
			int data = *it;
			if (data == 3) 
			{
				// 찾음
				found = true;
				break;
			}
		}

		if (it != v.end())
		{
			// end까지 탐색한 게 아니라면 찾음 
			cout << "찾음" << endl << endl;
			// 삭제한다
			v.erase(it);	// 두번째 인자 넣으면 어디부터 어디까지 삭제할지 지정 가능
		}
	}

	{
		vector<int> v{ 1,2,3,4,5 };

		//for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
		//{
		//	int value = *it;
		//	if (value % 2 == 0)
		//	{
		//		it = v.erase(it);
		//		// v.erase(it)만 적으면 반환되는 게 앞당겨진 것의 다음 위치라서 이상하게 동작함
		//		// it로 앞당겨진 것의 다음 위치를 받아주면 it가 다음 위치로 지정돼서 동작하긴 함.
		//		// 근데 이것도 2가 삭제되면 it에 3의 위치가 반환되는데 it++이 뒤에 또 있어서
		//		// 3을 지나치고 4를 바로 수행하게 됨. 로직이 이상함. 
		//		// 마지막 데이터에 이 if문을 수행하게 된다면... 순회할 수 없는 곳까지 접근하게 되어 터짐
		//	}
		//	// 즉 위의 코드가 아니라 밑에 코드로 만들어야 함.
		//}
		// 밑에가 정상적 코드!!
		for (vector<int>::iterator it = v.begin(); it != v.end(); )
		{
			int value = *it;
			if (value % 2 == 0)
				it = v.erase(it);
			else
				it++;
		}

		for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
		{
			cout << *it << endl;
		}
	}

}