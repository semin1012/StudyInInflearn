#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>

// map이랑 set이랑 짝꿍이다.
// 키값만 있냐, 키와 밸류가 묶여 있냐 차이다.
// 보통 키와 밸류가 묶여 있기 때문에 map으로 먼저 공부한다. 

class Player
{
public:
	Player() { }
	Player(int id) : _id(id) {} 

public:
	int _id = 0;
};

// 만약 Player가 들고 있는 변수의 규모가 굉장히 커진다면,
// Q) vector에 모든 Player 정보를 담는 것이 합당한가? vector로 관리해도 되는가?
// -> 그래서 실제로는 참조로 들고 있는 것처럼 
//	  vector<Player*> 이렇게 동적할당으로 들고 있는 경우가 많을 것이다.
//	  이렇게 만들게 되면 성능은 좋아지는 대신 소멸까지 책임져야 한다. 

template<typename T, typename U>
struct Pair
{
	T first;
	U second;
};

template<typename T, typename U>
void MakePair(T first, U second)
{
	return std::pair<T, U>(first, second);
}

int main()
{
	vector<Player*> v;
	v.push_back(new Player(100));
	v.push_back(new Player(200));
	v.push_back(new Player(300));
	v.push_back(new Player(400));
	v.push_back(new Player(500));

	// vector로 관리하면 중간 삽입/삭제 같은 것에 한계가 있다. 
	// map으로 관리하면 균형도 잘 맞을 뿐더러 왼쪽으로 가면 작고, 오른쪽으로 가면 크다.
	// 업앤다운 놀이도 가능한 만능형 자료구조가 생긴 것이다. 
	
	// (key, value) 형식으로 저장 가능한 것이 map이다.
	map<int, Player*> m;
	
	// 추가
	// 찾기
	// 삭제
	// 순회

	// 추가?
	Pair<int, Player*> p;
	int key = p.first;
	Player* value = p.second;

	// 벡터로 있는 정보를 추가한다면
	for (Player* player : v)
	{
		int key = player->_id;
		Player* data = player;
		
		//m.insert(pair<int, Player*>(key, value));
		// 만약 위의 코드가 귀찮다면?

		MakePair(key, value); // = MakePair<int, Player*>(key, value);
		// auto랑 template은 비슷한 느낌이다.
		// auto, template은 컴파일러가 유추를 해줘서 형식 생략 가능하다. 
		// 이 코드를 공식에서도 지원을 한다.
		m.insert(make_pair(key, value));
		// make_pair가 공식에서 지원하는 함수.
	}

	for (Player* player : v)
	{
		// 결국 간단하게 추가하고 싶으면 이렇게 쓰면 됨. 
		// 위의 for문과 완전히 동일
		m.insert(make_pair(key, value));
		
		//m[player->_id] = player;
		// 위처럼 넣어도 되긴 하는데 덮어쓰는 문제랑 자동적 만들어지는 문제에 엮여있어서
		// 나중에 언급하기로 하고 첫 번째 방식만 언급하기로 한다. 
	}

	
	// 순회, vector는 순차적으로 찾는 형식이었음
	// map은 왼쪽으로 가냐, 오른쪽으로 가냐 이진탐색으로 효율적 탐색 가능.
	auto it = m.find(300);	// iterator를 뱉는다.
	
	// 사용법 1
	auto whoami = *it;
	whoami.first;
	whoami.second;
	
	// 사용법 2
	it = m.find(300);	// O(logN), 이진탐색과 동일하다. 
	if (it != m.end())
	{
		int key = it->first;
		Player* value = it->second;
	}
	else
	{
		cout << "없음" << endl;
	}



}
