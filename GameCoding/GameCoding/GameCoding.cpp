#include <iostream>
using namespace std;

const int SCISSORS = 0;
const int ROCK = 1;
const int PAPER = 2;

enum ENUM_GBB 
{
	GBB_SCISSORS = 0,
	GBB_ROCK = 1,
	GBB_PAPER = 2,
};

// 컴파일 단계에서 변수명을 모두 숫자로 바꿔버린다
// 오류가 쉽게 나기 때문에 권장하지는 않는다
#define DEF_SCISSORS 0
#define DEF_ROCK 1
#define DEF_PAPER

bool isTall;
bool isRich;

int choice;

int main()
{
	isRich = true;
	isTall = true;

	cout << (isRich && isTall) << endl;
	cout << !isRich << endl;

	// 분기문
	int hp = 100;
	hp -= 200;	// 데미지

	if ( hp <= 0 ) 
	{
		cout << "몬스터를 처치했습니다!" << endl;
	}
	else {
		cout << "생존" << endl;
	}

	choice = 1;
	if ( choice == 0 )
		cout << "가위를 냈습니다" << endl;
	else if ( choice == 1 ) 
		cout << "바위를 냈습니다" << endl;
	else if ( choice == 2 )
		cout << "보를 냈습니다" << endl;
	else
		cout << "숫자를 다시 입력하세요" << endl;

	// switch-case break
	switch(choice)
	{
		case 0:
			cout << "가위를 냈습니다" << endl;	
			break;
		case 1:
			cout << "바위를 냈습니다" << endl;	
			break;
		case 2:
			cout << "보를 냈습니다" << endl;	
			break;
		default:
			cout << "숫자를 다시 입력하세요" << endl;
			break;
	}

	// 반복문
	// while, for, do-while
	int count = 0;
	while ( count < 5)
	{
		// while문 위쪽에 continue를 쓰면 무한루프에 빠질 가능성
		cout << "Hello World" << endl;
		count++;

		if ( count == 3 ) 
			continue;
	}

	for (count = 0 ; count < 5; count++ ) {
		cout << "Hello World 22" << endl;

		if ( count == 50 ) 
			break;
	}


	// 별 찍기
	for ( int j = 0; j < 5; j++)
	{
		for ( int i = 0; i < 5; i++) 
		{
			cout << "*";
		}
		cout << endl;
	}

	// 구구단
	for ( int j = 2 ; j < 10; j++ ) 
	{
		for ( int i = 1 ; i < 10; i++ )
		{
			// cout << j << " * " << i << " = " << j * i << endl;
		}
	}

	// 간단한 전투
	int round = 1;
	hp = 100; // 몬스터 Hp 
	int damage = 25; // 플레이어 데미지

	while(true)
	{
		// 전투 진행
		hp -= damage;
		if (hp < 0)
			hp = 0;

		cout << "Round: " << round << ", 몬스터 체력: " << hp << endl;

		if ( hp == 0 ) 
		{
			cout << "몬스터 처치!" << endl;
			break;
		}

		if ( round == 5 ) 
		{
			cout << "제한 라운드 종료" << endl;
			break;
		}

		round++;
	}

	// 가위바위보
	srand(time(0)); // 시간에 따른 랜덤성 부여

	while(true)
	{
		cout << "가위(0), 바위(1), 보(2) 골라주세요! " << endl;
		cout << "> ";
		
		// 사용자
		int value;
		cin >> value;

		// 컴퓨터 
		int computerValue = rand() % 3;

		if (value == GBB_SCISSORS)
		{
			// switch의 case 값은 꼭!! const 상수여야 한다
			// 바뀌면 안 되기 때문에
			switch(computerValue)
			{
				case GBB_SCISSORS:
					cout << "가위(Player) vs 가위(Computer): 비겼습니다!" << endl;
					break;
				case GBB_ROCK:
					cout << "가위(Player) vs 바위(Computer): 졌습니다!" << endl;
					break;
				case GBB_PAPER:
					cout << "가위(Player) vs 보(Computer): 이겼습니다!" << endl;
					break;
			}
		}
		else if (value == GBB_ROCK) 
		{
			switch(computerValue)
			{
				case GBB_SCISSORS:
					cout << "바위(Player) vs 가위(Computer): 이겼습니다!" << endl;
					break;
				case GBB_ROCK:
					cout << "바위(Player) vs 바위(Computer): 비겼습니다!" << endl;
					break;
				case GBB_PAPER:
					cout << "바위(Player) vs 보(Computer): 졌습니다!" << endl;
					break;
			}
		}
		else 
		{
			switch(computerValue)
			{
				case GBB_SCISSORS:
					cout << "보(Player) vs 가위(Computer): 졌습니다!" << endl;
					break;
				case GBB_ROCK:
					cout << "보(Player) vs 바위(Computer): 이겼습니다!" << endl;
					break;
				case GBB_PAPER:
					cout << "보(Player) vs 보(Computer): 비겼습니다!" << endl;
					break;
			}
		}
	}
}
