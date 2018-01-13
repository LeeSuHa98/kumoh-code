#pragma once
#include "Stack.h"
#include "Queue.h"
#include "Chain.h"
#include "IoHandler.h"

class ListGraph
{
private:
	Chain* ChainList;
	int size;

public:
	ListGraph() {}
	~ListGraph()
	{
		for (int i = 0; i < size; i++)
		{
			ChainList[i].deleteNode();
		}
		delete[] ChainList;
	}

	void setGraph(int numberOfElements);	// �׷��� ����
	void updateGraph(int firstVertex, int secondVertex);	// ���� ǥ��

	void dfs(); // ���� �켱 Ž��
	void bfs(); // �ʺ� �켱 Ž��

	void printList(); // ��������Ʈ ���
	void displayList(ListGraph& lg);	// �Էµ� �׷����� ��������Ʈ ǥ��

};