#include <iostream>
using namespace std;
#include <iomanip>

// 객체지향(Object Oriented Programming)
// 데이터 + 로직

class Knight
{
public:
	// 기본 생성자(constructor)
	// 생성자에 밑줄이 뜨는 이유: 멤버 변수 초기화하라고
	// 초기화하지 않으면 쓰레기값이 들어가게 됨, 예상 불가 
	Knight()
	{
		m_hp = 0;
		m_attack = 0;
		m_defence = 0;
		cout << "Knight()" << endl;
	}

	// 기타 생성자
	// 만약 기본 생성자 없이 기타 생성자만 존재하다면 컴파일러가 기본 생성자를 안 처리해줌
	// 꼭 인자를 넣는 방식의 기타 생성자로만 Knight를 생성할 수 있게 됨
	Knight(int hp, int attack, int defence)
	{
		m_hp = hp;
		m_attack = attack;
		this->m_defence = defence;
		// 인자와 멤버변수 이름이 같은 경우 this로 명시 가능
		cout << "Knight" << endl;
	}
	
	// 복사 생성자
	// 두개의 같은 타입 객체를 복사해서
	// 동일한 상태의 데이터를 갖는 다른 객체를 만든다
	Knight(const Knight& other)
	{
		m_hp = other.m_hp;
		m_attack = other.m_attack;
		m_defence = other.m_defence;
	}

	// 소멸자(destructor)
	~Knight()
	{
		cout << "~Knight()" << endl;
	}

	// 멤버 함수
	void Attack() { cout << "Attack " << endl; }
	void Die() { cout << "Die" << endl; }
	void HealMe(int value) 
	{
		m_hp += value;
	}

public:
	// 멤버 변수
	int m_hp;
	int m_attack;
	int m_defence;
};

int main() 
{
	// 객체 (instance)
	Knight k1(100, 10, 1);
	//Knight k1 = Knight(100, 10, 1);
	//Knight k1{ 100, 10, 1 };
	//Knight k1 = { 100, 10, 1 };
	//모두 같은 코드임, 문법만 다르다
	
	//복사 생성자 사용법은 밑에처럼 쓴다
	Knight k2(k1);
	k1.Attack();
}