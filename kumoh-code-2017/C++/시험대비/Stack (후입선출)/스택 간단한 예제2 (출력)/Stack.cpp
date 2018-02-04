#include "Stack.h"

void Stack::Push(int data)
{
	if (isFull())
	{
		cout << " overflow " << endl; // 스택의 공간이 포화상태
	}
	else
	{
		top++; // -1로 초기화된 상태에서 증가하므로 0부터 공간이 생김
		arr[top] = data; // 증가된 공간에 데이터 값을 할당
	}
}

int Stack::Pop()
{
	if (isEmpty())
	{
		cout << " underflow " << endl; // 스택의 공간에 아무런 데이터가 없을때
	}
	else
	{
		int data = arr[top]; // 마지막 데이터 값에 배열을 할당
		top--; // 마지막 데이터값에서 증감하므로 마지막으로부터 전의 데이터를 보여주게 됨
		return data;
	}
}

bool Stack::isFull()
{
	if (top == MAX_STACK_SIZE - 1) // 스택이 포화상태일때
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
	if (top == -1) // 스택에 아무런 데이터가 없을때
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

	cout << " 데이터 : " << endl;
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