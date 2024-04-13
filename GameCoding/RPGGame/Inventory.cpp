#include "Inventory.h"
#include "Item.h"
// cpp에 인클루드하는 것이 중요하다. 
// header에 인클루드를 하면 다른 곳에서 Inventory.h를 인클루드하는 경우 Item.h까지 모두 컴파일하게 되어서 무거워짐.
// Inventroy.h 와 Item.h 등 헤더끼리 얽히는 경우 사이클이 반복되어서 오류가 크게 생길 수 있다.

Inventory* Inventory::s_instance = nullptr;

Inventory::Inventory()
{
	for (int i = 0; i < MAX_SLOT; i++)
		_items[i] = nullptr;
}

Inventory::~Inventory()
{
}

bool Inventory::AddItem(Item* item)
{
	if (item == nullptr)
		return false;

	int emptySlot = FindEmptySlot();
	// 자리가 없으면 return으로 실패했다고 넘기기
	if (emptySlot < 0)
		return false;

	_items[emptySlot] = item;
	_itemCount++;
	return true;
}

bool Inventory::RemoveItem(Item* item)
{
	if (item == nullptr)
		return false;

	int slot = FindItemSlot(item);
	if (slot < 0)
		return false;

	_items[slot] = nullptr;
	_itemCount--;

	// delete item ?

	return true;
}

Item* Inventory::GetItemAtSlot(int slot)
{
	if (slot < 0 || slot >= MAX_SLOT)
		return nullptr;

	return _items[slot];
}

void Inventory::Clear()
{
	for (int i = 0; i < MAX_SLOT; i++)
	{
		if (_items[i])
		{
			delete _items[i];
			_items[i] = nullptr;
		}
	}
}

Inventory* Inventory::GetInstance()
{
	if (s_instance == nullptr)
		s_instance = new Inventory();

	return s_instance;
}

int Inventory::FindEmptySlot()
{
	for (int i = 0; i < MAX_SLOT; i++) 
	{
		if (_items[i] == nullptr)
			return i;
	}

	return -1;
}

int Inventory::FindItemSlot(Item* item)
{
	for (int i = 0; i < MAX_SLOT; i++)
	{
		if (_items[i] == item)
			return i;
	}
	return -1;
}
