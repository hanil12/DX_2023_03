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
vector<vector<bool>> adjacent;
vector<bool> discovered;
vector<int> parent; // parent[1] = 0

// �������
void CreateGraph()
{
	//	  0  1  2  3  4  5  6
	// 0  1  1  1  0  0  0  0
	// 1  1  1  0  0  0  0  1
	// 2  1  0  1  1  0  1  0
	// 3  0  0  1  1  0  0  0
	// 4  1  0  0  0  1  0  0
	// 5  0  0  1  0  0  1  0
	// 6  0  1  0  0  0  0  1

	adjacent = vector<vector<bool>>(7, vector<bool>(7, false));

	adjacent[0][0] = true;
	adjacent[0][1] = true;
	adjacent[0][2] = true;
	adjacent[0][4] = true;

	adjacent[1][0] = true;
	adjacent[1][1] = true;
	adjacent[1][6] = true;

	adjacent[2][0] = true;
	adjacent[2][2] = true;
	adjacent[2][3] = true;
	adjacent[2][5] = true;

	adjacent[3][3] = true;
	adjacent[3][2] = true;

	adjacent[4][0] = true;
	adjacent[4][4] = true;

	adjacent[5][2] = true;
	adjacent[5][5] = true;

	adjacent[6][1] = true;
	adjacent[6][6] = true;
}

void BFS(int here)
{
	discovered = vector<bool>(7, false);
	parent = vector<int>(7, -1);

	queue<int> q;
	q.push(here);
	discovered[here] = true;
	parent[here] = here;

	while (true)
	{
		if(q.empty())
			break;

		int here = q.front();
		q.pop();

		cout << here << "���� Ž�� ����!!!" << endl;

		for (int there = 0; there < adjacent.size(); there++)
		{
			// ���� �������ִ��� ����Ȯ��
			if(adjacent[here][there] == false)
				continue;

			// �ش� ������ �湮�� �Ǿ��־����� Ȯ��
			if(discovered[there] == true)
				continue;

			cout << there << "�湮�ϰ� ť�� ����!!" << endl;
			q.push(there);
			discovered[there] = true;
			parent[there] = here;
		}
	}
}

int main()
{
	CreateGraph(); // �������
	BFS(0);

	int check = 3;
	while (true)
	{
		if (check == parent[check])
		{
			cout << "������ : " << check << endl;
			break;
		}

		cout << check << endl;
		check = parent[check];
	}

	return 0;
}