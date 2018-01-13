#include "Expression.h"

void Expression::toTree()
{
	Stack<char> operatorStack;	// ������ Stack �ʱ�ȭ
	Stack<TreeNode<Token>*> operandStack;	// �ǿ����� Stack �ʱ�ȭ

	operatorStack.Push('#');	// Stack ����
	for (int i = 0; i < size; ++i)
	{
		if (tokens[i].isOperand())	// ������� Token�� �ǿ������� ���
		{
			operandStack.Push(new TreeNode<Token>(tokens[i]));	// Stack Push
		}
		else if (tokens[i].getOperator() == ')')	// Token�� �ݴ� ��ȣ�� ���
		{
			while (operatorStack.Top() != '(')	// Top�� ��ġ�� ���� ��ȣ�� �ƴ� ��� : �ݴ� ��ȣ�� ���
			{
				Token operatorToken = operatorStack.Top();	// Top���� ������ Token�� �Ҵ�
				TreeNode<Token>* operatorNode = new TreeNode<Token>(operatorToken);	// TreeNode�� �Ҵ�

				if (operatorToken.getOperator() == '~')	// �����ڰ� ~�� ���
				{
					TreeNode<Token>* childToken = operandStack.Top();	// �ǿ����� Stack�� Top�� �ڽ� Token�� �Ҵ�
					operandStack.Pop();									// Stack�� Pop()�� ȣ���Ҷ� �Ҹ��ڰ� ȣ��
					operatorNode->setRightChild(childToken);			// ������ �ڽ��� ��忡 ���� �Ҵ�
				}
				else
				{	// �� ���� ���
					TreeNode<Token>* rightChild = operandStack.Top();	// ������ �ڽĿ� Stack�� Top()�� �ִ� ������� �Ҵ�
					operandStack.Pop();									// Stack�� Pop()�� ȣ���Ҷ� �Ҹ��ڰ� ȣ��
					TreeNode<Token>* leftChild = operandStack.Top();	// ���� �ڽĿ� Stack�� Top()�� �ִ� ������� �Ҵ�
					operandStack.Pop();
					operatorNode->setLeftChild(leftChild);				// ���� �ڽ��� ��忡 ���� �Ҵ�
					operatorNode->setRightChild(rightChild);			// ������ �ڽ��� ��忡 ���� �Ҵ�
				}

				// ������ ��带 �ϳ��� �ǿ����ڷ� ����.
				operandStack.Push(operatorNode);

				operatorStack.Pop();
			}
			operatorStack.Pop();	// '(' �� ���ش�.
		}
		else
		{	// Token�� Operator�� ���
			while (isp(operatorStack.Top()) >= icp(tokens[i].getOperator()))	// ���� Token�� �����ں��� Stack�� ����ִ� �������� �켱������ ���� ���
			{
				Token operatorToken = operatorStack.Top();	// �������� Token�� Top�� �ִ� ������ ���� �Ҵ�
				TreeNode<Token>* operatorNode = new TreeNode<Token>(operatorToken);	// ������ ���� ������ Node�� �Ҵ�

				if (operatorToken.getOperator() == '~')
				{
					TreeNode<Token>* childToken = operandStack.Top();	// �ǿ����� Stack�� Top�� �ڽ� Token�� �Ҵ�
					operandStack.Pop();									// Stack�� Pop()�� ȣ���Ҷ� �Ҹ��ڰ� ȣ��ǹǷ� ����!
					operatorNode->setRightChild(childToken);			// ������ �ڽ��� ��忡 ���� �Ҵ�
				}
				else
				{
					TreeNode<Token>* rightChild = operandStack.Top();	// ������ �ڽĿ� Stack�� Top()�� �ִ� ������� �Ҵ�
					operandStack.Pop();
					TreeNode<Token>* leftChild = operandStack.Top();	// ���� �ڽĿ� Stack�� Top()�� �ִ� ������� �Ҵ�
					operandStack.Pop();

					operatorNode->setLeftChild(leftChild);
					operatorNode->setRightChild(rightChild);
				}

				// ������ ��带 �ϳ��� �ǿ����ڷ� ����.
				operandStack.Push(operatorNode);

				operatorStack.Pop();
			}	// end while
			operatorStack.Push(tokens[i].getOperator());
		}	// end else
	}

	while (operatorStack.Top() != '#')
	{
		Token operatorToken = operatorStack.Top();	// �������� Token�� Top�� �ִ� ������ ���� �Ҵ�

		TreeNode<Token>* operatorNode = new TreeNode<Token>(operatorToken);	// ������ ���� ������ Node�� �Ҵ�

		if (operatorToken.getOperator() == '~')
		{	// ���̳ʽ� �����ڴ� ������ �ڽ��� ������ �Ѵ�(������ȸ�� ���� �� �� �ִ�)
			TreeNode<Token>* childToken = operandStack.Top();
			operandStack.Pop();									// Stack�� Pop()�� ȣ���Ҷ� �Ҹ��ڰ� ȣ��ǹǷ� ����!
			operatorNode->setRightChild(childToken);
		}
		else
		{
			TreeNode<Token>* rightChild = operandStack.Top();
			operandStack.Pop();									// Stack�� Pop()�� ȣ���Ҷ� �Ҹ��ڰ� ȣ��ǹǷ� ����!
			TreeNode<Token>* leftChild = operandStack.Top();
			operandStack.Pop();

			operatorNode->setLeftChild(leftChild);
			operatorNode->setRightChild(rightChild);
		}

		// ������ ��带 �ϳ��� �ǿ����ڷ� ����.
		operandStack.Push(operatorNode);
		operatorStack.Pop();
	}

	tree.setRoot(operandStack.Top());
}

