#pragma once
#include "Token.h"
#include "Stack.h"
#include "Tree.h"

class Expression
{
private:
	int capacity;
	int size;
	Token* tokens;
	Tree<Token> tree;
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
		tree = e.tree;

		for (int i = 0; i < size; ++i)
		{
			tokens[i] = e.tokens[i];
		}
	}
	~Expression()
	{
		delete[] tokens;
	}

	void toTree();	// Ʈ���� ����
	void setExpression(string e);	// string ������ ���� expression ������ ������ �ٲ۴�

	void ChangeSizeID(const int newSize);
	void add(int operand);
	void add(char oper);

	Expression& operator=(const Expression& src);

	static int isp(char oper);	// in stack priority ( ���� �켱 ���� )
	static int icp(char oper);	// in coming priority ( ���� �켱 ����)
	static int calculate(int val1, int val2, char oper);	// calculate
	static int stoi(int& idx, const string& expression);	// string to int ( ���ڿ��� ������ ��ȯ )

	// ���� ��� �� ����� ����
	int makeTree(TreeNode<Token>* currentNode, TreeNode<int>*& result, int& length);
	// ������� �����ϸ鼭 Tree�� Setting
	void setTree(TreeNode<Token>* currentNode, TreeNode<int>*& result, int count, int length, bool isPrinted);

	void toPrefix(TreeNode<Token>* currentNode);	// ��������� Ʈ�� ���
	void toPostfix(TreeNode<Token>* currentNode);	// ��������� Ʈ�� ���
	void displayPrefix();			// ��������� ���
	void displayPostfix();		// ��������� ���
	int displayTree();	// Ʈ�� ���
	void eval();	// �� ��
};