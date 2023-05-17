#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ENCHANT
// 0������ ���� ����

// +1
// +2
// +3

// n���� �� �� ��ȭ�ϴ� ��� ����� ��

// 1�� : 1
// 1

// 2�� : 2
// 1 + 1
// 2

// �� : 3���� �ϰ� �ʹ� -> 4
// 1 + 1 + 1
// 1 + 2
// 2 + 1
// 3

// ��: 4�� -> 7
// 1 + 1 + 1 + 1
// 1 + 2 + 1
// 1 + 1 + 2
// 2 + 1 + 1
// 2 + 2
// 3 + 1
// 1 + 3

// 5�� -> 13
// EnChant(4)
// EnChant(3) + Enchant(2)

vector<int> cache = vector<int>(100, -1);

int targetNum = 5;

int Enchant(int n)
{
	// �������
	if(n > targetNum)
		return 0;

	if(n == targetNum)
		return 1;

	// �޸������̼�
	if(cache[n] != -1)
		return cache[n];

	// ���ϱ�
	return cache[n] = Enchant(n + 1) + Enchant(n + 2) + Enchant(n + 3);
}

int main()
{
	cout << Enchant(0) << endl;

	return 0;
}