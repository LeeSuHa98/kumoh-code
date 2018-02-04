#pragma once
#include "FileHandler.h"
#include "IoHandler.h"
#include "MatrixGraph.h"
#include "ListGraph.h"
#include "SetsGraph.h"
#include "MinimumSpanningTree.h"

class TaskManager
{
public:
	TaskManager() {}
	~TaskManager() {}

	void searchGraph(MatrixGraph& mg, ListGraph& lg);	// Ž��
	void minimumCostSpanningTree(SetsGraph& sg, MinimumSpanningTree& mt);	// �ּҺ�� ����Ʈ�� ����
};