#include "SetsGraph.h"

void SetsGraph::setGraph(int numberOfElements)
{
	if (numberOfElements < 2)
	{
		IoHandler ioh;
		ioh.putString("Must have at least 2 elements.");
		ioh.putNewLine();
	}

	size = numberOfElements;
	parent = new int[size];
	for (int i = 0; i < numberOfElements; ++i)
	{
		parent[i] = -1;	// ��� ���Ұ� ����
	}
}

// �� ���� ������ ��带 ���� ������ �� ū ������ ��带 ���� ���տ� �պ�
void SetsGraph::weightedUnion(int i, int j)
{	//  ���߱�Ģ�� �̿��Ͽ� ��Ʈ�� i�� j(i != j)�� ���� ���Ѵ�.
	//	parent[i] = -count[i]�̸� parent = -count[j]�̴�.
	int temp = parent[i] + parent[j];
	if (parent[i] > parent[j])	// i�� ��� ���� ������
	{
		parent[i] = j;	// j�� �� ��Ʈ�� �����
		parent[j] = temp;
	}
	else // j�� ��� ���� ���ų� ������
	{
		parent[j] = i;	// i�� �� ��Ʈ�� �����
		parent[i] = temp;
	}
	return;
}
// ���Ҹ� �����ϴ� ��Ʈ�� ã���鼭, ���Ե� ������ ���̸� ����
int SetsGraph::collapsingFind(int i)
{	// ���� i�� �����ϴ� ��Ʈ�� ã�´�.
	// �ر� ��Ģ�� �̿��Ͽ� i�κ��� ��Ʈ�� ���� ��� ��带 �ر���Ų��.
	int r = 0;
	for (r = i; parent[r] >= 0; r = parent[r]);	// ��Ʈ�� ã��
	while (i != r)	// �ر�
	{
		int s = parent[i];
		parent[i] = r;
		i = s;
	}
	return r;
}