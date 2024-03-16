#include <iostream>
using namespace std;
#include <iomanip>

// 객체지향(Object Oriented Programming)
// 데이터 + 로직

// OOP 3대 요소
// - 상속성 << inheritance
//	 물려받는 것. 부모 클래스에서 물려받을 수 있는 것.
// - 은닉성
// - 다형성

// GameObject
// - Creature
// -- Player, Monster, Npc, Pet
// - projectile
// -- Arrow, Fireball
// - Env ...
// 이런식으로 유기적 클래스 디자인 설계 가능
// 상속 구조 미리 생각해 두면서 설계하는 게 좋다

// Item
// - Weapon
// -- Sword, Bow, Lance
// - Armor
// -- Helmet, Boots, Armor, Glove
// - Consumable
// -- Potion, Scroll

enum PLAYER_TYPE
{
	PT_KNIGHT = 1,
	PT_MAGE = 2,
	PT_ARCHER = 3,
};

class Player
{
public:
	void Move() {}
	void Attack() { }
	void Die() { }

public:
	int _hp;
	int _attack;
	int _defence;
};

//설계도
class Knight : public Player
{
public:

public:
	int _stamina;
};

class Archer : public Player
{
public:

public:
	int _arrowCount;
};

class Mage : public Player
{
public:

public:
	int _mp;
};

 