#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Vertex
{
	// int data;
};

vector<Vertex> vertices;
vector<vector<int>> adjacent;

void CreateGraph()
{
	vertices.resize(6);	// 이 사이즈의 데이터를 넣는 것. reverse는 이 사이즈의 영역만 잡는 것.

	adjacent = vector<vector<int>>(6, vector<int>(6, -1));
	adjacent[0][1] = adjacent[1][0] = 15;	// 서로가 연결되어 있는 것을 나타냄, 양방향
	adjacent[0][3] = adjacent[3][0] = 35; 
	adjacent[1][2] = adjacent[2][1] = 5;
	adjacent[1][3] = adjacent[3][1] = 10;
	adjacent[3][4] = adjacent[4][3] = 5;
	adjacent[4][5] = adjacent[5][4] = 5;
}

struct VertexCost
{
	VertexCost(int cost, int vertex) : cost(cost), vertex(vertex) {}

	// 비교 오퍼레이터를 안 넣으면 오류가 떠서 안 돌아간다.
	// priority_queue 자체에 코스트 비교가 들어가야 함. 
	// const를 꼭 뒤에 붙여야 한다. 안 붙이면 다른 거 호출됨.
	// const는 안의 내용을 수정하지 않겠다는 뜻이다. 
	bool operator<(const VertexCost& other) const
	{
		return cost < other.cost;
	}

	bool operator>(const VertexCost& other) const
	{
		return cost >  other.cost;
	}


	int cost;
	int vertex;
};

#include <queue>
// Dijikstra = BFS + 양념(cost)
// - BFS = queue
// - Dijikstra = priority_queue

void Dijikstra(int here)
{
	// 기본적으로 priority_queue 는 less 로 되어 있어서 큰 숫자가 나오는 게 기본임
	// 우리는 작은 것을 원하기 때문에 greater로 바꾸면 됨
	priority_queue<VertexCost, vector<VertexCost>, greater<VertexCost>> pq;
	
	// 그동안의 베스트 경로만을 저장하는 변수다. 존재할 수 있는 가장 큰값을 넣는다.
	vector<int> best(6, INT32_MAX);
	vector<int> parent(6, -1);	// 부모 노드를 저장하기 위한 변수

	pq.push(VertexCost(0, here));
	best[here] = 0;
	parent[here] = here;

	while (pq.empty() == false)
	{
		// 제일 좋은 후보를 찾는다.
		VertexCost v = pq.top();
		pq.pop();

		here = v.vertex;
		int cost = v.cost;

		// 더 짧은 경로를 뒤늦게 찾았다면 스킵
		if (best[here] < cost) // here까지의 베스트 경로보다 cost가 크다면 넣지 않고 스킵
			continue;

		// 방문
		cout << "방문! " << here << endl;
		// 지금까지 살아남았다면 뒤늦게라도 누가 더 좋은 경로라며 새치기할 수가 없음
		// 수학적 귀납법으로 증명 가능하지만 우리가 그것까지 찾아보지는 않을 것이다
		
		for (int there = 0; there < 6; there++)
		{
			// 연결되지 않았으면 스킵
			if (adjacent[here][there] == -1)
				continue;

			// 더 좋은 경로를 과거에 찾았으면 스킵
			int nextCost = best[here] + adjacent[here][there];
			if (nextCost >= best[there])
				continue;

			// 지금까지 찾은 경로 중에서는 최선의 수치 = 갱신
			best[there] = nextCost;
			parent[there] = here;	// 나중에 갱신될 수 있다
			pq.push(VertexCost(nextCost, there));
		}
	}
}

int main()
{
	CreateGraph();
	Dijikstra(0);
}