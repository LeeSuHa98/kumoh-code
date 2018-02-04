#pragma once
#include <iostream>
using namespace std;

template <class T>
class Tree
{
private:
	T* data; // 배열
	int capacity; // 용량

public:
	Tree(T nodeCount);
	~Tree(void) { delete[] data; }

	int setTree(int currentNode, int nodeCount);

	int preOrder(int currentNode, int nodeCount);
	int inOrder(int currentNode, int nodeCount);
	int postOrder(int currentNode, int nodeCount);
	void levelOrder(int nodeCount);
	void traversalOrder(int nodeCount);
};

template <class T>
Tree<T>::Tree(T nodeCount)
{
	capacity = 100;

	data = new T[capacity];

	for (int i = 1; i <= nodeCount; i++)
	{
		data[i] = i;
	}
	capacity = 0;
}

template <class T>
int Tree<T>::setTree(int currentNode, int nodeCount)
{
	if (currentNode > nodeCount)
	{
		cout << endl;
		return 0;
	}

	if (currentNode == 1)
	{
		cout << currentNode;
	}
	else
	{
		cout << " --- " << currentNode;
	}

	capacity++;

	setTree(2 * currentNode, nodeCount); // leftChild : 2i

	cout << " ";

	for (int i = 0; i < capacity - 1; i++)
	{
		cout << "      ";
	}
	setTree(2 * currentNode + 1, nodeCount); // rightChild : 2i+1

	capacity--;
}

template <class T>
int Tree<T>::preOrder(int currentNode, int nodeCount)
{
	if (currentNode > nodeCount)
	{
		return 0;
	}
	cout << data[currentNode] << " ";
	preOrder(2 * currentNode, nodeCount);
	preOrder(2 * currentNode + 1, nodeCount);
}

template <class T>
int Tree<T>::inOrder(int currentNode, int nodeCount)
{
	if (currentNode > nodeCount)
	{
		return 0;
	}
	inOrder(2 * currentNode, nodeCount);
	cout << data[currentNode] << " ";
	inOrder(2 * currentNode + 1, nodeCount);
}

template <class T>
int Tree<T>::postOrder(int currentNode, int nodeCount)
{
	if (currentNode > nodeCount)
	{
		return 0;
	}
	postOrder(2 * currentNode, nodeCount);
	postOrder(2 * currentNode + 1, nodeCount);
	cout << data[currentNode] << " ";
}

template <class T>
void Tree<T>::levelOrder(int nodeCount)
{
	for (int i = 1; i <= nodeCount; i++)
	{
		cout << data[i] << " ";
	}
}

template <class T>
void Tree<T>::traversalOrder(int nodeCount)
{
	int root = 1;
	setTree(root, nodeCount);
	cout << "preorder    : ";
	preOrder(root, nodeCount);
	cout << endl << "inorder     : ";
	inOrder(root, nodeCount);
	cout << endl << "postorder   : ";
	postOrder(root, nodeCount);
	cout << endl << "level order : ";
	levelOrder(nodeCount);
	cout << endl;
}