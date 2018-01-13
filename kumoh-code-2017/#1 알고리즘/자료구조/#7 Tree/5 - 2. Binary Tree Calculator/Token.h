#pragma once
#include <iostream>
#include <string>

using namespace std;

typedef union
{
	int operand;	// operand ( 피연산자 )
	char oper;	// operator	( 연산자 )
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
	void setOperator(char oper) { item.oper = oper; isFlag = false; }	// 연산자 : false
	char getOperator() const { return item.oper; }
	void setOperand(int operand) { item.operand = operand; isFlag = true; }	// 피연산자 : true
	int getOperand() const { return item.operand; }
};