#pragma once
#include <iostream>

using namespace std;

const int MAX_STACK_SIZE = 10;

class Stack
{
private:
	int data;
	int* arr;
	int top;
public:
	Stack() 
	{ 
		top = -1;
		arr = new int[MAX_STACK_SIZE];
	}
	~Stack() {}

	void push(int data);
	int pop();
	bool isFull();
	bool isEmpty();
};