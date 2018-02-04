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

	void loadMatrixGraph(string fileName, MatrixGraph& mg);	// 인접 행렬 load
	void loadListGraph(string fileName, ListGraph& lg);	// 인접 리스트 load
};