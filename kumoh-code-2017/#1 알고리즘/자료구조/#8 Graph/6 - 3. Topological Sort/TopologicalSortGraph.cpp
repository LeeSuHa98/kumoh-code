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
			{	//	����Ŭ �߻�
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
	if (checkedCycle(firstVertex, secondVertex) == false)	// �ش� ������ cycle���� Ȯ��
	{	//	����Ŭ�� �ƴϸ�
		chainList[firstVertex].insertNode(new ChainNode(nullptr, secondVertex));
		chainList[secondVertex].increaseEdge();	// ���� ���� �߰�
	}
	else
	{	//	����Ŭ�̸�
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

	//	���԰����� 0�� vertex�� Push�ϱ� ���� for��
	for (int i = 0; i < size; i++)
	{
		if (chainList[i].getEdge() == 0)	//	���԰����� 0�̸�
		{
			visit[i] = true;
			stack.Push(i);	//	���԰����� 0�� vertex Push
		}
	}

	ioh.putString("������ �ϳ��� ���� ���� : ");
	while (1)
	{
		int visited = stack.Top();
		ioh.printConnectedComponent(stack.Top());
		stack.Pop();

		if (stack.IsEmpty() == true)
		{	//	��������
			int flag = 0;
			for (int i = 0; i < size; i++)
			{	//	��� ������ �湮���� ��� flag���� ����
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

		if (thisNode == nullptr);	//	���� ������ ���� vertex�� ��� pass
		else
		{

			while (1)
			{
				chainList[thisNode->getVertex()].decreaseEdge();

				if (chainList[thisNode->getVertex()].getEdge() == 0)
				{	//���� ���԰����� --�ߴµ� edge�� 0�̵ȴٸ� Push
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