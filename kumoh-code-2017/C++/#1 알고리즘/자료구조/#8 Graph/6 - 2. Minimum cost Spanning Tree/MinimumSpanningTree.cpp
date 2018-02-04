#include "MinimumSpanningTree.h"

void MinimumSpanningTree::changeSize(const int newSize)
{
	if (newSize < size) throw "New size must be >= number of size";
	HeapNode* temp = new HeapNode[newSize];
	for (int i = 0; i < count; i++)
	{
		temp[i] = minHeap[i];
	}
	delete[] minHeap;
	minHeap = temp;
	return;
}

void MinimumSpanningTree::setTree(int numberOfElements)
{
	size = numberOfElements;
	minHeap = new HeapNode[size + 1];

	return;
}

void MinimumSpanningTree::kruskalAlgorithm(SetsGraph& sg)
{
	IoHandler ioh;

	int flag = 0; //	n-1개의 간선이 있는지 확인하는 flag
	int totalSum = 0; //	총합

	HeapNode* value = new HeapNode[sg.getSize()];
	int insert = 0;
	while (1)
	{
		HeapNode node = popNode(); //	최소힙에서 제일 작은 값을 추출

		int i = sg.collapsingFind(node.getFirstVertex());
		int j = sg.collapsingFind(node.getSecondVertex());

		if (node.getWeight() == 0)
		{
			break;
		}

		if (i == j)
		{	//cycle
			continue;
		}
		else
		{
			sg.weightedUnion(i, j);
			flag++;
			totalSum = totalSum + node.getWeight();
			value[insert++] = node;
		}
	}

	if ((flag + 1) == sg.getSize())	//	신장트리를 찾음
	{
		ioh.putString("선택된 간선 ");
		for (int i = 0; i < insert; i++)
		{
			printEdge(value[i]);
		}
		ioh.putNewLine();

		ioh.putString("최소비용 신장트리를 구할 수 있음");
		ioh.putNewLine();

		ioh.putString("최소비용은 ");
		for (int i = 0; i < insert; i++)
		{
			ioh.putInteger(value[i].getWeight());
			if ((i + 1) != insert)
			{
				ioh.putString(" + ");
			}
		}
		ioh.putString(" = ");
		ioh.putInteger(totalSum);
		ioh.putNewLine();
	}
	else
	{
		ioh.putString("최소비용 신장트리를 구할 수 없음");
		ioh.putNewLine();
	}

	delete[] value;
	return;
}

void MinimumSpanningTree::pushNode(HeapNode& h)
{
	if (count == 1)
	{	//처음은 비교 안하고 그냥 삽입
		minHeap[count++] = h;
	}
	else
	{	//처음이 아닌 상태에서는 부모 노드와 비교하여 삽입
		if (h.getWeight() < minHeap[count / 2].getWeight())
		{	//부모 노드의 가중치가 더 클 경우
			minHeap[count] = minHeap[count / 2];
			minHeap[count / 2] = h;
		}
		else
		{	//부모 노드의 가중치가 더 작은 경우
			minHeap[count] = h;
		}
		count++;
	}

	if (count == size)
	{
		changeSize(size * 2);
	}

	return;
}

HeapNode MinimumSpanningTree::popNode()
{
	if (1 == count)
	{	//	heap가 비었음
		return HeapNode(0, 0, 0);
	}
	HeapNode returnNode = minHeap[1];
	int index = 1;
	int leaf = minHeap[count - 1].getWeight();

	HeapNode leafNode = minHeap[count - 1];
	count--;

	while (1)
	{
		if ((index * 2) >= count)
		{	//	자식이 없기 때문에 리프노드를 넣고 break;
			minHeap[index] = leafNode;
			break;
		}
		else if ((index * 2 + 1) == count)
		{	//	왼쪽 자식만 있는 것
			int left = minHeap[index * 2].getWeight();
			if (leaf < left)
			{
				minHeap[index] = leafNode;
				break;
			}
			else
			{
				minHeap[index] = minHeap[index * 2];
				minHeap[index * 2] = leafNode;
				break;
			}
			//	index = index * 2;
		}
		else
		{	//	왼쪽,오른쪽 자식 다 가지고 있을 경우
			int left = minHeap[index * 2].getWeight();
			int right = minHeap[index * 2 + 1].getWeight();

			if (leaf < left && leaf < right)
			{	//	leaf가 제일 작을 경우
				minHeap[index] = leafNode;
				break;
			}
			else if (left < leaf && left < right)
			{	//	left가 제일 작을 경우
				minHeap[index] = minHeap[index * 2];
				index = index * 2;
			}
			else if (right < leaf && right < left)
			{	//	right가 제일 작을 경우
				minHeap[index] = minHeap[index * 2 + 1];
				index = index * 2 + 1;
			}
		}

	}
	return returnNode;
}