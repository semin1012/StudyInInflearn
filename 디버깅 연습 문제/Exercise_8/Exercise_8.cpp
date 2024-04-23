#include <iostream>
using namespace std;
#include "Knight.h"
#include "Archer.h"
#include "Mage.h"
#include "Pet.h"

// [Bug Report #8]
// 펫을 궁수의 생성자에서 만드는 것이
// 깔끔하지 않다는 사장님의 지적에 따라
// 일단 밖으로 빼서 펫을 생성하게 수정했습니다.

// 그런데 막상 밖으로 빼니 또 크래시가 납니다.
// 가만히 있으면 중간은 간다던데...
// 뭐가 문제일까요?

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	while (true)
	{
		// 나중엔 궁수, 법사 등 추가 예정
		Player* p = nullptr;

		switch (rand() % 3)
		{
			case 0:
			{
				p = new Knight();
				p->_hp = 100;
				p->_attack = 100;
				break;
			}	
			case 1:
			{
				// 여기서 같이 만들어준다
				// 이런 저런 펫 정보 추가될 예정
				// Pet pet; << 이건 스택메모리에서 만들어짐
				// Pet* pet = new Pet() << 이건 힙 메모리에서 만들어짐
				// 스택메모리(로컬변수)를 가르키는 것이 문제였음
				// 스택은 공간 지나가면 자동으로 삭제되는데
				// 힙 영역에 만들어진 애들은 우리가 직접 삭제해줘야 됨
				// 그래서 힙 영역에 만들었으면 Archer에서 Pet을 삭제해줘야 함
				Pet* pet = new Pet();

				// Archer를 만들 때 pet 정보도 넘겨준다
				p = new Archer(pet);
				p->_hp = 100;
				p->_attack = 100;

				break;
			}		
			case 2:
			{
				p = new Mage();
				p->_hp = 100;
				p->_attack = 100;
				break;
			}			
		}

		delete p;
	}

}
