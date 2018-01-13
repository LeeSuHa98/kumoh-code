#include "Stack.h"

void Stack::Push(int data)
{
	if (isFull())
	{
		cout << " overflow " << endl; // ������ ������ ��ȭ����
	}
	else
	{
		top++; // -1�� �ʱ�ȭ�� ���¿��� �����ϹǷ� 0���� ������ ����
		arr[top] = data; // ������ ������ ������ ���� �Ҵ�
	}
}

int Stack::Pop()
{
	if (isEmpty())
	{
		cout << " underflow " << endl; // ������ ������ �ƹ��� �����Ͱ� ������
	}
	else
	{
		int data = arr[top]; // ������ ������ ���� �迭�� �Ҵ�
		top--; // ������ �����Ͱ����� �����ϹǷ� ���������κ��� ���� �����͸� �����ְ� ��
		return data;
	}
}

bool Stack::isFull()
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

bool Stack::isEmpty()
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

void Stack::Show()
{
	int data;
	int count;

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