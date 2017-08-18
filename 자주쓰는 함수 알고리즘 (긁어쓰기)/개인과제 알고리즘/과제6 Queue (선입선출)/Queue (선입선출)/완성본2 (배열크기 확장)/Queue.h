#pragma once
#include "QueueException.h"

template <typename T>
class Queue // Queue ���Լ��� (First In First Out)
{
private:
	T* queue;
	T data;
	int front; // ����
	int rear; // �Ĵ�
	int capacity;
public:
	Queue()
	{ 
		capacity = 5;
		front = rear = 0; // ť�� �ƹ��� �����Ͱ� ���ٴ� ���� �˸�
		queue = new T[capacity]; // �����迭�� ť�� ũ�⸦ �Ҵ�
	}
	~Queue() { delete[] queue; }

	T* resize()
	{
		T* temp = new T[capacity * 2]; // ������ �迭���� 2�� �� ū �迭�� temp�� �Ҵ�
		for (int i = 0; i < capacity; i++)
		{
			temp[i] = queue[i]; // ������ �迭 ������ 2�� �� ū �迭�� ���� �Ҵ�
		}
		// ������ �迭 ���� �����Ǹ鼭 ũ�Ⱑ �þ

		capacity *= 2; // capacity�� ũ�⸦ 2��� ������ش�. 
		delete[] queue; // arr�� �����Ҵ�� �ּ��� ������ ����
		queue = temp; // arr�� ���θ��� temp�� �ּҸ� �Ҵ�
		return queue;
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

	T& Front() // ť�� ���ܰ����� �����͸� ����
	{
		if (isEmpty() == true)
		{
			throw QueueException(2);
		}
		front = (front + 1) % capacity; // ť�� First In�� �� ������ (��� ������)
		return queue[front];
	}

	void Rear(const T& data) // ť�� �Ĵܰ������� �����͸� �Ҵ�
	{
		if (isFull() == true)
		{
			throw QueueException(1);
		}
		queue[++rear] = data; // ������ �Ҵ� 
	}

	void pushShow() // push ���� ť�� ������ �����ش�.
	{
		try
		{
			cout << "�����͸� �Է��Ͻÿ�. (-1 �Է� �� ����) : ";

			while (1)
			{
				cin >> data;

				if (data == "-1")
				{
					break;
				}

				Rear(data);
			}
		}
		catch (QueueException e)
		{
			if (e.getCode() == 1)
			{
				cout << e.getCode() << " : " << e.getStr() << endl;
			}
			else if (e.getCode() == 2)
			{
				cout << e.getCode() << " : " << e.getStr() << endl;
			}
		}
	}

	void popShow() // pop ���� ������ ������ ������ �����ش�.
	{
		try
		{
			cout << "First In First Out : ";
			cout << Front() << endl;
		}
		catch (QueueException e)
		{
			if (e.getCode() == 1)
			{
				cout << e.getCode() << " : " << e.getStr() << endl;
			}
			else if (e.getCode() == 2)
			{
				cout << e.getCode() << " : " << e.getStr() << endl;
			}
		}
	}

	void QueueShow() // ť�� ���� ������ �����ش�.
	{
		cout << "Queue�� �������" << endl;
		for (int i = front + 1; i <= rear; i++)
		{
			cout << queue[i] << endl;
		}
	}
};