#pragma once
#include <iostream>
using namespace std;

template <class T>
class Queue
{	// 0개 이상의 원소를 가진 유한 순서 리스트
private:
	T* queue;	// 큐의 원소를 위한 배열
	int front;	// 첫 번째 원소로부터 반시계 방향으로 한 위치 뒤
	int rear;	// 마지막 원소의 위치
	int capacity;	// 큐 배열의 크기

public:
	Queue(int queueCapacity = 10);	// 처음에 크기가 queueCapacity인 공백 큐를 생성
	~Queue();

	bool isEmpty() const;	// 큐의 전단과 후단의 원소가 같으면 비어있다고 판단
	T& Front() const;	// 큐의 앞에 있는 원소를 반환
	T& Rear() const;	// 큐의 뒤에 있는 원소를 반환
	void Push(const T& item);	// 큐의 뒤에 item을 삽입
	void Pop();	// 큐의 앞 원소를 삭제
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
	{	// 큐가 만원이면 크기를 두 배로
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

		// newQueue로 전환
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
{// 큐로부터 원소를 삭제한다.
	if (isEmpty()) throw "Queue is empty. Cannot delete.";
	front = (front + 1) % capacity;
	queue[front].~T();	// T를 위한 파괴자
}