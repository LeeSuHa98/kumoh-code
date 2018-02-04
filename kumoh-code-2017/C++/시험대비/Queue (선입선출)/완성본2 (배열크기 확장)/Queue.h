#pragma once
#include "QueueException.h"

template <typename T>
class Queue // Queue 선입선출 (First In First Out)
{
private:
	T* queue;
	T data;
	int front; // 전단
	int rear; // 후단
	int capacity;
public:
	Queue()
	{ 
		capacity = 5;
		front = rear = 0; // 큐에 아무런 데이터가 없다는 것을 알림
		queue = new T[capacity]; // 동적배열에 큐의 크기를 할당
	}
	~Queue() { delete[] queue; }

	T* resize()
	{
		T* temp = new T[capacity * 2]; // 기존의 배열보다 2배 더 큰 배열을 temp에 할당
		for (int i = 0; i < capacity; i++)
		{
			temp[i] = queue[i]; // 기존의 배열 내용을 2배 더 큰 배열에 복사 할당
		}
		// 기존의 배열 값은 유지되면서 크기가 늘어남

		capacity *= 2; // capacity의 크기를 2배로 만들어준다. 
		delete[] queue; // arr에 동적할당된 주소의 공간을 삭제
		queue = temp; // arr에 새로만든 temp의 주소를 할당
		return queue;
	}

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