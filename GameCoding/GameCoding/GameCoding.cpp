#include <iostream>
using namespace std;
#include <vector>
#include <queue>

// 함수 포인터의 단점
// - 시그니처가 안 맞으면 사용 X (함수의 return, 변수 타입이 다르면 할당할 수 없음)
// - 상태를 가질 수 없음 (데이터를 바인딩해서 가질 수 없음)

// 함수를 호출하는 용도로 사용하는 것을 함수 객체라고 한다.

class Functor
{
public:
	// 오버로딩 -> 같은 함수가 여러 의미를 갖는 것
	// 오버라이딩 -> 상속받은 부모의 함수에 자식이 새로운 의미를 갖는 것
	void operator()()	// 괄호에 대해서 오버로딩을 하는 것이다
	{
		cout << "Functor Test" << endl;
		cout << _value << endl;
	}

	void operator()(int n)
	{
		cout << "Functor Test" << endl;
		_value += n;
		cout << _value << endl;
	}

public:
	int _value = 0;
};

class Job
{
public:
	Job() {}
	virtual ~Job() {}	// 부모는 가상함수 꼭 소멸자 해두고 시작
						// 안 그러면 자식 소멸자 실행 안 됨
};

class MoveJob : public Job
{
public:
	MoveJob(int x, int y) : x(x), y(y) {}

	void operator()()
	{
		cout << "Player Move" << endl;
	}

public:
	int x;
	int y;
};

class AttackJob : public Job
{

};

int main()
{
	// 클라: (10, 20) 좌표로 이동할래? (서버상에 요청했지만 순서가 밀릴 경우)
	// 먼저 만들어 놓고 다른 것 처리 후에 함수 수행 -> 멀티스레드에 이점이 많아진다.
	// 이 방식 자체가 선입선출이니까 큐가 좋다.
	// 근데 엔씨에서는 연결리스트를 사용했다. 왜지?
	// 연결리스트는 취소를 바로하지 않고 기억하고 있다가 진짜 사용해야 할때 삭제한다.
	// 보스가 죽었으면 필살기 취소해야 함. 뺄 때 활용할 수 있도록 연결리스트로 구현한 것.
	MoveJob* job = new MoveJob(10, 20);

	AttackJob* attackJob = new AttackJob();
	

	// ...
	// 다른 작업 후에
	// ... 

	(*job)();
	
	// 부모가 둘 다 Job이라서 큐에 둘 다 넣을 수 있다.
	queue<Job*> q;
	q.push(job);
	q.push(attackJob);
}