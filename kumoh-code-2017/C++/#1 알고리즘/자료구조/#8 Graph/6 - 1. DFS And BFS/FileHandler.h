#pragma once
#include <fstream>
#include "IoHandler.h"
#include "MatrixGraph.h"
#include "ListGraph.h"

using namespace std;

class FileHandler
{
public:
	FileHandler() {}
	~FileHandler() {}

	void loadMatrixGraph(string fileName, MatrixGraph& mg);	// ���� ��� load
	void loadListGraph(string fileName, ListGraph& lg);	// ���� ����Ʈ load
};