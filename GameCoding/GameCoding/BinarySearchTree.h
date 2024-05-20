#pragma once

struct Node
{
	Node* parent = nullptr;
	Node* left = nullptr;
	Node* right = nullptr;
	int key = 0;
};

class BinarySearchTree
{
public:
	void Print() { Print(_root, 10, 0); }
	void Print(Node* node, int x, int y);
	void Insert(int key); 

	Node* Search(Node* node, int key);

	// 삭제를 위한 min, max, next
	Node* Min(Node* node);
	Node* Max(Node* node);
	Node* Next(Node* node);

	void Replace(Node* u, Node* v);

	void Delete(int key);
	void Delete(Node* node);

	Node* GetRootNode() { return _root; }

private:
	Node* _root = nullptr;
};