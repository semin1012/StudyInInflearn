#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <unordered_map>
#include <algorithm>

// find, find_if 자주 쓴다.
// count, count_if 자주 쓴다.
// all_of, any_of, none_of 종종 쓴다.
// for_each 많이 쓴다.
// remove, remove_if도 꽤 쓴다.

namespace Rookiss
{
	void Test()
	{

	}
}



int main()
{
	Rookiss::Test();
	// 이름은 namespace라서 ::을 쓰게 되는 것이다. 

	vector<int> v;

	for (int i = 0; i < 100; i++)
	{
		int n = rand() % 100;
		v.push_back(n);
	}

	// Q) 특정 숫자가 있는지?
	{
		int number = 50;

		bool found = false;
		vector<int>::iterator it;

		for (auto it = v.begin(); it != v.end(); it++)
		{
			int value = *it;
			if (value == number)
			{
				found = true;
				break;
			}
		}
		// 이렇게 해도 되고 현업에서도 쓰이는 코드지만
		// 길이가 너무 길고 다 읽어야만 기능을 눈치 챌 수가 있다.

		auto it = std::find(v.begin(), v.end(), number);
		if (it == v.end())
		{
			cout << "못 찾음" << endl;
		}
		else
		{
			cout << "찾음" << endl;
		}
		// 성능은 완전히 똑같은데 가독성이 더 좋아진다.
		// 순전히 가독성에만 이점이 있는 것이다. 
		// 너무 특이한 함수는 쓰지 않는 게 좋다.
	}

	// Q2) 11로 나뉘는 숫자가 있는지 찾고 싶다면?
	{
		int div = 11;

		vector<int>::iterator it;

		for (it = v.begin(); it != v.end(); it++)
		{
			int value = *it;
			if (value % div == 0)
			{
				break;
			}
		}
		// 안에 것만 바뀜

		struct CanDivideBy11	// 나중에 람다를 배우면 람다로 하면 된다.
		{
			bool operator()(int n)
			{
				return n % 11 == 0;
			}
		};

		auto it = std::find_if(v.begin(), v.end(), CanDivideBy11());
		if (it == v.end())
		{
			cout << "못 찾음" << endl;
		}
		else
		{
			cout << "찾음" << endl;
		}
	}

	// Q) 홀수인 숫자 개수는?
	{
		int count = 0;
		for (auto it = v.begin(); it != v.end(); it++)
		{
			if (*it % 2 != 0)
				count++;
		}

		struct IsOdd
		{
			bool operator()(int n)
			{
				return n % 2 != 0;
			}
		};

		int n = std::count_if(v.begin(), v.end(), IsOdd());

		// 모든 데이터가 홀수입니까?
		bool b1 = std::all_of(v.begin(), v.end(), IsOdd());
		// 홀수인 데이터가 하나라도 있습니까?
		bool b1 = std::any_of(v.begin(), v.end(), IsOdd());
		// 모든 데이터가 홀수가 아닙니까?
		bool b1 = std::none_of(v.begin(), v.end(), IsOdd());
	}

	// Q) 벡터에 있는 모든 숫자들에 3을 곱해 주세요
	{
		for (int i = 0; i < v.size(); i++)
		{
			v[i] *= 3;
		}

		struct MultiplyBy3
		{
			void operator()(int& n)
			{
				n *= 3;
			}
		};

		std::for_each(v.begin(), v.end(), MultiplyBy3());
		// 상대적으로 활용 빈도가 높다. 기왕이면 만들어진 것을 활용하는 게 좋으니 사용.
	}

	// Q) 홀수인 데이터를 일괄 삭제
	{
		vector<int> v = { 1, 4, 3, 5, 8, 2 };

		/*for (auto it = v.begin(); it != v.end(); )
		{
			if (*it % 2 != 0)
				it = v.erase(it);
			else
				it++;
		}*/

		struct IsOdd
		{
			bool operator()(int n)
			{
				return n % 2 != 0;
			}
		};

		// 1 4 3 5 8 2 여기에서 홀수 삭제하기
		vector<int>::iterator it = std::remove_if(v.begin(), v.end(), IsOdd());
		// 이거 돌리면 4 8 2 5 8 2 < 이렇게 된다
		// iterator가 5를 가리키고 있음. 그래서 뒷부분 삭제하라고 하는 거.
		v.erase(it, v.end());
		// 삭제해줘야 한다.
		// remove_if 사용할 때는 꼭 주의해야 한다.
	}
}