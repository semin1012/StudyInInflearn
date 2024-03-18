#include <iostream>
using namespace std;
#include <iomanip>

// 객체지향(Object Oriented Programming)
// 데이터 + 로직

// OOP 3대 요소
// - 상속성 << inheritance
//	 물려받는 것. 부모 클래스에서 물려받을 수 있는 것.
// - 은닉성 << data hiding (캡슐화 encapsulation)
// - 다형성 << polymorphism (poly + morphism)
// 		-> 오버라이딩

// 오버로딩(overloading) = 함수 이름의 재사용, 타입이 다르거나 인자의 개수가 다르거나 할 때 동일한 이름 재사용 가능
// 오버라이딩(overriding) = 부모 클래스의 함수를 자식 클래스 내에서 재정의하는 것이다

// 접근 지정자
// public, protected, private

class Player
{
public:
	// 가상 함수 virtual, 이거 붙이면 동적 바인딩 돼서 MovePlayer(&k1)을 해도 Knight Move() 뜸
	//virtual void Move() { cout << "Player Move()" << endl;}
	
	// 모든 자식 클래스에서 구현을 해야 하는 거라면 순수 가상함수로 밑에처럼 만들어야 한다.
	// 이렇게 만들면 Player p1을 만들 수가 없다. 정의되어 있지 않은 함수가 있기 때문에. 
	virtual void Move() = 0; // = virtual void Move() obstract;

public:
	int _hp = 100;
};

class Knight : public Player
{
public:
	// 부모에도 붙였으면 자식한테도 붙이는 게 좋다
	virtual void Move() override {cout << "Knight Move()" << endl;}

public:
	int _stamina = 200;
};

// 바인딩(binding) = 묶는다
// - 정적 바인딩 (Static binding) = 컴파일 시점에 결정
// - 동적 바인딩 (Dynamic binding) = 실행 시점에 결정

// 가상 함수를 사용하면 클래스 공간 내에 가상함수 테이블이 생긴다.
// vftable (virtual function table)
// ex) .vftable [ 주소1 | 주소2 | 주소3 ]
// 주소를 찾아가서 실행할 수 있도록 결국 주소값을 넣어 주는 것이다. 주소값이 저장된 테이블.
// 주소를 타고 가야 하니까 속도가 조금 느리긴 하지만 실제적으로 어떤 타입으로 만들어졌는지에 따라 어떤 함수를 호출하게 되는지가 완전히 달라지게 된다.
// virtual 가상함수를 사용하면 소멸자에도 virtual을 붙여줘야 한다. 덜 지워질 가능성이 있기 때문에.
// override를 자식 키워드에 붙이는 건 부모에 정의된 함수를 자식에서 재정의한다는 뜻이다. override를 자식에서 썼는데 부모에 virtual이 안 붙어있으면 오류가 난다. 실수를 방지하는 효과.
	// 자식 - virtual override 붙여아 하고 부모 - virtual 붙여서 써야 한다

void MovePlayer(Player* player) // 정적 바인딩
{
	player->Move();
}

int main()
{
	// Player p1; // Move()가 순수가상함수라서 Player는 만들어지지 않음
	Knight k1;
	k1.Move();		 // Knight Move()
	MovePlayer(&k1); // Player Move()
}
 