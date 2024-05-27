#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <unordered_map>
#include <algorithm>

enum class ItemType
{
	None,
	Armor,
	Weapon, 
	Jewelry,
	Consumable
};

enum class Rarity
{
	Common,
	Rare,
	Unique
};

class Item
{
public:
	Item() { }
	Item(int itemId, Rarity rarity, ItemType type) : _itemId(itemId), _rarity(rarity), _type(type) { }

public:
	int _itemId = 0;
	Rarity _rarity = Rarity::Common;
	ItemType _type = ItemType::None;
};

//struct MakeResetHpJob
//{
//	void operator()()
//	{
//
//	}
//
//	int _hp = 200;
//}
// 위의 이 클래스 함수를 간단하게 람다로 표현 가능 

class Knight
{
public:
	auto MakeResetHpJob()
	{
		auto job = [=]()
			{
				_hp = 200;
			};

		return job;
	}

public:
	int _hp = 100;
};

int main()
{
	// lambda
	// 기능적으로 새로운 것은 아니지만 
	// 편리하게 작업할 수 있게 되었다. 서버를 다룰 때도 유용! 나중에도 많이 쓰게 될 것.

	vector<Item> v;
	v.push_back(Item(1, Rarity::Common, ItemType::Weapon));
	v.push_back(Item(2, Rarity::Common, ItemType::Armor));
	v.push_back(Item(3, Rarity::Rare, ItemType::Jewelry));
	v.push_back(Item(4, Rarity::Unique, ItemType::Weapon));

	{
		struct IsUniqueItem
		{
			bool operator()(Item& item)
			{
				return item._rarity == Rarity::Unique;
			}
		}; // 기존에는 이렇게 함수를 만들어서 사용했다.
		// 이제는 람다를 사용할 것!
		
		// 람다
		// [](){} < 이것부터 그려주고 시작한다.
		std::find_if(v.begin(), v.end(), [](Item& item) {return item._rarity == Rarity::Unique; });

		auto isUniqueLambda = [](Item& item) { return item._rarity == Rarity::Unique;  }; // 이렇게 받아서 사용해도 된다
		//std::find_if(v.begin(), v.end(), isUniqueLambda);
		// 일회성 함수를 만들 수 있어서 편리하다

		auto l = [](Item& item) -> int // boolean 타입을 int로 바꾸는 문법
		{ 
				return item._rarity == Rarity::Unique; 
		}; 

		
		{
			struct IsWantedItem
			{
				IsWantedItem(int& wantedId) : wantedId(wantedId) { } // 참조

				bool operator()(Item& item)
				{
					return item._itemId == wantedId;
				}

				int& wantedId;	// 참조
			};

			//IsWantedItem isWantedItem;
			//isWantedItem.wantedId = 2;	// 복사 방식

			int wantedId = 2;

			//std::find_if(v.begin(), v.end(), isWantedItem);
			// 이거 람다로 만들 수 있다.

			// 1. (람다에서도) = 복사 방식, 모든 애들을 다 복사 방식으로 넘긴다
			//	  (람다에서도) & 참조 방식, 모든 애들을 다 참조 방식으로 넘긴다
			IsWantedItem isWantedItem(wantedId);
			// 참조니까 원본이랑 같은 애를 가르키고 있다	

			[&](Item& item) // 이렇게 만들면 참조인 거임! 편리
			// 이때는 모든 애들이 참조(혹은 복사)됨
			{
				return item._itemId == wantedId;
			};

			[&wantedId](Item& item) // 이렇게 만들면 참조인 거임! 편리
			// 2. 이렇게 하면 wantedId만 참조(혹은 복사)를 넘김, 이걸 더 권장함
			//	  단일 변수마다 캡처 모드를 지정할 수 있다.
			{
				return item._itemId == wantedId;
			};
		}
	}

	// 람다가 위험한 상황은?
	// 주소값이 유효해야만 의미가 있는 건데 만약 주소가 날라갔다면? 문제 발생 소지 충분
	// 나중에 객체가 사라져서 피보는 경우 많다. 참조값 가지고 있을 때는 이런 경우 유의해야 한다.
	//[wantedId, wantedId1, wantedId2, , , ,] // 이런식으로 여러개 지정 가능하다. 이렇게 지정하는 게 더 안전할 것.
	

	Knight* k = new Knight();
	k->_hp = 100;

	auto job = k->MakeResetHpJob(); // hp를 200으로 초기화
	delete k;
	// MakeResetHpJob은 _hp를 참조해서 덮어씌우는 작업이라 
	// 문제가 있다. delete로 날라간 메모리를 건들이려고 한다. 
	// _hp 자체가 this->_hp라서 주소를 복사하는 게 참조값을 넘기는 것과 같게 된다.
	// 그래서 모든 것을 [=]로 복사한다고 해도 결국 참조값 넘기는 것과 같아질 수 있으니 주의할 것.
	job();

	[/*캡처모드*/](/*인자*/)
	{
		// 내용물
	};

	// std::find_if(v.begin(), v.end(), []() {});	// 이런 형태 자주 쓸 것
	// 처음에는 어렵지만 굉장히 편리하고 장점이 많다.	
}