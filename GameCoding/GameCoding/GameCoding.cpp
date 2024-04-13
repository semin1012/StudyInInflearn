#include <iostream>
using namespace std;

// 캐스팅 4총사
// static_cast <<
// dynamic_cast <<
// const_cast
// reinterpret_cast

// 맨 위의 두 가지만 자주 쓰지만 면접에서는 다 잘 나온다. c++에서 굉장히 중요한 문제.

class Player
{
public:
	virtual ~Player();
};

class Knight : public Player
{

};

class Archer : public Player
{

};

class Dog
{

};

int main()
{
	// static_cast : 타입 원칙에 비춰볼 때 상식적인 캐스팅만 허용해 준다.
	// 1) int <-> float 변환, 정수와 부동소수점 사이의 변화는 당연히 가능하다.

	int hp = 100;
	int maxHp = 200;
	//float ratio = hp / maxHp;	// 이렇게만 하면 0.5가 나와야 하는데 정수를 정수로 나누어서 0이 나옴.
	float ratio = static_cast<float>(hp) / maxHp;	// float이랑 정수를 나누어야 실수가 결과로 나온다.

	Knight* k = new Knight();
	Player* p = k;				// 기사는 플레이어입니까? 당연히 Yes. 당연히 타입 변환을 해 준다.

	//Knight k2 = p;			// 플레이어는 기사입니까? 이건 고민해볼 문제. 안 해 준다. 
	//Knight* k2 = (Knight*)p;	// 상식적이지는 않지만 가능하다. 통과시켜 줌. c 스타일 문법이다.
	//Knight* k2 = static_cast<Knight*>(p);	// 얘도 통과시켜 줌. c++ 스타일 문법이다.
	// 만약 원본인 k가 Archer 였다면 난리 남. Archer가 Knight로 변화된 것.
	
	// dynamic_cast : 상속 관계에서의 안전한 변환을 보장한다.
	// 다형성을 활용하는 방식 (virtual)
	// RTTI (RunTime Type Information)
	// Player에 virtual 함수가 하나라도 있으면 가상 함수 테이블이 메모리에 같이 만들어진다.
	// 즉, 그래서 원본 데이터가 Knight 타입이 맞는지 확인 가능. 
	// 만약 이때 원본이 Archer 라면 0(nullptr)으로 밀어 준다. 타입이 맞을 때만 값을 넣어 준다.
	Knight* k2 = dynamic_cast<Knight*>(p);
	// nullptr이 아니라면
	if (k2 != nullptr)
	{
		// 기사가 맞다는 것 확신 가능. 이런 식으로 if 문이랑 같이 씀.
	}

	//const_cast : const와 관련된 cast를 할 수가 있다. 실상에서 진짜 안 씀. 
	const char* name = "Semin";
	char* name2 = const_cast<char*>(name);	// const를 잠시 뗄 수가 있다.

	// reinterpret_cast
	// 위험하고, 강력한 형태
	// re-interpret : 다시 생각하다?
	// 포인터 -> 전혀 관계없는 다른 포인터로 변환한다.
	Dog* dog = reinterpret_cast<Dog*>(k);	// 상식적인 캐스팅이 아니다.
	// malloc으로 메모리 할당하고 그걸 Dog*에 할당하고 싶은 경우나
	// 포인터 값을 잠시 정수로 들고 있고 싶을 때 사용할 수 있다.
	// 상속 관계도 전혀 없고, 관련이 전혀 없는 클래스 둘을 '사용 용도가 확실'할 때 쓸 수 있도록 한 캐스팅이다.
	// 얘도 물론 거의 안 쓴다.
}
 