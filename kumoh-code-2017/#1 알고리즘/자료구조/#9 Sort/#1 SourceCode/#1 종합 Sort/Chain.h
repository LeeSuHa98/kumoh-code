#pragma once
#include "Node.h"

template <class T>
class Chain
{
private:
	Node<T>* head;
	Node<T>* currPtr;
	void deleteChain();

public:
	Chain();
	~Chain();

	void setCurrToFirst();
	void setCurrToNext();
	T getCurrData();
	void insertNode(T data);
	void insertionSort();
	void print()
	{
		currPtr = head->link;
		while (currPtr)
		{
			printf_s("%d ", currPtr->data);
			currPtr = currPtr->link;
		}
		printf_s("\n");
	}
};

template <class T>
void Chain<T>::deleteChain()
{
	while (!head->link)
	{
		Node<T>* temp = head->link;
		head->link = head->link->link;
		delete temp;
	}

	delete head;
}

template <class T>
Chain<T>::Chain()
{
	head = new Node<T>();
	currPtr = head;
}

template <class T>
Chain<T>::~Chain()
{
	deleteChain();
}

template<class T>
void Chain<T>::setCurrToFirst()
{
	currPtr = head;
}

template<class T>
void Chain<T>::setCurrToNext()
{
	currPtr = currPtr->link;
}

template<class T>
T Chain<T>::getCurrData()
{
	return currPtr->data;
}

template<class T>
void Chain<T>::insertNode(T data)
{
	Node<T>* newNode = new Node<T>(data);
	newNode->link = head->link;
	head->link = newNode;
}

template <class T>
void Chain<T>::insertionSort()
{
	Node<T>* compPtr;
	currPtr = head;

	while (true)
	{
		if (!currPtr || !currPtr->link)
		{
			break;
		}

		compPtr = head;
		while (compPtr != currPtr)
		{
			if (compPtr->link->data > currPtr->link->data)
			{
				Node<T>* temp = currPtr->link;
				currPtr->link = currPtr->link->link;
				temp->link = compPtr->link;
				compPtr->link = temp;
				break;
			}
			compPtr = compPtr->link;
		}
		if (compPtr == currPtr)
		{
			currPtr = currPtr->link;
		}
	}
}
