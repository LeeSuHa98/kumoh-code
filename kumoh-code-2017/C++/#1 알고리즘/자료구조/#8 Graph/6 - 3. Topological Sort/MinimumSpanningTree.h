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
	~MinimumSpanningTree() { delete[] minHeap; }	// 배열 원소 각각 delete 여부 확인

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
MinHeap는 삽입, 탐색 등 log N 의 시간복잡도를 가지게 됨
그러므로 가장 작은 가중치를 선택 해야하는 알고리즘인 
kruskalalgorithm 을 구현할 때
MinHeap를 효율적으로 사용할 수 있을거라고 판단
*/