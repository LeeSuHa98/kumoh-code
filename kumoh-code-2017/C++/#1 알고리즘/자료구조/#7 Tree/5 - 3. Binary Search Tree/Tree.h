#pragma once
#include <iostream>
#include <string>

using namespace std;

template <class T> class Tree; // 전방 선언
template <class T>
class TreeNode
{
	friend class Tree<T>;
private:
	T data;
	TreeNode<T>* rightChild;
	TreeNode<T>* leftChild;
public:
	TreeNode(T data)
	{
		this->data = data;
		rightChild = nullptr;
		leftChild = nullptr;
	}
	~TreeNode(void) { delete[] data; }
};

template <class T>
class Tree
{
private:
	TreeNode<T>* root;
	int count;
public:
	Tree(string data) { root = new TreeNode<T>(data), count = 0; }
	~Tree(void) {}

	void addTree(TreeNode<T>* currentNode, string data);
	void insertTree(string data) { addTree(root, data); }
	void setTree(TreeNode<T>* currentNode);
	void getTree() { setTree(root); }
};


template <class T>
void Tree<T>::addTree(TreeNode<T>* currentNode, string data)
{
	if (currentNode->data.compare(data) < 0)	// current->name > name
	{
		if (currentNode->rightChild == nullptr || currentNode->rightChild->data == "0")
		{
			TreeNode<T>* newNode = new TreeNode<T>(data);
			currentNode->rightChild = newNode;
			if (currentNode->leftChild == nullptr)
			{
				currentNode->leftChild = new TreeNode<T>("0");
			}
		}
		else
		{
			addTree(currentNode->rightChild, data);
		}
	}
	else if (currentNode->data.compare(data) > 0)	// current->name < name
	{
		if (currentNode->leftChild == nullptr || currentNode->leftChild->data == "0")
		{
			TreeNode<T>* newNode = new TreeNode<T>(data);
			currentNode->leftChild = newNode;
			if (currentNode->rightChild == nullptr)
			{
				currentNode->rightChild = new TreeNode<T>("0");
			}
		}
		else
		{
			addTree(currentNode->leftChild, data);
		}
	}
}

template <class T>
void Tree<T>::setTree(TreeNode<T>* currentNode)
{
	cout << " --- " << currentNode->data;

	if (currentNode->leftChild != nullptr)
	{
		count++;
		setTree(currentNode->leftChild);
		cout << endl;
		count--;
	}
	if (currentNode->rightChild != nullptr)
	{
		for (int i = 0; i <= count; i++)
		{
			cout << "           ";
		}
		count++;
		setTree(currentNode->rightChild);
		count--;
	}
}