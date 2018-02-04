#pragma once
#include "Queue.h"

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
	~TreeNode(void) {}
};

template <class T>
class Tree
{
private:
	TreeNode<T>* root;
	int count;
public:
	Tree(void) { root = new TreeNode<T>(1), count = 0; }
	~Tree(void) {}

	void addTree(int nodeCount);
	void setTree(TreeNode<T>* currentNode);
	void preOrder(TreeNode<T>* currentNode);
	void inOrder(TreeNode<T>* currentNode);
	void postOrder(TreeNode<T>* currentNode);
	void levelOrder(TreeNode<T>* currentNode);
	void traversalOrder();
};


template <class T>
void Tree<T>::addTree(int nodeCount)
{
	Queue<TreeNode<T>*> q; // 큐의 선언과 초기화
	TreeNode<T>* currentNode = root;
	T data = 2;
	while (1)
	{
		if (data <= nodeCount)
		{
			currentNode->leftChild = new TreeNode<T>(data);
			q.Push(currentNode->leftChild);
			data++;
		}
		if (data <= nodeCount)
		{
			currentNode->rightChild = new TreeNode<T>(data);
			q.Push(currentNode->rightChild);
			data++;
		}
		if (data > nodeCount)
		{
			return;
		}
		currentNode = q.Front();
		q.Pop();
	}
}

template <class T>
void Tree<T>::setTree(TreeNode<T>* currentNode)
{
	if (currentNode != nullptr)
	{
		if (currentNode->data == 1)
		{
			cout << currentNode->data;
		}
		else
		{
			cout << " --- " << currentNode->data;
		}
		count++;
		setTree(currentNode->leftChild);
		cout << endl;
		cout << " ";
		for (int i = 0; i < count - 1; i++)
		{
			cout << "      ";
		}
		setTree(currentNode->rightChild);
		count--;
	}
}

template <class T>
void Tree<T>::preOrder(TreeNode<T>* currentNode)
{
	if (currentNode != nullptr)
	{
		cout << currentNode->data << " ";
		preOrder(currentNode->leftChild);
		preOrder(currentNode->rightChild);
	}
}

template <class T>
void Tree<T>::inOrder(TreeNode<T>* currentNode)
{
	if (currentNode != nullptr)
	{
		inOrder(currentNode->leftChild);
		cout << currentNode->data << " ";
		inOrder(currentNode->rightChild);
	}
}

template <class T>
void Tree<T>::postOrder(TreeNode<T>* currentNode)
{
	if (currentNode != nullptr)
	{
		postOrder(currentNode->leftChild);
		postOrder(currentNode->rightChild);
		cout << currentNode->data << " ";
	}
}

template <class T>
void Tree<T>::levelOrder(TreeNode<T>* currentNode)
{ // 이진 트리의 레벨 순서 순회.
	Queue<TreeNode<T>*> q;
	while (1)
	{
		cout << currentNode->data << " ";
		if (currentNode->leftChild) q.Push(currentNode->leftChild);
		if (currentNode->rightChild) q.Push(currentNode->rightChild);
		if (q.isEmpty()) return;
		currentNode = q.Front();
		q.Pop();
	}
}

template <class T>
void Tree<T>::traversalOrder()
{
	setTree(root);
	cout << endl << "preorder    : ";
	preOrder(root);
	cout << endl << "inorder     : ";
	inOrder(root);
	cout << endl << "postorder   : ";
	postOrder(root);
	cout << endl << "level order : ";
	levelOrder(root);
	cout << endl;
}