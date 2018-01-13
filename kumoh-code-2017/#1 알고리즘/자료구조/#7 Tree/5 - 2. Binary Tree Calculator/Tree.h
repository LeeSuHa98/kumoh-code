#pragma once
#include "Token.h"

template <class T> class Tree; // ���� ����
template <class T>
class TreeNode
{
	friend class Tree<T>;
private:
	T data;
	TreeNode<T>* rightChild;	// ������ �ڽ�
	TreeNode<T>* leftChild;		// ���� �ڽ�

public:
	TreeNode()
	{
		rightChild = nullptr;
		leftChild = nullptr;
	}
	TreeNode(T data)
	{
		this->data = data;
		rightChild = nullptr;
		leftChild = nullptr;
	}
	TreeNode(T data, TreeNode<T> *rightChild, TreeNode<T> *leftChild)
	{
		this->data = data;
		this->rightChild = rightChild;
		this->leftChild = leftChild;
	}
	~TreeNode(void) {}

	void setRightChild(TreeNode<T>* rightChild)
	{
		this->rightChild = rightChild;
	}
	void setLeftChild(TreeNode<T>* leftChild)
	{
		this->leftChild = leftChild;
	}
	void setData(const T& data)
	{
		this->data = data;
	}

	T getData()
	{
		return data;
	}
	TreeNode<T>*& getRightChild()
	{
		return rightChild;
	}
	TreeNode<T>*& getLeftChild()
	{
		return leftChild;
	}
};

template <class T>
class Tree
{
private:
	TreeNode<T>* root;

	void deleteTree(TreeNode<T>* currentNode)	// ����
	{
		if (currentNode == nullptr)
		{
			return;
		}
		deleteTree(currentNode->getLeftChild());
		deleteTree(currentNode->getRightChild());
		delete currentNode;	// Node ����
	}
	TreeNode<T>* updateTree(TreeNode<T>* currentNode)	// ����
	{
		if (currentNode == nullptr)
		{
			return nullptr;
		}
		// ���ο� Tree�� ��ȯ
		return new TreeNode<T>(currentNode->getData(), updateTree(currentNode->getLeftChild()), updateTree(currentNode->getRightChild()));
	}
public:
	Tree()	// �⺻ ������
	{
		root = nullptr;
	}
	Tree(Tree<T>& tree)	// ���ο� Ʈ�� ������
	{
		root = updateTree(tree.getRoot());
	}
	~Tree()	// �Ҹ���
	{
		deleteTree(root);
	}

	TreeNode<T>* getRoot()
	{
		return root;
	}
	void setRoot(TreeNode<T>* root)
	{
		deleteTree(this->root);	// ���� Tree ����
		this->root = root;	// ���ο� root �Ҵ�
	}

	Tree<T>& operator=(const Tree<T>& tree)
	{
		if (this == &tree)
		{
			return *this;
		}
		deleteTree(root);	// ���� Tree ����
		root = updateTree(tree.root);	// ������ Tree�� �Ҵ�

		return *this;
	}
};