#pragma once
#include "ChainNode.h"

class Chain
{
private:
	ChainNode* nextNode;
	int edge;
public:
	Chain() { nextNode = nullptr; edge = 0; }
	~Chain() { }

	void increaseEdge() { edge = edge + 1; }	// vertex�� ���ԵǴ� ������ �߰�
	void decreaseEdge() { edge = edge - 1; }	// vertex�� ���� �� ���԰����� ����

	ChainNode* getNextNode() { return nextNode; }	// ���������� ���� NextNode
	int getEdge() { return edge; }

	void insertNode(ChainNode* newNode)
	{	// �տ� ����
		if (nextNode == nullptr)
		{
			nextNode = newNode;
		}
		else
		{
			newNode->setNextNode(nextNode);
			nextNode = newNode;
		}

		return;
	}
	void deleteNode()
	{
		if (nextNode == nullptr)	//	������ ��尡 ������ ����
		{
			return;
		}
		else
		{
			ChainNode* delnode = nextNode;
			ChainNode* delNextNode = nextNode->getNextNode();

			delete delnode;

			while (delNextNode != nullptr)
			{
				delnode = delNextNode;
				delNextNode = delNextNode->getNextNode();

				delete delnode;
			}
		}
		return;
	}
};