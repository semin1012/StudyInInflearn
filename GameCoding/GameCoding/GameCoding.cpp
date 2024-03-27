#include <iostream>
using namespace std;

class Node
{
public:
	Node(int data) : data(data) { }

public:
	int data; 
	// 포인터를 안 붙이면 러시아 인형처럼 끝없이 자기 자신을 타고 들어가서 끝 안 나는 클래스가 됨
	// 포인터를 붙이면 그저 주소값을 넣는 것 
	Node* prev = nullptr;
	Node* next = nullptr;
};

int main()
{
	// 양방향이 더 장점이 많고 더 많이 쓰인다. 
	// 새 정보를 넣고 싶을 때 앞뒤 정보를 같이 비교해서 넣는 게 일반적이기 때문에.
	Node* n1 = new Node(1);
	Node* n2 = new Node(2);
	Node* n3 = new Node(3);
	Node* n4 = new Node(4);
	Node* n5 = new Node(5);
	
	// [1]<->[2]<->[3]<->[4]<->[5]
	// [head]				   [tail]
	n1->next = n2;
	n2->prev = n1;
	
	n2->next = n3;
	n3->prev = n2;

	n3->next = n4;
	n4->prev = n3;

	n4->next = n5;
	n5->prev = n4;

	Node* head = n1;
	Node* tail = n5;
}