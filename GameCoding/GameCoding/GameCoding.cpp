#include <iostream>
using namespace std;
#include <iomanip>

// MMO 동접 1만, 몬스터 50만

// - 스택
// - 메모리
// 두 가지로는 방대한 MMO RPG 데이터를 감당하기 힘들다
// 스택은 공간 자체가 좁아서 백만마리 몬스터 생성부터 불가능
// 데이터(전역)은 만들 수는 있지만 공간 해제할 수가 없음

class Monster
{
public:
	Monster() { cout << "Monster()" << endl; }
	~Monster() { cout << "~Monster()" << endl; }

public:
	int _hp = 0;
};

class Player
{
public:
	Monster* _target;
};

// 스택은 불안정한 공간이지만 힙은 안정적인 공간이다
// 다만 힙은 직접적으로 관리해야 한다는 단점이 있다

int main()
{
	// malloc + free 세트
	// new + delete 세트
	// 위 둘의 차이는 연산자 차이다. 생성자, 소멸자의 호출에 차이가 있음.
	//  - malloc은 생성자, 소멸자가 전혀 안 뜸. 

	
	// malloc 사용법, 생성자 호출 X, 공간을 지정해야 하는 불편함
	/*void* ptr = malloc(1000); // heap 영역에 할당해 달라고 하는 것
	
	Monster* m = (Monster*)ptr;
	m->_hp = 100;
	
	free(ptr);*/ // 해제를 수기로 해야 함, 안 하면 메모리 누수


	// new 사용법, 생성자 호출됨
	// 연달아 있는 배열로 호출 가능, 지울 때도 delete[] 해야 함
	Monster* m1 = new Monster();
	//Monster* m1 = new Monster[5]();
	m1->_hp = 100;

	delete m1;

	// 이거 의외로 크래시 안 남
	m1->_hp = 200;
	// 매번 요청하는 대로 생성,삭제하면 너무 느림
	// 그래서 일단 날리지는 않고 들고 있는다
	// 잡을 수 없는 문제가 되면 더욱 큰일이 될 수 있음

	m1 = nullptr;
	// = 0이라고 명시해도 됨
	// 이렇게 바뀌면 사용하려고 할 때 크래쉬가 난다.

	Player* player = new Player();
	player->_target = m1;

	delete m1;
	m1 = nullptr;
	// 이렇게 해도 player->_taget은 사라지지 않음. 크래쉬 가능성 큼.
}