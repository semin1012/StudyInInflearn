#include "BinarySearchTree.h"
#include <iostream>
#include <windows.h>
using namespace std;

void SetCursorPosition(int x, int y)
{
	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
	::SetConsoleCursorPosition(output, pos);
}

void BinarySearchTree::Print(Node* node, int x, int y)
{
	if (node == nullptr)
		return;

	SetCursorPosition(x, y);

	cout << node->key;

	// 공식은 그냥 임의로 찾은 공식임 예쁘게 보기 위한 거
	Print(node->left, x - (5 / (y + 1)), y + 1);
	Print(node->right, x + (5 / (y + 1)), y + 1);
}

void BinarySearchTree::Insert(int key)
{
	Node* newNode = new Node();
	newNode->key = key;

	// 첫 번째 데이터일 경우
	if (_root == nullptr)
	{
		_root = newNode;
		return;
	}

	// 추가할 위치를 찾기 (핵심)
	Node* node = _root;
	Node* parent = nullptr;

	// 위치 찾기
	while (node)
	{
		parent = node;
		if (key < node->key)
			node = node->left;
		else
			node = node->right;
	}

	// parent 연결해 주기
	newNode->parent = parent;
	
	if (key < parent->key)
		parent->left = newNode;
	else
		parent->right = newNode;
}

Node* BinarySearchTree::Search(Node* node, int key)
{
	if (node == nullptr || node->key == key)
		return node;	// nullptr이 반환되거나 key가 반환되거나

	if (key < node->key)
		return Search(node->left, key);
	else
		return Search(node->right, key);
}

Node* BinarySearchTree::Min(Node* node)
{
	if (node == nullptr)
		return nullptr;

	while (node->left)
		node = node->left;

	return node;
}

Node* BinarySearchTree::Max(Node* node)
{
	if (node == nullptr)
		return nullptr;

	while (node->right)
		node = node->right;

	return node;
}

// 이거 어려움
// 왼쪽으로 한 번 가고 계속 오른쪽으로 간다는 게 일반적으로는 다 맞음 
// 근데 만약... 가장 리프 노드인 15부터 시작을 한다?
// 한 칸을 올라가서 왼쪽 부모가 있는지 보면 된다
Node* BinarySearchTree::Next(Node* node)
{
	// 노드에 자식 노드(오른쪽이 있으면)
	// 오른쪽으로 한 칸 간 다음 계속 왼쪽으로만 가면 됨
	if (node->right)
		return Min(node->right);

	// 그게 아니라면 나를 왼쪽 자식으로 가지고 있는 조상님을 찾으면 된다
	Node* parent = node->parent;

	// 나를 왼쪽 자식으로 가진 부모를 찾을 때까지 위로 올라간다.
	while (parent && node == parent->right)
	{
		node = parent;
		parent = parent->parent;
	}

	return nullptr;
}

void BinarySearchTree::Replace(Node* u, Node* v)
{
	// case 2, 자식이 있던 부모(u)가 삭제 될 경우
	// => 자식(v)이 부모(u)의 자리를 차지한다.

	// u의 부모가 없을 경우는 루트 노드인 것
	if (u->parent == nullptr)
		_root = v;
	// u라는 애가 부모의 왼쪽 차일드였다면 v도 부모의 왼쪽에 연결해 주면 된다.
	else if (u == u->parent->left)
		u->parent->left = v;
	// u가 부모의 왼쪽 차일드가 아니었다면 오른쪽 차일드였을 것. 
	else
		u->parent->right = v;

	// v에도 부모를 연결해 준다. 
	if (v)
		v->parent = u->parent;
}

void BinarySearchTree::Delete(int key)
{
	Node* deleteNode = Search(_root, key);
	Delete(deleteNode);
}

void BinarySearchTree::Delete(Node* node)
{
	if (node == nullptr)
		return;

	// 자식이 하나라도 있다
	if (node->left == nullptr)
	{
		// 나는 죽으니까 '하나 있던 자식'을 나의 부모님을 연결해준다. 
		Replace(node, node->right);
	}
	else if (node->right == nullptr)
	{
		Replace(node, node->left);
	}
	// 자식이 양쪽에 있다
	else
	{
		// 자식 중에 나의 다음 값을 찾아주고
		Node* next = Next(node);
		// 자식 key 값을 나에게 복사해 준 뒤에
		node->key = next->key;
		// 자식을 없앤다.
		Delete(next);
	}
}
