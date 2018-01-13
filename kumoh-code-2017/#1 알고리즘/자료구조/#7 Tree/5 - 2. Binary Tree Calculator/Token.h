#pragma once
#include <iostream>
#include <string>

using namespace std;

typedef union
{
	int operand;	// operand ( �ǿ����� )
	char oper;	// operator	( ������ )
}token;

class Token
{
private:
	token item;	// union token
	bool isFlag;	// flag variable
public:
	Token() {}
	Token(char oper)
	{
		item.oper = oper;
		isFlag = false;
	}
	~Token() {}

	bool isOperand() { return isFlag; }
	void setOperator(char oper) { item.oper = oper; isFlag = false; }	// ������ : false
	char getOperator() const { return item.oper; }
	void setOperand(int operand) { item.operand = operand; isFlag = true; }	// �ǿ����� : true
	int getOperand() const { return item.operand; }
};