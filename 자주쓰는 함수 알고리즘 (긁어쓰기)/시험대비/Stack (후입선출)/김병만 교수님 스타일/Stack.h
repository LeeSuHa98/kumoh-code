#pragma once
#include <iostream>

using namespace std;

const int capacity = 10;

template <typename T>
class Stack // Stack ���Լ��� (Last In First Out)
{
private:
	T* stack;
	T data;
	int top;
public:
	Stack()
	{
		top = -1; // ���ÿ� �ƹ��� �����Ͱ� ���ٴ� ���� �˸�
		stack = new T[capacity]; // �����迭�� ������ ũ�⸦ �Ҵ�
	}
	~Stack() { delete[] stack; }

	void init()
	{
		cout << "top: " << top << " capacity: " << capacity << endl;
	}

	T& get() const
	{
		return stack[top];
	}

	bool isFull() const // ������ ������ �������� �ʾҳ��� �˻��Ѵ�.
	{
		if (top == capacity - 1) // ������ ��ȭ�����϶�
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool isEmpty() const // ������ ������ ����ִ��� �˻��Ѵ�.
	{
		if (top == -1) // ���ÿ� �ƹ��� �����Ͱ� ������
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void Push(const T& data) // ������ ������ �����͸� �� �ؿ����� �״´�.
	{
		if (isFull() == true)
		{
			throw "OverFlow";
		}
		else
		{
			// -1�� �ʱ�ȭ�� ���¿��� �����ϹǷ� 0���� ������ ����
			stack[++top] = data; // ������ ������ ������ ���� �Ҵ�
		}
	}

	T& Pop() // ������ ������ �����͸� �� ������ ����.
	{
		if (isEmpty() == true)
		{
			throw "UnderFlow";
		}
		else
		{
			return stack[top--]; // ������ �����Ͱ����� �����ϹǷ� ���������κ��� ���� �����͸� �����ְ� ��
		}
	}

	void Show() // ������ ���� ������ �����ش�.
	{
		cout << "Stack�� �������" << endl;
		for (int i = 0; i <= top; i++)
		{
			cout << stack[i] << endl;
		}
	}
};