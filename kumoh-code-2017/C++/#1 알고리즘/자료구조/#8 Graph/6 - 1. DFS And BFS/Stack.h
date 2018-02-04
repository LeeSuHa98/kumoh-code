#pragma once

template <class T>
class Stack
{
private:
	int capacity;
	T* stack;
	int top;
public:
	Stack()
	{
		capacity = 10;
		stack = new T[capacity];
		top = -1;
	}
	Stack(int capacity)
	{
		this->capacity = capacity;
		if (capacity < 1) throw "Stack capacity must be > 0 !";

		stack = new T[capacity];
		top = -1;
	}
	Stack(const Stack& s) // Deep Copy
	{
		this->capacity = s.capacity;
		this->top = s.top;

		stack = new T[capacity];
		copy(s.stack, s.stack + Top, stack);
	}
	~Stack() { delete[] stack; }

	void ChangeSizeID(const int newSize)
	{
		if (newSize < top) throw "New length must be >= 0 !";
		T* temp = new T[newSize];

		for (int i = 0; i < top; ++i)
		{
			temp[i] = stack[i];
		}
		delete[] stack;

		stack = temp;
		capacity = newSize;
	}

	inline bool IsEmpty() const
	{
		return top == -1;
	}

	inline T& Top() const
	{
		if (IsEmpty()) throw "Stack is empty!";

		return stack[top];
	}

	void Push(const T& item)
	{
		if (top == capacity - 1)
		{
			ChangeSizeID(2 * capacity);
		}

		stack[++top] = item;
	}
	void Pop()
	{
		if (IsEmpty()) throw "Stack is empty. Cannot delete.";
		stack[top--].~T();
	}

	int getTop() { return top; }
};