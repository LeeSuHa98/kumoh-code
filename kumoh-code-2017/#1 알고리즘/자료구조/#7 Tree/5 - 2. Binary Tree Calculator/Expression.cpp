#include "Expression.h"

void Expression::toTree()
{
	Stack<char> operatorStack;	// 연산자 Stack 초기화
	Stack<TreeNode<Token>*> operandStack;	// 피연산자 Stack 초기화

	operatorStack.Push('#');	// Stack 삽입
	for (int i = 0; i < size; ++i)
	{
		if (tokens[i].isOperand())	// 연산식의 Token이 피연산자인 경우
		{
			operandStack.Push(new TreeNode<Token>(tokens[i]));	// Stack Push
		}
		else if (tokens[i].getOperator() == ')')	// Token이 닫는 괄호인 경우
		{
			while (operatorStack.Top() != '(')	// Top의 위치에 여는 괄호가 아닌 경우 : 닫는 괄호인 경우
			{
				Token operatorToken = operatorStack.Top();	// Top부터 연산자 Token에 할당
				TreeNode<Token>* operatorNode = new TreeNode<Token>(operatorToken);	// TreeNode에 할당

				if (operatorToken.getOperator() == '~')	// 연산자가 ~인 경우
				{
					TreeNode<Token>* childToken = operandStack.Top();	// 피연산자 Stack의 Top을 자식 Token에 할당
					operandStack.Pop();									// Stack의 Pop()을 호출할때 소멸자가 호출
					operatorNode->setRightChild(childToken);			// 오른쪽 자식의 노드에 값을 할당
				}
				else
				{	// 그 외의 경우
					TreeNode<Token>* rightChild = operandStack.Top();	// 오른쪽 자식에 Stack의 Top()에 있는 연산식을 할당
					operandStack.Pop();									// Stack의 Pop()을 호출할때 소멸자가 호출
					TreeNode<Token>* leftChild = operandStack.Top();	// 왼쪽 자식에 Stack의 Top()에 있는 연산식을 할당
					operandStack.Pop();
					operatorNode->setLeftChild(leftChild);				// 왼쪽 자식의 노드에 값을 할당
					operatorNode->setRightChild(rightChild);			// 오른쪽 자식의 노드에 값을 할당
				}

				// 연산자 노드를 하나의 피연산자로 본다.
				operandStack.Push(operatorNode);

				operatorStack.Pop();
			}
			operatorStack.Pop();	// '(' 를 빼준다.
		}
		else
		{	// Token이 Operator인 경우
			while (isp(operatorStack.Top()) >= icp(tokens[i].getOperator()))	// 현재 Token의 연산자보다 Stack에 들어있는 연산자의 우선순위가 높은 경우
			{
				Token operatorToken = operatorStack.Top();	// 연산자의 Token에 Top에 있는 연산자 값을 할당
				TreeNode<Token>* operatorNode = new TreeNode<Token>(operatorToken);	// 연산자 값을 연산자 Node에 할당

				if (operatorToken.getOperator() == '~')
				{
					TreeNode<Token>* childToken = operandStack.Top();	// 피연산자 Stack의 Top을 자식 Token에 할당
					operandStack.Pop();									// Stack에 Pop()을 호출할때 소멸자가 호출되므로 주의!
					operatorNode->setRightChild(childToken);			// 오른쪽 자식의 노드에 값을 할당
				}
				else
				{
					TreeNode<Token>* rightChild = operandStack.Top();	// 오른쪽 자식에 Stack의 Top()에 있는 연산식을 할당
					operandStack.Pop();
					TreeNode<Token>* leftChild = operandStack.Top();	// 왼쪽 자식에 Stack의 Top()에 있는 연산식을 할당
					operandStack.Pop();

					operatorNode->setLeftChild(leftChild);
					operatorNode->setRightChild(rightChild);
				}

				// 연산자 노드를 하나의 피연산자로 본다.
				operandStack.Push(operatorNode);

				operatorStack.Pop();
			}	// end while
			operatorStack.Push(tokens[i].getOperator());
		}	// end else
	}

	while (operatorStack.Top() != '#')
	{
		Token operatorToken = operatorStack.Top();	// 연산자의 Token에 Top에 있는 연산자 값을 할당

		TreeNode<Token>* operatorNode = new TreeNode<Token>(operatorToken);	// 연산자 값을 연산자 Node에 할당

		if (operatorToken.getOperator() == '~')
		{	// 마이너스 연산자는 오른쪽 자식을 가져야 한다(중위순회를 통해 알 수 있다)
			TreeNode<Token>* childToken = operandStack.Top();
			operandStack.Pop();									// Stack에 Pop()을 호출할때 소멸자가 호출되므로 주의!
			operatorNode->setRightChild(childToken);
		}
		else
		{
			TreeNode<Token>* rightChild = operandStack.Top();
			operandStack.Pop();									// Stack에 Pop()을 호출할때 소멸자가 호출되므로 주의!
			TreeNode<Token>* leftChild = operandStack.Top();
			operandStack.Pop();

			operatorNode->setLeftChild(leftChild);
			operatorNode->setRightChild(rightChild);
		}

		// 연산자 노드를 하나의 피연산자로 본다.
		operandStack.Push(operatorNode);
		operatorStack.Pop();
	}

	tree.setRoot(operandStack.Top());
}

