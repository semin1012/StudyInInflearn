#pragma once
#include "Enums.h"

// Item
// - Weapon
// - Armor
// - Consumable


class Item
{
protected:
	//Item(); // 기본 생성자, 이걸 막아두면 하위 클래스에서 Item 생성자를 따로 호출해 줘야 함
	Item(ItemType itemType);
	// 부모 클래스니까 꼭 virtual 만들기
	// 만약 안 붙인다면 무슨 일이 생기는가?
public:
	virtual ~Item();

public:
	// 가상함수. 
	virtual void PrintInfo();
	ItemType GetItemType() { return _itemType; }

protected:
	int _itemId = 0;
	int _itemCount = 0;
	ItemRarity _rarity = IR_Normal;
	ItemType _itemType = IT_None;
};

// 규모가 크지 않으니 따로 파일 안 만들고 밑에다가 이어서 씀
// ----------------------------------------------------------------------------
//				  	 			     Weapon
// ----------------------------------------------------------------------------

class Weapon : public Item
{
public:
	Weapon();
	virtual ~Weapon();

	virtual void PrintInfo() override;

	void SetDamage(int damage) { _damage = damage; }
	int GetDamage() { return _damage; }

private:
	int _damage = 0;
};


// ----------------------------------------------------------------------------
//				  	 			     Armor
// ----------------------------------------------------------------------------

class Armor : public Item
{
public:
	Armor();
	virtual ~Armor();

	virtual void PrintInfo() override;

	void SetDefence(int defence) { _defence = defence; }
	int GetDefence() { return _defence; }

private:
	int _defence = 0;
};