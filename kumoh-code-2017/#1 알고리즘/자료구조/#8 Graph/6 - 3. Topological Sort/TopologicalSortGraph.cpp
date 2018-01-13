#include "TopologicalSortGraph.h"

TopologicalSortGraph::~TopologicalSortGraph()
{
	for (int i = 0; i < size; i++)
	{
		chainList[i].deleteNode();
	}
	delete[] chainList;
}

bool TopologicalSortGraph::checkedCycle(int firstVertex, int secondVertex)
{
	ChainNode* thisNode = chainList[secondVertex].getNextNode();

	if (thisNode == nullptr);
	else
	{
		while (1)
		{
			if (thisNode->getVertex() == firstVertex)
			{	//	싸이클 발생
				return true;
			}

			thisNode = thisNode->getNextNode();

			if (thisNode == nullptr)
			{
				break;
			}
		}
	}
	return false;
}

void TopologicalSortGraph::setGraph(int inputSize)
{
	size = inputSize;
	chainList = new Chain[size];

	return;
}

void TopologicalSortGraph::updateGraph(int firstVertex, int secondVertex, bool& cycleFlag)
{
	if (checkedCycle(firstVertex, secondVertex) == false)	// 해당 간선이 cycle인지 확인
	{	//	싸이클이 아니면
		chainList[firstVertex].insertNode(new ChainNode(nullptr, secondVertex));
		chainList[secondVertex].increaseEdge();	// 진입 간선 추가
	}
	else
	{	//	싸이클이면
		cycleFlag = true;
	}

	return;
}

void TopologicalSortGraph::topologicalSort()
{
	Stack<int> stack;
	IoHandler ioh;

	bool* visit = new bool[size];
	memset(visit, false, size);

	//	진입간선이 0인 vertex를 Push하기 위한 for문
	for (int i = 0; i < size; i++)
	{
		if (chainList[i].getEdge() == 0)	//	진입간선이 0이면
		{
			visit[i] = true;
			stack.Push(i);	//	진입간선이 0인 vertex Push
		}
	}

	ioh.putString("가능한 하나의 위상 정렬 : ");
	while (1)
	{
		int visited = stack.Top();
		ioh.printConnectedComponent(stack.Top());
		stack.Pop();

		if (stack.IsEmpty() == true)
		{	//	종료조건
			int flag = 0;
			for (int i = 0; i < size; i++)
			{	//	모든 정점을 방문했을 경우 flag변수 증가
				if (visit[i] == true)
				{
					flag++;
				}
				else
				{
					break;
				}
			}
			if (flag == size)
			{
				break;
			}
		}
		ChainNode* thisNode = chainList[visited].getNextNode();

		if (thisNode == nullptr);	//	진출 차선이 없는 vertex일 경우 pass
		else
		{

			while (1)
			{
				chainList[thisNode->getVertex()].decreaseEdge();

				if (chainList[thisNode->getVertex()].getEdge() == 0)
				{	//만약 진입간선을 --했는데 edge가 0이된다면 Push
					visit[thisNode->getVertex()] = true;
					stack.Push(thisNode->getVertex());
				}
				thisNode = thisNode->getNextNode();

				if (thisNode == nullptr)
				{
					break;
				}
			}
		}
	}
	delete[] visit;
	return;
}