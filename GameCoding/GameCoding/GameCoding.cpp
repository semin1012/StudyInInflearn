#include <iostream>
using namespace std;
#include <iomanip>

// 객체지향(Object Oriented Programming)
// 데이터 + 로직

// struct vs class
//  - 차이가 거의 없음
//	- struct는 public이 기본
//	- class는 private가 기본

struct Knight
{
	int hp;
};

class Knight2
{
	int hp;
};

int main()
{
	Knight k1;
	k1.hp = 10;

	// Knight2 k2;
	// k2.hp = 20;
	// 클래스는 hp가 기본적으로 private라서 안 됨
}