void Expression::setExpression(string e)
{
	size = 0;	// size 초기화

	int parenthesisN;		// 괄호 예외처리를 위해.
	bool previous_operator;	// true: 이전에 operator가 나옴
							// false: 이전에 operator가 나오지 않음(operand가 나옴)
	parenthesisN = 0;
	previous_operator = true;
	for (int i = 0; i < e.length(); ++i)
	{
		switch (e[i])	// 연산식의 원소 배열
		{
		case '^':
		case '*':
		case '/':
		case '%':
		case '+':
			if (previous_operator) throw "이해할 수 없는 수식";	// 연산자가 연속으로 나오면 오류
			add(e[i]);
			previous_operator = true;	// 다음 값을 위해 기존 값 할당
			break;
		case '-':	// 단항 연산자
			if (previous_operator)
			{
				add('~');	// - 연산자
			}
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

			add(stoi(i, e));	// 문자열을 int로 변환해서 add

			previous_operator = false;	// 연산자 : false
			break;

		default:
			throw "이해할 수 없는 수식";
		}	// end of switch
	}		// end of for i

	if (parenthesisN > 0) throw "괄호의 짝이 맞지 않습니다";

	if (previous_operator) throw "이해할 수 없는 수식";	// 마지막이 연산자인 경우

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

void Expression::add(int operand)
{
	if (size == capacity)
	{
		ChangeSizeID(capacity * 2);
	}
	tokens[size++].setOperand(operand);
}

void Expression::add(char oper)
{
	if (size == capacity)
	{
		ChangeSizeID(capacity * 2);
	}
	tokens[size++].setOperator(oper);
}

Expression& Expression::operator=(const Expression& src)
{
	if (this == &src)
	{
		return *this;
	}

	tree = src.tree;

	if (capacity < src.size)
	{
		capacity = src.capacity;
		delete[] tokens;
		tokens = new Token[capacity];
	}

	for (int i = 0; i < src.size; ++i)
	{
		tokens[i] = src.tokens[i];
	}
	size = src.size;

	return *this;
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
	case '~':	// 단항 연산자가 스택안에 있을 때 꺼내지지 않도록 isp우선순위 보다 높음
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
	switch (oper)	// 연산자
	{
	case '-':
		return val1 - val2;
	case '+':
		return val1 + val2;
	case '*':
		return val1 * val2;
	case '/':
		if (val2 == 0)
			throw "나누기의 두번째 연산자가 0인 경우가 발생";
		return val1 / val2;
	case '%':
		if (val2 == 0)
			throw "나머지의 두번째 연산자가 0인 경우가 발생";
		return val1 % val2;
	case '^':
		return int(pow(double(val1), double(val2)));	// pow : 제곱 함수 pow(밑, 지수)
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

int Expression::makeTree(TreeNode<Token>* currentNode, TreeNode<int>*& result, int& length)
{
	Token token = currentNode->getData();	// node의 data값을 token에 할당
	int val;

	if (token.isOperand())	// token값이 true인 경우 ( operand인 경우 )
	{
		val = token.getOperand();	// 값에 피연산자를 할당

		return token.getOperand();
	}
	result = new TreeNode<int>();

	if (token.getOperator() == '~')	// token값이 tilde인 경우
	{	// 마이너스 연산자는 오른쪽 자식을 가져야 한다(중위순회를 통해 알 수 있다)
		val = -makeTree(currentNode->getRightChild(), result->getRightChild(), length);	// int형 함수이므로 -연산 가능

		result->setData(val);
		return val;
	}
	// 값을 계산할 결과 Tree를 생성
	int val1 = makeTree(currentNode->getLeftChild(), result->getLeftChild(), length);
	int val2 = makeTree(currentNode->getRightChild(), result->getRightChild(), length);

	val = calculate(val1, val2, token.getOperator());	// 계산 값을 할당

	result->setData(val);

	return val;
}

void Expression::setTree(TreeNode<Token>* currentNode, TreeNode<int>*& result, int count, int length, bool isPrinted)
{
	if (currentNode == nullptr)
	{
		return;
	}
	if (!isPrinted)	// 출력 되지 않았으면
	{
		for (int i = 0; i < count - 1; ++i)
		{
			cout << " ";
			cout << "           ";
		}
		cout << "        ";
		cout << " --- ";
	}

	Token token = currentNode->getData();	// token에 node의 결과 값을 할당
	if (token.isOperand())	// 피연산자인 경우
	{
		cout << token.getOperand();
	}
	else
	{
		if (token.getOperator() == '~')	// 연산자의 값이 tilde인 경우
		{	// 마이너스 연산자는 오른쪽 자식을 가져야 한다(중위순회를 통해 알 수 있다)
			cout << "~";
			cout << " (";
			cout << result->getData();
			cout << ")";
			cout << " --- ";
			setTree(currentNode->getRightChild(), result->getRightChild(), count + 1, length, true);
			return;
		}
		cout << token.getOperator() << " (";
		cout << result->getData() << ") ";

		if (currentNode->getLeftChild() != nullptr)
		{
			cout << " --- ";
		}
		setTree(currentNode->getLeftChild(), result->getLeftChild(), count + 1, length, true);

		if (currentNode->getRightChild() != nullptr)
		{
			cout << endl;
		}
		setTree(currentNode->getRightChild(), result->getRightChild(), count + 1, length, false);
	}
}

void Expression::toPrefix(TreeNode<Token>* currentNode)
{
	if (currentNode == nullptr)
	{
		return;
	}

	Token token = currentNode->getData();	// token에 node의 값을 할당

	if (token.isOperand())	// 피연산자인 경우
	{
		cout << token.getOperand() << " ";
	}
	else	// 연산자인 경우
	{
		cout << token.getOperator() << " ";
	}
	toPrefix(currentNode->getLeftChild());
	toPrefix(currentNode->getRightChild());
}

void Expression::toPostfix(TreeNode<Token>* currentNode)
{
	if (currentNode == nullptr)
	{
		return;
	}

	toPostfix(currentNode->getLeftChild());
	toPostfix(currentNode->getRightChild());

	Token token = currentNode->getData();	// token에 node의 값을 할당

	if (token.isOperand())	// 피연산자인 경우
	{
		cout << token.getOperand() << " ";
	}
	else	// 연산자인 경우
	{
		cout << token.getOperator() << " ";
	}
}

void Expression::displayPrefix()
{
	TreeNode<Token>* root = tree.getRoot();

	toPrefix(root);
}

void Expression::displayPostfix()
{
	TreeNode<Token>* root = tree.getRoot();

	toPostfix(root);
}

int Expression::displayTree()
{
	TreeNode<int>* result = nullptr;
	int length;
	int val = makeTree(tree.getRoot(), result, length);	// 계산한 값의 결과값을 할당

	setTree(tree.getRoot(), result, 0, length, true);	// 결과값을 참고한 Tree
	cout << endl;

	Tree<int> resultTree;
	resultTree.setRoot(result);		// resultNode를 파괴

	return val;	// Tree의 결과를 반환
}

void Expression::eval()
{
	string input_str;

	while (1)
	{
		cout << "계산식을 입력하세요(종료는 quit) : ";

		getline(cin, input_str);

		if (input_str == "quit")
		{
			break;
		}
		try {
			setExpression(input_str);
			toTree();

			cout << "---후위 계산식은 : ";
			displayPostfix();
			cout << endl;

			int result = displayTree();

			cout << endl;
			cout << " ---- 결과는 " << result << endl;
			cout << endl;

		}
		catch (char* exception) {
			cout << "[오류] " << exception << endl;
			cout << endl;
		}
	}

	cout << "**** 종료합니다 ****" << endl;
}