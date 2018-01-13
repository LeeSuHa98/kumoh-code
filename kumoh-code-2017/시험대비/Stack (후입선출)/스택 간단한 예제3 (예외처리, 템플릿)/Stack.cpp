#include "Stack.h"

template <typename T>
void Stack<T>::Push()
{
	if (isFull() == true)
	{
		throw StackException(1);
	}
	else
	{
		top++; // -1�� �ʱ�ȭ�� ���¿��� �����ϹǷ� 0���� ������ ����
		arr[top] = data; // ������ ������ ������ ���� �Ҵ�
	}
}
template <typename T>
T Stack<T>::Pop()
{
	if (isEmpty() == true)
	{
		throw StackException(2);
	}
	else
	{
		data = arr[top]; // ������ ������ ���� �迭�� �Ҵ�
		top--; // ������ �����Ͱ����� �����ϹǷ� ���������κ��� ���� �����͸� �����ְ� ��
		return data;
	}
}
template <typename T>
bool Stack<T>::isFull() const
{
	if (top == MAX_STACK_SIZE - 1) // ������ ��ȭ�����϶�
	{
		return true;
	}
	else
	{
		return false;
	}
}
template <typename T>
bool Stack<T>::isEmpty() const
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
template <typename T>
void Stack<T>::Show()
{
	int count;

	try
	{
		cout << " count : ";
		cin >> count;

		cout << " ������ : " << endl;
		for (int i = 0; i < count; i++)
		{
			cin >> data;
			Push(data);
		}

		for (int i = 0; i < count; i++)
		{
			cout << Pop() << endl;
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