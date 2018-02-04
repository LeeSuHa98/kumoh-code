#pragma once
#include <iostream>
using namespace std;

template <class T>
class Queue
{	// 0�� �̻��� ���Ҹ� ���� ���� ���� ����Ʈ
private:
	T* queue;	// ť�� ���Ҹ� ���� �迭
	int front;	// ù ��° ���ҷκ��� �ݽð� �������� �� ��ġ ��
	int rear;	// ������ ������ ��ġ
	int capacity;	// ť �迭�� ũ��

public:
	Queue(int queueCapacity = 10);	// ó���� ũ�Ⱑ queueCapacity�� ���� ť�� ����
	~Queue();

	bool isEmpty() const;	// ť�� ���ܰ� �Ĵ��� ���Ұ� ������ ����ִٰ� �Ǵ�
	T& Front() const;	// ť�� �տ� �ִ� ���Ҹ� ��ȯ
	T& Rear() const;	// ť�� �ڿ� �ִ� ���Ҹ� ��ȯ
	void Push(const T& item);	// ť�� �ڿ� item�� ����
	void Pop();	// ť�� �� ���Ҹ� ����
};

template<class T>
Queue<T>::Queue(int queueCapacity) : capacity(queueCapacity)
{
	if (capacity < 1)
	{
		capacity = 10;
		throw "Queue capacity must be > 0, So the current capacity : 10";
	}

	queue = new T[capacity];
	front = rear = 0;
}

template<class T>
Queue<T>::~Queue(void)
{
	if (!queue)
	{
		delete[] queue;
	}
}

template<class T>
bool Queue<T>::isEmpty() const
{
	return front == rear;
}

template<class T>
T& Queue<T>::Front() const
{
	if (isEmpty()) throw "Queue is empty. No front element";
	return queue[(front + 1) % capacity];
}

template<class T>
T& Queue<T>::Rear() const
{
	if (isEmpty()) throw "Queue is empty. No rear element";
	return queue[rear];
}

template<class T>
void Queue<T>::Push(const T& x)
{
	if ((rear + 1) % capacity == front)
	{	// ť�� �����̸� ũ�⸦ �� ���
		T* newQueue = new T[2 * capacity];

		int start = (front + 1) % capacity;

		if (start < 2)
		{
			for (int i = 0; i < capacity; i++)
			{
				newQueue[i] = queue[i];
			}
		}
		else
		{
			for (int i = 0; i < capacity; i++)
			{
				if (start > i)
				{
					newQueue[capacity - start + i] = queue[i];
				}
				else if (start <= i)
				{
					newQueue[start - i] = queue[i];
				}
			}
		}

		// newQueue�� ��ȯ
		front = 2 * capacity - 1;
		rear = capacity - 2;
		capacity *= 2;
		delete[] queue;
		queue = newQueue;
	}

	rear = (rear + 1) % capacity;
	queue[rear] = x;
}

template<class T>
void Queue<T>::Pop()
{// ť�κ��� ���Ҹ� �����Ѵ�.
	if (isEmpty()) throw "Queue is empty. Cannot delete.";
	front = (front + 1) % capacity;
	queue[front].~T();	// T�� ���� �ı���
}