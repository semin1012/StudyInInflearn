#include <iostream>
using namespace std;

class Player
{
public:
	virtual ~Player() {	};
};

class Knight : public Player
{
public:
	int hp;
	int defence;
};

class Dog
{
public:
	int age;
	int size;
};

int main()
{
	// C 스타일 캐스팅

	Knight* k = new Knight(); 

	Dog* dog = (Dog*)k;
	// 포인터는 화살표를 타고 가면 무엇이 있을 것이라는 '주장'이다.
	// 주장으로 떼를 쓰고 있는 상황이기 때문에 일단 컴파일이 넘어간다. 

	// 원본은 나이트인데 도그로 타입 변환한 상황에서 밑의 코드는 어떤 일이 일어나겠는가?
	// Player에는 virtual 함수도 있어서 Knight와 Dog의 메모리 구조도 달라졌다. 
	// Knight의 한 공간이 Dog로 바뀌었을 때 age의 위치와 겹칠 텐데, 그 Knight의 한 공간을 age라고 생각하고 엉뚱하게 건들게 된다.
	// 크기가 일치하건, 안 하건 문제는 발생한다. 
	// 그러나 오류 코드가 발생하지는 않기 때문에 메모리가 이상하게 사용되고 있는 상황이 발생. 
	dog->age = 10;
	// (*dog).age = 10; 위와 100퍼센트 동일한 의미

}
 