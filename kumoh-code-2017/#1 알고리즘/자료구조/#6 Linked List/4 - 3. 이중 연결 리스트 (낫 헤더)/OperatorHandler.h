#pragma once
#include "BookList.h"

class OperatorHandler
{
private:
	Book* curNode;	// 현재 노드
public:
	OperatorHandler(Book* pNode = NULL) { curNode = pNode; }
	~OperatorHandler() {}

	Book* getLink() const { return curNode; }
	Book& operator*() const { return* curNode; }
	Book* operator->() const { return curNode; }
	// 증감 연산자
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
	// 비교 연산자
	bool operator!=(const OperatorHandler oh)const
	{
		return curNode != oh.curNode;
	}
	bool operator==(const OperatorHandler oh)const
	{
		return curNode == oh.curNode;
	}
};