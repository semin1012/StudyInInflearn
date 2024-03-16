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

// 접근 지정자
// public, protected, private

class Car
{
public:
	void MoveHandle() {}
	void PushPedal() {}
	void OpenDoor() {}
	void TurnKey()
	{
		// ......
		// 
	}

private:
	void PutFuellnEngine() {}
	void ConnectCircuit() {}

protected:
	void Disassemble() {}

public:
};

class SuperCar : Car
{
public:
	void Test() 
	{
		MoveHandle();
		Disassemble();
	}
};

class Knight
{
public:
	void SetHp(int hp)
	{
		_hp = hp;
	}

	int GetHp()
	{
		return _hp;
	}

private:
	int _hp = 100;
};

int main()
{
	Car c;	

	Knight k1;
	k1.SetHp(200);
	// k1._hp = 200처럼 직접 고치는 코드는 아주 안 좋다. 
}
 