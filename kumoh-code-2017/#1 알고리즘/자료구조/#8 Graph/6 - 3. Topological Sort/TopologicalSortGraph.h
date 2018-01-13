#pragma once
#include "Chain.h"
#include "IoHandler.h"
#include "Stack.h"

class TopologicalSortGraph
{
private:
	Chain* chainList;
	int size;

	bool checkedCycle(int firstVertex, int secondVertex);	// 입력되는 간선 싸이클 체크
public:
	TopologicalSortGraph() {}
	~TopologicalSortGraph();

	void setGraph(int inputSize);
	void updateGraph(int firstVertex, int secondVertex, bool& cycleFlag);

	void topologicalSort();	// 위상정렬

};