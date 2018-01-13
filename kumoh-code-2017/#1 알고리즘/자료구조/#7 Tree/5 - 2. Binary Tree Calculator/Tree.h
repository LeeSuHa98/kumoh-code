#pragma once
#include "Token.h"

template <class T> class Tree; // 전방 선언
template <class T>
class TreeNode
{
	friend class Tree<T>;
private:
	T data;
	TreeNode<T>* rightChild;	// 오른쪽 자식
	TreeNode<T>* leftChild;		// 왼쪽 자식

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

	void deleteTree(TreeNode<T>* currentNode)	// 삭제
	{
		if (currentNode == nullptr)
		{
			return;
		}
		deleteTree(currentNode->getLeftChild());
		deleteTree(currentNode->getRightChild());
		delete currentNode;	// Node 삭제
	}
	TreeNode<T>* updateTree(TreeNode<T>* currentNode)	// 수정
	{
		if (currentNode == nullptr)
		{
			return nullptr;
		}
		// 새로운 Tree를 반환
		return new TreeNode<T>(currentNode->getData(), updateTree(currentNode->getLeftChild()), updateTree(currentNode->getRightChild()));
	}
public:
	Tree()	// 기본 생성자
	{
		root = nullptr;
	}
	Tree(Tree<T>& tree)	// 새로운 트리 생성자
	{
		root = updateTree(tree.getRoot());
	}
	~Tree()	// 소멸자
	{
		deleteTree(root);
	}

	TreeNode<T>* getRoot()
	{
		return root;
	}
	void setRoot(TreeNode<T>* root)
	{
		deleteTree(this->root);	// 기존 Tree 삭제
		this->root = root;	// 새로운 root 할당
	}

	Tree<T>& operator=(const Tree<T>& tree)
	{
		if (this == &tree)
		{
			return *this;
		}
		deleteTree(root);	// 기존 Tree 삭제
		root = updateTree(tree.root);	// 수정된 Tree를 할당

		return *this;
	}
};