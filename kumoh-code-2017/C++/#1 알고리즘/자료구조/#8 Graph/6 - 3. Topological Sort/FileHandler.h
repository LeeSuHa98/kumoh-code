#pragma once
#include <fstream>
#include "IoHandler.h"
#include "MatrixGraph.h"
#include "ListGraph.h"
#include "SetsGraph.h"
#include "MinimumSpanningTree.h"
#include "TopologicalSortGraph.h"

using namespace std;

class FileHandler
{
public:
	FileHandler() {}
	~FileHandler() {}

	void loadMatrixGraph(string fileName, MatrixGraph& mg);	// ���� ��� load
	void loadListGraph(string fileName, ListGraph& lg);	// ���� ����Ʈ load
	void loadKruskal(string fileName, SetsGraph& sg, MinimumSpanningTree& mt);	// �ּҺ�� ����Ʈ�� load
	void loadTopologicalSortGraph(string fileName, TopologicalSortGraph& tg);	// ���� ���� load
};