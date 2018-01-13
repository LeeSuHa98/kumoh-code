#pragma once
#include "Stack.h"
#include "Queue.h"
#include <string>
#include "IoHandler.h"

class MatrixGraph
{
private:
	bool** adjMatrix;
	int size;

public:
	MatrixGraph() {}
	~MatrixGraph()
	{
		for (int i = 0; i < size; i++)
		{
			delete[] adjMatrix[i];
		}

		delete[] adjMatrix;
	}

	void setGraph(int numberOfElements);	// 그래프 구성
	void updateGraph(int firstVertex, int secondVertex);	// 간선 표현

	void dfs();	// 깊이 우선 탐색
	void bfs();	// 너비 우선 탐색

	void printMatrix();	// 행렬 표현 출력
	void displayMatrix(MatrixGraph& mg);	// 입력된 그래프의 인접 행렬 표현
};