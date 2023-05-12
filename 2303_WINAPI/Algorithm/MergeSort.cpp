#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Merge Sort ���� ����
// - �� ���̸� ����
// - ���� ����
// => ���� ���� �з�����

// Divide : ���� ���� ������ �ɰ���
// Conquer : �ذ��ϱ�
// Merge : �ذ�� ������ ��ġ��

void MergeResult(vector<int>& v, int left, int mid, int right)
{
	int leftIndex = left;
	int rightIndex = mid + 1;

	vector<int> temp;

	while (true)
	{
		if(leftIndex > mid || rightIndex > right)
			break;

		if (v[leftIndex] <= v[rightIndex])
		{
			temp.push_back(v[leftIndex]);
			leftIndex++;
		}
		else
		{
			temp.push_back(v[rightIndex]);
			rightIndex++;
		}
	}

	// ������ ���� ������.
	if (leftIndex > mid)
	{
		while (rightIndex <= right)
		{
			temp.push_back(v[rightIndex]);
			rightIndex++;
		}
	}

	// �������� ���� ������.
	else
	{
		while (leftIndex <= mid)
		{
			temp.push_back(v[leftIndex]);
			leftIndex++;
		}
	}

	for (int i = 0; i < temp.size(); i++)
	{
		v[left + i] = temp[i];
	}
}

void MergeSort(vector<int>& v, int left, int right)
{
	if(left >= right)
		return;

	// Divide
	int mid = (left + right) / 2;
	MergeSort(v,left, mid);
	MergeSort(v,mid + 1, right);

	// Merge
	MergeResult(v, left, mid ,right);
}

int main()
{
	// Quick Sort
	// -> std::sort
	// Merge Sort
	// -> std::stable_sort
	// Heap Sort
	// -> std::partial_sort : nlog (m: mid)

	vector<int> v = { 55, 30, 15, 100, 1, 5, 70, 30 };

	
	std::partial_sort(v.begin(), v.begin() + 3, v.end());

	return 0;
}