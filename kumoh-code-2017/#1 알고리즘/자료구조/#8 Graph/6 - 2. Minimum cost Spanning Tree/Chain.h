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

	void increaseEdge() { edge = edge + 1; }	// vertex에 진입되는 간선을 추가
	void decreaseEdge() { edge = edge - 1; }	// vertex를 제거 시 진입간선을 제거

	ChainNode* getNextNode() { return nextNode; }	// 위상정렬을 위한 NextNode
	int getEdge() { return edge; }

	void insertNode(ChainNode* newNode)
	{	// 앞에 삽입
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
		if (nextNode == nullptr)	//	삭제할 노드가 없으면 리턴
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