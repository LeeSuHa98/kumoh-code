#pragma once
#include "Chain.h"
#include "IoHandler.h"
#include "Stack.h"

class TopologicalSortGraph
{
private:
	Chain* chainList;
	int size;

	bool checkedCycle(int firstVertex, int secondVertex);	// �ԷµǴ� ���� ����Ŭ üũ
public:
	TopologicalSortGraph() {}
	~TopologicalSortGraph();

	void setGraph(int inputSize);
	void updateGraph(int firstVertex, int secondVertex, bool& cycleFlag);

	void topologicalSort();	// ��������

};