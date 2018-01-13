#pragma once
#include "IoHandler.h"

class SetsGraph
{
private:
	int* parent;
	int size;	// 집합 원소의 개수

public:
	SetsGraph() {}
	~SetsGraph() { delete[] parent; }

	void setGraph(int numberOfElements);	// 그래프 구성
	void weightedUnion(int i, int j);	// 가중규칙을 이용한 합집합
	int collapsingFind(int i);	// 붕괴규칙을 이용한 알고리즘

	int getArr(int i) { return parent[i]; }
	int getSize() { return size; }
};