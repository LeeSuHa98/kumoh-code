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

	void setGraph(int numberOfElements);	// �׷��� ����
	void updateGraph(int firstVertex, int secondVertex);	// ���� ǥ��

	void dfs();	// ���� �켱 Ž��
	void bfs();	// �ʺ� �켱 Ž��

	void printMatrix();	// ��� ǥ�� ���
	void displayMatrix(MatrixGraph& mg);	// �Էµ� �׷����� ���� ��� ǥ��
};