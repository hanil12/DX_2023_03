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

// priority_queue
// - �� Ʈ��
// -- ��������Ʈ��
// -- ���̷��� ���� ��

template <typename T, typename Container, typename Pred>
class Priority_Queue
{
public:
	void push(const T& value)
	{
		// ���� ���� Ʈ�� ��Ģ
		v.push_back(value);

		// �� ��Ģ
		int now = v.size() - 1;

		while (true)
		{
			if(now <= 0)
				break;

			int parent = (now - 1) / 2;

			if(Pred()(v[now], v[parent]))
				break;

			std::swap(v[now], v[parent]);
			now = parent;
		}
	}

	void pop()
	{
		// ���� ����Ʈ�� ��Ģ
		v[0] = v.back();
		v.pop_back();

		// ���̷� ��Ģ
		int now = 0;
		while (true)
		{
			int leftChild = now * 2 + 1;
			int rightChild = now * 2 + 2;

			// �����ڽ��� ����...=> ��������̴� break
			if(leftChild >= v.size())
				break;

			int change = now;

			if(Pred()(v[change] , v[leftChild]))
				change = leftChild;

			if(rightChild < v.size() && Pred()(v[change] , v[rightChild]))
				change = rightChild;

			if(change == now)
				break;

			std::swap(v[now], v[change]);
			now = change;
		}
	}

	const T& top()
	{
		return v[0];
	}

	bool empty()
	{
		return v.empty();
	}

private:
	Container v;
};

int main()
{
	struct myLess
	{
		bool operator()(const int& value1, const int& value2)
		{
			return value1 < value2;
		}
	};

	Priority_Queue<int, vector<int>, myLess> pq;

	pq.push(15);
	pq.push(10);
	pq.push(11);
	pq.push(1);
	pq.push(300);
	pq.push(30);
	pq.push(3);

	while (true)
	{
		if(pq.empty())
			break;
		cout << pq.top() << endl;
		pq.pop();
	}

	return 0;
}