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

// Tree
// - root
// - leaf
// - depth

// 1. ������ ������ ��Ÿ���⿡ ���� ������ ����.
// 2. ����Ʈ���� �����ϸ�, Ʈ���� ����� �Ӽ��� ���´�.

struct Node
{
	Node() {}
	Node(const string& data) : _data(data) {}
	
	vector<Node*> _children;
	string _data;
};

Node* CreateTree()
{
	Node* root = new Node("������");
	{
		Node* children_1 = new Node("���α׷�����");
		root->_children.push_back(children_1);

		{
			Node* children_2 = new Node("Ŭ���̾�Ʈ");
			children_1->_children.push_back(children_2);
		}

		{
			Node* children_2 = new Node("����");
			children_1->_children.push_back(children_2);
		}

		{
			Node* children_2 = new Node("����");
			children_1->_children.push_back(children_2);
		}
	}

	{
		Node* children_1 = new Node("��ȹ");
		root->_children.push_back(children_1);

		{
			Node* children_2 = new Node("���丮");
			children_1->_children.push_back(children_2);
		}

		{
			Node* children_2 = new Node("����������");
			children_1->_children.push_back(children_2);
		}

		{
			Node* children_2 = new Node("�뷱��");
			children_1->_children.push_back(children_2);
		}
	}

	{
		Node* children_1 = new Node("��Ʈ");
		root->_children.push_back(children_1);

		{
			Node* children_2 = new Node("���");
			children_1->_children.push_back(children_2);
		}

		{
			Node* children_2 = new Node("��ȭ");
			children_1->_children.push_back(children_2);
		}

		{
			Node* children_2 = new Node("�𵨸�");
			children_1->_children.push_back(children_2);
		}
	}

	return root;
}

void PrintTree(Node* root, int depth)
{
	for (int i = 0; i < depth; i++)
	{
		cout<< "-";
	}


	cout << root->_data << endl;
	for (auto node : root->_children)
	{
		PrintTree(node, depth + 1);
	}
}

int main()
{
	Node* root = CreateTree();

	PrintTree(root,0);

	return 0;
}