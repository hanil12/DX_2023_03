#include <iostream>

using namespace std;

#include "BST.h"

BST::BST()
{
}

BST::~BST()
{
}

void BST::Insert(int key)
{
    Node* newNode = new Node(key);

    // Ʈ���� ù ����
    if (_root == nullptr)
    {
        _root = newNode;
        return;
    }

    Node* node = _root;
    Node* parent = nullptr;

    while (true)
    {
        if(node == nullptr)
            break;

        parent = node;
        if(key < node->key)
            node = node->left;
        else
            node = node->right;
    }

    node = newNode;
    node->parent = parent;

    if(node->key < parent->key)
        parent->left = node;
    else
        parent->right = node;
}

void BST::PrintTree(Node* node)
{
    if(node == nullptr)
        return;

    // ���� ��ȸ : root�� ���� ������
    // ���� ��ȸ : root�� �߰�
    // ���� ��ȸ : root�� ���� �ڿ�

    PrintTree(node->left);
    cout << node->key << endl;
    PrintTree(node->right);
}

Node* BST::Search(Node* node, int key)
{
    return nullptr;
}

Node* BST::Min(Node* node)
{
    return nullptr;
}

Node* BST::Max(Node* node)
{
    return nullptr;
}

Node* BST::Previous(Node* node)
{
    return nullptr;
}

Node* BST::Next(Node* node)
{
    return nullptr;
}
