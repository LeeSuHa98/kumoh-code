#include "Expression.h"

int Expression::eval()
{
	Stack<int> operand_stack;
	int val1, val2, result;

	for (int i = 0; i < size; ++i)
	{
		if (tokens[i].isOperand())
		{
			operand_stack.Push(tokens[i].getValue());
		}
		else
		{
			if (tokens[i].getOper() == '~')
			{
				val1 = operand_stack.Top();
				operand_stack.Pop();
				operand_stack.Push(-val1);
			}
			else
			{
				val2 = operand_stack.Top();
				operand_stack.Pop();
				val1 = operand_stack.Top();
				operand_stack.Pop();

				result = calculate(val1, val2, tokens[i].getOper());
				operand_stack.Push(result);
			}
		}
	}

	return operand_stack.Top();
}

void Expression::toPostfix()
{
	Token* postfix = new Token[capacity];
	Stack<char> operator_stack;

	int idx = -1;
	int parenthesisN = 0;	// '(' ')' ������ ������ �Ǹ������� size ���� ���ش�.

	operator_stack.Push('#');
	for (int i = 0; i < size; ++i)
	{
		if (tokens[i].isOperand())	// operand�� ��� �׳� ���� �ִ´�.
		{
			postfix[++idx] = tokens[i];
		}
		else if (tokens[i].getOper() == ')')
		{
			parenthesisN++;
			while (operator_stack.Top() != '(')
			{
				postfix[++idx] = operator_stack.Top();
				operator_stack.Pop();
			}
			operator_stack.Pop();	// '(' �� ���ش�.
		}
		else
		{
			if (tokens[i].getOper() == '(')
			{
				parenthesisN++;
			}
			while (isp(operator_stack.Top()) >= icp(tokens[i].getOper()))	// ������ token�� operator���� ���ÿ� ����ִ� operatoar�� �켱������ ���� ��� �����ش�.
			{
				postfix[++idx] = operator_stack.Top();
				operator_stack.Pop();
			}
			operator_stack.Push(tokens[i].getOper());
		}
	}

	while (operator_stack.Top() != '#')
	{
		postfix[++idx] = operator_stack.Top();
		operator_stack.Pop();
	}

	delete[] tokens;
	tokens = postfix;
	size -= parenthesisN;
}

void Expression::setExpression(string e)
{
	size = 0;

	int parenthesisN;		// ��ȣ ����ó���� ����.
	bool previous_operator;	// true: ������ operator�� ����
							// false: ������ operator�� ������ ����(operand�� ����)
	parenthesisN = 0;
	previous_operator = true;
	for (int i = 0; i < e.length(); ++i)
	{
		switch (e[i])
		{
		case '^':
		case '*':
		case '/':
		case '%':
		case '+':
			if (previous_operator) throw "������ �� ���� ����";	// �����ڰ� �������� ������ ����
			add(e[i]);
			previous_operator = true;
			break;
		case '-':
			if (previous_operator)
				add('~');	// ������ operator�� �������Ƿ� minus�������̴�.
			else
			{
				previous_operator = true;
				add('-');
			}
			break;
		case '!':	// ���� ������
			if (previous_operator)
			{
				previous_operator = true;	// -!0
				add('!');
			}
			else
			{
				previous_operator = true;	// 1!0
				add('!');
			}
			break;
		case '(':
			if (!previous_operator) throw "������ �� ���� ����";	// operand����  '('�� ������ ��.
			parenthesisN++;
			add('(');
			break;
		case ')':
			if (previous_operator) throw "������ �� ���� ����";	// operator ���� ')' �� ������ ��.
			parenthesisN--;

			if (parenthesisN < 0) throw "��ȣ�� ¦�� ���� �ʽ��ϴ�";	// �ݴ� ��ȣ�� �� ���� ����.
			add(')');
			break;
		case ' ':
			break;
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			if (!previous_operator) throw "������ �� ���� ����";	// ������ �о����� �ǿ������϶�. �ǿ����ڰ� �������� ������ ����

			add(stoi(i, e));

			previous_operator = false;
			break;

		default:
			throw "������ �� ���� ����";
		}	// end of switch
	}		// end of for i

	if (parenthesisN > 0) throw "��ȣ�� ¦�� ���� �ʽ��ϴ�";

	if (previous_operator) throw "������ �� ���� ����";	// �������� �о��°� ������ �϶�.

	return;
}

void Expression::ChangeSizeID(const int newSize)
{
	if (newSize < size) throw "New size must be >= number of size";
	Token* temp = new Token[newSize];

	for (int i = 0; i < size; ++i)
	{
		temp[i] = tokens[i];
	}
	delete[] tokens;

	tokens = temp;
	capacity = newSize;
}

void Expression::add(int value)
{
	if (size == capacity)
	{
		ChangeSizeID(capacity * 2);
	}
	tokens[size++].set(value);
}

void Expression::add(char oper)
{
	if (size == capacity)
	{
		ChangeSizeID(capacity * 2);
	}
	tokens[size++].set(oper);
}

Expression& Expression::operator=(const Expression& erc)
{
	if (capacity < erc.size)
	{
		capacity = erc.capacity;
		delete[] tokens;
		tokens = new Token[capacity];
	}

	for (int i = 0; i < erc.size; ++i)
	{
		tokens[i] = erc.tokens[i];
	}
	size = erc.size;

	return *this;
}

ostream& operator<<(ostream& os, const Expression& erc)
{
	for (int i = 0; i < erc.size; ++i)
	{
		if (erc.tokens[i].isOperand())
		{
			os << erc.tokens[i].getValue() << " ";
		}
		else
		{
			os << erc.tokens[i].getOper() << " ";
		}
	}
	return os;
}

int Expression::isp(char oper)
{
	switch (oper)
	{
	case '~':
	case '!':
		return 5;
	case '^':
		return 4;
	case '*':
	case '/':
	case '%':
		return 3;
	case '+':
	case '-':
		return 2;
	case '(':
		return 1;
	case '#':
		return 0;
	}
}

int Expression::icp(char oper)
{
	switch (oper)
	{
	case '(':
		return 7;
	case '~':	// ���� �����ڰ� ���þȿ� ������ �������� �ʵ��� isp�켱���� ���� ����
	case '!':
		return 6;
	case '^':
		return 4;
	case '*': 
	case '/': 
	case '%':
		return 3;
	case '+': 
	case '-':
		return 2;
	case '#':
		return 0;
	}
}

int Expression::calculate(int val1, int val2, char oper)
{
	switch (oper)
	{
	case '-':
		return val1 - val2;
	case '+':
		return val1 + val2;
	case '*':
		return val1 * val2;
	case '/':
		if (val2 == 0)
			throw "������ ������ �ι�° �ǿ����ڰ� 0�� ��� �߻�";
		return val1 / val2;
	case '%':
		if (val2 == 0)
			throw "������ ������ �ι�° �ǿ����ڰ� 0�� ��� �߻�";
		return val1 % val2;
	case '^':
		return int(pow(double(val1), double(val2)));
	}
}

int Expression::stoi(int& idx, const string& e)
{
	int val = 0;
	while (idx < e.length() && '0' <= e[idx] && e[idx] <= '9')
	{
		val = (val * 10) + (e[idx++] - '0');
	}
	idx--;

	return val;
}