#pragma once

enum
{
	MAX_SLOT = 100
};

class Item;
// 나중에 Item 이 나올 것을 명시하는 코드

class Inventory
{
public:
	Inventory();
	~Inventory();

	bool AddItem(Item* item);
	bool RemoveItem(Item* item);

	Item* GetItemAtSlot(int slot);

	void Clear();
	
	static Inventory* GetInstance();

private:
	int FindEmptySlot();
	int FindItemSlot(Item* item);

private:
	Item* _items[MAX_SLOT];
	int _itemCount = 0;

	static Inventory* s_instance;
};

