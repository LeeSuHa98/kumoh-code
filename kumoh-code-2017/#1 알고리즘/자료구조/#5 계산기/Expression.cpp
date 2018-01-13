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
	int parenthesisN = 0;	// '(' ')' 개수를 세고나서 맨마지막에 size 에서 빼준다.

	operator_stack.Push('#');
	for (int i = 0; i < size; ++i)
	{
		if (tokens[i].isOperand())	// operand인 경우 그냥 집어 넣는다.
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
			operator_stack.Pop();	// '(' 를 빼준다.
		}
		else
		{
			if (tokens[i].getOper() == '(')
			{
				parenthesisN++;
			}
			while (isp(operator_stack.Top()) >= icp(tokens[i].getOper()))	// 현재의 token의 operator보다 스택에 들어있는 operatoar의 우선순위가 높을 경우 꺼내준다.
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

	int parenthesisN;		// 괄호 예외처리를 위해.
	bool previous_operator;	// true: 이전에 operator가 나옴
							// false: 이전에 operator가 나오지 않음(operand가 나옴)
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
			if (previous_operator) throw "이해할 수 없는 수식";	// 연산자가 연속으로 나오면 오류
			add(e[i]);
			previous_operator = true;
			break;
		case '-':
			if (previous_operator)
				add('~');	// 이전에 operator가 나왔으므로 minus연산자이다.
			else
			{
				previous_operator = true;
				add('-');
			}
			break;
		case '!':	// 단항 연산자
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
			if (!previous_operator) throw "이해할 수 없는 수식";	// operand이후  '('가 나왔을 때.
			parenthesisN++;
			add('(');
			break;
		case ')':
			if (previous_operator) throw "이해할 수 없는 수식";	// operator 이후 ')' 가 나왔을 때.
			parenthesisN--;

			if (parenthesisN < 0) throw "괄호의 짝이 맞지 않습니다";	// 닫는 괄호가 더 많아 질때.
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
			if (!previous_operator) throw "이해할 수 없는 수식";	// 이전에 읽었던게 피연산자일때. 피연산자가 연속으로 나오면 오류

			add(stoi(i, e));

			previous_operator = false;
			break;

		default:
			throw "이해할 수 없는 수식";
		}	// end of switch
	}		// end of for i

	if (parenthesisN > 0) throw "괄호의 짝이 맞지 않습니다";

	if (previous_operator) throw "이해할 수 없는 수식";	// 마지막에 읽었는게 연산자 일때.

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
	case '~':	// 단항 연산자가 스택안에 있을때 꺼내지지 않도록 isp우선순위 보다 높음
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
			throw "나누기 연산의 두번째 피연산자가 0인 경우 발생";
		return val1 / val2;
	case '%':
		if (val2 == 0)
			throw "나머지 연산의 두번째 피연산자가 0인 경우 발생";
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