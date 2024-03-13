#include <iostream>
using namespace std;
#include <iomanip>

// 객체지향(Object Oriented Programming)
// 데이터 + 로직

// OOP 3대 요소
// - 상속성 << inheritance
//	 물려받는 것. 부모 클래스에서 물려받을 수 있는 것.
// - 은닉성
// - 다형성

class Player
{
public:
	void Move() {}
	void Attack() { }
	void Die() { }

public:
	int _hp;
	int _attack;
	int _defence;
};

//설계도
class Knight : public Player
{
public:

public:
};

class Archer : public Player
{
public:

public:
	int _arrowCount;
};

class Mage : public Player
{
public:

public:
	int _mp;
};

int main()
{
	Knight k1;
	k1._hp;
	Mage m1;
	m1._hp;
}