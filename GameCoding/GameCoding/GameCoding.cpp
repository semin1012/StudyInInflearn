#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <queue>
#include <map>

class ItemInfo
{
public:
	
};

class Iterator
{
public:
	Iterator() : _data(nullptr) {}
	Iterator(int* data) : _data(data) {}

	bool operator==(const Iterator& other)
	{
		return _data == other._data;
	}
	
	bool operator!=(const Iterator& other)
	{
		return _data != other._data;
	}

	void operator++()
	{
		_data++;
	}

	int operator*()
	{
		return *_data;
	}

public:
	int* _data;
};

class Inventory
{
public:
	using iterator = Iterator;

	Inventory() {}
	~Inventory() {}

	iterator begin() { return iterator(&_items[0]); }
	iterator end() { return iterator(&_items[10]); }
	
public:
	int _items[10] = { 1,2,3,4,5,6,7,8,9,10 };
};
int main()
{
	// ranged-based for(범위 기반 for문)

	vector<int> v{ 1,2,3,4,5 };

	for (int i = 0; i < v.size(); i++)
	{
		v[i] = 100;
		cout << v[i] << endl;
	}

	for (auto it = v.begin(); it != v.end(); it++)
	{
		*it = 100;
		cout << *it << endl;
	}

	// C# foreach 와 비슷함
	for (int& data : v)
		// 참조를 하고 싶으면 &를 붙이면 된다. 
	{
		data = 100;
		cout << data << endl;
	}

	// 위의 세 개가 같은 순회인데 세 번째 방식이 가독성 좋다.
	// 무조건 좋다고 볼 수밖에 없다. 성능 어쩌고 하는 사람도 있으나 루키스님은 3이 무조건 좋다고 생각.


	vector<ItemInfo> items;
	for (ItemInfo& data : items)
	{
		// items가 굉장히 큰 상황이라면 &를 안 붙이면 공간 복사가 일어나기 때문에
		// 메모리 낭비가 너무나 심각해질 수 있음
		// 그래서 &를 붙이는 게 좋고,
		// ItemInfo& 대신 auto&를 쓰는 것도 좋음.
	}

	Inventory inventory;
	// iterator 구현하면 이것도 쓸 수 있다. 
	for (const auto& item : inventory)
	{
		static int i = 0;
		cout << "item[" << i << "]: " << item << endl;
		i++;
	}
}