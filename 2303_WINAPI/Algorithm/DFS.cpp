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
vector<bool> visited;

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

void DFS(int here)
{
	visited[here] = true;
	cout << here << "�� �湮 �߽��ϴ�." << endl;

	for (int there = 0; there < adjacent.size(); there++)
	{
		if(here == there)
			continue;

		if(adjacent[here][there] == false)
			continue;

		if(visited[there] == true)
			continue;

		DFS(there);
	}
}

int main()
{
	CreateGraph(); // �������

	visited = vector<bool>(adjacent.size(), false);

	DFS(0);

	return 0;
}


// ���α׷��ӽ� DFS/BFS ��Ʈ��ũ ����
/*
* #include <string>
#include <vector>

using namespace std;

int answer = 0;
vector<bool> visited;

void DFS(int here, vector<vector<int>>& adjacent)
{
    // �������
    // ���������� Ÿ�� ���ų�, �߰� �߰� �ɰ��� �� ������ ������ ����� ��
    
    visited[here] = true;
    
    for(int there = 0; there < adjacent.size(); there++)
    {
        if(here == there)
            continue;
        if(visited[there] == true)
            continue;
        if(adjacent[here][there] == false)
            continue;
        DFS(there, adjacent);
    }
}

void DFS_ALL(vector<vector<int>>& computers)
{
    for(int here = 0; here < computers.size(); here++)
    {
        if(visited[here] == false)
        {
            answer++;
            DFS(here,computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    visited = vector<bool>(n, false);
    DFS_ALL(computers);

    return answer;
}
*/