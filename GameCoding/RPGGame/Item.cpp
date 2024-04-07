#include "Item.h"
#include <iostream>
using namespace std;
// *******************************************
//				     Item
// *******************************************

Item::Item()
{
	int randValue = rand() % 100;

	if (randValue < 50)
	{
		_rarity = IR_Normal;
	}
	else if (randValue < 80)
	{
		_rarity = IR_Rare;
	}
	else
	{
		_rarity = IR_Unique;
	}
}

Item::~Item()
{
}

void Item::PrintInfo()
{
	switch (_rarity)
	{
	case IR_Normal:
		cout << "[희귀도] 일반" << endl;
	case IR_Rare:
		cout << "[희귀도] 레어" << endl;
	case IR_Unique:
		cout << "[희귀도] 유니크" << endl;
	}
}

// *******************************************
//				   Weapon
// *******************************************

Weapon::Weapon()
{
}

Weapon::~Weapon()
{
}

void Weapon::PrintInfo()
{
	cout << " ------------------------- " << endl;
	cout << "[아이템 타입]: 무기" << endl;
	cout << "[공격력]: " << _damage << endl;
	Item::PrintInfo();
	cout << " ------------------------- " << endl;
}

// *******************************************
//				    Armor
// *******************************************

Armor::Armor()
{
}

Armor::~Armor()
{
}

void Armor::PrintInfo()
{
	cout << " ------------------------- " << endl;
	cout << "[아이템 타입]: 방어구" << endl;
	cout << "[방어력]: " << _defence << endl;
	Item::PrintInfo();
	cout << " ------------------------- " << endl;
}
