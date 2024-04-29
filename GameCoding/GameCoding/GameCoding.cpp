#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
	Node(const char* data) : data(data) { }

public:
	const char* data;
	vector<Node*> childen;
};

Node* CreateTree()
{
	Node* root = new Node("R1 개발실");
	{
		Node* node = new Node("디자인팀");	
		root->childen.push_back(node);
		{
			Node* leaf = new Node("전투");
			node->childen.push_back(leaf);
		}
		{
			Node* leaf = new Node("경제");
			node->childen.push_back(leaf);
		}
		{
			Node* leaf = new Node("스토리");
			node->childen.push_back(leaf);
		}
	}
	{
		Node* node = new Node("프로그래밍팀");	
		root->childen.push_back(node);
		{
			Node* leaf = new Node("클라");
			node->childen.push_back(leaf);
		}
		{
			Node* leaf = new Node("서버");
			node->childen.push_back(leaf);
		}
		{
			Node* leaf = new Node("엔진");
			node->childen.push_back(leaf);
		}
	}
	{
		Node* node = new Node("아트팀");	
		root->childen.push_back(node);
		{
			Node* leaf = new Node("배경");
			node->childen.push_back(leaf);
		}
		{
			Node* leaf = new Node("캐릭터");
			node->childen.push_back(leaf);
		}
	}

	return root;
}

// 깊이(Depth): 루트에서 어떤 노드에 도달하기 위해 거쳐야 하는 간선의 개수
void PrintTree(Node* root, int depth = 0)
{
	for( int i = 0 ; i < depth; i++ )
		cout << " ";

	cout << root->data << endl;

	int size = root->childen.size();
	if ( size > 0 )
	{
		for ( int i = 0 ; i < size; i++ ) 
		{
			Node* node = root->childen[i];
			PrintTree(node, depth+1);
		}
		cout << endl;
	}	
}

// 높이 
int GetHeight(Node* root)
{
	int ret = 1;

	int size = root->childen.size();
	for ( int i = 0 ; i < size ; i++ )
	{
		Node* node = root->childen[i];
		int h = GetHeight(node) + 1;
		// 이게 이해 안 가면 노션 

		if (ret < h)
			ret = h;
	}

	return ret;
}

int main()
{
	Node* root = CreateTree();

	PrintTree(root);

	cout << GetHeight(root) << endl;
}