#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <queue>
#include <map>
#include "List.h"

// auto ( c++11에서 나온 것, 새로운 문법 )

class Knight
{

};

template<typename T>
void Print(T t)
{
	cout << t << endl;
}

int main()
{
	// C++03
	// C++11 (대격변, Modern C++)
	// C++14
	// C++17
	// C++20 (2차 대격변, couritine, module)
	// 우리가 배우는 것은 03, 그리고 이제 11이다.

	{
		int a = 3;
		float b = 3.14f;
		double c = 1.23;
		Knight* d = new Knight();
		const char* e = "semin";
	}

	{
		auto a = 3;
		auto b = 3.14f;
		auto c = 1.23;
		auto d = new Knight();
		auto e = "semin";

		// 이렇게 돌려도 오류 없다
		// auto는 일종의 조커 카드 ( template과 뿌리가 비슷 )
		Print<int>(1);
		Print<const char*>("semin");
		// 알아서 형식 골라 주는 것을 "형식 연역(type deduction)"이라고 한다.
		// -> 말이 되게 잘 맞춰 주는 추론을 해 줌
		// 주의: 추론 규칙이 생각보다 복잡해질 때가 있다.

		// int* ptr = a;
		// 이건 안 됨 말이 안 되는 문법임
		int& ret = a;
		const int cst = a;
		
		// 주의! auto는 const, &는 빼고 추론한다
		auto& ret2 = ret;
		const auto cst2 = cst;

		vector<int> v{ 1,2,3,4,5 };

		for (int i = 0; i < v.size(); i++)
		{
			// int& value = v[i];
			// 원본을 건들려면 &를 붙여라
			auto& value = v[i];
			// auto를 쓸 때도 &를 붙여야 한다
			if (value < 5)
			{

			}
			value = 10;
		}	

	}
	
	// auto 의 문제점: 가독성
	// - c++의 장점이 자료형 가독성이 좋다는 것인데
	//	 가독성이 좋지 않다. auto를 막 쓰는 것은 c++ 장점을 망침.
	//	 속도에 대해 치명적 단점은 없음. 가독성이 치명적. 무지성 사용 지양.
	// auto 의 장점은?: 타이핑
	// - 템플릿과 엮어 사용할 때 효과적일 수 있음.
	// - vector<int>::iterator와 같은 귀찮은 타이핑을 줄일 수 있다
	//   auto it = v.begin() 이런 건 누가 봐도 이터레이터인 거 알 수 있음
	
	map<int, int> m;
	//std::map<int, int>::iterator it = m.begin();
	auto it = m.begin();	// 위의 것을 auto로 사용하면 간단

	// 결론!) 앞으로 auto는  iterator의 경우메나 사용하기로 한다.
	// 주의!) 복사면 안 되고 참조일 때 &를 붙이는 것은 잊지 말기.
}