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

	void toTree();	// 트리로 변경
	void setExpression(string e);	// string 형태의 식을 expression 형태의 식으로 바꾼다

	void ChangeSizeID(const int newSize);
	void add(int operand);
	void add(char oper);

	Expression& operator=(const Expression& src);

	static int isp(char oper);	// in stack priority ( 스택 우선 순위 )
	static int icp(char oper);	// in coming priority ( 오는 우선 순위)
	static int calculate(int val1, int val2, char oper);	// calculate
	static int stoi(int& idx, const string& expression);	// string to int ( 문자열을 정수로 변환 )

	// 값을 계산 후 결과값 생성
	int makeTree(TreeNode<Token>* currentNode, TreeNode<int>*& result, int& length);
	// 결과값을 참고하면서 Tree를 Setting
	void setTree(TreeNode<Token>* currentNode, TreeNode<int>*& result, int count, int length, bool isPrinted);

	void toPrefix(TreeNode<Token>* currentNode);	// 전위연산식 트리 출력
	void toPostfix(TreeNode<Token>* currentNode);	// 후위연산식 트리 출력
	void displayPrefix();			// 전위연산식 출력
	void displayPostfix();		// 후위연산식 출력
	int displayTree();	// 트리 출력
	void eval();	// 값 평가
};