#include <iostream>
using namespace std;

// NULL 크래시
// 프로그램이 뻗었다 하면 95 퍼센트 NULL 크래시다.
// 정수 오버플로우(언더플로우)

class Player
{
public:
	int hp = 0;
};

Player* FindPlayer(int id)
{
	// TODO

	// 못 찾았으면 nullptr 리턴
	return nullptr;
}

void Test(Player* p)
{
	if (p == nullptr)
		return;

	p->hp = 10;
}

int main()
{
	Player* p = FindPlayer(100);

	//p->hp = 100;	// p 에 0x0000000000000000 같은 값이 들어있으면 당연히 NULL 크래시라고 보면 된다. nullptr이 들어있음.
	Test(nullptr);	// 함수 내에 null 체크가 되어 있으므로 뻗지 않음.
}
 