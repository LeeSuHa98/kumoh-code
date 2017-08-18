#pragma once
#include <iostream>
#include <fstream>

using namespace std;

const int capacity = 100; // 용량

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

	void init()
	{
		cout << "rear: " << rear << " front: " << front << " capacity: " << capacity << endl;
	}

	T& get() const
	{
		return queue[rear];
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

	void Push(const T& data) // 큐의 후단공간부터 데이터를 할당
	{
		if (isFull() == true)
		{
			throw "OverFlow";
		}
		queue[++rear] = data; // 데이터 할당 
	}

	T& Pop() // 큐의 전단공간에 데이터를 삭제
	{
		if (isEmpty() == true)
		{
			throw "UnderFlow";
		}
		front = (front + 1) % capacity; // 큐의 First In을 뺀 나머지 (계속 증가함)
		return queue[front];
	}

	void Show() // 큐의 현재 공간을 보여준다.
	{
		cout << "Queue의 현재공간" << endl;
		for (int i = front + 1; i <= rear; i++)
		{
			cout << queue[i] << endl;
		}
	}
};