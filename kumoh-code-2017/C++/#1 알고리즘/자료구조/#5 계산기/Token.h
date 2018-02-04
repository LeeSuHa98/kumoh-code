#pragma once
typedef union
{
	int operand; // operand
	char oper; // operator
}token;

class Token
{
private:
	token item;
	bool is_operand;

public:
	Token() {}
	Token(char oper)
	{
		item.oper = oper;
		is_operand = false;
	}
	~Token(){}

	void set(int operand)
	{
		item.operand = operand;
		is_operand = true;
	}
	void set(char oper)
	{
		item.oper = oper;
		is_operand = false;
	}
	bool isOperand()
	{
		return is_operand;
	}

	char getOper() const { return item.oper; }
	int getValue() const { return item.operand; }
};