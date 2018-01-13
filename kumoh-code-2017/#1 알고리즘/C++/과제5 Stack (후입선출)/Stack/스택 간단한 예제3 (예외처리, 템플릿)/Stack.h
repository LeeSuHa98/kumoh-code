#pragma once
#include "StackException.h"

const int MAX_STACK_SIZE = 5;

template <typename T>
class Stack // Stack ���Լ��� (Last In First Out)
{
private:
	T* arr;
	T data;
	int top;
public:
	Stack() 
	{ 
		top = -1; // ���ÿ� �ƹ��� �����Ͱ� ���ٴ� ���� �˸�
		arr = new T[MAX_STACK_SIZE]; // �����迭�� ������ ũ�⸦ �Ҵ�
	}
	~Stack() {}

	void Push(); // ������ ������ �����͸� �� �ؿ����� �״´�.
	T Pop(); // ������ ������ �����͸� �� ������ ����.
	bool isFull() const; // ������ ������ �������� �ʾҳ��� �˻��Ѵ�.
	bool isEmpty() const; // ������ ������ ����ִ��� �˻��Ѵ�.
	void Show(); // ������ ������ �����ش�.
};