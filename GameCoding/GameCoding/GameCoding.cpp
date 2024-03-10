#include <iostream>
using namespace std;

struct StatInfo
{
	int hp;
	int attack;
	int defence;
};

void Print(int* ptr, int count)
{
	// 이런식으로 ptr의 시작 주소와 배열의 크기만 알면
	// 배열의 모든 곳을 다 돌 수 있다.
}

int main()
{
	// 포인터 연산
	// - 주소 연산자(&)
	// - 산술 연산자 (+-)
	//	  -> 다음 주소로 넘어갈 때 사용
	// - 간접 연산자 (*)
	// - 간접 멤버 연산자 (->)

	int hp = 100;
	hp += 50;

	int* ptr = &hp;
	ptr += 1;
	// 데이터의 크기만큼 한 칸 뒤로 이동하게 된다
	// 주소가 바뀌는 것. 4바이트만큼 뒤로 갈 것.

	int numbers[100] = { 1,2,3,4,5,6 };

	int* ptr1 = &numbers[0];
	ptr1 += 1;

	cout << *ptr1 << endl;	// 2가 나옴

	StatInfo monster;
	monster.hp = 100;
	monster.attack = 10;
	monster.defence = 1;
	StatInfo* ptrMonster = &monster;

	cout << (*ptrMonster).hp << endl;	// 이렇게 사용 가능
	// (*ptrMonster).hp == ptrMonster->hp
	cout << ptrMonster->hp << endl;		// 위 코드와 같음
}