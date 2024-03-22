#include <iostream>
using namespace std;
#include <iomanip>

// 객체지향(Object Oriented Programming)
// 데이터 + 로직

class Player
{
public:
	Player()
	{
		cout << "Player() " << endl;
	}

	~Player()
	{
		cout << "~Player()" << endl;
	}
};

class Inventory
{
public:
	Inventory() : _a(0)
	{
		cout << "Inventory()" << endl;
	}

	Inventory(int a)
	{
		_a = a;
		cout << "Inventory(int)" << endl;
	}

	~Inventory()
	{
		cout << "~Inventory()" << endl;
	}

public:
	int _a;
};

class Knight : public Player
{
public:
	Knight() : _hp(0), _inventory(Inventory(100)), _hpRef(_hp), _hpConst(_hp)
		/*
			선처리 영역
			Player()
			_inventory = Inventory(100)
		*/
	{
		// 생성자에서 변수들 초기화하는 것이 좋다
		// _inventory = Inventory(100); // Inventory(), Inventory(int) 호출 두 번 됨
		// 그래서 위의 코드 말고 Knight() : _hp(0)처럼 옆으로 쓰면 한 번만 호출된다. 이게 깔끔하다.
		cout << "Knight()" << endl;
	}

	Knight(int hp) : _hp(hp)
	{
		cout << "Knight(int)" << endl;
	}

	~Knight()
	{
		cout << "~Knight()" << endl;
	}

public:
	int _hp;
	int _defence = 20;

	// 밑에 둘은 Knight() : 이 뒤에서만 초기화 가능하다
	// const는 처음 세팅값이 불변, 래퍼런스는 무언가를 가르키고 있어야 하기 때문
	int& _hpRef;
	const int _hpConst;

	Inventory _inventory;
};


int main()
{
	// C# Knight k1 = new Knight();

	// C++ Knight* k1 = new Knight();

	Knight k1;
	// 부모 자식의 호출 순서 주의!
	// Player() -> Knight() -> ~Knight() -> ~Player()


}