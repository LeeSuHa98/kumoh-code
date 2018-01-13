#pragma once
#include "BookList.h"

class OperatorHandler
{
private:
	Book* curNode;	// ���� ���
public:
	OperatorHandler(Book* pNode = NULL) { curNode = pNode; }
	~OperatorHandler() {}

	Book* getLink() const { return curNode; }
	Book& operator*() const { return* curNode; }
	Book* operator->() const { return curNode; }
	// ���� ������
	OperatorHandler& operator++()
	{
		curNode = curNode->rightLink;
		return *this;
	}
	OperatorHandler operator++(int)
	{
		OperatorHandler postfix = *this;
		curNode = curNode->rightLink;
		return postfix;
	}
	OperatorHandler& operator--()
	{
		curNode = curNode->leftLink;
		return *this;
	}
	OperatorHandler operator--(int)
	{
		OperatorHandler postfix = *this;
		curNode = curNode->leftLink;
		return postfix;
	}
	// �� ������
	bool operator!=(const OperatorHandler oh)const
	{
		return curNode != oh.curNode;
	}
	bool operator==(const OperatorHandler oh)const
	{
		return curNode == oh.curNode;
	}
};