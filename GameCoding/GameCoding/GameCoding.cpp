#include <iostream>
using namespace std;

// 얕은 복사 vs 깊은 복사
class Pet
{
public:
	Pet() { cout << "Pet()" << endl; }
	~Pet() { cout << "~Pet()" << endl; }

	Pet(const Pet& pet) { cout << "Pet(const Pet&)" << endl; }
};

class Knight
{
public:
	Knight()
	{
		_pet = new Pet();
	}

	~Knight()
	{
		delete _pet;
	}

	Knight(const Knight& k)	// 복사 생성자
	{
		_hp = k._hp;
		_pet = new Pet(*(k._pet)); // k.pet 의 주소에 이동해서 참조 값으로 넘어갈 수 있게 된다.
	}

	void operator=(const Knight& k) // 복사 연산자
	{
		_hp = k._hp;
	}

public:
	int _hp = 100;
	Pet* _pet;
};

int main()
{
	Knight k1;
	k1._hp = 200;

	Knight k2 = k1;	// 복사 생성자, 얕은 복사가 된다.
	// 값을 하나하나 일일이 똑같이 넣어 주는 게 얕은 복사다.
	// 같은 주소를 가르키고 있는데 이중으로 delete를 할 수 있어서 프로그램이 뻗어버릴 수 있다.

	// 깊은 복사란 포인터를 타고 간 메모리에 있는 정보를 또 다른 메모리에 복사하는 것이다.
	// 같은 메모리를 가르키는 게 아니라, 다른 메모리를 가르키는데 내용은 똑같이 복사하는 것.
	
	//Knight k3;		// 기본 생성자
	//k3 = k1;		// 복사 연산자
}
 