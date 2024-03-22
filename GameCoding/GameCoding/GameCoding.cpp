#include <iostream>
using namespace std;
#include <iomanip>

// 객체지향(Object Oriented Programming)
// 데이터 + 로직

// class는 설계도!
// 다중 상속은 막아둬서 안 된다. 설계상에 문제가 생김.

class Object
{
	// = 0을 붙이면 순수 가상함수가 된다. 단독 사용 불가능해짐.
	virtual void Shout() = 0;
};

class IFly
{
	// Fly는 is-a 관계나 has-a 관계가 아님.
	// Interface로 구현되는 클래스임. 순수 가상함수로 만든다.
	// IFly 상속 받는 클래스는 무조건 Fly()와 Land()를 구현해야 한다.
	virtual void Fly();
	virtual void Land();
};

class Player : public Object, public IFly
{
public:
	Player() {}
	~Player() {}
	
	// Interface 클래스를 받아왔으니 무조건 구현해야 함
	virtual void Fly() override { }
	virtual void Land() override { }

	// operator() 사용할 수 있음

	// 어떤 class의 Shout을 호출할지는 런타임에 결정되는 동적 바인딩, virtual 
	virtual void Shout() { }

	void Move() {}
	void SetHp(int hp) { this->hp = hp; }

private:
	int hp = 10;
};

void AddObject(Player* player)
{
	player->Shout();
}

void FlyTest(IFly* fly)
{

}

int main()
{
	Player p;
	FlyTest(&p); // IFly 대신 Player형 사용 가능, 상속받아 구현되어 있기 때문에
}