void Expression::setExpression(string e)
{
	size = 0;	// size �ʱ�ȭ

	int parenthesisN;		// ��ȣ ����ó���� ����.
	bool previous_operator;	// true: ������ operator�� ����
							// false: ������ operator�� ������ ����(operand�� ����)
	parenthesisN = 0;
	previous_operator = true;
	for (int i = 0; i < e.length(); ++i)
	{
		switch (e[i])	// ������� ���� �迭
		{
		case '^':
		case '*':
		case '/':
		case '%':
		case '+':
			if (previous_operator) throw "������ �� ���� ����";	// �����ڰ� �������� ������ ����
			add(e[i]);
			previous_operator = true;	// ���� ���� ���� ���� �� �Ҵ�
			break;
		case '-':	// ���� ������
			if (previous_operator)
			{
				add('~');	// - ������
			}
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

			add(stoi(i, e));	// ���ڿ��� int�� ��ȯ�ؼ� add

			previous_operator = false;	// ������ : false
			break;

		default:
			throw "������ �� ���� ����";
		}	// end of switch
	}		// end of for i

	if (parenthesisN > 0) throw "��ȣ�� ¦�� ���� �ʽ��ϴ�";

	if (previous_operator) throw "������ �� ���� ����";	// �������� �������� ���

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
	case '~':	// ���� �����ڰ� ���þȿ� ���� �� �������� �ʵ��� isp�켱���� ���� ����
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
	switch (oper)	// ������
	{
	case '-':
		return val1 - val2;
	case '+':
		return val1 + val2;
	case '*':
		return val1 * val2;
	case '/':
		if (val2 == 0)
			throw "�������� �ι�° �����ڰ� 0�� ��찡 �߻�";
		return val1 / val2;
	case '%':
		if (val2 == 0)
			throw "�������� �ι�° �����ڰ� 0�� ��찡 �߻�";
		return val1 % val2;
	case '^':
		return int(pow(double(val1), double(val2)));	// pow : ���� �Լ� pow(��, ����)
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
	Token token = currentNode->getData();	// node�� data���� token�� �Ҵ�
	int val;

	if (token.isOperand())	// token���� true�� ��� ( operand�� ��� )
	{
		val = token.getOperand();	// ���� �ǿ����ڸ� �Ҵ�

		return token.getOperand();
	}
	result = new TreeNode<int>();

	if (token.getOperator() == '~')	// token���� tilde�� ���
	{	// ���̳ʽ� �����ڴ� ������ �ڽ��� ������ �Ѵ�(������ȸ�� ���� �� �� �ִ�)
		val = -makeTree(currentNode->getRightChild(), result->getRightChild(), length);	// int�� �Լ��̹Ƿ� -���� ����

		result->setData(val);
		return val;
	}
	// ���� ����� ��� Tree�� ����
	int val1 = makeTree(currentNode->getLeftChild(), result->getLeftChild(), length);
	int val2 = makeTree(currentNode->getRightChild(), result->getRightChild(), length);

	val = calculate(val1, val2, token.getOperator());	// ��� ���� �Ҵ�

	result->setData(val);

	return val;
}

void Expression::setTree(TreeNode<Token>* currentNode, TreeNode<int>*& result, int count, int length, bool isPrinted)
{
	if (currentNode == nullptr)
	{
		return;
	}
	if (!isPrinted)	// ��� ���� �ʾ�����
	{
		for (int i = 0; i < count - 1; ++i)
		{
			cout << " ";
			cout << "           ";
		}
		cout << "        ";
		cout << " --- ";
	}

	Token token = currentNode->getData();	// token�� node�� ��� ���� �Ҵ�
	if (token.isOperand())	// �ǿ������� ���
	{
		cout << token.getOperand();
	}
	else
	{
		if (token.getOperator() == '~')	// �������� ���� tilde�� ���
		{	// ���̳ʽ� �����ڴ� ������ �ڽ��� ������ �Ѵ�(������ȸ�� ���� �� �� �ִ�)
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

	Token token = currentNode->getData();	// token�� node�� ���� �Ҵ�

	if (token.isOperand())	// �ǿ������� ���
	{
		cout << token.getOperand() << " ";
	}
	else	// �������� ���
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

	Token token = currentNode->getData();	// token�� node�� ���� �Ҵ�

	if (token.isOperand())	// �ǿ������� ���
	{
		cout << token.getOperand() << " ";
	}
	else	// �������� ���
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
	int val = makeTree(tree.getRoot(), result, length);	// ����� ���� ������� �Ҵ�

	setTree(tree.getRoot(), result, 0, length, true);	// ������� ������ Tree
	cout << endl;

	Tree<int> resultTree;
	resultTree.setRoot(result);		// resultNode�� �ı�

	return val;	// Tree�� ����� ��ȯ
}

void Expression::eval()
{
	string input_str;

	while (1)
	{
		cout << "������ �Է��ϼ���(����� quit) : ";

		getline(cin, input_str);

		if (input_str == "quit")
		{
			break;
		}
		try {
			setExpression(input_str);
			toTree();

			cout << "---���� ������ : ";
			displayPostfix();
			cout << endl;

			int result = displayTree();

			cout << endl;
			cout << " ---- ����� " << result << endl;
			cout << endl;

		}
		catch (char* exception) {
			cout << "[����] " << exception << endl;
			cout << endl;
		}
	}

	cout << "**** �����մϴ� ****" << endl;
}