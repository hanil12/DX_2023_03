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
    if(node == nullptr)
        return nullptr;

    if (node->key == key)
    {
        return node;
    }

    if(node->key > key)
        return Search(node->left, key);
    else
        return Search(node->right,key);
}

Node* BST::Min(Node* node)
{
    if(node == nullptr)
        return nullptr;

    if(node->left != nullptr)
        return Min(node->left);

    return node;
}

Node* BST::Max(Node* node)
{
    if (node == nullptr)
        return nullptr;

    if (node->right != nullptr)
        return Min(node->right);

    return node;
}

Node* BST::Previous(Node* node)
{
    if(node == nullptr)
        return nullptr;

    if(node->left == nullptr)
        return nullptr;

    return Max(node->left);
}

Node* BST::Next(Node* node)
{
    if (node == nullptr)
        return nullptr;

    if (node->right == nullptr)
        return nullptr;

    return Min(node->right);
}

void BST::Delete(Node* node)
{
    if(node == nullptr)
        return;

    // ���� ����� ���� �ڽ��� ����
    if(node->left == nullptr)
        Replace(node, node->right);
    // ���� ����� ������ �ڽ��� ���� ���
    else if(node->right == nullptr)
        Replace(node, node->left);
    // �ڽ� �Ѵ� �ִ� ���
    else
    {
        Node* prev = Previous(node);
        node->key = prev->key;
        node->data = prev->data;
        Delete(prev);
    }
}

void BST::Replace(Node* node1, Node* node2)
{
    // node1�� ��Ʈ�� ��
    if(node1->parent == nullptr)
        _root = node2;

    // node1�� �θ��ʿ��� ���� �ڽ� ����� ��
    else if (node1 == node1->parent->left)
    {
        node1->parent->left = node2;
    }
    // node1�� �θ��ʿ��� ������ �ڽ� ����� ��
    else if (node1 == node1->parent->right)
    {
        node1->parent->right = node2;
    }

    if(node2 != nullptr)
        node2->parent = node1->parent;

    delete node1;
}
