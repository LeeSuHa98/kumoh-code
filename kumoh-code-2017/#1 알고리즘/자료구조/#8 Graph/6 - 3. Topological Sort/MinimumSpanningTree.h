#pragma once
#include "HeapNode.h"
#include "IoHandler.h"
#include "SetsGraph.h"

class MinimumSpanningTree
{
private:
	int size;
	int count;
	HeapNode* minHeap;

	void changeSize(const int newSize);
public:
	MinimumSpanningTree() { size = 0; count = 1; minHeap = nullptr; }
	~MinimumSpanningTree() { delete[] minHeap; }	// �迭 ���� ���� delete ���� Ȯ��

	void setTree(int numberOfElements);
	void kruskalAlgorithm(SetsGraph& sg);

	void pushNode(HeapNode& h);
	HeapNode popNode();
	void printEdge(HeapNode& h)
	{
		cout << "(" << h.getFirstVertex() << " " << h.getSecondVertex() << " " << h.getWeight() << ")";
	}
};

/*
MinHeap�� ����, Ž�� �� log N �� �ð����⵵�� ������ ��
�׷��Ƿ� ���� ���� ����ġ�� ���� �ؾ��ϴ� �˰����� 
kruskalalgorithm �� ������ ��
MinHeap�� ȿ�������� ����� �� �����Ŷ�� �Ǵ�
*/