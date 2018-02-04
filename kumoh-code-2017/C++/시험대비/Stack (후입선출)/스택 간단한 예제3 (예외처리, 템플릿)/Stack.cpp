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
		top++; // -1로 초기화된 상태에서 증가하므로 0부터 공간이 생김
		arr[top] = data; // 증가된 공간에 데이터 값을 할당
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
		data = arr[top]; // 마지막 데이터 값에 배열을 할당
		top--; // 마지막 데이터값에서 증감하므로 마지막으로부터 전의 데이터를 보여주게 됨
		return data;
	}
}
template <typename T>
bool Stack<T>::isFull() const
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
template <typename T>
bool Stack<T>::isEmpty() const
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
template <typename T>
void Stack<T>::Show()
{
	int count;

	try
	{
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