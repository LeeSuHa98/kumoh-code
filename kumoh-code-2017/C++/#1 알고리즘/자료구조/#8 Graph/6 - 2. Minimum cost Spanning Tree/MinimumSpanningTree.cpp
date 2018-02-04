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

	int flag = 0; //	n-1���� ������ �ִ��� Ȯ���ϴ� flag
	int totalSum = 0; //	����

	HeapNode* value = new HeapNode[sg.getSize()];
	int insert = 0;
	while (1)
	{
		HeapNode node = popNode(); //	�ּ������� ���� ���� ���� ����

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

	if ((flag + 1) == sg.getSize())	//	����Ʈ���� ã��
	{
		ioh.putString("���õ� ���� ");
		for (int i = 0; i < insert; i++)
		{
			printEdge(value[i]);
		}
		ioh.putNewLine();

		ioh.putString("�ּҺ�� ����Ʈ���� ���� �� ����");
		ioh.putNewLine();

		ioh.putString("�ּҺ���� ");
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
		ioh.putString("�ּҺ�� ����Ʈ���� ���� �� ����");
		ioh.putNewLine();
	}

	delete[] value;
	return;
}

void MinimumSpanningTree::pushNode(HeapNode& h)
{
	if (count == 1)
	{	//ó���� �� ���ϰ� �׳� ����
		minHeap[count++] = h;
	}
	else
	{	//ó���� �ƴ� ���¿����� �θ� ���� ���Ͽ� ����
		if (h.getWeight() < minHeap[count / 2].getWeight())
		{	//�θ� ����� ����ġ�� �� Ŭ ���
			minHeap[count] = minHeap[count / 2];
			minHeap[count / 2] = h;
		}
		else
		{	//�θ� ����� ����ġ�� �� ���� ���
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
	{	//	heap�� �����
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
		{	//	�ڽ��� ���� ������ ������带 �ְ� break;
			minHeap[index] = leafNode;
			break;
		}
		else if ((index * 2 + 1) == count)
		{	//	���� �ڽĸ� �ִ� ��
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
		{	//	����,������ �ڽ� �� ������ ���� ���
			int left = minHeap[index * 2].getWeight();
			int right = minHeap[index * 2 + 1].getWeight();

			if (leaf < left && leaf < right)
			{	//	leaf�� ���� ���� ���
				minHeap[index] = leafNode;
				break;
			}
			else if (left < leaf && left < right)
			{	//	left�� ���� ���� ���
				minHeap[index] = minHeap[index * 2];
				index = index * 2;
			}
			else if (right < leaf && right < left)
			{	//	right�� ���� ���� ���
				minHeap[index] = minHeap[index * 2 + 1];
				index = index * 2 + 1;
			}
		}

	}
	return returnNode;
}