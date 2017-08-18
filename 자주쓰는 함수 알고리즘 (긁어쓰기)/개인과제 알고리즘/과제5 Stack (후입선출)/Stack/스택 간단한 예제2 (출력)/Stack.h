#pragma once
#include <iostream>

using namespace std;

const int MAX_STACK_SIZE = 10;

class Stack // Stack ���Լ��� (Last In First Out)
{
private:
	int data;
	int* arr;
	int top;
public:
	Stack() 
	{ 
		top = -1; // ���ÿ� �ƹ��� �����Ͱ� ���ٴ� ���� �˸�
		arr = new int[MAX_STACK_SIZE]; // �����迭�� ������ ũ�⸦ �Ҵ�
	}
	~Stack() {}

	void Push(int data); // ������ ������ �����͸� �� �ؿ����� �״´�.
	int Pop(); // ������ ������ �����͸� �� ������ ����.
	bool isFull(); // ������ ������ �������� �ʾҳ��� �˻��Ѵ�.
	bool isEmpty(); // ������ ������ ����ִ��� �˻��Ѵ�.
	void Show(); // ������ ������ �����ش�.
};