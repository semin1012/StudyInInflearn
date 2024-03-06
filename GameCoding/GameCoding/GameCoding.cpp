#include <iostream>
using namespace std;

enum PlayerType
{
	PT_None = 0,
	PT_Knight = 1,
	PT_Archer = 2,
	PT_Mage = 3,
};

enum MonsterType
{
	MT_None = 0,
	MT_Slime = 1,
	MT_Orc = 2,
	MT_Skeleton = 3,
};

struct StatInfo
{
	int hp;
	int attack;
	int defence;
};

PlayerType playerType;
StatInfo playerStat;

MonsterType monsterType;
StatInfo monsterStat;

void EnterLobby();
void SelectPlay();
void EnterField();
void CreateRandomMonster();
void EnterBattle();
void WaitForNextKey();

int main()
{
	srand(time(0));
	EnterLobby();
}

void EnterLobby()
{
	while (true)
	{
		cout << "---------------------------------" << endl;
		cout << "      로비에 입장했습니다!" << endl;
		cout << "---------------------------------" << endl;

		// 플레이어 직업 선택
		SelectPlay();

		cout << "---------------------------------" << endl;
		cout << "(1) 필드 입장  (2) 게임 종료" << endl;
		cout << "---------------------------------" << endl;

		int input;
		cin >> input;

		if (input == 1)
		{
			EnterField();
		}
		else
		{
			return;
		}
	}
}

void SelectPlay()
{
	while (true)
	{
		cout << "---------------------------------" << endl;
		cout << "      직업을 선택해 주세요! " << endl;
		cout << "  (1) 기사  (2) 궁수  (3) 법사 " << endl;
		cout << "> " ;

		int choice;
		cin >> choice;

		playerType = (PlayerType)choice;

		if (choice == PT_Knight) 
		{
			cout << "기사 생성 중..." << endl;
			playerStat.hp = 150;
			playerStat.attack = 10;
			playerStat.defence = 5;
			playerType = PT_Knight;
			break;
		}
		else if (choice == PT_Archer)
		{
			cout << "궁수 생성 중... " << endl;
			playerStat.hp = 100;
			playerStat.attack = 15;
			playerStat.defence = 3;
			break;
		}
		else if (choice == PT_Mage)
		{
			cout << "법사 생성 중... " << endl;
			playerStat.hp = 80;
			playerStat.attack = 25;
			playerStat.defence = 0;
			break;
		}
	}

}

void EnterField()
{
	while (true)
	{
		cout << "---------------------------------" << endl;
		cout << "      필드에 입장했습니다! " << endl;
		cout << "---------------------------------" << endl;

		cout << "[PLAYER] HP: " << playerStat.hp << " / ATT: " << playerStat.attack << " / DEF: " << playerStat.defence << endl;

		//몬스터 스폰
		CreateRandomMonster();

		//전투
		cout << "---------------------------------" << endl;
		cout << "      (1) 전투  (2) 도주  " << endl;
		cout << "> ";

		int input;
		cin >> input;

		if (input == 1)
		{
			EnterBattle();

			if (playerStat.hp == 0)
				return;
		}
		else
		{
			break;
		}
	}
}

void CreateRandomMonster()
{
	int randomChoice = 1 + (rand() % 3);

	monsterType = (MonsterType)randomChoice;

	switch (randomChoice)
	{
	case MT_Slime:
		cout << "슬라임 생성 중...! (HP:30 / ATT:2 / DEF:0)" << endl;
		monsterStat.hp = 30;
		monsterStat.attack= 2;
		monsterStat.defence = 0;
		break;
	case MT_Orc:
		cout << "오크 생성 중...! (HP:40 / ATT:10 / DEF:3)" << endl;
		monsterStat.hp = 40;
		monsterStat.attack = 10;
		monsterStat.defence = 3;
		break;
	case MT_Skeleton:
		cout << "해골 생성 중...! (HP:80 / ATT:15 / DEF:5)" << endl;
		monsterStat.hp = 80;
		monsterStat.attack = 15;
		monsterStat.defence = 5;
		break;
	}
}

void EnterBattle()
{
	while (true)
	{
		int damage = playerStat.attack - monsterStat.defence;
		if (damage < 0)
			damage = 0;

		// 선빵
		monsterStat.hp -= damage;
		if (monsterStat.hp < 0)
			monsterStat.hp = 0;

		cout << "   몬스터 남은 체력: " << monsterStat.hp << endl;

		if (monsterStat.hp == 0)
		{
			cout << "   몬스터를 처치했습니다! " << endl;
			WaitForNextKey();
			return;
		}

		// 반격
		damage = monsterStat.attack - playerStat.defence;
		if (damage < 0)
			damage = 0;

		playerStat.hp -= damage;
		if (playerStat.hp < 0)
			playerStat.hp = 0;

		cout << "   플레이어 남은 체력: " << playerStat.hp << endl;

		if (playerStat.hp == 0)
		{
			cout << "당신은 사망했습니다... GAME OVER" << endl;
			WaitForNextKey();
			return;
		}
	}
}

void WaitForNextKey()
{
	cout << "계속하려면 1을 눌러 주세요 " << endl;
	cout << "> ";

	int input;
	cin >> input;

	//내용을 다 지워주는 함수
	system("cls");
}
