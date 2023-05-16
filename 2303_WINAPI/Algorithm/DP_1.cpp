#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// n���� ���� �����ִ�.
// ���� ������� m���� ���� ���� �� ���� �� �ִ� ����� ���� ��� ���Ͻÿ�.
// n >= 1
// m >= 0

vector<vector<int>> cache = vector<vector<int>>(101, vector<int>(101, -1));

int Combine(int n, int m)
{
	// ��������
	if(n == 1 || m == 0 || n == m)
		return 1;

	// �޸������̼�
	if(cache[n][m] != -1)
		return cache[n][m];

	// ���ϱ�
	return cache[n][m] = Combine(n-1, m) + Combine(n-1, m -1);
}

int main()
{
	cout << Combine(99,15) << endl;
	// 5! = 120
	// 2! * (5-2)! = 2 * 6

	vector<int> v = {1,2,3,4};

	while (true)
	{
		if (std::next_permutation(v.begin(), v.end()))
		{
			for (auto value : v)
			{
				cout << value << ",";
			}

			cout << endl;
		}
		else
			break;
	}

	return 0;
}