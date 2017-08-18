#pragma once
#include <iostream>
#include <fstream>

using namespace std;

const int capacity = 100; // �뷮

template <typename T>
class Queue // Queue ���Լ��� (First In First Out)
{
private:
	T* queue;
	T data;
	int front; // ����
	int rear; // �Ĵ�
public:
	Queue()
	{
		front = rear = 0; // ť�� �ƹ��� �����Ͱ� ���ٴ� ���� �˸�
		queue = new T[capacity]; // �����迭�� ť�� ũ�⸦ �Ҵ�
	}
	~Queue() { delete[] queue; }

	void init()
	{
		cout << "rear: " << rear << " front: " << front << " capacity: " << capacity << endl;
	}

	T& get() const
	{
		return queue[rear];
	}

	bool isFull() const // ť�� ������ �������� �ʾҳ��� �˻��Ѵ�.
	{
		if (rear == capacity - 1) // ť�� ������ ��ȭ�����϶�
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool isEmpty() const // ť�� ������ ����ִ��� �˻��Ѵ�.
	{
		if (front == rear) // ���ܰ� �Ĵ��� ��ġ�� ������ ����ִٰ� �Ǵ�
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void Push(const T& data) // ť�� �Ĵܰ������� �����͸� �Ҵ�
	{
		if (isFull() == true)
		{
			throw "OverFlow";
		}
		queue[++rear] = data; // ������ �Ҵ� 
	}

	T& Pop() // ť�� ���ܰ����� �����͸� ����
	{
		if (isEmpty() == true)
		{
			throw "UnderFlow";
		}
		front = (front + 1) % capacity; // ť�� First In�� �� ������ (��� ������)
		return queue[front];
	}

	void Show() // ť�� ���� ������ �����ش�.
	{
		cout << "Queue�� �������" << endl;
		for (int i = front + 1; i <= rear; i++)
		{
			cout << queue[i] << endl;
		}
	}
};