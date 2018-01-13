#pragma once
#include <iostream>

using namespace std;

const int MAX_STACK_SIZE = 10;

class Stack // Stack 후입선출 (Last In First Out)
{
private:
	int data;
	int* arr;
	int top;
public:
	Stack() 
	{ 
		top = -1; // 스택에 아무런 데이터가 없다는 것을 알림
		arr = new int[MAX_STACK_SIZE]; // 동적배열에 스택의 크기를 할당
	}
	~Stack() {}

	void Push(int data); // 스택의 공간에 데이터를 맨 밑에부터 쌓는다.
	int Pop(); // 스택의 공간에 데이터를 맨 위부터 비운다.
	bool isFull(); // 스택의 공간이 가득차지 않았나를 검사한다.
	bool isEmpty(); // 스택의 공간이 비어있는지 검사한다.
	void Show(); // 스택의 공간을 보여준다.
};