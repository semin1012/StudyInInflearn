#include <iostream>
using namespace std;

class Player
{
public:
	Player()
	{
		cout << "Player()" << endl;
	}

	virtual ~Player()
	{
		cout << "~Player()" << endl;
	}
};

class Pet
{

};

class Archer : public Player
{
public:
	Archer()
	{
		_pet = new Pet();
		cout << "Archer()" << endl;
	}

	virtual ~Archer()
	{
		cout << "~Archer()" << endl;
		delete _pet;
	}

private:
	Pet* _pet;
};

int main()
{
	while (true)
	{
		Player* player = new Archer();
		delete player;

	}


	// 1. Archer* player = new Archer(); 로 만들 경우에는 
	//		Player() -> Archer() -> ~Archer() -> ~Player()
	//		= 정상적이다.

	// 2. Player* player = new Archer(); 로 만들 경우에는
	//		Player() -> Archer() -> ~Player() 
	//		= ~Archer()에서 중요한 작업을 할 때에는 문제가 생길 수 있다. 
	//		이 코드에서는 Pet을 소멸시키고 있음. 중요함. 메모리가 자꾸 올라간다. 
	//		따라서 소멸자에 virtual을 붙여야만 메모리가 제대로 관리된다. 
}
 