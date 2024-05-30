#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <unordered_map>
#include <algorithm>

class Pet
{
public:
};

class Knight
{
public:
	Knight()
	{

	}

	~Knight()
	{
		if (_pet)
		{
			delete _pet;
		}
	}

	// 복사 생성자, 컴파일러가 기본으로 처리해주던 부분
	Knight(const Knight& knight)
	{

	}

	// 복사 대입 연산자, 컴파일러가 기본으로 처리해주던 부분
	void operator=(const Knight& knight)
	{
		_hp = knight._hp;
		// _pet = knight._pet;
		// 문제가 있다. 복사될 때 별도의 펫을 만들어야 하는데
		// 동일한 원본 펫을 가르키게 된다. 

		if (knight._pet)
			_pet = new Pet(*knight._pet);
		// 이렇게 만들어야 새로운 펫을 가지게 된다. 
		// 문제는 해결되지만 복사 비용이 적지 않게 되었다.
		// 펫을 만들때 드는 비용이 크다면 복사할 때도 크게 된다. 
	}

	// 이동 생성자, 컴파일러가 기본으로 처리해주던 부분
	Knight(Knight&& knight)
	{
		_hp = knight._hp;
		_pet = knight._pet;
		knight._pet = nullptr;
		// 상대방에게서 소유권을 이전한 개념이다.
	}
	
	// 이동 대입 연산자, 컴파일러가 기본으로 처리해주던 부분
	void operator=(Knight&& knight)
	{
		_hp = knight._hp;
		_pet = knight._pet;
		knight._pet = nullptr;
		// 상대방에게서 소유권을 이전한 개념이다.
	}

	// 복사랑 이동이랑 별 차이가 없으면 상관이 없지만
	// 둘의 차이가 아주 큰 상황을 불러올 경우 아주 주의해야 한다.
	// 밑줄 없애고 싶은 ㄴ경우 noexcept 붙이면 된다. 사소한 부분이라 스킵


public:
	int _hp = 0;
	Pet* _pet = nullptr;
};

void TestKnight_Copy(Knight knight)
{
	// 이렇게 바꾸어도 원본에는 영향이 없다.
	knight._hp = 100;
}

// 원본을 넘겨줄 테니... 건드려도 된다는 뜻
void TestKnight_LValueRef(Knight& knight)
{
	knight._hp = 100;
}

// 원본을 넘겨줄 테니... 건들 순 없어
void TestKnight_ConstLValueRef(const Knight& knight)
{
	// &&가 참조의 참조라는 뜻이 아니라는 것 알아두면 된다.
	// &&는 오른값 참조라는 것이다. 
}

// 오른값 참조라는 새로운 것
// 원본 넘겨줄 테니... 더이상 활용하지 않을테니 맘대로 해라!
void TestKnight_RValueRef(Knight&& knight)
{

}

int main()
{
	// C++11: auto, lambda, rvalue-ref(오른쪽 참조)가 추가됨
	// rvalue-ref는 아예 없던 기능이 새로 추가된 것임
	// 아주 편리해졌고, C++11의 기능 중 1순위다

	// 왼값(l-value) vs 오른값(r-value)
	// l-value : 단일식을 넘어서 계속 지속되는 개체
	// r-value : l-value가 아닌 나머지

	int a = 3;
	// a는 l-value, 3은 r-value

	Knight k1;
	Knight k2;
	k1._pet = new Pet();
	// Knight k2 = k1 // 이거면 복사 생성자 

	k2 = k1; // 복사 대입 연산자

	
	TestKnight_Copy(k1); // 통째로 복사됨. 객체 크기가 크면 클수록 비효율적.
	TestKnight_LValueRef(k1); // 왼값 참조. 
	// TestKnight_LValueRef(Knight());	// 이러면 에러 나온다.
	// 비const 참조에 대한 초기값은 왼값이어야만 한다고 뜸.
	TestKnight_ConstLValueRef(Knight());
	// const 붙이니까 실행이 된다. 그렇지만 knight 수정 불가능.
	// 오른값은 const 붙여야 넘겨준다. 근데 안 바꿀 개체를 넘기는 행위 자체가 이상함.
	// 그래서 일단 오류를 내뱉는 방식으로 한번 경고를 준 것임.
	TestKnight_RValueRef(Knight());
	// k1을 더이상 활용하지 않아서 넘기고 싶다면? 이렇게 쓸 수 있다.
	TestKnight_RValueRef(static_cast<Knight&&>(k1));
	
	
	k2 = static_cast<Knight&&>(k1);	// 이동 대입 연산자
	// k1을 이제 쓸 일이 없어서 k2한테 주면 소유권이 완전히 이전된다.
	// k1은 이제 빈껍데기가 됨. 
	// k2 = std::move(k1) 이 문법이랑 완전히 동일한 기능이다. 

	
}