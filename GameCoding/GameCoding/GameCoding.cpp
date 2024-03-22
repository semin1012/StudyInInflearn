#include <iostream>
using namespace std;
#include <iomanip>

// 객체지향(Object Oriented Programming)
// 데이터 + 로직

// 연산자 오버로딩
// - 멤버 연산자 함수 버전
//	 a op b 형태에서 왼쪽을 기준으로 실행된다.
// - 전역 연산자 함수 버전
//	 a op b 형태라면, a/b 모두를 연산자 함수의 피연산자로 사용한다.

class Pos
{
public:
	Pos() { }

	// 간접적으로 변환되어 넘어오는 것을 예방하는 것이다
	// ex) TestPos(10)이 가능하게 되는 것을 예방하는 것
	explicit Pos(int b) 
	{
		x = b;
		y = b;
	}

	// 멤버 연산자 함수 버전
	Pos operator+ (const Pos& b)
	{
		Pos pos;
		pos.x = x + b.x;
		pos.y = y + b.y;
		return pos;
	}

	Pos operator+(int b)
	{
		Pos pos;
		pos.x = x + b;
		pos.y = y + b;
		return pos;
	}

	Pos(int a, int b)
	{
		x = a;
		y = b;
	}

	bool operator==(const Pos& b)
	{
		return x == b.x && y == b.y;
	}

	// 대입 연산자
	void operator=(int b)
	{
		x = b;
		y = b;
	}

	//Pos& operator=(int b)
	//{
	//	x = b;
	//	y = b;
	//	return *this;
	//}
	// 이걸 쓰면 pos1 = pos2 = pos3; 같은 코드를 사용 가능

	int x = 0;
	int y = 0;
};

Pos operator+(int a, const Pos& b)
{
	Pos pos;
	pos.x = a + b.x;
	pos.y = a + b.y;
	return pos;
}

void TestPos(Pos a)	// TestPos(10) 이라고 해도 됨
{
	// TestPos(10)이 되는 이유는?
	// Pos = 10 이 만들어질 수 있는 대입 연산자가 존재하기 때문에
	// TestPos(10)도 만들어질 수가 있다는 포인트 
}

int main()
{
	int a = 10;
	int b = 20;
	int c = a + b;

	Pos pos1 = Pos(10, 20);
	Pos pos2 = Pos(40, 20);

	Pos pos3 = pos1 + pos2;

	Pos pos4 = 10 + pos2;

	// 밑에 두 방법 모두 생성자(int)가 불린다
	Pos pos5(10);
	Pos pos6 = 10;

	// 대입, 생성이 된 이후에 호출되는 게 대입
	pos5 = 10;
	pos6 = 20;

	cout << pos3.x << " " << pos3.y << endl;
}