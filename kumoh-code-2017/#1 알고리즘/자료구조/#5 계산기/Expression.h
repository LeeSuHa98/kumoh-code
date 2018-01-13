#pragma once
#include "Stack.h"
#include "Token.h"
#include <math.h>
#include <string>
#include <iostream>

using namespace std;

class Expression
{
private:
	int capacity;
	int size;
	Token* tokens;
public:
	Expression() 
	{ 
		capacity = 10;
		size = 0;
		tokens = new Token[capacity];
	}
	Expression(int capacity)
	{
		this->capacity = capacity;
		size = 0;
		tokens = new Token[capacity];
	}
	Expression(const Expression& e)
	{
		capacity = e.capacity;
		size = e.size;
		tokens = new Token[capacity];

		for (int i = 0; i < size; ++i)
		{
			tokens[i] = e.tokens[i];
		}
	}
	~Expression() { delete[] tokens; }

	int eval();	// �� ��
	void toPostfix();	// ������������� ����
	void setExpression(string e);	// string ������ ���� expression ������ ������ �ٲ۴�

	void ChangeSizeID(const int newSize);
	void add(int value);
	void add(char oper);

	// expression reference const
	Expression& operator=(const Expression& erc);
	friend ostream& operator<<(ostream& os, const Expression& erc);

	int isp(char oper);	// in stack priority
	int icp(char oper);	// in coming priority
	int calculate(int val1, int val2, char oper);
	int stoi(int& idx, const string& e);	// string to int
};