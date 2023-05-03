#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>

using namespace std;
vector<vector<int>> adjacent;
vector<bool> discovered;
vector<int> parent;
vector<int> best;

struct Vertex
{
	int vertexNum;
	int cost;

	bool operator<(const Vertex& other) const
	{
		return cost < other.cost;
	}

	bool operator>(const Vertex& other) const
	{
		return cost > other.cost;
	}
};


void CreateGraph()
{
	adjacent = vector<vector<int>>(7, vector<int>(7, -1));

	adjacent[0][0] = 0;
	adjacent[0][1] = 4;
	adjacent[0][2] = 1;
	adjacent[0][4] = 8;

	adjacent[1][0] = 4;
	adjacent[1][1] = 0;
	adjacent[1][6] = 7;
	adjacent[1][2] = 2;

	adjacent[2][0] = 1;
	adjacent[2][1] = 2;
	adjacent[2][2] = 0;
	adjacent[2][3] = 4;
	adjacent[2][5] = 5;

	adjacent[3][3] = 0;
	adjacent[3][2] = 4;

	adjacent[4][0] = 8;
	adjacent[4][4] = 0;

	adjacent[5][2] = 5;
	adjacent[5][5] = 0;
	adjacent[5][6] = 80;

	adjacent[6][1] = 7;
	adjacent[6][5] = 80;
	adjacent[6][6] = 0;
}

void Dijkstra(int startIndex)
{
	priority_queue<Vertex, vector<Vertex>, greater<Vertex>> pq;
	best = vector<int>(adjacent.size(), INT_MAX);
	discovered = vector<bool>(adjacent.size(), false);
	parent = vector<int>(adjacent.size(), -1);

	Vertex start;
	start.vertexNum = startIndex;
	start.cost = 0;

	pq.push(start);
	best[start.vertexNum] = start.cost;
	discovered[start.vertexNum] = true;
	parent[start.vertexNum] = start.vertexNum;

	while (true)
	{
		if(pq.empty())
			break;

		int cost = pq.top().cost;
		int here = pq.top().vertexNum;

		pq.pop();

		// ���� ã���� ���� �߰��ҷ��� Vertex�� ����ġ���� ���� ���
		if (best[here] < cost)
		{
			cout<< here << endl;
			cout << cost << endl;
			cout << best[here] << endl;
			continue;
		}

		// BFS�� �����ϰ� ������ Vertex Ȯ��
		for (int there = 0; there < adjacent.size(); there++)
		{
			// ���� pq�� �߰��� ��ġ�� �����ϸ� continue;
			if(here == there)
				continue;

			// ����Ȯ��
			if(adjacent[here][there] == -1)
				continue;

			int nextCost = best[here] + adjacent[here][there];

			// �ڴʰ� ã�� Vertex�� best��
			// ������ ã�� Vertex�� best���� �� ũ�� ���� �� Ȯ��
			if (nextCost >= best[there])
			{
				cout << here << "���� " << there <<"����" << endl;
				cout << "�̹� �� ���� best���� �־ �����ϰڽ��ϴ�." <<endl;
				continue;
			}

			Vertex v;
			v.vertexNum = there;
			v.cost = nextCost;
			pq.push(v);
			best[there] = nextCost;
			discovered[there] = true;
			parent[there] = here;
		}
	}

	for (int i = 0; i < adjacent.size(); i++)
	{
		cout << i << "�� �θ� : " << parent[i] << endl;
		cout << i << "�� ������������ �ּҰŸ� : " << best[i] << endl;
	}
}

int main()
{
	CreateGraph(); // �������
	Dijkstra(0);

	return 0;
}