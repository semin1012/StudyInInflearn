#include <iostream>
using namespace std;
#include <iomanip>

// 객체지향(Object Oriented Programming)
// 데이터 + 로직

// stati : 특정 객체에 종속적인지
//	 - 클래스로 만들어낸 모든 객체의 값이 공통되게 된다.
//	 - 메모리 낭비가 되지 않도록 함.

// 자료구조&알고리즘
// 디자인 패턴
//  - 싱글톤, 옵저버, 콤포넌트, ...

// 싱글톤 - 정말 딱 1개만 존재하고 어디서든 사용할 수 있는 [매니저] 클래스

class UserManager
{
public:
	static UserManager* GetInstance()
	{
		// um은 static이라 다른 메모리에 만들어지게 됨, 사라지지 않음
		static UserManager um;
		return &um;
	}

public:
	void AddUser() { _userCount++; }
	int GetUserCount() { return _userCount; }

private:
	int _userCount = 0;
};

class Player
{
public:
	Player()
	{
		id = s_idGenerator++;
	}

public:
	int id;
	// 처음 만들 때 초기화해 줘야 되겠지만 이렇게 id를 만들면 편해서 이렇게 잘 쓴다
	static int s_idGenerator;
};

int Player::s_idGenerator = 1;

int GenerateId()
{
	static int s_id = 10; // 안 사라짐
	return s_id++;
}

#define GET_MANAGER (UserManager::GetInstance())

int main()
{
	for (int i = 0; i < 10; i++)
		GET_MANAGER->AddUser(); // = UserManager::GetInstance()->AddUser();

	cout << GET_MANAGER->GetUserCount() << endl;
}