#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <unordered_map>
#include <algorithm>

// 면접에서 맨날 스마트 포인터 얘기한다 중요함

class Knight;

class ObjectManager
{
	Knight* GetObject(int id)
	{
		return nullptr;	// id로 무언가를 뱉어내게 만드는 게 best
	}
};

class Knight
{
public:
	~Knight() {}

	void Attack()
	{
		/*if (_target)
			_target->_hp = _damage;*/

		if (_target.expired() == false )
		{
			shared_ptr<Knight> spr = _target.lock();
		}
	}

public:
	int _hp = 100;
	int _damage = 10;

	//shared_ptr<Knight> _target = nullptr;
	int _targetId = 0;
	weak_ptr<Knight> _target;
};

template<typename T>
class Wrapper
{
public:
	Wrapper(T* ptr) : _ptr(ptr) { }
	~Wrapper()
	{
		if (_ptr)	// 포인터가 null 이 아니라면 삭제시킨다
			delete _ptr;
	}

public:
	T* _ptr;
};


class RefCountBlock
{
public:
	int _refCount = 1;
};


template<typename T>
class SharedPtr
{
public:
	SharedPtr() { }
	SharedPtr(T* ptr) : _ptr(ptr) 
	{
		if (ptr)
		{
			_block = new RefCountBlock();
			cout << "RefCountBlock: " << _block << endl;
		}
	} 

	SharedPtr(const SharedPtr& other) : _ptr(other._ptr), _block(other._block)
	{
		if (_ptr)
		{
			_block->_refCount++;
		}
	}

	~SharedPtr()
	{
		if (_ptr) 
		{
			_block->_refCount--;

			if (_block->_refCount == 0)
			{
				delete _ptr;
				delete _block;
				cout << "Delete data" << endl;
			}
		}
	}

	void operator=(const SharedPtr& other)
	{
		_ptr = other._ptr;
		_block = other._block;

		if ( _ptr ) 
			_block->_refCount++;
	}

public:
	T* _ptr = nullptr;	// 포인터 관리.
	//int _refCount		// 몇개나, 얼마나 사용하고 있는지 카운트를 센다
	RefCountBlock* _block;	// refCount 대신 동적할당으로 관리하는 게 일반적이다. 참조횟수 관리.

};

void Test(shared_ptr<Knight>& k)
{
	// 이런식으로 k를 부르면 불릴 때 +1, 소멸될때 -1의 부담이 생기게 된다.
	// 이런 부담을 주기 싫다면 shared_ptr<Knight>& 처럼 레퍼런스를 붙이면 
	// +1, -1의 부담이 안 들게 된다. 
	// 이처럼 &를 붙이면 스마트포인터를 쓰는 이유가 완전히 사라지는 것이기도 하기 때문에
	// 보통 shared_ptr<Knight>와 같이 쓸 때는 절대 레퍼런스 쓰지 않아야 한다.
}

