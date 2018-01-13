#pragma once
#include "FileHandler.h"
#include "IoHandler.h"
#include "MatrixGraph.h"
#include "ListGraph.h"

class TaskManager
{
public:
	TaskManager() {}
	~TaskManager() {}

	void searchGraph(MatrixGraph& mg, ListGraph& lg);	// Å½»ö
};