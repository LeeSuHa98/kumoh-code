#include "Stack.h"

void Stack::push(int data)
{
	if (isFull())
	{
		cout << " overflow " << endl;
	}
	else
	{
		top++;
		arr[top] = data;
	}
}

int Stack::pop()
{
	if (isEmpty())
	{
		cout << " underflow " << endl;
	}
	else
	{
		int data = arr[top];
		top--;
		return data;
	}
}

bool Stack::isFull()
{
	if (top == MAX_STACK_SIZE - 1)
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
	if (top == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}