int main()
{
	{
		//Knight* knight = new Knight();
		// delete를 안 하면 언젠가 메모리 릭으로 프로그램이 죽는다
		// 정책에 따라 자동으로 관리하는 무언가를 넣어주는 게 스마트 포인터의 개념이다

		//Wrapper<Knight> w(knight);
	}	// 스택 영역을 벗어나면 소멸자가 호출될 것이고, 포인터를 알아서 딜리트해주게 될 것이다.
		// Wrapper class는 스마트 포인터는 아니지만 delete를 자동으로 해 주는 역할

	// * 밑의 세 가지가 스마트 포인터고 다 알아둬야 한다.
	// shared_ptr	<< 99프로. 가장 비중이 높다.
	// weak_ptr
	// unique_ptr

	{	// 생포인터 사용
		/*Knight* k1 = new Knight();
		Knight* k2 = new Knight();

		k1->_target = k2;
		delete k2;
		k1->Attack();*/		// Knight 안에 SharedPtr를 넣게 되어서 포인터는 못 쓰게 됨
		// 이런 경우 Attack을 할 때 k2가 없어져 있으니 오류가 생기지 않을까?
		// 프로그램이 돌아가긴 하는데 _target에 접근하면 안 되는데 접근하는 메모리 오염이 생긴다
		// 죽은 뒤에 _target을 어떻게 처리하는가?
		// 포인터는 어쩔 수가 없다. 차라리 int targetId를 들고 있는 게 낫다.
		// 그래서 생포인터는 안 쓰는 게 좋다. 생명주기가 꼬인다. 스마트포인터를 써야 한다. 
	}

	{ // shared_ptr 사용
		/* shared_ptr */
		SharedPtr<Knight> k1(new Knight());
		//SharedPtr<Knight> k2(new Knight());

		SharedPtr<Knight> k3;
		k3 = k1;	// k3와 k1은 동일한 나이트 객체를 가르킨다. 이럴 때 refCount를 늘려줌.
		// SharedPtr이 복사된다. 
		// Knight* k1 = new Knight();
		// Knight* k3;
		// k3 = k1;
		// 이것과 완전한 동일한 의미다. 포인터를 복사하는 것임. 
		// 같은 객체를 가르키고 있는 상태가 된다. 얕은 복사다.
	}

	{
		/* shared_ptr */
		shared_ptr<Knight> k1(new Knight());
		shared_ptr<Knight> k2(new Knight());
		//k1->_target = k2;
		// shared_ptr로 관리하면 k2가 사라질지언정
		// k1->_target는 기억하고 있으니 소멸되지 않는다는 게 보장된다.
		// 머언 훗날 아무도 사용하지 않을때 알아서 소멸되게 된다. 
		// 한 명이라도 기억하고 있을 때는 사라지지 않는다.

		//k2->_target = k1;
		// 만약 k1과 k2 서로 _target으로 서로를 바라보고 있다면?
		// 서로 refCount가 2가 되어서 어느쪽이 사라져도 refCount가 0이 되는 상황이 오지 않음.
		// 이러면 영영 소멸이 되지 않는다. 메모리 릭 발생.
		// 조심해서 사용하는 방법밖에 없다...

		//k1->_target = nullptr;
		//k2->_target = k1; 
		// 이런 식으로 사이클 발생하지 않도록 해줘야 한다. 
	}


	{
		/* weak_ptr */
		// 약한 포인터다. 생명 주기에 영향을 줘서 refCount를 자체를 늘리지는 못 한다.
		// 생명에는 영향을 주지 않는다. 생포인터랑 다른 게 뭐냐??
		// _target.expired() << 존재하는지 확인해서 날라가지 않았으면 
		// shared_ptr<Knight> spr = _target.lock();	// .lock() << null이 아니면 유효한 것 넘어옴
		// 이렇게 해서 사이클 끊어줄 수 있다.
		shared_ptr<Knight> k1(new Knight());
		weak_ptr<Knight> weak = k1;
		// k1을 가르키고 있어도 k1의 refCount는 늘어나지 않음. 
		// weakCount만 늘어난다. 
		shared_ptr<Knight> k2(new Knight());

		k1->_target = k2;
		k2->_target = k1;
	}

	{
		/* unique_ptr */
		// 딱 하나만 존재하는 것을 이것으로 관리하면 좋다. 매니저 포인터 같은 것. 
		unique_ptr<Knight> k(new Knight());
		//unique_ptr<Knight> k2 = k;
		// 이거 안 됨. 복사를 다 막아둠.
		// 그거 빼고는 포인터와 다 같다.
		unique_ptr<Knight> k2 = std::move(k);
		// 이건 k의 내용을 k2로 아예 옮겨버리는 것이니까 가능하다. k는 이제 사용 x.
		// 물론 별로 쓸 일은 없다. 그냥 전체 하나만 존재하면 되는 ptr를 이걸로 만듬. 
		// 사용하는 경우 거의 없다.
	}

	// 스마트 포인터 중 가장 중요한 것은 shared_ptr이다. weak_ptr은 그것을 보조하기 위한 역할,
	// unique_ptr은 사용할 일이 거의 없음. 그러나 면접에서 자꾸 물어보니까 알아둬야 한다. 
	// C#에서는 가비지 컬렉터를 사용한다. 레퍼런스 카운터 방식이 아니기 때문에 사이클 문제가 발생하지 않음.
	// 가비지 컬렉터는 갑자기 크게 핑 튈 수가 있다. 장단점이 존재함. 
	// 스마트 포인터를 사용할 거라면 일반 포인터를 사용 안 하는 게 맞다. 
}