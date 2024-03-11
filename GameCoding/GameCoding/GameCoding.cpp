#include <iostream>
using namespace std;

struct StatInfo
{
	int hp;
	int attack;
	int defence;
};

// 1) 값(복사) 전달 방식
//StatInfo의 크기가 커질수록 메모리 부담이 커진다.
void PrintByCopy(StatInfo player)
{
	cout << "-----------------------------" << endl;
	cout << "H P: " << player.hp << endl;
	cout << "ATT: " << player.attack << endl;
	cout << "DEF: " << player.defence << endl;
	cout << "-----------------------------" << endl;

}

// 2) 주소 전달 방식
void PrintByPointer(StatInfo* player)
{
	cout << "-----------------------------" << endl;
	cout << "H P: " << player->hp << endl;
	cout << "ATT: " << player->attack << endl;
	cout << "DEF: " << player->defence << endl;
	cout << "-----------------------------" << endl;

}

#define OUT
// OUT을 사용해서 참조된 player가 변할 것을 명시해 둠
// 참조를 쓸 때 값 변경이 없다면 StatInfo& 앞에 const를 붙임
// #define PI 3.141592 라고 하면 컴파일 단계에서 PI가 숫자로 치환되는데
// 현재 OUT 뒤에는 아무것도 없으니 컴파일 단계에서 그냥 사라지는 코드가 됨
void PrintByRef(OUT StatInfo& player)
{
	cout << "-----------------------------" << endl;
	cout << "H P: " << player.hp << endl;
	cout << "ATT: " << player.attack << endl;
	cout << "DEF: " << player.defence << endl;
	cout << "-----------------------------" << endl;
	player.hp = 110;
}



int main()
{
	StatInfo player = { 100, 10, 1 };
	
	PrintByCopy(player);
	
	//POINTER
	// 1) 원본을 건드리고 싶을 때 (원격)
	// 2) 복사 비용 X
	// 3) nullptr을 사용 가능함, 없는 것을 찾을 수 있다
	//	  다만 null 처리를 안 해서 크래쉬가 날 가능성 有
	StatInfo* ptr = nullptr;
	PrintByPointer(&player);
	
	//REFERENCE
	// 내부 원리는 포인터와 같지만 사용방식은 아무것도 안 붙은
	// 기본 자료형처럼 사용하면 된다. -> 이거 안 씀. & 이거 안 씀.
	// 1) 원본을 건드리고 싶을 때 원격으로 사용 가능
	// 2) 복사 비용 X, 참조하는 거니까
	// 다만 ptr는 nullptr을 표현할 수 있다.
	// 닉네임을 찾을 때 해당하는 값이 없어도 null 값으로 리턴할 수 없다.
	// 참조할 때는 값을 안 바꾸기 위함을 강조하려고 참조 앞에 const를 붙여서 나타내기도 한다.
	// - void PrintByRef(const StatInfo& player)처럼!
	PrintByRef(OUT player); // OUT, player를 고친다는 뜻
}