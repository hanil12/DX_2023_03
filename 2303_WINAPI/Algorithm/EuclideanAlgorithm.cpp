#include <iostream>

using namespace std;

// ��Ŭ������ ȣ����, �˰���
// => �ִ�����

// p , q  �� ���� �ִ�����
// �� �� p > q

// 21 6 - 3
// 15 6 - 3
// 9 6 - 3
// 6 3 - 3
// 3 3 - 3
// gcd(p,q) == gcd (p - q, q)

int gcd(int p, int q)
{
	if(q == 0) return p;
	return gcd(q, p % q);
}

int main()
{
	cout << gcd(21,6) << endl;

	return 0;
}