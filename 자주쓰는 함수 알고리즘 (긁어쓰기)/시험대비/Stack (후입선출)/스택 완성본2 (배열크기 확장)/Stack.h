#pragma once
#include "StackException.h"

template <typename T>
class Stack // Stack ���Լ��� (Last In First Out)
{
private:
	T* stack;
	T data;
	int top;
	int capacity;
public:
	Stack() 
	{ 
		capacity = 5;
		top = -1; // ���ÿ� �ƹ��� �����Ͱ� ���ٴ� ���� �˸�
		stack = new T[capacity]; // �����迭�� ������ ũ�⸦ �Ҵ�
	}
	~Stack() { delete[] stack; }

	T* resize()
	{
		T* temp = new T[capacity * 2]; // ������ �迭���� 2�� �� ū �迭�� temp�� �Ҵ�
		for (int i = 0; i < capacity; i++)
		{
			temp[i] = stack[i]; // ������ �迭 ������ 2�� �� ū �迭�� ���� �Ҵ�
		}
		// ������ �迭 ���� �����Ǹ鼭 ũ�Ⱑ �þ

		capacity *= 2; // capacity�� ũ�⸦ 2��� ������ش�. 
		delete[] stack; // arr�� �����Ҵ�� �ּ��� ������ ����
		stack = temp; // arr�� ���θ��� temp�� �ּҸ� �Ҵ�
		return stack;
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
			throw StackException(1);
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
			throw StackException(2);
		}
		else
		{
			return stack[top--]; // ������ �����Ͱ����� �����ϹǷ� ���������κ��� ���� �����͸� �����ְ� ��
		}
	}

	void pushShow() // push ���� ������ ������ �����ش�.
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

				Push(data);
			}
		}
		catch (StackException e)
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
			cout << " Last In First Out : ";
			cout << Pop() << endl;
		}
		catch (StackException e)
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

	void stackShow() // ������ ���� ������ �����ش�.
	{
		cout << "Stack�� �������" << endl;
		for (int i = 0; i <= top; i++)
		{
			cout << stack[i] << endl;
		}
	}
};