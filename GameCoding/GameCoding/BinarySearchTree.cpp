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

	// ������ �׳� ���Ƿ� ã�� ������ ���ڰ� ���� ���� ��
	Print(node->left, x - (5 / (y + 1)), y + 1);
	Print(node->right, x + (5 / (y + 1)), y + 1);
}

void BinarySearchTree::Insert(int key)
{
	Node* newNode = new Node();
	newNode->key = key;

	// ù ��° �������� ���
	if (_root == nullptr)
	{
		_root = newNode;
		return;
	}

	// �߰��� ��ġ�� ã�� (�ٽ�)
	Node* node = _root;
	Node* parent = nullptr;

	// ��ġ ã��
	while (node)
	{
		parent = node;
		if (key < node->key)
			node = node->left;
		else
			node = node->right;
	}

	// parent ������ �ֱ�
	newNode->parent = parent;
	
	if (key < parent->key)
		parent->left = newNode;
	else
		parent->right = newNode;
}

Node* BinarySearchTree::Search(Node* node, int key)
{
	if (node == nullptr || node->key == key)
		return node;	// nullptr�� ��ȯ�ǰų� key�� ��ȯ�ǰų�

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

// �̰� �����
// �������� �� �� ���� ��� ���������� ���ٴ� �� �Ϲ������δ� �� ���� 
// �ٵ� ����... ���� ���� ����� 15���� ������ �Ѵ�?
// �� ĭ�� �ö󰡼� ���� �θ� �ִ��� ���� �ȴ�
Node* BinarySearchTree::Next(Node* node)
{
	// ��忡 �ڽ� ���(�������� ������)
	// ���������� �� ĭ �� ���� ��� �������θ� ���� ��
	if (node->right)
		return Min(node->right);

	// �װ� �ƴ϶�� ���� ���� �ڽ����� ������ �ִ� ������� ã���� �ȴ�
	Node* parent = node->parent;

	// ���� ���� �ڽ����� ���� �θ� ã�� ������ ���� �ö󰣴�.
	while (parent && node == parent->right)
	{
		node = parent;
		parent = parent->parent;
	}

	return nullptr;
}

void BinarySearchTree::Replace(Node* u, Node* v)
{
	// case 2, �ڽ��� �ִ� �θ�(u)�� ���� �� ���
	// => �ڽ�(v)�� �θ�(u)�� �ڸ��� �����Ѵ�.

	// u�� �θ� ���� ���� ��Ʈ ����� ��
	if (u->parent == nullptr)
		_root = v;
	// u��� �ְ� �θ��� ���� ���ϵ忴�ٸ� v�� �θ��� ���ʿ� ������ �ָ� �ȴ�.
	else if (u == u->parent->left)
		u->parent->left = v;
	// u�� �θ��� ���� ���ϵ尡 �ƴϾ��ٸ� ������ ���ϵ忴�� ��. 
	else
		u->parent->right = v;

	// v���� �θ� ������ �ش�. 
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

	// �ڽ��� �ϳ��� �ִ�
	if (node->left == nullptr)
	{
		// ���� �����ϱ� '�ϳ� �ִ� �ڽ�'�� ���� �θ���� �������ش�. 
		Replace(node, node->right);
	}
	else if (node->right == nullptr)
	{
		Replace(node, node->left);
	}
	// �ڽ��� ���ʿ� �ִ�
	else
	{
		// �ڽ� �߿� ���� ���� ���� ã���ְ�
		Node* next = Next(node);
		// �ڽ� key ���� ������ ������ �� �ڿ�
		node->key = next->key;
		// �ڽ��� ���ش�.
		Delete(next);
	}
}
