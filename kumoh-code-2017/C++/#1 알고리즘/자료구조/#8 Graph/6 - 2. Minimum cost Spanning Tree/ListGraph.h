#pragma once
#include "Stack.h"
#include "Queue.h"
#include "Chain.h"
#include "IoHandler.h"

class ListGraph
{
private:
	Chain* ChainList;
	int size;

public:
	ListGraph() {}
	~ListGraph()
	{
		for (int i = 0; i < size; i++)
		{
			ChainList[i].deleteNode();
		}
		delete[] ChainList;
	}

	void setGraph(int numberOfElements);	// 그래프 구성
	void updateGraph(int firstVertex, int secondVertex);	// 간선 표현

	void dfs(); // 깊이 우선 탐색
	void bfs(); // 너비 우선 탐색

	void printList(); // 인접리스트 출력
	void displayList(ListGraph& lg);	// 입력된 그래프의 인접리스트 표현

};