#pragma once
#include "QueueException.h"

const int capacity = 10; // 용량

template <typename T>
class Queue // Queue 선입선출 (First In First Out)
{
private:
	T* queue;
	T data;
	int front; // 전단
	int rear; // 후단
public:
	Queue()
	{ 
		front = rear = 0; // 큐에 아무런 데이터가 없다는 것을 알림
		queue = new T[capacity]; // 동적배열에 큐의 크기를 할당
	}
	~Queue() { delete[] queue; }

	bool isFull() const // 큐의 공간이 가득차지 않았나를 검사한다.
	{
		if (rear == capacity - 1) // 큐의 공간이 포화상태일때
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool isEmpty() const // 큐의 공간이 비어있는지 검사한다.
	{
		if (front == rear) // 전단과 후단의 위치가 같으면 비어있다고 판단
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	T& Front() // 큐의 전단공간에 데이터를 삭제
	{
		if (isEmpty() == true)
		{
			throw QueueException(2);
		}
		front = (front + 1) % capacity; // 큐의 First In을 뺀 나머지 (계속 증가함)
		return queue[front];
	}
	void Rear(const T& data) // 큐의 후단공간부터 데이터를 할당
	{
		if (isFull() == true)
		{
			throw QueueException(1);
		}
		queue[++rear] = data; // 데이터 할당 
	}

	void pushShow() // push 이후 큐의 공간을 보여준다.
	{
		try
		{
			cout << "데이터를 입력하시오. (-1 입력 시 종료) : ";

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

	void popShow() // pop 이후 스택의 마지막 공간을 보여준다.
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

	void QueueShow() // 큐의 현재 공간을 보여준다.
	{
		cout << "Queue의 현재공간" << endl;
		for (int i = front + 1; i <= rear; i++)
		{
			cout << queue[i] << endl;
		}
	}
};